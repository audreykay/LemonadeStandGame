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

//min-max stock costs
const float MAX_COST_LEMON = 1.5f;
const float MIN_COST_LEMON = 0.25f;
const float MAX_COST_SUGAR = 2.2f;
const float MIN_COST_SUGAR = 0.75f;
const float MAX_COST_ICE = 2.0f;
const float MIN_COST_ICE = 1.05f;

//min-max number of cups bought by customers
const int MAX_CUPS = 10;
const int MIN_CUPS = 1;

//win win win
const int MONETARY_GOAL = 500;