#include <iostream>
#include <cstdlib>
#include <regex>
#include <sstream>
#include <fstream>
#include <unordered_set>

// Function to extract app name from log entry
std::string extractAppName(const std::string& logEntry, bool isMicLog) {
        std::regex appRegex = isMicLog
        ? std::regex(R"(app=([\w\.\-]+)|client=([\w\.\-]+)|originator\s*\[osservice<([\w\.\-]+)>\]|Process\s+([\w\.\-]+)\.(\d+))")
        : std::regex(R"(\d{2}:\d{2}:\d{2}\.\d{3}\s+[A-Za-z]+\s+([^\[\]]+))"); // Camera logs

    std::smatch match;
    if (std::regex_search(logEntry, match, appRegex)) {
        if (isMicLog) {
            if (match[1].matched) return match[1].str();  // `app=...`
            if (match[2].matched) return match[2].str();  // `client=...`
            if (match[3].matched) return match[3].str();  // `originator osservice<...>`
            if (match[4].matched) return match[4].str();  // `Process coreaudiod`
        } else {
            return match[1].str();  // Camera process name before `[`
        }
    }
    return "Unknown";
}

// Monitor camera and microphone usage
void monitorUsage(const std::unordered_set<std::string>& authorizedCameraApps, 
                  const std::unordered_set<std::string>& authorizedMicApps) {

    std::string command = "log stream --predicate 'eventMessage CONTAINS \"AVCaptureDevice\" OR eventMessage CONTAINS \"coreaudiod\" OR eventMessage CONTAINS \"powerd\"' --style compact";
    FILE* pipe = popen(command.c_str(), "r");
    if (!pipe) {
        std::cerr << "Failed to run log stream command.\n";
        return;
    }

    char buffer[1024];

    while (fgets(buffer, sizeof(buffer), pipe) != nullptr) {
        std::string logEntry(buffer);
        std::string detectedApp = "Unknown";

        // std::cout << "Debug Log: " << logEntry << std::endl;

        if (logEntry.find("AVCaptureDevice") != std::string::npos) {
            // 🔍 Camera Detected
            detectedApp = extractAppName(logEntry, false);
            std::cout << "📸 Camera in Use by: " << detectedApp << "\n";
        } 
        else if (logEntry.find("coreaudiod") != std::string::npos || logEntry.find("powerd") != std::string::npos) {
            // 🎤 Microphone Detected (Includes powerd)
            detectedApp = extractAppName(logEntry, true);
            std::cout << "🎤 Microphone in Use by: " << detectedApp << "\n";
        }
    }

    pclose(pipe);
}

int main() {
    // List of authorized apps for Camera and Microphone
std::unordered_set<std::string> authorizedCameraApps = {
    "FaceTime", "Zoom", "Photo Booth", "zoom.us", "caphost", 
    "ZoomClips", "avconferenced", "FaceTimeNotificationCenterService", 
    "VDCAssistant", "AppleCameraAssistant", "Google Chrome", "Microsoft Teams"
};

std::unordered_set<std::string> authorizedMicApps = {
    "FaceTime", "Zoom", "zoom.us", "caphost", "ZoomClips", 
    "avconferenced", "coreaudiod", "Google Chrome", "Microsoft Teams", 
    "Skype", "Slack", "Webex", "OBS", "Discord"
};

    std::cout << "🔍 Monitoring camera & microphone access...\n";
    monitorUsage(authorizedCameraApps, authorizedMicApps);

    return 0;
}
