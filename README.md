This project has been created as part of the 42 curriculum by _vkyryche_, _zabishev_.

# Description
Push_swap is an algorithmic project from the 42 School curriculum. The objective is to sort data on a stack, using a limited set of instructions, with the lowest possible number of operations.

This implementation also introduce a dynamic disorder metric and an adaptive routing system. Instead of using a single algorithm for all inputs, the program calculates the initial disorder of the stack (the ratio of misplaced pairs to total pairs) and dynamically routes the input to one of three specialized sorting algorithms (Simple, Medium, or Complex) to guarantee optimal performance. It also includes an optional benchmark mode (--bench) to evaluate sorting efficiency and strategy metrics in real time.

# Instructions

## Compilation
The project includes a standard Makefile that compiles the push_swap executable alongside the required libft library using -Wall -Wextra -Werror flags.
### Compile the main executable
make
### Clean object files
make clean
### Clean all generated files including the executable
make fclean
### Recompile from scratch
make re

## Execution
Run the program by passing a list of integers as arguments. The operations required to sort the stack will be printed to standard output (stdout). 
Example: ./push_swap 4 67 3 87 23

## Advanced Flags
You can force specific algorithmic strategies or enable benchmark mode using optional flags:
### --adaptive:
Dynamically selects the best algorithm based on input size and disorder (default behavior).
### --simple:
Forces the $O(n^2)$ Minimum Extraction strategy
### --medium:
Forces the $O(n\sqrt{n})$ Chunk Sort strategy.
### --complex:
Forces the $O(n \log n)$ Radix Sort strategy.
### --bench:
Outputs diagnostic metrics (disorder percentage, strategy used, total operations, and operation breakdown) to standard error (stderr).

# Resources
## Documentation & References:
42 School Subject PDF — Push_swap Version 1.1.
## AI Usage Statement:
AI tools were utilized during the development process to assist with algorithmic optimization logic (specifically structuring the relative ranking normalization for Radix sort), debugging edge cases and structuring the README.md layout in strict accordance with the 42 curriculum guidelines.