//include matching header
#include "Defines.h"
#include "OpeningMenu.h"
#include "MainGameLoop.h"
#include "Customer.h"
#include "DayCycle.h"
#include "Lemonade.h"

//include iostream etc and namespace
#include <iostream>
#include <fstream>
#include <conio.h>
using namespace std;

//access GAMESTATE
extern enum GAMESTATE;

//game loop
bool bGameOver = false;

int playGame()
{
	//access enum
	GAMESTATE stateGame = MAIN_MENU;

	//player menu choice
	int iChoice;

	//MAIN GAME MENU
	system("cls");
	cout <<"------" <<endl;
	cout <<"Game Menu"<<endl;
	cout <<"------"<<endl;
	cout <<"1.	View Stock and Finances"<<endl;
	cout <<"2.	Buy Stock"<<endl;
	cout <<"3.	Make Lemonade"<<endl;
	cout <<"4.	Change recipe and price"<<endl;
	cout <<"5.	Start Day"<<endl;
	cout <<"6.	Exit to Main Menu"<<endl;
	cout <<"Please enter a number: ";
	cin >>iChoice;

	//main game menu loop
	while(bGameOver=false)
	{
		switch(iChoice)
		{
		case 1: //View Stock/Finances
			stateGame=VIEW_FINANCES;
			{
			}
			break;
		case 2: //Buy Stock
			stateGame=VIEW_STOCK;
			{
			}
			break;
		case 3: //Make Lemonade
			stateGame=MAKE_LEMONADE;
			{
			}
			break;
		case 4: //Change recipe
			stateGame=CHANGE_RECIPE;
			{
			}
			break;
		case 5: // Start The Day Cycle
			stateGame=DAY_CYCLE;
			{

			}
			break;
		case 6: //Exit to Main Menu
			{
			system("cls");
			cout << "Now returning to Main Menu" <<endl;
			system("pause");
			system("cls");
			return 0;
			}
			break;
		default:
			{
			system("cls");
			cout<<"Please enter a valid number!"<<endl;
			system("pause");
			}
			break;	
		}
		//redisplay MAIN GAME MENU
		system("cls");
		cout <<"------" <<endl;
		cout <<"Game Menu"<<endl;
		cout <<"------"<<endl;
		cout <<"1.	View Stock and Finances"<<endl;
		cout <<"2.	Buy Stock"<<endl;
		cout <<"3.	Make Lemonade"<<endl;
		cout <<"4.	Change recipe and price"<<endl;
		cout <<"5.	Start Day"<<endl;
		cout <<"6.	Exit to Main Menu"<<endl;
		cout <<"Please enter a number: ";
		cin >>iChoice;
	}

}

int main(int argc, const char*argv[])
{

	displayMainMenu();
	
}