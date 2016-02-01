//include matching header
#include "Defines.h"
#include "MainGameLoop.h"
#include "Customer.h"
#include "DayCycle.h"
#include "Lemonade.h"

//include iostream and namespace (needed for each header)
#include <iostream>
#include <fstream>
#include <sstream>
#include <windows.h>
#include <string>
#include <conio.h>
using namespace std;

//missed cups
int iMissedCups;
int iCustomerCount;

extern struct RecipeStruct sLemonadeRecipe;
extern void startTime();

void gotoxy( int column, int line )
  {
  COORD coord;
  coord.X = column;
  coord.Y = line;
  SetConsoleCursorPosition(
    GetStdHandle( STD_OUTPUT_HANDLE ),
    coord
    );
  }

int wherex()
  {
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  COORD                      result;
  if (!GetConsoleScreenBufferInfo(
         GetStdHandle( STD_OUTPUT_HANDLE ),
         &csbi
         ))
    return -1;
  return result.X;
  }

int wherey()
  {
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  COORD                      result;
  if (!GetConsoleScreenBufferInfo(
         GetStdHandle( STD_OUTPUT_HANDLE ),
         &csbi
         ))
    return -1;
  return result.Y;
  }

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
	/*int iFrugality = rand()%10;

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
	}*/
}
//eventbool
bool eCustomerSatisfied = false;
bool eCustomerCheap = false;
bool eCustomerTasteSour = false;
bool eCustomerTasteSweet = false;
bool eCustomerNoStock = false;
bool eCustomerLast = false;



