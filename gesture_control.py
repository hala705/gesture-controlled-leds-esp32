import cv2
import mediapipe as mp
import serial
import time


esp = serial.Serial('COM4', 115200, timeout=1)  # 
time.sleep(2)  

mpHands = mp.solutions.hands
hands = mpHands.Hands(
    static_image_mode=False,
    max_num_hands=1,
    min_detection_confidence=0.7,
    min_tracking_confidence=0.7
)
mpDraw = mp.solutions.drawing_utils

tipIds = [4, 8, 12, 16, 20]  

def fingersUp(lmList):
    fingers = []

    
    if lmList[tipIds[0]][1] > lmList[tipIds[0] - 1][1]:
        fingers.append(1)
    else:
        fingers.append(0)

    for i in range(1, 5):
        if lmList[tipIds[i]][2] < lmList[tipIds[i] - 2][2]:
            fingers.append(1)
        else:
            fingers.append(0)

    return fingers


cap = cv2.VideoCapture(0)
prev_command = ''

print("Gesture control started...")

while True:
    success, img = cap.read()
    if not success:
        break


    img = cv2.flip(img, 1)
    img = cv2.rotate(img, cv2.ROTATE_90_COUNTERCLOCKWISE)

    imgRGB = cv2.cvtColor(img, cv2.COLOR_BGR2RGB)
    results = hands.process(imgRGB)

    if results.multi_hand_landmarks:
        for handLms in results.multi_hand_landmarks:
            lmList = []
            h, w, _ = img.shape

            for id, lm in enumerate(handLms.landmark):
                lmList.append([id, int(lm.x * w), int(lm.y * h)])

            if lmList:
                fingers = fingersUp(lmList)

                
                led_letters = ['R', 'G', 'B', 'Y', 'O']  
                cmd = ''

                for i in range(5):
                    if fingers[i] == 1:
                        cmd += led_letters[i]

                if sum(fingers) == 0:
                    cmd = 'A'  

                
                if cmd != prev_command:
                    esp.write((cmd + '\n').encode())  
                    prev_command = cmd
                    print(f"Fingers {fingers} → {cmd}")

            mpDraw.draw_landmarks(img, handLms, mpHands.HAND_CONNECTIONS)

    cv2.imshow("Hand Gesture Control", img)

    if cv2.waitKey(1) & 0xFF == 27:  
        break

cap.release()
cv2.destroyAllWindows()
esp.close()
