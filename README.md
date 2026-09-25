# 🌀 Raylib Spring Physics Simulator in C++

A 2D interactive physics simulator built from scratch using C++ and the Raylib library. 
This project focuses on realistic physical interactions between a rigid, player-controlled body and a network of elastic particles. By separating collision resolution from velocity integration, the simulation ensures robust performance, impenetrable objects, and highly organic spring behavior based on Hooke's Law.

## ✨ Features
* **Hooke's Law Physics:** Particles are pulled back to their original "anchor" positions with a force proportional to their distance, creating a natural elastic effect.
* **Velocity Damping:** Friction is continuously applied to dissipate kinetic energy, allowing particles to settle smoothly at their resting points without vibrating infinitely.
* **Impenetrable Rigid Collisions:** Uses positional projection (instantly pushing points out of the circle's radius) to ensure particles never glitch or get trapped inside the player's circle.
* **Smooth Vector Sliding:** Calculates the dot product during collisions to cancel only the inward velocity. This allows particles to retain their momentum and slide fluidly along the curved edge of the circle rather than stopping abruptly.
* **Centralized Physics Loop:** Clean architectural separation between the collision resolution step and the position/velocity integration step for a stable simulation.

## 🎮 Controls
* **Mouse Movement:** Move the cursor around the screen to control the black rigid circle. Ram into the red particles to see them react, stretch, and snap back into place!
* **ESC:** Exit the simulation.

## 🛠️ Prerequisites
To compile and run this project, you need:

* A C++ compiler (like GCC / g++).
* Raylib installed on your system.

## 🚀 How to Build and Run
Open your terminal or command prompt in the project folder and run the appropriate command for your operating system.

**Linux**
Compile the simulation linking the Raylib library and its dependencies:

```bash
g++ main.cpp circle.cpp spring.cpp -o spring_sim -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

./spring_sim
```
---
*Note: This README was drafted with AI assistance.*