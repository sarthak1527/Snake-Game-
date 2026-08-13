# 🐍 C++ Raylib Snake Game

A simple retro-style Snake Game built with **C++ and Raylib**.

## ✨ Features

- Classic Snake gameplay
- Arrow-key controls
- Random food generation
- Score tracking
- Wall & self-collision
- Game Over and restart
- Food image and MP3 sound effects
- Modular C++ files

## 🛠️ Tech Stack

- C++
- Raylib
- MSYS2 UCRT64

## 📁 Project Structure

```text
SNAKEGAME/
├── main.cpp
├── Game.cpp
├── Game.h
├── Snake.cpp
├── Snake.h
├── Food.cpp
├── Food.h
├── Graphics/
│   └── food.jpg
└── Sounds/
    ├── eat.mp3
    └── gameover.mp3
 ```
## 🚀 Run the Game

### 1. Install Raylib

Using **MSYS2 UCRT64**:

```bash
pacman -S mingw-w64-ucrt-x86_64-raylib
 ```
### 2. Clone the Repository

```bash
git clone <YOUR-REPOSITORY-URL>
cd SNAKEGAME
```

### 3. Compile

```bash
g++ main.cpp Game.cpp Snake.cpp Food.cpp -o SnakeGame.exe -lraylib -lopengl32 -lgdi32 -lwinmm
```

### 4. Run

```bash
./SnakeGame.exe
```
## 🎮 Controls

| Key       | Action                  |
|-----------|-------------------------|
| ↑ ↓ ← →   | Move Snake              |
| ENTER     | Restart after Game Over |
| ESC       | Exit                    |
 
## 👨‍💻 Author
Sarthak Acharya
