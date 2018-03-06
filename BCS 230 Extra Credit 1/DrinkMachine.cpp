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
	cout << "Here is your " << inventory[choice - 1].name << endl;
	inventory[choice - 1].stock--;
	moneyCollected += inventory[choice - 1].price;
}

void DrinkMachine::dailyReport() {
	cout << "Daily Report: \n";
	displayChoices();
	cout << "Total money collected: $" << moneyCollected << endl;
}

