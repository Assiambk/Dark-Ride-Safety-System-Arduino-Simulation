# Dark-Ride-Safety-System-Arduino-Simulation

Ce projet regroupe plusieurs petites simulations inspirées des systèmes de sécurité des dark rides
(block-zones, distances entre véhicules, arrêts d’urgence, logique d’exploitation).

L’objectif n’est pas de reproduire un système réel, mais de :
- comprendre les **principes généraux** de sécurité d’attraction,
- les traduire dans des petits modules Arduino,
- faire le lien entre mon expérience terrain en tant qu’Opératrice Animatrice Attraction
  et ma formation d’ingénieure systèmes.

---

## 🎢 Modules

### 1. `block_zone_basic`

Simulation simple d’une block-zone à partir d’un capteur ultrason :

- mesure en continu de la distance avec un “véhicule” fictif,
- gestion de plusieurs zones (SAFE / WARNING / EMERGENCY STOP),
- affichage de l’état dans le Moniteur Série (IHM texte).

👉 Code : [`modules/block_zone_basic/block_zone_basic.ino`](modules/block_zone_basic/block_zone_basic.ino)  
👉 Description détaillée : (à venir)

---

## 🧩 Contexte

Dans les dark rides, le parcours est découpé en **block-zones**.  
Chaque zone ne peut être occupée que par un seul véhicule (VL) à la fois.

Si deux véhicules se rapprochent trop :
- on passe d’abord dans une zone de **surveillance** (warning),
- puis on peut aller jusqu’à un **arrêt d’urgence** pour éviter un rattrapage.

Ce projet est une manière simple de :
- rejouer ces logiques sur une table, avec un Arduino et quelques capteurs,
- préparer un futur projet plus poussé autour du comptage de véhicules et de la logique d’E-stop.

---

## 👩‍🔧 À propos

Je m’appelle Assia, je suis étudiante en ingénierie futurement spécialisée en systèmes embarqués et ancienne
Opératrice Animatrice Attraction à Disneyland Paris.

J’utilise ce projet pour relier :
- ce que j’ai vu et vécu côté **Opérations** (pannes, E-stop, procédures),
- ce que j’apprends côté **systèmes** actuellement en auto-didacte (capteurs, états, sécurité, automates).

---

## 📬 Contact

• Email : **assiamoubakir@gmail.com**  
• GitHub : Assiambk

• LinkedIn : www.linkedin.com/in/assia-moubakir-98926019b
