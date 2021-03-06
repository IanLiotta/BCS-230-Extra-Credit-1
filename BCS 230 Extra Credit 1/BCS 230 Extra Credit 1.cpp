// BCS 230 Extra Credit 1
// Ian Liotta

#include "stdafx.h"
#include "DrinkMachine.h"
#include <iostream>
using namespace std;


int main()
{
	DrinkMachine vendor;
	int input;

	do {
		vendor.displayChoices();
		cout << "Please choose 1 - 5 (0 to quit):\n";
		cin >> input;
		if (input >= 1 && input <= 5) {
			system("CLS");
			vendor.buyDrink(input);
		}
		else if (input != 0) {
			system("CLS");
			cout << "Invalid input.\n";
			// in case the user entered a char or string, clear the input buffer
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
			
	} while (input != 0);

    return 0;
}

