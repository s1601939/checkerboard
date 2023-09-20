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
 * \todo repeat while user doesn't say No
 * \todo add a MAXROWS
 *********************************************************************/
#include <iostream>

using namespace std;

int main() {
	const int MAXCOLS = 40;
	int userRows = 0;
	int userCols = 0;

	cout << "How many rows? ";
	cin >> userRows;

	do {
		cout << "How many columns? " ;
		cin >> userCols;
		if (userCols > MAXCOLS) {
			cout << "I can't do that, Dave. It can't be more than " << MAXCOLS << "." << endl;
		}
	} while (userCols > MAXCOLS);

	for (int row = 1; row <= userRows; ++row ) {
		for (int column = 1; column <= userCols; ++column) {

			/* for each odd row*/
			if (row % 2 == 1) {
				if (column % 2 == 1) { //is odd
					cout << '+';
				}
				else { // is even
					cout << 'o';
				}
			}
			/* or for each even row */
			else {
				if (column % 2 == 1) { //is odd
					cout << 'o';
				}
				else { // is even
					cout << '+';
				}
			}

		} // end of the column loop
		cout << endl;
	} // end of the row loop

	return 0;
}
