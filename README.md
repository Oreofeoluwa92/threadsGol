Adebunmi Ademuyiwa 
Multithreaded Game of Life

Description

This project implements Game of Life using C++ and the ncurses library for interactive visualization. 
The simulation divides the grid into sub-regions processed by multiple threads to optimize performance.

User Input:

n - Move to the next generation.

q - Quit the simulation.
Requirements

System: Ubuntu or other Linux distributions.

Compiler: g++

Standard C++ library for threading.
Compilation and Execution
Use the provided Makefile to compile the program:
make

Usage

Run the program with three command-line arguments:

./GOL <M> <N> <MAX>

M: Size of the grid (MxM).

N: Number of threads in each dimension (NxN threads total). Must divide M.

MAX: Number of generations to simulate.


Example:

./GOL 25 5 100

This creates a 25x25 board, uses 5x5 (25) threads, and runs for 100 generations.

Controls
n: Advance to the next generation.

q: Quit the simulation.

File Structure

main.cpp: Contains the main() function, handles ncurses initialization, and controls the simulation loop.

game.cpp: Core logic for the Game of Life, including grid updates and multithreading.

game.h: Header file containing function declarations and global variables.

Makefile: Build instructions for compiling the program.


Known Issues

Ensure that M is divisible by N for the program to function correctly.

The program may not behave as expected if the terminal window is too small for the specified grid size.
