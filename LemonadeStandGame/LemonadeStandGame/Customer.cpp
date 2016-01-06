//include matching header
#include "Customer.h"
#include "Lemonade.h"
#include "Defines.h"
#include "MainGameLoop.h"

//use namespace std
using namespace std;

//external constants/variables
extern const int MAX_CUPS;
extern const int MIN_CUPS;

extern float fLemonadePrice;

extern float fStockLemonade;
extern float fMoneyOnHand;
extern int iLemonadeSold;
extern float fLemonadeProfit;

//Missed cups sold
int iMissedCups;

void updateCustomerTimer()
{
	//random cup number gen
	int iCups = rand()%( MAX_CUPS - MIN_CUPS ) + MIN_CUPS;

	if( fStockLemonade >= iCups )
	{
		system("cls");
		fStockLemonade = fStockLemonade - iCups;
		fMoneyOnHand = (fMoneyOnHand + (fLemonadePrice*iCups));
		fLemonadeProfit = (fLemonadeProfit + (fLemonadePrice*iCups));
		iLemonadeSold = iLemonadeSold + iCups;
		cout<<"*!* You sold "<<iCups<<" cups of Lemonade and earned $"<<(fLemonadePrice*iCups)<<" *!*"<<endl;
		system("pause");
	}
	else if( fStockLemonade == 0 )
	{
		system("cls");

		cout<<"*!* You have no Lemonade in stock *!*"<<endl;
		cout<<"*!* Buy ingredients and make Lemonade to get customers *!*"<<endl;

		system("pause");
	}
	else
	{
		system("cls");
		iMissedCups = (iCups - fStockLemonade);
		cout<<"*!* The customer wanted "<<iCups<<" cups of Lemonade, so they bought all your Lemonade left *!*"<<endl;
		cout<<"*!* You sold "<<fStockLemonade<<" cups of Lemonade and earned $"<<(fLemonadePrice*fStockLemonade)<<" *!*"<<endl;
		cout<<"*!* You could have sold "<<iMissedCups<<" more cups of Lemonade, if you had stock *!*"<<endl;
		cout<<"*!* You now have no Lemonade in stock and need to make more *!*"<<endl;
		
		fMoneyOnHand = (fMoneyOnHand + (fLemonadePrice*fStockLemonade));
		fLemonadeProfit = (fLemonadeProfit + (fLemonadePrice*fStockLemonade));
		iLemonadeSold = iLemonadeSold + fStockLemonade;
		fStockLemonade = fStockLemonade - fStockLemonade;
		system("pause");

	}

}