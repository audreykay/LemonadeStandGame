//include matching header
#include "Defines.h"
#include "MainGameLoop.h"
#include "Customer.h"
#include "DayCycle.h"
#include "Lemonade.h"

//include iostream and namespace (needed for each header)
#include <iostream>
#include <fstream>
using namespace std;

//missed cups
int iMissedCups;

void saleScreen()
{
	/*system("cls");
	fStockLemonade = fStockLemonade - iCups;
	fMoneyOnHand = (fMoneyOnHand + (fLemonadePrice*iCups));
	fLemonadeProfit = (fLemonadeProfit + (fLemonadePrice*iCups));
	iLemonadeSold = iLemonadeSold + iCups;
	cout<<"*!* You sold "<<iCups<<" cups of Lemonade and earned $"<<(fLemonadePrice*iCups)<<" *!*"<<endl;
	system("pause");
	updateCustomerTimer();*/
}

void customerFrugality()
{
	//assign a frugality
	int iFrugality = rand()%10;

	//check customers frugality
	if (iFrugality <= 5) //customer will buy anything
	{
		//saleScreen();

	}
	else if (iFrugality == 6 || 7) //customer will buy under $2
	{
		if (fLemonadePrice <= 2)
		{
			//saleScreen();
		}
		else
		{
			cout<<"The customer thinks your price is too high!"<<endl;
		}
	}
	else if (iFrugality == 8 || 9) //customer will buy under $1.5
	{
		if (fLemonadePrice <= 1.5)
		{
			//saleScreen();
		}
		else
		{
			cout<<"The customer thinks your price is too high!"<<endl;
		}
	}
}

void updateCustomerTimer()
{
	//random cup number gen
	int iCups = rand()%( MAX_CUPS - MIN_CUPS ) + MIN_CUPS;
	int iTaste = rand()%4;

	if( fStockLemonade >= iCups ) //If player has sufficient stock
	{
		switch(iTaste)
		{
		case 0: //customer pref sour
				//check lemonade is sour
				if (iLemonadeTaste == 0) //lemonade is sour!
				{
					customerFrugality();
				}
				else //lemonade is not to taste!
				{
					cout<<"The customer hated your recipe and bought nothing!"<<endl;
				}
		
		case 1: //customer pref sour or standard
				//check lemonade is sour or standard
				if (iLemonadeTaste == 0 || 1) //lemonade is sour or stand!
				{
					customerFrugality();
				}
				else //lemonade is not to taste!
				{
					cout<<"The customer hated your recipe and bought nothing!"<<endl;
				}

			case 2: //customer pref sour or standard
				//check lemonade is stand or sweet
				if (iLemonadeTaste == 1 || 2) //lemonade is standard or sweet!
				{
					customerFrugality();
				}
				else //lemonade is not to taste!
				{
					cout<<"The customer hated your recipe and bought nothing!"<<endl;
				}

			case 3: //customer pref sweet
				//check lemonade is sweet
				if (iLemonadeTaste == 3) //lemonade is sweet!
				{
					customerFrugality();
				}
				else //lemonade is not to taste!
				{
					cout<<"The customer hated your recipe and bought nothing!"<<endl;
				}
			default:
				{
					cout<<"Something went horribly wrong!"<<endl;
				}
		}
		
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
