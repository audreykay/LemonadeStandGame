//include matching header
#include "Defines.h"
#include "OpeningMenu.h"
#include "MainGameLoop.h"
#include "Customer.h"
#include "DayCycle.h"
#include "Lemonade.h"

//include iostream and namespace (needed for each header)
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

//recipe structure
struct RecipeStruct
{
	float fLemonRecipe;
	float fSugarRecipe;
	float fIceRecipe;
	float fLemonadePrice;
};

//variables
RecipeStruct sLemonadeRecipe;
extern int iLemonadeTaste;
int sourTaste = 0;
int standardTaste = 1;
int sweetTaste = 2;

void displayStock()
{
	cout <<"------"<<endl;
	cout <<"Stock"<<endl;
	cout <<"------"<<endl;
	cout <<"Lemon(s): "<< fStockLemon <<endl;
	cout <<"Cup(s) of Sugar: "<< fStockSugar <<endl;
	cout <<"Cup(s) of Ice: "<< fStockIce <<endl;
	cout <<"Cup(s) of Lemonade: "<< fStockLemonade <<endl;
}

void displayFinances()
{
	float fProfit = (fLemonadeProfit - fMoneySpent);

	cout <<"Cash on Hand: $"<< fMoneyOnHand <<endl;
	cout <<"Cups of Lemonade sold: "<< iLemonadeSold <<endl;
	cout <<"Total profit: $"<< fProfit <<endl;
}

float randomPrice(float max, float min)
{
	return max + (rand() / (RAND_MAX / (min-max) ) );
}

void displayBuyStock()
{
	int iStockChoice;
	int iStockNumber;

	//Random Stock Prices
	float COST_LEMON = randomPrice(MAX_COST_LEMON,MIN_COST_LEMON);
	float COST_SUGAR = randomPrice(MAX_COST_SUGAR,MIN_COST_SUGAR);
	float COST_ICE = randomPrice(MAX_COST_ICE,MIN_COST_ICE);

	
	cout<< "------"<<endl;
	cout<< "Buy Stock"<<endl;
	cout<< "------"<<endl;
	cout<<fixed;
	cout<<setprecision(2);
	cout<< "1.	Lemon $"<<COST_LEMON<<endl;
	cout<< "2.	Bag of Sugar (8 cups) $"<<COST_SUGAR<<endl;
	cout<< "3.	Bag of Ice (20 cups) $"<<COST_ICE<<endl;
	cout<< "4.	Return to Game Menu"<<endl;

	//prompt player for stock option
	cout<< "Please enter a number: ";
	cin>> iStockChoice;
		
	//Buying Stock switch statement
		
	switch (iStockChoice)
	{
	case 1://Buy x Lemon(s)
		{
		cout<< "How many Lemon(s) would you like to buy? ";
		cin>> iStockNumber;
		cout<<endl;
		system("cls");
		if(fMoneyOnHand < iStockNumber*COST_LEMON)
		{
			cout<<"Insufficient Funds!"<<endl;
		//	shopMenu();
		}
		else //enough money to buy lemon(s)
		{
		fStockLemon = fStockLemon+(iStockNumber);	
		fMoneyOnHand = fMoneyOnHand-(iStockNumber*COST_LEMON);
		fMoneySpent = fMoneySpent+(iStockNumber*COST_LEMON);
		cout<< "You purchased "<<iStockNumber<<" Lemon(s)"<<endl;
		cout<< "Lemon(s) in stock: "<<fStockLemon<<endl;
		cout <<"Cash on Hand: $"<< fMoneyOnHand <<endl;
		//shopMenu();
		}
		}
		break;
	case 2://Buy x Bags of Sugar
		{
		cout<< "How many Bag(s) of Sugar would you like to buy? ";
		cin>> iStockNumber;
		cout<<endl;
		system("cls");
		if(fMoneyOnHand < iStockNumber*COST_SUGAR)
		{
			cout<<"Insufficient Funds!"<<endl;
			//shopMenu();
		}
		else //enough money to buy sugar
		{
		fStockSugar = fStockSugar+(iStockNumber*8);	
		fMoneyOnHand = fMoneyOnHand-(iStockNumber*COST_SUGAR);
		fMoneySpent = fMoneySpent+(iStockNumber*COST_SUGAR);
		cout<< "You purchased "<<iStockNumber<<" Bag(s) of Sugar"<<endl;
		cout<< "Cup(s) of Sugar in stock: "<<fStockSugar<<endl;
		cout <<"Cash on Hand: $"<< fMoneyOnHand <<endl;
		//shopMenu();
		}
		}
		break;
	case 3://Buy x Bags of Ice
		{
		cout<< "How many Bag(s) of Ice would you like to buy? ";
		cin>> iStockNumber;
		cout<<endl;
		system("cls");
		if(fMoneyOnHand < iStockNumber*COST_ICE)
		{
			cout<<"Insufficient Funds!"<<endl;
			//shopMenu();
		}
		else //enough money to buy ice
		{
		fStockIce = fStockIce+(iStockNumber*20);	
		fMoneyOnHand = fMoneyOnHand-(iStockNumber*COST_ICE);
		fMoneySpent = fMoneySpent+(iStockNumber*COST_ICE);
		cout<< "You purchased "<<iStockNumber<<" Bag(s) of Ice"<<endl;
		cout<< "Cup(s) of Ice in stock: "<<fStockIce<<endl;
		cout <<"Cash on Hand: $"<< fMoneyOnHand <<endl;
		//shopMenu();
		}
		}
		break;
	case 4://exit to main menu
		switch(GAMESTATE::MAIN_MENU)
		{
			//case MAIN_MENU;
		}
		break;
	default: //invalid number
		system("cls");
		cout<<"*~*Please enter a valid number*~*"<<endl;
		//shopMenu();
		//cin >>iStockChoice;
		break;
		}
}

