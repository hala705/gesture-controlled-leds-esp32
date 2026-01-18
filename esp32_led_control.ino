// === Gesture Controlled LEDs using Serial Communication ===

// PINS
#define RED_LED     25
#define GREEN_LED   26
#define BLUE_LED    27
#define YELLOW_LED  14
#define ORANGE_LED  12

void setup() {
  Serial.begin(115200);

  pinMode(RED_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(BLUE_LED, OUTPUT);
  pinMode(YELLOW_LED, OUTPUT);
  pinMode(ORANGE_LED, OUTPUT);

  // Turn all off initially
  digitalWrite(RED_LED, LOW);
  digitalWrite(GREEN_LED, LOW);
  digitalWrite(BLUE_LED, LOW);
  digitalWrite(YELLOW_LED, LOW);
  digitalWrite(ORANGE_LED, LOW);

  Serial.println("ESP32 Ready for multi-LED commands...");
}

void loop() {
  if (Serial.available() > 0) {
    String cmd = Serial.readStringUntil('\n'); // read full command
    cmd.trim(); // remove whitespace

    // Turn all off first
    digitalWrite(RED_LED, LOW);
    digitalWrite(GREEN_LED, LOW);
    digitalWrite(BLUE_LED, LOW);
    digitalWrite(YELLOW_LED, LOW);
    digitalWrite(ORANGE_LED, LOW);

    if (cmd.indexOf('A') >= 0) { // special case: all ON
      digitalWrite(RED_LED, HIGH);
      digitalWrite(GREEN_LED, HIGH);
      digitalWrite(BLUE_LED, HIGH);
      digitalWrite(YELLOW_LED, HIGH);
      digitalWrite(ORANGE_LED, HIGH);
    } else {
      // Check each letter and turn ON corresponding LED
      if (cmd.indexOf('R') >= 0) digitalWrite(RED_LED, HIGH);
      if (cmd.indexOf('G') >= 0) digitalWrite(GREEN_LED, HIGH);
      if (cmd.indexOf('B') >= 0) digitalWrite(BLUE_LED, HIGH);
      if (cmd.indexOf('Y') >= 0) digitalWrite(YELLOW_LED, HIGH);
      if (cmd.indexOf('O') >= 0) digitalWrite(ORANGE_LED, HIGH);
    }

    Serial.print("Command received: ");
    Serial.println(cmd);
  }
}
