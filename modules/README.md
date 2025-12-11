# On-Vehicle Distance Sensor – Arduino Module

Ce module simule un **capteur embarqué sur un véhicule de dark ride**, chargé de surveiller la distance
avec le véhicule précédent.  
Il illustre un principe fondamental de sécurité : **maintenir un espacement suffisant entre les véhicules
pour éviter les rattrapages et détecter les comportements anormaux**.

Ce module est un composant de la simulation globale du projet  
**Dark Ride Safety System – Arduino Simulation**.

---

# 🎯 Objectifs du module

- Représenter un **véhicule équipé d’un capteur embarqué** (proximité avant).  
- Mesurer en continu la distance avec un obstacle ou un autre véhicule.  
- Déterminer l’état du système en fonction des seuils :  
  - SAFE  
  - WARNING  
  - EMERGENCY STOP  
- Fournir un **affichage console** simulant une IHM simple utilisée en exploitation.  
- Servir de base à des modules plus avancés (logique de block-zone, comptage VL, incohérence de zone).

---

# 🔧 Matériel utilisé

- Arduino Uno  
- Capteur ultrason HC-SR04  
- Câbles Dupont  
- Un objet représentant le véhicule précédent (main, boîte, etc.)

Le capteur est considéré ici comme **embarqué sur le véhicule**, ce qui correspond mieux aux logiques
observées dans de nombreuses attractions.

---

# 🧠 Logique du système

Le capteur mesure la distance devant le véhicule.  
Selon cette distance, l’état change :

| État | Condition | Signification |
|------|-----------|----------------|
| SAFE | distance > 50 cm | Espacement normal |
| WARNING | 20 < distance ≤ 50 cm | Rapprochement inhabituel, surveillance requise |
| EMERGENCY STOP | distance ≤ 20 cm | Distance critique → arrêt de sécurité |

Ces valeurs sont **exagérées** et **adaptées au matériel** :  
le but est la pédagogie, pas la fidélité aux valeurs réelles.

---

# 💻 Code principal (extrait)

👉 Le code complet est disponible ici :  
[`on_vehicle_distance_sensor.ino`](on_vehicle_distance_sensor.ino)

```cpp
if (distanceCm <= WARNING_DISTANCE) {
    currentState = STATE_EMERGENCY_STOP;
}
else if (distanceCm <= SAFE_DISTANCE) {
    currentState = STATE_WARNING;
}
else {
    currentState = STATE_SAFE;
}
