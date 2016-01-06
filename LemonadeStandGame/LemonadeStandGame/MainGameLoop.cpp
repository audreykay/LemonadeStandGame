//include iostream
#include <iostream>

//include headers
#include "Defines.h"
#include "Customer.h"
#include "Lemonade.h"
#include <conio.h>

//make namespace std global
using namespace std;

//access enumeration
extern enum GAMESTATE;

//gamestate
bool bGameOver = false;


	void HandleInput()
	{
		char c = getchar();
		fflush( stdin );
	}

int PlayGame()
{
	//access enum
	GAMESTATE stateGame = MAIN_MENU;

	//access global variables
	//stock
	extern float fStockLemon;
	extern float fStockSugar;
	extern float fStockIce;
	extern float fStockLemonade;

	//price of lemonade per cup
	extern float fLemonadePrice;

	//cups of lemonade sold
	extern int iLemonadeSold;

	//money business
	extern float fLemonadeMoney;
	extern float fMoneySpent;
	extern float fMoneyOnHand;

	//lemonade externals
	extern void displayStock();
	extern void displayFinances();
	extern void displayBuyStock();
	extern void makeLemonade();
	extern void updateCustomerTimer();

	int iChoice;
	//MAIN GAME MENU
	system("cls");
	cout <<"------" <<endl;
	cout <<"Game Menu"<<endl;
	cout <<"------"<<endl;
	cout <<"1.	View Stock and Finances"<<endl;
	cout <<"2.	Buy Stock"<<endl;
	cout <<"3.	Make Lemonade"<<endl;
	cout <<"4.	Exit to Main Menu"<<endl;
	cout <<"Please enter a number: ";
	cin >>iChoice;


	//main game loop
	while(!bGameOver)
	{
		updateCustomerTimer();

		if( _kbhit() )
		{
			HandleInput();
		}

		
	if(fMoneyOnHand <= 1)
	{
		bGameOver = !bGameOver;
		stateGame=LOSE_GAME;
		system("cls");
		cout << "YOU'RE BANKRUPT!"<<endl;
		cout<<endl;
		cout << "YOU LOSE, YOU ENTREPRENEURIAL FAILURE!"<<endl;
		system("pause");
		return 0;
	}
	else if(fMoneyOnHand >= 5000)
	{
		stateGame=WIN_GAME;
		bGameOver = !bGameOver;
		system("cls");
		cout << "YOU WIN, YOU ENTREPRENEURIAL GENIUS!"<<endl;
		system("pause");
		return 0;
	}
	//game menu switch statement
	switch (iChoice)
	{
		
		case 1: //View Finances/Stock
			stateGame=VIEW_FINANCES;
			{//code here
			system("cls");
			displayStock();
			displayFinances();
			system("pause");
			stateGame=MAIN_MENU;
			}
			break;

		case 2: //View/Buy Stock
			stateGame=VIEW_STOCK;
			{//code here
			system("cls");
			//displayStock();
			displayBuyStock();
			//system("pause");
			//stateGame=MAIN_MENU;
			}
			break;

		case 3: //Make Lemonade
			stateGame=MAKE_LEMONADE;
			{//code here
			system("cls");
			makeLemonade();
			}
			break;

		case 4: //Exit to Main Menu
			system("cls");
			return 0;
			break;

		default:
			cout<<"*~*Please enter a valid number*~*"<<endl;
			cin >>iChoice;
			continue;
		}	
		system("cls");
		cout <<"------" <<endl;
		cout <<"Game Menu"<<endl;
		cout <<"------"<<endl;
		cout <<"1.	View Stock and Finances"<<endl;
		cout <<"2.	Buy Stock"<<endl;
		cout <<"3.	Make Lemonade"<<endl;
		cout <<"4.	Exit to Main Menu"<<endl;
		cout <<"Please enter a number: ";
		cin >>iChoice;
	}
	
	
	}


int main(int argc, const char*argv[])
{
	//PRE-GAME WARNINGS
	cout<<"*~*WARNING*~*"<<endl;
	cout<<"PLAYER MUST BUY STOCK AND MAKE LEMONADE BEFORE THE STALL CAN OPEN"<<endl;
	cout<<"*~*WARNING*~*"<<endl;
	int iMenuChoice;

	//place menu here and get users choice
	cout << "------" <<endl;
	cout << "Main Menu" <<endl;
	cout << "------" <<endl;
	cout << "1.	Play Game" <<endl;
	cout << "2.	View Instructions" <<endl;
	cout << "3.	View Credits" <<endl;
	cout << "4.	Exit Program" <<endl;
	cout << "Please enter your choice: ";
	cin >> iMenuChoice;

	//Opening Main Menu
	while( iMenuChoice >0 ) //this will make the program loop
	{
		switch(iMenuChoice)
		{
		case 1:
			{
			PlayGame();
			}
			break;
		case 2:
			{
			system("cls");
			cout << "------" <<endl;
			cout << "Instructions" <<endl;
			cout << "------" <<endl;
			cout << "The aim of the Lemonade Stand Game is to make $5,000 profit" <<endl;
			cout << "The Player must make jugs of Lemonade to sell before customers will come" <<endl;
			cout << "The Player must manage stock and finances" <<endl;
			cout << "If the Player's Cash On Hand falls below $1, the Player will become Bankrupt" <<endl;
			}
			break;
		case 3:
			{
			const int DEV_YEAR = 2015;
			int iGameVersion = 2;
			//about the game
			system("cls");
			cout << "------" <<endl;
			cout << "The Lemonade Stand Game" <<endl;
			cout << "------" <<endl;
			cout << "Game Version: " << iGameVersion <<endl;
			cout << "Company: Twoitle Games" <<endl;
			cout << "Created in " << DEV_YEAR << " by Audrey Kay, an avid Lemongrab enthusiast." <<endl;
			}
			break;
		case 4:
			{
			system("cls");
			cout << "Player has exited the game" <<endl;
			system("pause");
			return 0; //exits the program
			}
			break;
		default:
			{
				cout << "Please choose a valid number: ";
				cin >> iMenuChoice;
				cout << endl;
			}
			break;
		}

	//place menu here and get users choice
	cout << "------" <<endl;
	cout << "Main Menu" <<endl;
	cout << "------" <<endl;
	cout << "1.	Play Game" <<endl;
	cout << "2.	View Instructions" <<endl;
	cout << "3.	View Credits" <<endl;
	cout << "4.	Exit Program" <<endl;
	cout << "Please enter your choice: ";
	cin >> iMenuChoice;
	}

}

