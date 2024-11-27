## README for the "Setting Up" Project
# Project Overview

Setting Up is a C programming project focused on applying dynamic programming to solve a classic problem: finding the largest square within a grid while avoiding obstacles. This program allows you to either read a grid from a file or generate one dynamically based on given parameters.

# Features

    **Input Options:**
        Read a grid from a file where:
            The first line contains the number of lines on the grid.
            Each subsequent line contains . (empty spaces) and o (obstacles).
        Generate a grid dynamically by specifying its dimensions and a repeating pattern.

    **Core Functionality:**
        Identify and mark the largest possible square in the grid while avoiding obstacles.
        Replace . with x to represent the square on the grid.

    **Output:**
        Print the processed grid with the largest square marked.
        Handle ties by selecting the square positioned higher and to the left.

# Authorized Functions:

    open, read, write, close
    malloc, free
    stat

# Usage
**Reading a File:**

./setting_up <file_name>

The file must adhere to the following rules:

    The first line specifies the number of lines in the grid.
    Only . and o are allowed for grid lines.
    All lines (excluding the first) must have the same length.
    Each line is terminated with a newline character.

# Example:

Input File (example_file):

9
...........................
....o......................
............o..............
...........................
....o......................
..............o............
...........................
......o..............o.....
..o.......o................

Execution:

./setting_up example_file

Output:

.....xxxxxxx................
....oxxxxxxx................
.....xxxxxxxo...............
.....xxxxxxx................
....oxxxxxxx................
.....xxxxxxx...o............
.....xxxxxxx................
......o...............o.....
..o.......o.................

**Generating a Grid:**

./setting_up <size> <pattern>

    <size> specifies the grid's width and height.
    <pattern> defines the repeating sequence for each line of the grid.

# Example:

./setting_up 6 "..o.."

Output:

..oxx.
.o.xx.
o....o
....o.
...o..
..o...