void displayStockPrices()
{
}

void makeLemonade()
{
}

//display Recipe&Price function
void displayRecipe()
{
	cout<< "------"<<endl;
	cout<< "Recipe: ONE JUG LEMONADE"<<endl;
	cout<< "------"<<endl;
	cout<< sLemonadeRecipe.fLemonRecipe << " Lemons" <<endl;
	cout<< sLemonadeRecipe.fSugarRecipe << " Cups of Sugar" <<endl;
	cout<< sLemonadeRecipe.fIceRecipe << " Cups of Ice" <<endl;
	cout<< "$ "<<sLemonadeRecipe.fLemonadePrice<<" Per Cup"<<endl;
	cout<< endl;
}

//change recipe/price screen
void changeRecipe()
{
		if (sLemonadeRecipe.fLemonRecipe > sLemonadeRecipe.fSugarRecipe)
	{
		iLemonadeTaste = sourTaste;
	}
	else if (sLemonadeRecipe.fLemonRecipe < sLemonadeRecipe.fSugarRecipe)
	{
		iLemonadeTaste = sweetTaste;
	}
	else 
	{
		iLemonadeTaste = standardTaste;
	}
	
	system("cls");
	int iMenuChoice;
	displayRecipe();
	cout<<"Would you like to alter the recipe and price?"<<endl;
	cout<<"1.	Yes"<<endl;
	cout<<"2.	No (Return to Menu)"<<endl;
	cout<<"Please enter a number: ";
	cin>>iMenuChoice;
	cout<<endl;

	switch(iMenuChoice)
	{
	case 1:
		{
			cout<<"Change lemons per jug to: ";
			cin>>sLemonadeRecipe.fLemonRecipe;
			cout<<endl;
			//no cheating Jason!
			if (sLemonadeRecipe.fLemonRecipe <= 0)
			{
				cout<<"Please use a positive number!"<<endl;
				cout<<endl;
				cout<<"Change lemons per jug to: ";
				cin>> sLemonadeRecipe.fLemonRecipe;
				cout<<endl;
			}
			cout<<"Change bags of sugar per jug to: ";
			cin>>sLemonadeRecipe.fSugarRecipe;
			cout<<endl;
			if (sLemonadeRecipe.fSugarRecipe <= 0)
			{
				cout<<"Please use a positive number!"<<endl;
				cout<<endl;
				cout<<"Change bags of sugar per jug to: ";
				cin>> sLemonadeRecipe.fLemonRecipe;
				cout<<endl;
			}
			cout<<"Change bags of ice per jug to: ";
			cin>>sLemonadeRecipe.fIceRecipe;
			cout<<endl;
			if (sLemonadeRecipe.fIceRecipe <= 0)
			{
				cout<<"Please use a positive number!"<<endl;
				cout<<endl;
				cout<<"Change bags of ice per jug to: ";
				cin>> sLemonadeRecipe.fLemonRecipe;
				cout<<endl;
			}
			cout<<"Change price of Lemonade per cup to: $";
			cin>>sLemonadeRecipe.fLemonadePrice;
			cout<<endl;
			if (sLemonadeRecipe.fLemonadePrice <= 0)
			{
				cout<<"Please use a positive number!"<<endl;
				cout<<endl;
				cout<<"Change price of Lemonade per cup to: $";
				cin>> sLemonadeRecipe.fLemonRecipe;
				cout<<endl;
			}
			system("cls");
			displayRecipe();
		}
		break;
	case 2:
		{
			//TODO return to menu 
		}
		break;
	default:
		{
			cout<<"Please choose a valid number"<<endl;
		}
		break;
	}

}