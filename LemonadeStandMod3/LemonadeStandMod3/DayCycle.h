//include this file once only
#pragma once

//include iostream and namespace (needed for each header)
#include <iostream>
using namespace std;

extern float fMoneyOnHand;
extern float fProfit;
extern int iLemonadeSold;
extern int iCustomerCount;
extern int iCustomerCountCheap;
extern int iCustomerCountSweet;
extern int iCustomerCountSour;
extern void updateCustomerTimer();
extern int iUpdateCounter;

extern void gotoxy( int column, int line );
extern int wherex();
extern int wherey();
