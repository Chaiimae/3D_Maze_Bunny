3D_Maze_Bunny

Bunny Maze 3D is an exciting project aimed at exploring 3D game development using SDL2 and C. It focuses on creating immersive 3D environments and challenging maze puzzles.

Project Structure
The project follows a simple directory structure:

main.c: Contains all the source of the code
headers: Contains header files with function declarations and constants.
images: Holds image assets used in the game.

Dependencies
This project relies on the following dependencies:

SDL2: A cross-platform development library designed to provide low-level access to audio, keyboard, mouse, joystick, and graphics hardware.
SDL2_image: An extension library that enables loading and saving images in various formats.

Introducing SDL2 and Raycasting for Understanding
Simple DirectMedia Layer (SDL) is a cross-platform software development library designed to provide a hardware abstraction layer for computer multimedia hardware components. Software developers can use it to write high-performance computer games and other multimedia applications that can run on many operating systems such as Android, iOS, Linux, macOS, and Windows. SDL manages video, audio, input devices, CD-ROM, threads, shared object loading, networking and timers.

SDL2: SDL2 is a powerful library that simplifies the process of creating graphical applications. It provides functions for handling windows, rendering graphics, and capturing user input.
Raycasting: Raycasting is a rendering technique used to create a 3D perspective effect in 2D environments. It involves casting rays from the player's viewpoint and calculating intersections with objects in the scene to determine what is visible.

you can compile the project using GCC:

gcc -o 3D_Bunny_Maze main.c -I./headers -lSDL2 -lSDL2_image

to run and interact with your 3D game
./3D_Bunny_Maze


