/*****************************************************************//**
 * \file   checkers.cpp
 * \brief  This is an example of nested loops and if statements
 * 
 * \author s0075425
 * \date   September 2023
 * 
 * \algorithm
 *	repeat
 *		get rows and cols from user
 *		print the grid
 *	while the user doesn't say No
 * 
 * \todo maybe prevent or warn users about using negative numbers
 * \todo figure out what to do when user type letter instead of number
 *********************************************************************/
#include <iostream>

using namespace std;

int main() {
	const int MAXROWS = 25;		// upper bound for row input
	const int MAXCOLS = 40;		// upper bound for column input
	int userRows = 0;			// user requested number of rows
	int userCols = 0;			// user requested number of columns
	char userChoice = ' ';		// user's response to a question

	/* print instructions for the user */
	cout << "This program prints a 'checkerboard' pattern of +'s and o's" << endl;
	cout << "You get to decide (within limits) how many rows and columns." << endl;

	/* repeat the checkerboard generator until the user wants to stop */
	do {

		/* get the number of rows from the user */
		do {
			cout << "How many rows? ";
			cin >> userRows;
			if (userRows > MAXROWS) {
				cout << "I can't do that, Dave. It cant be more than " << MAXROWS << "." << endl;
			}
		} while (userRows > MAXROWS);

		/* get the nubmer of columns from the user */
		do {
			cout << "How many columns? ";
			cin >> userCols;
			if (userCols > MAXCOLS) {
				cout << "I can't do that, Dave. It can't be more than " << MAXCOLS << "." << endl;
			}
		} while (userCols > MAXCOLS);

		/* build the checkerboard */
		for (int row = 1; row <= userRows; ++row) {

			for (int column = 1; column <= userCols; ++column) {

				/* for each odd row*/
				if (row % 2 == 1) {
					if (column % 2 == 1) {
						// odd row + odd column
						cout << '+';
					}
					else {
						// odd row + even column
						cout << 'o';
					}
				}
				/* or for each even row */
				else {
					if (column % 2 == 1) { 
						// even row + odd column
						cout << 'o';
					}
					else {
						// even row + even column
						cout << '+';
					}
				}

			} // end of the column loop -- time to go to the next row
			cout << endl;

		} // end of the row loop - if there are no more rows we are done this grid
	
		/* get a valid choice from the user */
		do {
			cout << "Print another grid (Y/N)? ";
			cin >> userChoice;

			/* Adjust the choice to 'N' or 'Y' for valid choices */
			switch (userChoice) {
			case 'N':
			case 'n':
				userChoice = 'N'; break;
			case 'Y':
			case 'y':
				userChoice = 'Y'; break;
			default:
				userChoice = ' ';
				cout << "That is not a valid choice. Please try again." << endl;
			}

		} while (userChoice != 'N' && userChoice != 'Y');

	} while (userChoice != 'N');

	return 0;
}
