# Simple Calculator

This project is a terminal-based interactive calculator written in C for Holberton School.

## Description
The program runs in a loop and allows users to perform basic arithmetic operations. It handles floating-point numbers to provide accurate results for divisions and includes basic safety checks.

## How to Compile
Use the following command to compile with strict flags:

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 calculator.c -o calculator

## How to Use
1 - Run the program: ./calculator

2 - Select an option from the menu (1-4 to calculate, 0 to quit).

3 - Enter values for A and B when prompted.

## Operations
-Addition: A + B

-Subtraction: A - B

-Multiplication: A * B

-Division: A / B (Returns a decimal, e.g., 10 / 4 = 2.5)

## Features
-Division by Zero: If the user enters 0 for B during division, the program displays Error: division by zero.

-Input Robustness: The program handles non-numeric characters for operands A or B may cause unexpected behavior as per the project scope.

## Author
-Erwan Barat
