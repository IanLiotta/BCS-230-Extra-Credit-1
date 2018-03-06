// BCS 230 Extra Credit 1
// Ian Liotta

#ifndef DRINKMACHINE_H
#define DRINKMACHINE_H
#include <iostream>
using namespace std;

class DrinkMachine{
private:
	struct Drink
	{
		string name;
		double price;
		int stock;
	};
	double moneyCollected;
	double moneyInserted;
	Drink inventory[5];

	double inputMoney(int choice);
	void dailyReport();
public:
	DrinkMachine();
	void displayChoices();
	void buyDrink(int choice);
};

#endif

