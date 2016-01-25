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

//RE CUSTOMER MESSAGES

char msgCustomerSatisfied[] = " ANOTHER SATISFIED CUSTOMER! ";
char msgCustomerCheap[] =  " ''YOUR LEMONADE IS TOO EXPENSIVE'' ";
char msgCustomerTasteSour[] = " ''YOUR LEMONADE IS TOO SOUR'' ";
char msgCustomerTasteSweet[] = " ''YOUR LEMONADE IS TOO SWEET'' ";
char msgCustomerNoStock[] = " YOU ARE OUT OF LEMONADE AND NEED TO MAKE MORE! ";
char msgCustomerLast[] = " THE CUSTOMER BOUGHT ALL YOUR LEMONADE LEFT! ";

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

	//satisfied msg
	int lenSat = mystrlen(msgCustomerSatisfied);
	int startSat = lenSat - 20;
	int istartSat = startSat;
	//customer too cheap msg
	int lenCheap = mystrlen(msgCustomerCheap);
	int startCheap = lenCheap - 20;
	int istartCheap = startCheap;
	//too sour msg
	int lenSour = mystrlen(msgCustomerTasteSour);
	int startSour = lenSour - 20;
	int istartSour = startSour;
	//too sweet msg
	int lenSweet = mystrlen(msgCustomerTasteSweet);
	int startSweet = lenSweet - 20;
	int istartSweet = startSweet;
	//no stock msg
	int lenNoStock = mystrlen(msgCustomerNoStock);
	int startNoStock = -2;
	int istartNoStock = startNoStock;
	//last customermsg
	int lenLast = mystrlen(msgCustomerLast);
	int startLast = lenLast - 20;
	int istartLast = startLast;

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
						//cout<<"*!* You sold "<<iCups<<" cups of Lemonade and earned $"<<(fLemonadePrice*iCups)<<" *!*"<<endl;
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
							//cout<<"*!* You sold "<<iCups<<" cups of Lemonade and earned $"<<(fLemonadePrice*iCups)<<" *!*"<<endl;
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
							//cout<<"*!* You sold "<<iCups<<" cups of Lemonade and earned $"<<(fLemonadePrice*iCups)<<" *!*"<<endl;
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
						//cout<<"*!* You sold "<<iCups<<" cups of Lemonade and earned $"<<(fLemonadePrice*iCups)<<" *!*"<<endl;
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
							//cout<<"*!* You sold "<<iCups<<" cups of Lemonade and earned $"<<(fLemonadePrice*iCups)<<" *!*"<<endl;
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
							//cout<<"*!* You sold "<<iCups<<" cups of Lemonade and earned $"<<(fLemonadePrice*iCups)<<" *!*"<<endl;
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
						//cout<<"*!* You sold "<<iCups<<" cups of Lemonade and earned $"<<(fLemonadePrice*iCups)<<" *!*"<<endl;
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
							//cout<<"*!* You sold "<<iCups<<" cups of Lemonade and earned $"<<(fLemonadePrice*iCups)<<" *!*"<<endl;
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
							//cout<<"*!* You sold "<<iCups<<" cups of Lemonade and earned $"<<(fLemonadePrice*iCups)<<" *!*"<<endl;
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
						//cout<<"*!* You sold "<<iCups<<" cups of Lemonade and earned $"<<(fLemonadePrice*iCups)<<" *!*"<<endl;
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
							//cout<<"*!* You sold "<<iCups<<" cups of Lemonade and earned $"<<(fLemonadePrice*iCups)<<" *!*"<<endl;\
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
							//cout<<"*!* You sold "<<iCups<<" cups of Lemonade and earned $"<<(fLemonadePrice*iCups)<<" *!*"<<endl;
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
		/*system("cls");
		cout<<"*!* You have no Lemonade in stock *!*"<<endl;
		cout<<"*!* Buy ingredients and make Lemonade to get customers *!*"<<endl;
		system("pause");*/
		//CUSTOMER HAS NO STOCK
		eCustomerNoStock=true;
	}

	while(true)
	{
	//PRINT EVENT TO SCREEN
	if(eCustomerSatisfied==true)
	{
		--istartSat;
		for (i=0; i < 80; ++i)
		{
			if ((istartSat + i) >= lenSat)
			{
				fputc(msgCustomerSatisfied[(istartSat + i) - lenSat], stdout);
			}
			else
			{
				fputc(msgCustomerSatisfied[istartSat + i], stdout);
			}
		}
	}
	else if(eCustomerCheap==true)
	{
		--istartCheap;
		for (i=0; i < 80; ++i)
		{
			if ((istartCheap + i) >= lenCheap)
			{
				fputc(msgCustomerCheap[(istartCheap + i) - lenCheap], stdout);
			}
			else
			{
				fputc(msgCustomerCheap[istartCheap + i], stdout);
			}
		}
	}
	else if(eCustomerTasteSweet==true)
	{
		--istartSweet;
		for (i=0; i < 80; ++i)
		{
			if ((istartSweet + i) >= lenSweet)
			{
				fputc(msgCustomerTasteSweet[(istartSweet + i) - lenSweet], stdout);
			}
			else
			{
				fputc(msgCustomerTasteSweet[istartCheap + i], stdout);
			}
		}
	}
	else if(eCustomerTasteSour==true)
	{
		--istartSour;
		for (i=0; i < 80; ++i)
		{
			if ((istartSour + i) >= lenSour)
			{
				fputc(msgCustomerTasteSour[(istartSour + i) - lenSour], stdout);
			}
			else
			{
				fputc(msgCustomerTasteSour[istartCheap + i], stdout);
			}
		}
	}
	else if(eCustomerNoStock==true)
	{
		--istartNoStock;
		for (i=0; i < 80; ++i)
		{
			if ((istartNoStock + i) >= lenNoStock)
			{
				fputc(msgCustomerNoStock[(istartSat + i) - lenNoStock], stdout);
				
			}
			else
			{
				fputc(msgCustomerNoStock[istartNoStock + i], stdout);
				
			}
		}
	}
	else if(eCustomerLast==true)
	{
		--istartLast;
		for (i=0; i < 80; ++i)
		{
			if ((istartLast + i) >= lenLast)
			{
				fputc(msgCustomerLast[(istartLast + i) - lenLast], stdout);
			}
			else
			{
				fputc(msgCustomerLast[istartLast + i], stdout);
			}
		}
	}
	
	//IF END OF SCREEN, WRAP
	if (istartSat == 0) istartSat = lenSat;
	if (istartCheap == 0) istartCheap = lenCheap;
	if (istartSweet == 0) istartSweet = lenSweet;
	if (istartSour == 0) istartSour = lenSour;
	if (istartNoStock == 0) istartNoStock = lenNoStock;
	if (istartLast == 0) istartLast = lenLast;
	//clear input
	fflush(stdout);
	Sleep(100);
	system("cls");
	
	
	}
	
}
