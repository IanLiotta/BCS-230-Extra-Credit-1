#include "stdafx.h"
#include "DrinkMachine.h"
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

DrinkMachine::DrinkMachine() {
	inventory[0].name = "Cola";
	inventory[0].price = 1.00;
	inventory[0].stock = 20;
	inventory[1].name = "Root beer";
	inventory[1].price = 1.00;
	inventory[1].stock = 20;
	inventory[2].name = "Orange soda";
	inventory[2].price = 1.00;
	inventory[2].stock = 20;
	inventory[3].name = "Grape soda";
	inventory[3].price = 1.00;
	inventory[3].stock = 20;
	inventory[4].name = "Bottled water";
	inventory[4].price = 1.50;
	inventory[4].stock = 20;
}

DrinkMachine::~DrinkMachine()
{
	dailyReport();
}

void DrinkMachine::displayChoices() {
	int i = 1;
	cout << setprecision(2) << fixed;
	cout << "  " << setw(15) << "Name"<< setw(10) << "Price" << setw(10) << "In Stock" << endl;
	cout << string(40, '*') << endl;
	for (Drink drnk : inventory) {
		cout << i << ":" << setw(15) << drnk.name << setw(10) << drnk.price << setw(10) << drnk.stock << "\n";
		i++;
	}
}

void DrinkMachine::buyDrink(int choice) {
	int input;
	inputMoney(choice);
	if (moneyInserted >= inventory[choice - 1].price) {
		cout << "$" << moneyInserted << " inserted. Continue with purchase?\n1. Yes\n2. No\n";
		cin >> input;
		if (input == 1) {
			if (inventory[choice - 1].stock > 0) {
				cout << "Here is your " << inventory[choice - 1].name << endl;
				inventory[choice - 1].stock--;
				moneyCollected += inventory[choice - 1].price;
				moneyInserted -= inventory[choice - 1].price;
				cout << "Your change is $" << moneyInserted << endl;
				moneyInserted = 0;
			}
			else {
				cout << inventory[choice - 1].name << " is out of stock. Money returned.\n";
				moneyInserted = 0;
			}
		}
		else {
			cout << "Purchase cancelled. Money returned.\n";
			moneyInserted = 0;
			// in case the user entered a char or string, clear the input buffer
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	}
	else {
		cout << "Not enough money inserted. Money returned.\n";
		moneyInserted = 0;
	}
}

void DrinkMachine::inputMoney(int choice) {
	double input;
	cout << fixed << setprecision(2);
	cout << inventory[choice - 1].name << " costs $" << inventory[choice - 1].price << ". Insert money: \n";
	cin >> input;
	moneyInserted += input;
}

void DrinkMachine::dailyReport() {
	system("CLS");
	cout << "Daily Report: \n";
	displayChoices();
	cout << "Total money collected: $" << moneyCollected << endl;
}

