
### Grant Required Permissions

- Log stream requires Full Disk Access in System Preferences → Privacy & Security.

- Since the program reads system logs and hardware states, you must grant full disk access:

- Open System Settings → Privacy & Security → Full Disk Access.
- Click "+", then add Terminal (or iTerm if you use it).
- Restart your terminal.


### Running the Program

- make MicCamWatcher
- ./MicCamWatcher
- Launch Photo Booth, Factime, Zoom

### Logs

<pre>

1. Photo Booth

MacBook-Air-2:detect-mic-and-webcam anish$ ./MicCamWatcher 
🔍 Monitoring camera & microphone access...
📸 Camera in Use by: Unknown
🚨 ALERT: Unauthorized camera access by Unknown!
🎤 Microphone in Use by: Unknown
🚨 ALERT: Unauthorized microphone access by Unknown!
📸 Camera in Use by: Photo Booth
📸 Camera in Use by: Photo Booth
📸 Camera in Use by: Photo Booth
🎤 Microphone in Use by: Unknown
🚨 ALERT: Unauthorized microphone access by Unknown!
📸 Camera in Use by: Photo Booth
📸 Camera in Use by: Photo Booth
📸 Camera in Use by: Photo Booth
📸 Camera in Use by: Photo Booth

2. FaceTime

MacBook-Air-2:detect-mic-and-webcam anish$ ./MicCamWatcher 
🔍 Monitoring camera & microphone access...
📸 Camera in Use by: Unknown
🚨 ALERT: Unauthorized camera access by Unknown!
📸 Camera in Use by: FaceTime
📸 Camera in Use by: FaceTimeNotificationCenterService
📸 Camera in Use by: FaceTimeNotificationCenterService
📸 Camera in Use by: FaceTimeNotificationCenterService
📸 Camera in Use by: FaceTime
📸 Camera in Use by: FaceTime
📸 Camera in Use by: FaceTimeNotificationCenterService
📸 Camera in Use by: avconferenced
📸 Camera in Use by: avconferenced
📸 Camera in Use by: avconferenced
📸 Camera in Use by: avconferenced
📸 Camera in Use by: FaceTime


3. Zoom.us

MacBook-Air-2:detect-mic-and-webcam anish$ ./MicCamWatcher 
🔍 Monitoring camera & microphone access...
📸 Camera in Use by: Unknown
🚨 ALERT: Unauthorized camera access by Unknown!
🎤 Microphone in Use by: Unknown
🚨 ALERT: Unauthorized microphone access by Unknown!
🎤 Microphone in Use by: Unknown
🚨 ALERT: Unauthorized microphone access by Unknown!
📸 Camera in Use by: caphost
📸 Camera in Use by: zoom.us
📸 Camera in Use by: caphost
📸 Camera in Use by: ZoomClips
🎤 Microphone in Use by: Unknown
🚨 ALERT: Unauthorized microphone access by Unknown!
🎤 Microphone in Use by: Unknown
🚨 ALERT: Unauthorized microphone access by Unknown!
🎤 Microphone in Use by: Unknown
🚨 ALERT: Unauthorized microphone access by Unknown!
🎤 Microphone in Use by: Unknown
🚨 ALERT: Unauthorized microphone access by Unknown!
🎤 Microphone in Use by: Unknown
🚨 ALERT: Unauthorized microphone access by Unknown!
🎤 Microphone in Use by: Unknown
🚨 ALERT: Unauthorized microphone access by Unknown!
🎤 Microphone in Use by: coreaudiod
🎤 Microphone in Use by: coreaudiod
🎤 Microphone in Use by: coreaudiod
🎤 Microphone in Use by: coreaudiod
🎤 Microphone in Use by: coreaudiod
🎤 Microphone in Use by: coreaudiod
🎤 Microphone in Use by: coreaudiod
🎤 Microphone in Use by: coreaudiod
🎤 Microphone in Use by: coreaudiod
🎤 Microphone in Use by: coreaudiod
🎤 Microphone in Use by: coreaudiod

4. Unauthorized Apps

Remove Photo Booth App from the list for testing purposes. Verify alerts generated for Photo Booth App.

MacBook-Air-2:detect-mic-and-webcam anish$ ./MicCamWatcher 
🔍 Monitoring camera & microphone access...
📸 Camera in Use by: Unknown
🚨 ALERT: Unauthorized camera access by Unknown!
🎤 Microphone in Use by: Unknown
🚨 ALERT: Unauthorized microphone access by Unknown!
🎤 Microphone in Use by: Unknown
🚨 ALERT: Unauthorized microphone access by Unknown!
📸 Camera in Use by: Photo Booth
🚨 ALERT: Unauthorized camera access by Photo Booth!
📸 Camera in Use by: Photo Booth
🚨 ALERT: Unauthorized camera access by Photo Booth!
📸 Camera in Use by: Photo Booth
🚨 ALERT: Unauthorized camera access by Photo Booth!
🎤 Microphone in Use by: Unknown
🚨 ALERT: Unauthorized microphone access by Unknown!
📸 Camera in Use by: Photo Booth
🚨 ALERT: Unauthorized camera access by Photo Booth!
📸 Camera in Use by: Photo Booth
🚨 ALERT: Unauthorized camera access by Photo Booth!
📸 Camera in Use by: Photo Booth
🚨 ALERT: Unauthorized camera access by Photo Booth!
📸 Camera in Use by: Photo Booth
🚨 ALERT: Unauthorized camera access by Photo Booth!
🎤 Microphone in Use by: Unknown

</pre>
