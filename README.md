
# gesture-controlled-leds-esp32
Control multiple LEDs using hand gestures with Python, Mediapipe, and ESP32 through real-time serial communication.
🤖 Gesture Controlled LEDs using ESP32


I wanted to connect software with hardware in a way that feels natural — using hand gestures to control real LEDs. No buttons, no switches — just gestures, code, and electronics working together.

🔧 What This Project Does

Uses a camera to detect hand gestures

Processes gestures in Python using MediaPipe

Sends commands over Serial communication

An ESP32 receives the commands

Multiple LEDs can turn ON or OFF at the same time

All of this happens in real time.

🧠 Why I Built It

I enjoy projects where you can see the result of your code immediately.

This one pushed me to:

Work with computer vision

Handle real-time communication

Debug both software and hardware

Optimize performance to reduce lag

It reminded me that technology is most fun when different fields come together.

⚙️ Hardware Used

ESP32

LEDs (Red, Green, Blue, Yellow, Orange)

Resistors

Breadboard & jumper wires

USB cable

💻 Software & Tools

Python

MediaPipe

OpenCV

Arduino IDE

Serial communication

🔄 How It Works (Process)

The camera captures live video

MediaPipe detects hand landmarks

Specific gestures are mapped to commands

Python sends characters through Serial (USB)

ESP32 reads the data

LEDs turn ON or OFF based on received commands

Multiple LEDs can be controlled simultaneously without changing pin connections.








📂 Project Structure
gesture-controlled-leds-esp32/
│
├── gesture_control.py     # Python gesture detection code
├── esp32_led_control.ino  # ESP32 Arduino code
├── README.md
└── .gitignore

🚀 How to Run
1️⃣ ESP32

Open esp32_led_control.ino in Arduino IDE

Select ESP32 board & correct COM port

Upload the code

2️⃣ Python
pip install mediapipe opencv-python pyserial
python gesture_control.py


Make sure the ESP32 is connected before running the Python script.


🙌 Final Thoughts

This project helped me grow both technically and mentally.
It wasn’t always smooth; lag, errors, wiring issues; but solving them was the best part.

If you’re learning embedded systems, computer vision, or just like building things that move and light up, I hope this project helps or inspires you.
Microsoft Learn Student Ambassador
ID: studentamb_492918

