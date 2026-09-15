# Snake Game

A modular implementation of the classic Snake game written in C++. This project features two completely distinct interfaces running on top of the same core game logic: a text-based Command Line Interface (CLI) using ncurses, and a Graphical User Interface (GUI) using SFML 3.

## Architecture

This project was designed with a strong emphasis on clean architecture and separation of concerns.

### MVC-like Pattern
The codebase follows a pattern similar to Model-View-Controller (MVC):
*   **Model**: The `Game` and `Snake` classes handle the pure rules, grid coordinates, and collision logic. They are completely agnostic to rendering and input methods.
*   **View & Controller**: The `TerminalUI` and `SfmlUI` classes are responsible for translating the game's internal state into visual elements on the screen, as well as capturing hardware inputs and sending them back to the game logic.

This decoupling allows the game to switch seamlessly between a terminal environment and a fully graphical window without modifying a single line of the core game rules.

### Linked List Data Structure
Instead of using a standard array or vector to manage the snake's body, the `Snake` is implemented from scratch using a custom Doubly Linked List. 
*   Each segment of the snake is a `Node` containing `x` and `y` coordinates. 
*   When the snake moves, a new head node is allocated and linked to the front, and the tail node is unlinked and deleted.
*   This provides an efficient O(1) movement operation, avoiding the need to shift all body coordinates in memory every frame.
*   When the snake eats an apple, it simply bypasses the deletion of the tail for that specific frame, causing the list to grow by one node.

## Dependencies

To compile and run this game, you will need a C++17 compatible compiler, `make`, `ncurses`, and `SFML 3`.

### Ubuntu / Debian
```bash
sudo apt update
sudo apt install build-essential libncurses-dev libsfml-dev
```
*Note: Depending on your distribution version, `libsfml-dev` might install SFML 2.x by default. Ensure your system repositories provide SFML 3, or compile SFML 3 manually from source.*

### Arch Linux
```bash
sudo pacman -S base-devel ncurses sfml
```

## Compilation

The project uses a `Makefile` to manage compilation.

To compile both versions of the game:
```bash
make
```

To compile only the terminal (ncurses) version:
```bash
make cli
```

To compile only the graphical (SFML) version:
```bash
make sfml
```

To clean compiled objects and binaries:
```bash
make clean
```

## Usage

After compiling, the executables will be placed in the `bin/` directory.

Run the terminal version:
```bash
./bin/main-cli
```

Run the graphical version:
```bash
./bin/main-sfml
```