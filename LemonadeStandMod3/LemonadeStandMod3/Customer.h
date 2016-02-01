//include this file once only
#pragma once

//include iostream and namespace (needed for each header)
#include <iostream>
using namespace std;

extern int iLemonadeTaste;

//stock loss
extern float fSugarLoss;
extern float fIceLoss;
extern float fLemonLoss;
extern float fLemonadeLoss;

extern int mystrlen(char *s);

extern bool bDayCycle;

//eventbool
extern bool eCustomerSatisfied;
extern bool eCustomerCheap;
extern bool eCustomerTasteSour;
extern bool eCustomerTasteSweet;
extern bool eCustomerNoStock;
extern bool eCustomerLast;