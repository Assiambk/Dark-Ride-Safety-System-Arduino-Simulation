# Dark Ride Safety System – Arduino Simulation

Ce projet regroupe plusieurs simulations inspirées des logiques de sécurité utilisées dans les dark rides :
monitoring de distance entre véhicules, transitions d’états (SAFE / WARNING / EMERGENCY STOP), principes
de block-zones, et comportements système élémentaires.

L’objectif n’est **pas** de reproduire un système réel, mais de :

- comprendre les **principes généraux** de sécurité d’attraction,
- les transformer en modules Arduino pédagogiques,
- illustrer la façon dont mon expérience terrain d’opératrice attraction se connecte à ma formation d’ingénieure.

---

## 🎢 Modules

### 1. `on_vehicle_distance_sensor`

Ce module simule un **capteur embarqué sur un véhicule de dark ride**.  
Il surveille la distance avec le véhicule précédent et applique trois états de sécurité :

- **SAFE** → distance normale  
- **WARNING** → rapprochement inhabituel  
- **EMERGENCY STOP** → distance critique (arrêt simulé)

Dans de nombreuses attractions, ce principe contribue à éviter les rattrapages et à détecter des
situations potentiellement dangereuses.

👉 Code : [`modules/on_vehicle_distance_sensor/on_vehicle_distance_sensor.ino`](modules/on_vehicle_distance_sensor/on_vehicle_distance_sensor.ino)  
👉 Documentation détaillée : à venir

---

## 🧩 Contexte général

Dans les dark rides, le parcours est traditionnellement divisé en **block-zones**, chacune ne pouvant
être occupée que par un seul véhicule (VL).  
Les systèmes embarqués (capteurs, encodeurs, surveillance positionnelle) permettent d'assurer :

- le respect des distances,  
- la détection d’arrêts inattendus,  
- la mise en sécurité automatique si nécessaire.

Ce projet explore ces notions à travers des modules simples :

- capteur embarqué surveillant le véhicule précédent,  
- transitions logiques entre différents états,  
- premières briques d’une architecture de sécurité.

Ces modules constituent une base pour un futur projet plus avancé autour du comptage de véhicules
et de la logique d'arrêt automatique type “VL mal lu / incohérence de zone”.

---

## 👩‍🔧 À propos

Je m’appelle **Assia**, étudiante en ingénierie (futurement spécialisée en systèmes embarqués)  
et ancienne **Opératrice Animatrice Attraction** à Disneyland Paris.

J’utilise ce projet pour relier :

- ce que j’ai appris **côté Opérations** : pannes, E-stop, logique terrain, sécurité, procédures d’exploitation ;  
- ce que j’apprends **côté ingénierie** : capteurs, microcontrôleurs, systèmes embarqués, états, sûreté de fonctionnement.

---

## 📬 Contact

• Email : **assiamoubakir@gmail.com**  
• LinkedIn : **https://www.linkedin.com/in/assia-moubakir-98926019b/**
