/****************************************************
 * Dark Ride Safety System – On-Vehicle Distance Sensor
 * Assia M. – 2025
 *
 * Objectif :
 *  - Simuler un capteur embarqué sur un véhicule (VL)
 *    qui surveille la distance avec le véhicule précédent.
 *  - Déclencher des états sécurité en fonction
 *    du rapprochement :
 *       • SAFE
 *       • WARNING
 *       • EMERGENCY STOP
 *
 * Notes :
 *  - Le capteur représente un capteur embarqué (comme sur Pinocchio).
 *  - Le "véhicule devant" est simulé par un objet placé devant le capteur.
 ****************************************************/

// --- Pins du capteur ultrason HC-SR04 ---
const int trigPin = 9;
const int echoPin = 10;

// --- Variables pour la mesure ---
long duration;
int distanceCm;

// --- Seuils de sécurité ---
const int SAFE_DISTANCE = 50;        // Distance > 50 cm → SAFE
const int WARNING_DISTANCE = 20;     // 20–50 cm        → WARNING
// Distance ≤ 20 cm                   → EMERGENCY STOP

// --- États du véhicule ---
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
// Fonction : mesure la distance avec HC-SR04
// ------------------------------------------------------------
int getDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);

  return duration * 0.034 / 2; // Conversion en cm
}


// ------------------------------------------------------------
// LOOP – Logique principale
// ------------------------------------------------------------
void loop() {

  // --- Prise de mesure ---
  distanceCm = getDistance();

  // --- Détermination de l'état ---
  if (distanceCm <= WARNING_DISTANCE) {
    currentState = STATE_EMERGENCY_STOP;
  }
  else if (distanceCm <= SAFE_DISTANCE) {
    currentState = STATE_WARNING;
  }
  else {
    currentState = STATE_SAFE;
  }

  // --- Affichage IHM (console) ---
  switch (currentState) {

    case STATE_SAFE:
      Serial.print("[SAFE]            Distance OK : ");
      Serial.print(distanceCm);
      Serial.println(" cm");
      break;

    case STATE_WARNING:
      Serial.print("[WARNING]         VL proche : ");
      Serial.print(distanceCm);
      Serial.println(" cm");
      break;

    case STATE_EMERGENCY_STOP:
      Serial.print("[EMERGENCY STOP]  Distance critique ! ");
      Serial.print(distanceCm);
      Serial.println(" cm");
      break;
  }

  delay(300);
}
