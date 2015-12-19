//include matching header
#include "Lemonade.h"
#include "Defines.h"

//use namespace std
using namespace std;


//stock externals
	extern float fStockLemon;
	extern float fStockSugar;
	extern float fStockIce;
	extern float fStockLemonade;

//finance externals
	extern float fMoneyOnHand;
	extern int iLemonadeSold;
	extern float fLemonadeMoney;
	extern float fMoneySpent;

//Main Menu


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

		float fProfit = fLemonadeMoney - fMoneySpent;

		cout <<"Cash on Hand: $"<< fMoneyOnHand <<endl;
		cout <<"Cups of Lemonade sold: "<< iLemonadeSold <<endl;
		cout <<"Total profit: $"<< fProfit <<endl;

	}

//Buy Stock Menu
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
			else
			{
			fStockLemon = fStockLemon+(iStockNumber);	
			fMoneyOnHand = fMoneyOnHand-(iStockNumber*COST_LEMON);
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
			else
			{
			fStockSugar = fStockSugar+(iStockNumber*8);	
			fMoneyOnHand = fMoneyOnHand-(iStockNumber*COST_SUGAR);
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
			else
			{
			fStockIce = fStockIce+(iStockNumber*20);	
			fMoneyOnHand = fMoneyOnHand-(iStockNumber*COST_ICE);
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

//Buy Stock Menu
void displayBuyStock()
	{
		extern float fMoneyOnHand;
		
		cout<< "------"<<endl;
		cout<< "Recipe: ONE JUG LEMONADE"<<endl;
		cout<< "------"<<endl;
		cout<< RECIPE_LEMON << " Lemons" <<endl;
		cout<< RECIPE_SUGAR << " Cups of Sugar" <<endl;
		cout<< RECIPE_ICE << " Cups of Ice" <<endl;
		cout<< endl;
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

