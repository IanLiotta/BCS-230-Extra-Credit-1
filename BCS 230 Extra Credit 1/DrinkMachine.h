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
	double moneyCollected = 0.0;
	double moneyInserted = 0.0;
	Drink inventory[5];

	void inputMoney(int choice);
	void dailyReport();
public:
	DrinkMachine();
	~DrinkMachine();
	void displayChoices();
	void buyDrink(int choice);
};

#endif

