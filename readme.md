# 1010! Terminal Puzzle Game in C++ ![C++](https://img.shields.io/badge/C%2B%2B-11-blue.svg) ![ncurses](https://img.shields.io/badge/ncurses-6.3-green.svg)

**1010!** is a terminal-based puzzle game inspired by the classic mobile game of the same name. Developed in **C++** using the **ncurses** library, the project replicates the strategic challenge of placing various block pieces on a 10x10 grid to complete and clear lines while maximizing the score.

The game was designed with a modular architecture and clean terminal graphics, showcasing advanced C++ design and system programming skills.

---

## Features

- 🚀 **Interactive Terminal UI** using ncurses.
- 🧩 **10x10 Game Grid** that updates in real time.
- 🔲 **Multiple Block Shapes** that simulate the original 1010! experience.
- 💾 **Game Saving and Loading** via file persistence.
- 🏆 **High Score Tracking** stored between sessions.
- 🔄 **Rotations and Piece Validations** to simulate intuitive user interaction.
- 🔧 **Clear MVC-style architecture** for maintainability and readability.

---

## Build and Run Instructions

### Requirements
- `g++` (C++ compiler)
- `libncurses` (install with `sudo apt install libncurses-dev`)

### Build the Game
```bash
make
```

### Run the game
```bash
./1010
```

### Clean build artifacts 
```bash
make clean
```

### Project structure 
```
.
├── src/
│   ├── board.cpp       # Grid logic: placing, checking, clearing lines
│   ├── choice.cpp      # Handles random shape selection
│   ├── main.cpp        # Entry point
│   ├── myprogram.cpp   # Main loop and game logic controller
│   ├── score.cpp       # Score management
│   └── window.cpp      # Ncurses display logic
│
├── inc/
│   ├── board.h
│   ├── choice.h
│   ├── myprogram.h
│   ├── score.h
│   ├── shape.h         # Shape data and utility
│   └── window.h
│
├── annexe/
│   ├── piece.cpp/h     # Legacy/unused code from initial prototypes
│   └── base/           # Provided materials (original subject, test files)
│
├── Makefile
├── save/               # Save file directory
├── best_score          # Stores best score
└── set_1               # Piece configuration or save data
```

### System Architecture 

The project adopts a modular and maintainable design. Below is a high-level overview of how components interact:
- main.cpp initializes the game and delegates control to MyProgram.
- MyProgram orchestrates the core loop: reading input, updating state, rendering UI.
- Board manages the logic for piece placement and clearing lines.
- Choice selects new pieces and verifies placement validity.
- Window uses ncurses to draw the board, pieces, and score.
- Score tracks, displays, and saves the player’s score.
- Shape provides reusable data structures and constants for block pieces.

### UML
```
+-------------------+
|    MyProgram      |
+-------------------+
| +run()            |
| +initGame()       |
| +handleInput()    |
+-------------------+
     |      |       |       |
     v      v       v       v
+--------+ +--------+ +--------+ +--------+
| Board  | | Choice | | Window | | Score  |
+--------+ +--------+ +--------+ +--------+
              |
              v
           +--------+
           | Shape  |
           +--------+
```

### Author

**Ismael L. Sai**
Software Engineer | Puzzle Game Enthusiast

>This project was fully developed by Ismaël Labidi, including game logic, system design, and all code contributions.

### License

This project is licensed under the MIT License - see the LICENSE.md file for details.



