//include matching header
#include "Defines.h"
#include "OpeningMenu.h"
#include "MainGameLoop.h"
#include "Customer.h"
#include "DayCycle.h"
#include "Lemonade.h"

//include iostream and namespace (needed for each header)
#include <iostream>
#include <fstream>
using namespace std;

//stock
float fStockLemon = 0;
float fStockSugar = 0;
float fStockIce = 0;
float fStockLemonade = 0;

//price of lemonade per cup
float fLemonadePrice = 2.5;

//cups of lemonade sold
int iLemonadeSold = 0;

//money business
float fLemonadeProfit = 0;
float fMoneySpent = 0;
float fMoneyOnHand = 50;

//lemonade taste
int iLemonadeTaste;