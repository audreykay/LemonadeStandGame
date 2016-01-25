//include matching header
#include "Defines.h"
#include "MainGameLoop.h"
#include "Customer.h"
#include "DayCycle.h"
#include "Lemonade.h"

//include iostream and namespace (needed for each header)
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;


//random pricing float
float randomPrice(float max, float min)
{
	return max + (rand() / (RAND_MAX / (min-max) ) );
}


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
}

void shopMenu()
{
	int iStockChoice;
	int iStockNumber;

	//Random Stock Prices
	float COST_LEMON = randomPrice(MAX_COST_LEMON,MIN_COST_LEMON);
	float COST_SUGAR = randomPrice(MAX_COST_SUGAR,MIN_COST_SUGAR);
	float COST_ICE = randomPrice(MAX_COST_ICE,MIN_COST_ICE);

	displayRecipe();
	cout<<endl;
	displayStock();
	cout<<endl;
	cout<< "------"<<endl;
	cout<< "Buy Stock"<<endl;
	cout<< "------"<<endl;
	cout<<fixed;
	cout<<setprecision(2);
	cout<< "1.	Lemon $"<<COST_LEMON<<endl;
	cout<< "2.	Bag of Sugar (8 cups) $"<<COST_SUGAR<<endl;
	cout<< "3.	Bag of Ice (20 cups) $"<<COST_ICE<<endl;
	cout<< "4.	Return to Game Menu"<<endl;
	cout<<endl;
	cout<< "Cash on Hand: $"<< fMoneyOnHand <<endl;
	

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
			shopMenu();
		}
		else //enough money to buy lemon(s)
		{
		fStockLemon = fStockLemon+(iStockNumber);	
		fMoneyOnHand = fMoneyOnHand-(iStockNumber*COST_LEMON);
		fMoneySpent = fMoneySpent+(iStockNumber*COST_LEMON);
		cout<< "You purchased "<<iStockNumber<<" Lemon(s) for $"<<(COST_LEMON*iStockNumber)<<endl;
		cout<< "Lemon(s) in stock: "<<fStockLemon<<endl;
		cout <<"Cash on Hand: $"<< fMoneyOnHand <<endl;
		shopMenu();
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
			shopMenu();
		}
		else //enough money to buy sugar
		{
		fStockSugar = fStockSugar+(iStockNumber*8);	
		fMoneyOnHand = fMoneyOnHand-(iStockNumber*COST_SUGAR);
		fMoneySpent = fMoneySpent+(iStockNumber*COST_SUGAR);
		cout<< "You purchased "<<iStockNumber<<" Bag(s) of Sugar"<<endl;
		cout<< "Cup(s) of Sugar in stock: "<<fStockSugar<<endl;
		cout <<"Cash on Hand: $"<< fMoneyOnHand <<endl;
		shopMenu();
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
			shopMenu();
		}
		else //enough money to buy ice
		{
		fStockIce = fStockIce+(iStockNumber*20);	
		fMoneyOnHand = fMoneyOnHand-(iStockNumber*COST_ICE);
		fMoneySpent = fMoneySpent+(iStockNumber*COST_ICE);
		cout<< "You purchased "<<iStockNumber<<" Bag(s) of Ice"<<endl;
		cout<< "Cup(s) of Ice in stock: "<<fStockIce<<endl;
		cout <<"Cash on Hand: $"<< fMoneyOnHand <<endl;
		shopMenu();
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
		shopMenu();
		//cin >>iStockChoice;
		break;
		}
}


/*void displayBuyStock()
{
	//Random Stock Prices
	float COST_LEMON = randomPrice(MAX_COST_LEMON,MIN_COST_LEMON);
	float COST_SUGAR = randomPrice(MAX_COST_SUGAR,MIN_COST_SUGAR);
	float COST_ICE = randomPrice(MAX_COST_ICE,MIN_COST_ICE);
	
	displayRecipe();
	cout<<endl;
	displayStock();
	cout<<endl;
	cout<< "------"<<endl;
	cout<< "Stock Prices"<<endl;
	cout<< "------"<<endl;
	cout<<fixed;
	cout<<setprecision(2);
	cout<< "Lemons: $"<<COST_LEMON<< " each"<<endl;
	cout<< "Sugar: $"<<COST_SUGAR<< " per bag (8 cups)"<<endl;
	cout<< "Ice: $"<<COST_ICE<< " per bag (20 cups)"<<endl;
	cout<<endl;
	cout<< "Cash on Hand: $"<< fMoneyOnHand <<endl;
	cout<<endl;
	shopMenu();
}*/

void makeLemonade()
{
	int iLemonadeJug;
	int iLemonadeChoice;

	//making lemonade loop
	bool bMakeLemonade = true;

	float RECIPE_LEMON = sLemonadeRecipe.fLemonRecipe;
	float RECIPE_SUGAR = sLemonadeRecipe.fSugarRecipe;
	float RECIPE_ICE = sLemonadeRecipe.fIceRecipe;

	//while(bMakeLemonade = true)
	//{
	displayStock();
	cout<<endl;
	cout<<"1.	Make Lemonade"<<endl;
	cout<<"2.	Exit to Menu"<<endl;
	cout<<"Please enter a number: ";
	cin>>iLemonadeChoice;

	switch (iLemonadeChoice)
	{	
	case 1:
		{
		cout<<"How many jugs of lemonade would you like to make? ";
		cin>>iLemonadeJug;
		cout<<endl;
		//check there is enough stock to make lemonade
		if ((fStockLemon >= iLemonadeJug*RECIPE_LEMON)
			&& (fStockSugar >= iLemonadeJug*RECIPE_SUGAR)
			&& (fStockIce >= iLemonadeJug*RECIPE_ICE))
		{
			system("cls");
			cout<<"You made "<<iLemonadeJug<<" jug(s) of Lemonade!"<<endl;
			fStockLemon = fStockLemon-(iLemonadeJug*RECIPE_LEMON);
			fStockSugar = fStockSugar-(iLemonadeJug*RECIPE_SUGAR);
			fStockIce = fStockIce-(iLemonadeJug*RECIPE_ICE);
			fStockLemonade = fStockLemonade+(iLemonadeJug*6);
			makeLemonade();
		}
		else //not enough stock
		{
			system("cls");
			cout<<"*~*Insufficient Ingredients!*~*"<<endl;
			makeLemonade();
		}
		}
		break;
	case 2:
		bMakeLemonade = false;
		switch(GAMESTATE::MAIN_MENU)
		{
			//case MAIN_MENU;
		}
		break;
	default:
		{
			cout<<"*~*Please enter a valid number*~*"<<endl;
			makeLemonade();
		}
		break;
	}
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
				cin>> sLemonadeRecipe.fLemonadePrice;
				cout<<endl;
			}
			system("cls");
			displayRecipe();
		}
		break;
	case 2:
		switch(GAMESTATE::MAIN_MENU)
		{
			//case MAIN_MENU;
		}
		break;
	default:
		{
			cout<<"Please choose a valid number"<<endl;
		}
		break;
	}

}