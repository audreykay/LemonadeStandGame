//include matching header
#include "Lemonade.h"
#include "Customer.h"
#include "Defines.h"
#include "MainGameLoop.h"

//use namespace std
using namespace std;

//making lemonade loop
bool bMakeLemonade = true;

//default stock display
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

//See Finances Menu
void displayFinances()
	{
		float fProfit = (fLemonadeProfit - fMoneySpent);

		cout <<"Cash on Hand: $"<< fMoneyOnHand <<endl;
		cout <<"Cups of Lemonade sold: "<< iLemonadeSold <<endl;
		cout <<"Total profit: $"<< fProfit <<endl;

	}

//display buy stock
void shopMenu()
	{
		//while(GAMESTATE::VIEW_STOCK)
		//{
		int iStockChoice;
		int iStockNumber;

		cout<< "------"<<endl;
		cout<< "Buy Stock"<<endl;
		cout<< "------"<<endl;
		cout<< "1.	Lemon $"<<COST_LEMON<<endl;
		cout<< "2.	Bag of Sugar (8 cups) $"<<COST_SUGAR<<endl;
		cout<< "3.	Bag of Ice (20 cups) $"<<COST_ICE<<endl;
		cout<< "4.	Return to Game Menu"<<endl;

		//prompt player for stock option
		cout<< "Please choose stock to buy: ";
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
				cout<<"*~*Insufficient Funds*~*"<<endl;
				shopMenu();
			}
			else //enough money to buy lemon(s)
			{
			fStockLemon = fStockLemon+(iStockNumber);	
			fMoneyOnHand = fMoneyOnHand-(iStockNumber*COST_LEMON);
			fMoneySpent = fMoneySpent+(iStockNumber*COST_LEMON);
			cout<< "You purchased "<<iStockNumber<<" Lemon(s)"<<endl;
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
				cout<<"*~*Insufficient Funds*~*"<<endl;
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
				cout<<"*~*Insufficient Funds*~*"<<endl;
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
		//}

	}

void displayRecipe()
{
	cout<< "------"<<endl;
	cout<< "Recipe: ONE JUG LEMONADE"<<endl;
	cout<< "------"<<endl;
	cout<< RECIPE_LEMON << " Lemons" <<endl;
	cout<< RECIPE_SUGAR << " Cups of Sugar" <<endl;
	cout<< RECIPE_ICE << " Cups of Ice" <<endl;
	cout<< endl;
}

//Buy Stock Menu
void displayBuyStock() // stock prices
{
	displayRecipe();
	cout<< "------"<<endl;
	cout<< "Stock Prices"<<endl;
	cout<< "------"<<endl;
	cout<< "Lemons: $"<<COST_LEMON<< " each"<<endl;
	cout<< "Sugar: $"<<COST_SUGAR<< " per bag (8 cups)"<<endl;
	cout<< "Ice: $"<<COST_ICE<< " per bag (20 cups)"<<endl;
	cout<<endl;
	cout<< "Cash on Hand: $"<< fMoneyOnHand <<endl;
	cout<<endl;
	displayStock();
	cout<<endl;
	shopMenu();
}

//Making Lemonade menu
void makeLemonade()
{
	int iLemonadeJug;
	int iLemonadeChoice;

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

	//}
}