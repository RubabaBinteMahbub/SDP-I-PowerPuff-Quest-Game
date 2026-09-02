# 🩷 PowerPuff Quest Game

A console based RPG game developed in **C**, inspired by animated superhero series "Powerpuff Girls". This is a group project developed for the Software Development Course (CSE 100).

---

## 🎮 Overview

In **PowerPuff Quest**, players take on the role of one of the Powerpuff Girls and fight through **10 levels of increasingly powerful villains**.

Players can:

* Create and log into an account
* Choose between Blossom, Bubbles, and Buttercup
* Battle against 10 different villains
* Attack and heal during battles
* Unlock special skills after defeating enemies
* Increase their attack power as they progress
* Restore HP at rest areas
* Save their progress and resume later
* Experience different game outcomes depending on their performance

---

## ✨ Features

👤 **User Registration System**<br>
🔐 **Login Authentication**<br>
🩷 **Three Playable Characters** — Blossom, Bubbles & Buttercup<br>
👾 **10 Monster Battle Levels**<br>
⚔️ **Normal Attack System**<br>
💚 **Healing System (+20 HP)**<br>
✨ **Special Skill System**<br>
📈 **Level Progression**<br>
⬆️ **Attack Power Upgrades**<br>
❤️ **HP Management & Health Bonuses**<br>
💾 **Automatic Game Saving**<br>
🔄 **Resume Saved Game**<br>
🛏️ **Rest Area / Save Point**<br>
🎨 **Colorful Terminal Interface using ANSI Colors**<br>
💀 **Game Over System**<br>
🏆 **Final Victory System**<br>

---

## 🩷 Playable Characters

| Character    |  HP | Attack | Play Style    |
| ------------ | --: | -----: | ------------- |
| 🌸 Blossom   | 120 |     20 | Balanced      |
| 🩵 Bubbles   | 140 |     15 | Tank / Healer |
| 💚 Buttercup | 100 |     25 | Berserker     |

The character selection and initial statistics are implemented in the game logic.

---

## 👾 Monsters

The game contains **10 levels** with different monsters and increasing difficulty:

| Level | Monster            |  HP | Attack |
| ----: | ------------------ | --: | -----: |
|     1 | Fuzzy Lumpkins     |  50 |     12 |
|     2 | Mojo Jojo          |  70 |     16 |
|     3 | Sedusa             |  90 |     20 |
|     4 | Gangreen Gang      | 100 |     24 |
|     5 | HIM                | 120 |     28 |
|     6 | Princess Morbucks  | 140 |     32 |
|     7 | The Amoeba Boys    | 160 |     36 |
|     8 | The Rowdyruff Boys | 180 |     40 |
|     9 | Clone Professor    | 210 |     45 |
|    10 | Godzilla           | 250 |     50 |

The monsters, HP values, and attack values are defined in the game.

---

## ⚔️ Battle System

During each battle, players can choose from different actions.

### 1. Normal Attack

Deals damage equal to the player's current attack power.

### 2. Heal

Restores **20 HP**, up to the player's maximum HP.

### 3. Special Skill

After defeating enemies, players unlock special skills. Each special skill deals **2× the player's current attack damage**.

### 4. Save and Exit

Players can save their current progress and exit the battle. The saved game can be resumed later.

The battle menu, attack, healing, skill and save functionality are implemented in the main battle loop.

---

## ✨ Special Skills

A new skill is unlocked after completing each level.

The available skills are:

1. ❄️ Freeze Ray
2. 🔊 Sonic Scream
3. 👁️ Laser Eye
4. ⚡ Thunder Clap
5. 👊 Super Punch
6. ❄️ Ice Storm
7. 💥 Energy Blast
8. 🌊 Power Wave
9. 💣 Mega Attack
10. 🌟 Ultimate Power

Players can use their unlocked skills during battles to deal increased damage.

---

## 📈 Level Progression

After defeating a monster:

* A new special skill is unlocked.
* Base attack increases by **+5**.
* HP receives a **+15 bonus**, without exceeding maximum HP.
* The player proceeds to the next level.

After every two completed levels, the player reaches a **Rest Area / Save Point**, where HP is fully restored.

---

## 💾 Save & Resume System

The game supports file-based game saving.

Game progress is stored in:

```text
savegame.txt
```

The saved state contains information such as:

* Current username
* Current level
* Current HP
* Maximum HP
* Attack power
* Number of unlocked skills
* Selected character

The game automatically saves progress during gameplay and allows the player to resume from the saved level after logging in.

When a game is completed or the player is defeated, the save file is removed.

---

## 👤 User Authentication

Player accounts are stored in:

```text
users.txt
```

The authentication system supports:

* New user registration
* Duplicate username checking
* Login verification
* Logout
* Persistent user data using file handling

The system checks the stored username and password before allowing the player to access the game.

>** Since this is a course project, passwords are stored in plain text.

---

## 🎮 Game Flow

```text
        ┌───────────────┐
        │    Register   │
        └───────┬───────┘
                ↓
        ┌───────────────┐
        │     Login     │
        └───────┬───────┘
                ↓
        ┌───────────────────┐
        │ Start New Game /  │
        │ Resume Game       │
        └─────────┬─────────┘
                  ↓
        ┌───────────────────┐
        │ Choose Character  │
        └─────────┬─────────┘
                  ↓
        ┌───────────────────┐
        │  Fight Monsters   │
        │     Level 1–10    │
        └─────────┬─────────┘
                  ↓
        ┌───────────────────┐
        │ Unlock Skills &   │
        │ Increase Attack   │
        └─────────┬─────────┘
                  ↓
        ┌───────────────────┐
        │ Rest Area Every   │
        │ 2 Levels          │
        └─────────┬─────────┘
                  ↓
        ┌───────────────────┐
        │   Final Boss      │
        │    Godzilla       │
        └─────────┬─────────┘
                  ↓
          🏆 Victory / 💀 Game Over
```

---

## 🛠️ Technologies Used

* **C Programming Language**
* **GCC Compiler**
* **File Handling**
* **Standard C Libraries**
* **ANSI Escape Codes**
* **GitHub**
* **Code::Blocks / VS Code**

---

## 📂 Project Structure

```text
PowerPuff-Quest/
│
├── PowerPuff_Quest.c
├── users.txt
├── savegame.txt
├── Screenshots
├── README.md
└── LICENSE
```

> `savegame.txt` is generated when game progress is saved.

---

## 🚀 How to Compile and Run
1. Open the source file in in any compiler (for example, **Code::Blocks**).
4. Click **Build and Run** or press **F9**.
5. The game will compile and start automatically.

---

## 🏆 Victory Condition

The player must defeat all **10 villains** to complete PowerPuff Quest.

After defeating the final boss, **Godzilla**, the game displays the final victory message and deletes the completed save state.

---

## 💀 Game Over Condition

If the player's HP reaches **0 or below**, the player is defeated by the current monster.

The game displays a **GAME OVER** message and removes the saved game state.

---

## 🔮 Future Improvements

* 🌐 Add multiple player and leaderboard system
* 🛡️ Implement encrypted password storage
* 🎵 Add background music and sound effects
* 💾 Support multiple save slots
* 🎨 Improve the overall terminal UI and animations

## 👥 Team Members

### Team PowerPuff Girls

* **Rubaba Binte Mahbub** (ID: 20254103260)
* **Rezowan Hossain Rodela** (ID: 20254103258)
* **Mehreen Bintay Yusuf Simin** (ID: 20254103266)

---

## 📜 License

This project is licensed under the **MIT License**.

---

##  Acknowledgements

Developed as a **Software Development Course - I (CSE 100)** group project.
