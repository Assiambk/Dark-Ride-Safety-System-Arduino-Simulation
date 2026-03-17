# Dark Ride Safety System – Arduino Simulation

This project explores safety logic used in dark ride systems through simple Arduino-based simulations. 

It focuses on key principles such as: 

- vehicle distance monitoring
- system state transitions ( SAFE/ WARNING/ EMERGENCY STOP)
- block zone logic
- basic safety behaviors in ride operations

The goal is **not** to replicate a real industrial system, but to: 

- understand core ride safety principles
- translate them into simple embedded modules
- connect real-world operational experience with engineering concepts

This project is directly inspireed by my experience as a Ride Operator, where I obsvered how safety systems behave in real conditions.


---

## 🎢 Modules

### 1. `on_vehicle_distance_sensor`

This module simulates an onboard sensor monitoring the distance to the vehicle ahead. 

It applies three safety states: 

- **SAFE** → normal distance
- **WARNING** → abnormal proximity
- **EMERGENCY STOP** → critical distance (simulated stop)

This logic is widely used in real attractions to prevent collisions and detect unsafe situations.


👉 Code : [on_vehicle_distance_sensor.ino](on_vehicle_distance_sensor.ino)


---

## 🧩 System Overview

In dark rides, the track is divided into **block-zones**, where only one vehicle is allowed per section.

Embedded systems (sensors, position tracking, control logic) ensure:

- safe distance between vehicles
- detection of unexpected stops
- automatic safety responses when necessary



---

## 👩‍🔧 About

My name is Assia, an engineering student specializing in embedded systems and a former Ride Operator at Disneyland Paris.

This projects bridges:

- **operations experience** (failures, E-stop logic, real-world safety procedures)
- **engineering knowledge** (sensors, microcontrollers, embedded systems, system states)



---

## 📬 Contact

• Email : **assiamoubakir@gmail.com**  
• LinkedIn : **https://www.linkedin.com/in/assia-moubakir-98926019b/**
