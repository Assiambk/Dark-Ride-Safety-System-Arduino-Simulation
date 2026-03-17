/*******************************************************
 * Dark Ride Safety System – On-Vehicle Distance Sensor
 * Assia M. – 2025
 *
 * Objective:
 * - Simulate an onboard sensor on a vehicle
 *   monitoring the distance to the vehicle ahead
 * - Trigger safety states based on proximity:
 *     • SAFE
 *     • WARNING
 *     • EMERGENCY STOP
 *
 * Notes:
 * - The sensor represents an onboard sensor (like in real rides such as Pinocchio).
 * - The "vehicle ahead" is simulated by an object placed in front of the sensor.
 *******************************************************/

// --- Ultrasonic sensor HC-SR04 pins ---// 
const int trigPin = 9;
const int echoPin = 10;

// --- Mesureable variables ---
long duration;
int distanceCm;

// --- safety thresholds ---
const int SAFE_DISTANCE = 50;        // Distance > 50 cm → SAFE
const int WARNING_DISTANCE = 20;     // 20–50 cm        → WARNING
// Distance ≤ 20 cm                   → EMERGENCY STOP

// --- Vehicule states ---
enum VehicleState {
  STATE_SAFE,
  STATE_WARNING,
  STATE_EMERGENCY_STOP
};

VehicleState currentState = STATE_SAFE;


// ------------------------------------------------------------
// SETUP – Initialisation
// ------------------------------------------------------------
void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  Serial.begin(9600);

  Serial.println("=== Dark Ride Safety System ===");
  Serial.println("On-Vehicle Distance Sensor Ready");
  Serial.println("--------------------------------");
}


// ------------------------------------------------------------
// Function : measure distance using HC- SR04
// ------------------------------------------------------------
int getDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);

  return duration * 0.034 / 2; // Conversion in cm
}


// ------------------------------------------------------------
// LOOP – main logic 
// ------------------------------------------------------------
void loop() {

  // --- distance measurement ---
  distanceCm = getDistance();

  // --- state determination ---
  if (distanceCm <= WARNING_DISTANCE) {
    currentState = STATE_EMERGENCY_STOP;
  }
  else if (distanceCm <= SAFE_DISTANCE) {
    currentState = STATE_WARNING;
  }
  else {
    currentState = STATE_SAFE;
  }

  // --- HMI display (console) ---
  switch (currentState) {

    case STATE_SAFE:
      Serial.print("[SAFE]            Distance OK : ");
      Serial.print(distanceCm);
      Serial.println(" cm");
      break;

    case STATE_WARNING:
      Serial.print("[WARNING]         Vehicle too close : ");
      Serial.print(distanceCm);
      Serial.println(" cm");
      break;

    case STATE_EMERGENCY_STOP:
      Serial.print("[EMERGENCY STOP]  Critical distance : ");
      Serial.print(distanceCm);
      Serial.println(" cm");
      break;
  }

  delay(300);
}
