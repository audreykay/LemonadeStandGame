//include this file once only
#pragma once

//include iostream and namespace (needed for each header)
#include <iostream>
using namespace std;

//game state enumeration
enum GAMESTATE
{
	MAIN_MENU,
	VIEW_FINANCES,
	VIEW_STOCK,
	MAKE_LEMONADE,
	EXIT_GAME,
	WIN_GAME,
	LOSE_GAME
};

//lemonade recipe
const float RECIPE_LEMON = 2.5f;
const float RECIPE_SUGAR = 3.0f;
const float RECIPE_ICE = 3.0f;

//stock costs
const float COST_LEMON = 0.5f;
const float COST_SUGAR = 2.2f;
const float COST_ICE = 2.0f;

//min-max number of cups bought by customers
const int MAX_CUPS = 10;
const int MIN_CUPS = 1;

//win win win
const int MONETARY_GOAL = 500;