void updateCustomerTimer()
{	
	int i;
	//random cup number gen
	int iCups = rand()%( MAX_CUPS - MIN_CUPS ) + MIN_CUPS;

	if( fStockLemonade >= iCups ) //If player has sufficient stock
	{
		int iTaste = rand()%4;
		switch(iTaste)
		{
		case 0: //customer pref sour
				//check lemonade is sour
				if (iLemonadeTaste == 0) //lemonade is sour!
				{
					//assign a frugality
					int iFrugality = rand()%10;

					//check customers frugality
					if (iFrugality <= 5) //customer will buy anything
					{
						iCustomerCount+=1;
						fStockLemonade = fStockLemonade - iCups;
						fMoneyOnHand = (fMoneyOnHand + (sLemonadeRecipe.fLemonadePrice*iCups));
						fLemonadeProfit = (fLemonadeProfit + (sLemonadeRecipe.fLemonadePrice*iCups));
						iLemonadeSold = iLemonadeSold + iCups;
						//cout<<"*!* You sold "<<iCups<<" cups of Lemonade and earned $"<<(sLemonadeRecipe.fLemonadePrice*iCups)<<" *!*"<<endl;
						//CUSTOMER SATISFIED MSG
						eCustomerSatisfied=true;
					}
					else if (iFrugality == 6 || 7) //customer will buy under $2
					{
						if (sLemonadeRecipe.fLemonadePrice <= 2)
						{
							iCustomerCount+=1;
							fStockLemonade = fStockLemonade - iCups;
							fMoneyOnHand = (fMoneyOnHand + (sLemonadeRecipe.fLemonadePrice*iCups));
							fLemonadeProfit = (fLemonadeProfit + (sLemonadeRecipe.fLemonadePrice*iCups));
							iLemonadeSold = iLemonadeSold + iCups;
							//cout<<"*!* You sold "<<iCups<<" cups of Lemonade and earned $"<<(sLemonadeRecipe.fLemonadePrice*iCups)<<" *!*"<<endl;
							//CUSTOMER SATISFIED MSG
							eCustomerSatisfied=true;
						}
						else
						{
							//cout<<"The customer thinks your price is too high!"<<endl;
							//CUSTOMER TOO CHEAP
							eCustomerCheap=true;
						}
					}
					else if (iFrugality == 8 || 9) //customer will buy under $1.5
					{
						if (sLemonadeRecipe.fLemonadePrice <= 1.5)
						{
							iCustomerCount+=1;
							fStockLemonade = fStockLemonade - iCups;
							fMoneyOnHand = (fMoneyOnHand + (sLemonadeRecipe.fLemonadePrice*iCups));
							fLemonadeProfit = (fLemonadeProfit + (sLemonadeRecipe.fLemonadePrice*iCups));
							iLemonadeSold = iLemonadeSold + iCups;
							//cout<<"*!* You sold "<<iCups<<" cups of Lemonade and earned $"<<(sLemonadeRecipe.fLemonadePrice*iCups)<<" *!*"<<endl;
							//CUSTOMER SATISFIED MSG
							eCustomerSatisfied=true;
						}
						else
						{
							//cout<<"The customer thinks your price is too high!"<<endl;
							//CUSTOMER TOO CHEAP
							eCustomerCheap=true;
						}
					}
				}
				else //lemonade is not to taste!
				{
					//cout<<"The customer hated your recipe and bought nothing!"<<endl;
					//LEMONADE IS TOO SWEET FOR CUSTOMER
					eCustomerTasteSweet=true;
				}
				break;
		
		case 1: //customer pref sour or standard
				//check lemonade is sour or standard
				if (iLemonadeTaste == 0 || 1) //lemonade is sour or stand!
				{
					//assign a frugality
					int iFrugality = rand()%10;

					//check customers frugality
					if (iFrugality <= 5) //customer will buy anything
					{
						iCustomerCount+=1;
						fStockLemonade = fStockLemonade - iCups;
						fMoneyOnHand = (fMoneyOnHand + (sLemonadeRecipe.fLemonadePrice*iCups));
						fLemonadeProfit = (fLemonadeProfit + (sLemonadeRecipe.fLemonadePrice*iCups));
						iLemonadeSold = iLemonadeSold + iCups;
						//cout<<"*!* You sold "<<iCups<<" cups of Lemonade and earned $"<<(sLemonadeRecipe.fLemonadePrice*iCups)<<" *!*"<<endl;
						//CUSTOMER SATISFIED MSG
						eCustomerSatisfied=true;
					}
					else if (iFrugality == 6 || 7) //customer will buy under $2
					{
						if (sLemonadeRecipe.fLemonadePrice <= 2)
						{
							iCustomerCount+=1;
							fStockLemonade = fStockLemonade - iCups;
							fMoneyOnHand = (fMoneyOnHand + (sLemonadeRecipe.fLemonadePrice*iCups));
							fLemonadeProfit = (fLemonadeProfit + (sLemonadeRecipe.fLemonadePrice*iCups));
							iLemonadeSold = iLemonadeSold + iCups;
							//cout<<"*!* You sold "<<iCups<<" cups of Lemonade and earned $"<<(sLemonadeRecipe.fLemonadePrice*iCups)<<" *!*"<<endl;
							//CUSTOMER SATISFIED MSG
							eCustomerSatisfied=true;
						}
						else
						{
							//cout<<"The customer thinks your price is too high!"<<endl;
							//CUSTOMER TOO CHEAP
							eCustomerCheap=true;
						}
					}
					else if (iFrugality == 8 || 9) //customer will buy under $1.5
					{
						if (sLemonadeRecipe.fLemonadePrice <= 1.5)
						{
							iCustomerCount+=1;
							fStockLemonade = fStockLemonade - iCups;
							fMoneyOnHand = (fMoneyOnHand + (sLemonadeRecipe.fLemonadePrice*iCups));
							fLemonadeProfit = (fLemonadeProfit + (sLemonadeRecipe.fLemonadePrice*iCups));
							iLemonadeSold = iLemonadeSold + iCups;
							//cout<<"*!* You sold "<<iCups<<" cups of Lemonade and earned $"<<(sLemonadeRecipe.fLemonadePrice*iCups)<<" *!*"<<endl;
							//CUSTOMER SATISFIED MSG
							eCustomerSatisfied=true;
						}
						else
						{
							//cout<<"The customer thinks your price is too high!"<<endl;
							//CUSTOMER TOO CHEAP
							eCustomerCheap=true;
						}
					}
				}
				else //lemonade is not to taste!
				{
					//cout<<"The customer hated your recipe and bought nothing!"<<endl;
					//LEMONADE IS TOO SWEET FOR CUSTOMER
					eCustomerTasteSweet=true;
				}
				break;

			case 2: //customer pref sour or standard
				//check lemonade is stand or sweet
				if (iLemonadeTaste == 1 || 2) //lemonade is standard or sweet!
				{
					//assign a frugality
					int iFrugality = rand()%10;

					//check customers frugality
					if (iFrugality <= 5) //customer will buy anything
					{
						iCustomerCount+=1;
						fStockLemonade = fStockLemonade - iCups;
						fMoneyOnHand = (fMoneyOnHand + (sLemonadeRecipe.fLemonadePrice*iCups));
						fLemonadeProfit = (fLemonadeProfit + (sLemonadeRecipe.fLemonadePrice*iCups));
						iLemonadeSold = iLemonadeSold + iCups;
						//cout<<"*!* You sold "<<iCups<<" cups of Lemonade and earned $"<<(sLemonadeRecipe.fLemonadePrice*iCups)<<" *!*"<<endl;
						//CUSTOMER SATISFIED MSG
						eCustomerSatisfied=true;
					}
					else if (iFrugality == 6 || 7) //customer will buy under $2
					{
						if (sLemonadeRecipe.fLemonadePrice <= 2)
						{
							iCustomerCount+=1;
							fStockLemonade = fStockLemonade - iCups;
							fMoneyOnHand = (fMoneyOnHand + (sLemonadeRecipe.fLemonadePrice*iCups));
							fLemonadeProfit = (fLemonadeProfit + (sLemonadeRecipe.fLemonadePrice*iCups));
							iLemonadeSold = iLemonadeSold + iCups;
							//cout<<"*!* You sold "<<iCups<<" cups of Lemonade and earned $"<<(sLemonadeRecipe.fLemonadePrice*iCups)<<" *!*"<<endl;
							//CUSTOMER SATISFIED MSG
							eCustomerSatisfied=true;
						}
						else
						{
							//cout<<"The customer thinks your price is too high!"<<endl;
							//CUSTOMER TOO CHEAP
							eCustomerCheap=true;
						}
					}
					else if (iFrugality == 8 || 9) //customer will buy under $1.5
					{
						if (sLemonadeRecipe.fLemonadePrice <= 1.5)
						{
							iCustomerCount+=1;
							fStockLemonade = fStockLemonade - iCups;
							fMoneyOnHand = (fMoneyOnHand + (sLemonadeRecipe.fLemonadePrice*iCups));
							fLemonadeProfit = (fLemonadeProfit + (sLemonadeRecipe.fLemonadePrice*iCups));
							iLemonadeSold = iLemonadeSold + iCups;
							//cout<<"*!* You sold "<<iCups<<" cups of Lemonade and earned $"<<(sLemonadeRecipe.fLemonadePrice*iCups)<<" *!*"<<endl;
							//CUSTOMER SATISFIED MSG
							eCustomerSatisfied=true;
						}
						else
						{
							//cout<<"The customer thinks your price is too high!"<<endl;
							//CUSTOMER TOO CHEAP
							eCustomerCheap=true;
						}
					}
				}
				else //lemonade is not to taste!
				{
					//cout<<"The customer hated your recipe and bought nothing!"<<endl;
					//LEMONADE IS TOO SOUR FOR CUSTOMER
					eCustomerTasteSour=true;
				}
				break;

			case 3: //customer pref sweet
				//check lemonade is sweet
				if (iLemonadeTaste == 3) //lemonade is sweet!
				{
					//assign a frugality
					int iFrugality = rand()%10;

					//check customers frugality
					if (iFrugality <= 5) //customer will buy anything
					{
						iCustomerCount+=1;
						fStockLemonade = fStockLemonade - iCups;
						fMoneyOnHand = (fMoneyOnHand + (sLemonadeRecipe.fLemonadePrice*iCups));
						fLemonadeProfit = (fLemonadeProfit + (sLemonadeRecipe.fLemonadePrice*iCups));
						iLemonadeSold = iLemonadeSold + iCups;
						//cout<<"*!* You sold "<<iCups<<" cups of Lemonade and earned $"<<(sLemonadeRecipe.fLemonadePrice*iCups)<<" *!*"<<endl;
						//CUSTOMER SATISFIED MSG
						eCustomerSatisfied=true;
					}
					else if (iFrugality == 6 || 7) //customer will buy under $2
					{
						if (sLemonadeRecipe.fLemonadePrice <= 2)
						{
							iCustomerCount+=1;
							fStockLemonade = fStockLemonade - iCups;
							fMoneyOnHand = (fMoneyOnHand + (sLemonadeRecipe.fLemonadePrice*iCups));
							fLemonadeProfit = (fLemonadeProfit + (sLemonadeRecipe.fLemonadePrice*iCups));
							iLemonadeSold = iLemonadeSold + iCups;
							//cout<<"*!* You sold "<<iCups<<" cups of Lemonade and earned $"<<(sLemonadeRecipe.fLemonadePrice*iCups)<<" *!*"<<endl;\
							//CUSTOMER SATISFIED MSG
							eCustomerSatisfied=true;
						}
						else
						{
							//cout<<"The customer thinks your price is too high!"<<endl;
							//CUSTOMER TOO CHEAP
							eCustomerCheap=true;
						}
					}
					else if (iFrugality == 8 || 9) //customer will buy under $1.5
					{
						if (sLemonadeRecipe.fLemonadePrice <= 1.5)
						{
							iCustomerCount+=1;
							fStockLemonade = fStockLemonade - iCups;
							fMoneyOnHand = (fMoneyOnHand + (sLemonadeRecipe.fLemonadePrice*iCups));
							fLemonadeProfit = (fLemonadeProfit + (sLemonadeRecipe.fLemonadePrice*iCups));
							iLemonadeSold = iLemonadeSold + iCups;
						//	cout<<"*!* You sold "<<iCups<<" cups of Lemonade and earned $"<<(sLemonadeRecipe.fLemonadePrice*iCups)<<" *!*"<<endl;
							//CUSTOMER SATISFIED MSG
							eCustomerSatisfied=true;
						}
						else
						{
						//	cout<<"The customer thinks your price is too high!"<<endl;
							//CUSTOMER TOO CHEAP
							eCustomerCheap=true;
						}
					}
				}
				else //lemonade is not to taste!
				{
				//	cout<<"The customer hated your recipe and bought nothing!"<<endl;
					//LEMONADE IS TOO SOUR FOR CUSTOMER
					eCustomerTasteSour=true;
				}
				break;
			default:
				{
					//cout<<"Something went horribly wrong!"<<endl;
				}
				break;
		}
		
	}
	else if( fStockLemonade > iCups && fStockLemonade < 0)//Player has insufficient stock for cust, but more than 0
	{
		//system("cls");
		iMissedCups = (iCups - fStockLemonade);
	//	cout<<"*!* The customer wanted "<<iCups<<" cups of Lemonade, so they bought all your Lemonade left *!*"<<endl;
	//	cout<<"*!* You sold "<<fStockLemonade<<" cups of Lemonade and earned $"<<(fLemonadePrice*fStockLemonade)<<" *!*"<<endl;
	//	cout<<"*!* You could have sold "<<iMissedCups<<" more cups of Lemonade, if you had stock *!*"<<endl;
	//	cout<<"*!* You now have no Lemonade in stock and need to make more *!*"<<endl;
		//check stock, add funds, decrease stock, etc
		iCustomerCount+=1;
		fMoneyOnHand = (fMoneyOnHand + (sLemonadeRecipe.fLemonadePrice*fStockLemonade));
		fLemonadeProfit = (fLemonadeProfit + (sLemonadeRecipe.fLemonadePrice*fStockLemonade));
		iLemonadeSold = iLemonadeSold + fStockLemonade;
		fStockLemonade = fStockLemonade - fStockLemonade;
		//system("pause");
		//LAST CUSTOMER MSG
		eCustomerLast=true;
	}
	else if (fStockLemonade <= 0)//If player has no stock
	{
		//system("cls");
		//gotoxy(0,0);
		//cout<<"*!* You have no Lemonade in stock *!*"<<endl;
		//cout<<"*!* Buy ingredients and make Lemonade to get customers *!*"<<endl;
		//system("pause");
		//CUSTOMER HAS NO STOCK
		eCustomerNoStock=true;
	}
	
}
