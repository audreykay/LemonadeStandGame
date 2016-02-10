//include this file once only
#pragma once

//include iostream and namespace (needed for each header)
#include <iostream>
using namespace std;


//extern functions
extern int displayMainMenu();
extern void displayStock();
extern void displayFinances();
extern void displayBuyStock();
extern void displayRecipe();
extern void makeLemonade();
extern void changeRecipe();
extern void shopMenu();
extern void randomStockPrice();
extern void randomStockLoss();
extern int dayTimer();
extern int startDay();

extern unsigned int diffTime, newTime;
extern float fProfit;
extern bool bDayCycle;
extern int iDaysPassed;
extern int iCustomerTotal;
