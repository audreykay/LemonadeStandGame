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

//recipe structure
struct RecipeStruct
{
	float fLemonRecipe;
	float fSugarRecipe;
	float fIceRecipe;
	float fLemonadePrice;
};



//change recipe/price screen
void changeRecipe()
{
	RecipeStruct sLemonadeRecipe;

	if(sLemonadeRecipe.fLemonRecipe == 0)
	{
		sLemonadeRecipe.fLemonRecipe = rand()%5+1;
		sLemonadeRecipe.fSugarRecipe = rand()%3+1;
		sLemonadeRecipe.fIceRecipe = rand()%2+1;
		sLemonadeRecipe.fLemonadePrice = rand()%3+1;
	}
	
	int iMenuChoice;
	cout<<"Would you like to alter the recipe and price?"<<endl;
	cout<<"1.	Yes"<<endl;
	cout<<"2.	No (Return to Menu)"<<endl;
	cin>>iMenuChoice;
	cout<<endl;

	switch(iMenuChoice)
	{
	case 1:
		{
			cout<<"Change lemons per jug from "<<sLemonadeRecipe.fLemonRecipe<<" to: ";
			cin>>sLemonadeRecipe.fLemonRecipe;
			cout<<endl;

		}

	case 2:
		{

		}

	default:
		{
			cout<<"Please choose a valid number"<<endl;
		}
	}

}