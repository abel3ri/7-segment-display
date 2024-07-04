// Define the segment pins for a common cathode 7-segment display
const int segmentPins[7] = {2, 3, 4, 5, 6, 7, 8};

// Define the digit patterns for 0-9 (common cathode)
const int digitPatterns[10][7] = {
  {HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, LOW},   // 0
  {LOW, HIGH, HIGH, LOW, LOW, LOW, LOW},       // 1
  {HIGH, HIGH, LOW, HIGH, HIGH, LOW, HIGH},    // 2
  {HIGH, HIGH, HIGH, HIGH, LOW, LOW, HIGH},    // 3
  {LOW, HIGH, HIGH, LOW, LOW, HIGH, HIGH},     // 4
  {HIGH, LOW, HIGH, HIGH, LOW, HIGH, HIGH},    // 5
  {HIGH, LOW, HIGH, HIGH, HIGH, HIGH, HIGH},   // 6
  {HIGH, HIGH, HIGH, LOW, LOW, LOW, LOW},      // 7
  {HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH},  // 8
  {HIGH, HIGH, HIGH, HIGH, LOW, HIGH, HIGH}    // 9
};

void setup() {
  for (int i = 0; i < 7; i++) {
    pinMode(segmentPins[i], OUTPUT);
  }
}

void displayDigit(int digit) {
  for (int i = 0; i < 7; i++) {
    digitalWrite(segmentPins[i], digitPatterns[digit][i]);
  }
}

void loop() {
  // Count up from 0 to 9
  for (int i = 0; i <= 9; i++) {
    displayDigit(i);
    delay(500);
  }

  // Count down from 9 to 0
  for (int i = 9; i >= 0; i--) {
    displayDigit(i);
    delay(500);
  }
}
