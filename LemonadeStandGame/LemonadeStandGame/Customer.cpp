//include matching header
#include "Customer.h"
#include "Lemonade.h"
#include "Defines.h"
#include "MainGameLoop.h"

//use namespace std
using namespace std;

//# of cups missed out on selling
int iMissedCups;

void updateCustomerTimer()
{
	//random cup number gen
	int iCups = rand()%( MAX_CUPS - MIN_CUPS ) + MIN_CUPS;

	if( fStockLemonade >= iCups ) //If player has sufficient stock
	{
		system("cls");
		fStockLemonade = fStockLemonade - iCups;
		fMoneyOnHand = (fMoneyOnHand + (fLemonadePrice*iCups));
		fLemonadeProfit = (fLemonadeProfit + (fLemonadePrice*iCups));
		iLemonadeSold = iLemonadeSold + iCups;
		cout<<"*!* You sold "<<iCups<<" cups of Lemonade and earned $"<<(fLemonadePrice*iCups)<<" *!*"<<endl;
		system("pause");
		//updateCustomerTimer();
	}
	else if( fStockLemonade == 0 ) //If player has no stock
	{
		system("cls");

		cout<<"*!* You have no Lemonade in stock *!*"<<endl;
		cout<<"*!* Buy ingredients and make Lemonade to get customers *!*"<<endl;

		system("pause");
	}
	else //Player has insufficient stock
	{
		system("cls");
		iMissedCups = (iCups - fStockLemonade);
		cout<<"*!* The customer wanted "<<iCups<<" cups of Lemonade, so they bought all your Lemonade left *!*"<<endl;
		cout<<"*!* You sold "<<fStockLemonade<<" cups of Lemonade and earned $"<<(fLemonadePrice*fStockLemonade)<<" *!*"<<endl;
		cout<<"*!* You could have sold "<<iMissedCups<<" more cups of Lemonade, if you had stock *!*"<<endl;
		cout<<"*!* You now have no Lemonade in stock and need to make more *!*"<<endl;
		//check stock, add funds, decrease stock, etc
		fMoneyOnHand = (fMoneyOnHand + (fLemonadePrice*fStockLemonade));
		fLemonadeProfit = (fLemonadeProfit + (fLemonadePrice*fStockLemonade));
		iLemonadeSold = iLemonadeSold + fStockLemonade;
		fStockLemonade = fStockLemonade - fStockLemonade;
		system("pause");

	}

}