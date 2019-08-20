list-style-type:lower-roman;

# Sudoku solver:
This is a sudoku solver

## Compiling and Running
i. To compile, enter "Make" on the root folder at a terminal

ii. To run type "./run" on the root folder at a terminal

iii. The program will load puzzles and their respective answers from the ./input/sudoku.csv file
	* Each puzzle must be given in the form of 81 digits from 0 to 9), '0' represent blank squares.
	* Each expected answer must be given in the form of 81 digits from 1 to 9, separated by a comma.
	* Put the puzzle before the answer.
	* Leave only puzzles and answers in the file, and no blank lines.

iv. The interface has four commands, each one assigned to a number displayed at the menu

	1 - Solve a random puzzle

	2 - Solve all puzzles at the list and make a csv file reporting solving time (./output/time_record.csv)

	3 - Check if all the answers match the expected one (which was given at the ./input folder)

	4 - Exit


Note: The full test file has 1.000.000 puzzles, "./input/sudoku_full.csv" this version uses a shorter version uses 150.000 puzzles, the "./input/sudoku_full.csv".
