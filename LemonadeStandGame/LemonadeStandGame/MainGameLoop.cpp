//include iostream
#include <iostream>

//include headers
#include "Defines.h"
#include "Customer.h"
#include "Lemonade.h"
#include "MainGameLoop.h"
#include <conio.h>

//make namespace std global
using namespace std;

//access enumeration
extern enum GAMESTATE;

//gamestate
bool bGameOver = false;

//HandleInput
void HandleInput()
{
	char c = getchar();
	fflush( stdin );
}

//Main Game Function
int PlayGame()
{
	//access enum
	GAMESTATE stateGame = MAIN_MENU;

	//Player Choice
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

		if(fMoneyOnHand <= 1) //If player goes bankrupt
		{
			bGameOver = true;
			stateGame=LOSE_GAME;
			system("cls");
			cout << "YOU'RE BANKRUPT!"<<endl;
			cout<<endl;
			cout << "YOU LOSE, YOU ENTREPRENEURIAL FAILURE!"<<endl;
			system("pause");
			return 0;
		}
		else if(fMoneyOnHand >= MONETARY_GOAL) //If player reaches goal
		{
			bGameOver = true;
			stateGame=WIN_GAME;
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
			{
			system("cls");
			displayStock();
			displayFinances();
			system("pause");
			stateGame=MAIN_MENU;
			}
			break;

		case 2: //View/Buy Stock
			stateGame=VIEW_STOCK;
			{
			system("cls");
			//displayStock();
			displayBuyStock();
			//system("pause");
			//stateGame=MAIN_MENU;
			}
			break;

		case 3: //Make Lemonade
			stateGame=MAKE_LEMONADE;
			{
			system("cls");
			displayRecipe();
			makeLemonade();
			}
			break;

		case 4: //Exit to Main Menu
			system("cls");
			cout << "Now returning to Main Menu" <<endl;
			system("pause");
			system("cls");
			return 0;
			break;

		default:  //invalid choice
		system("cls");
		cout<<"*~*Please enter a valid number*~*"<<endl;
		system("pause");
			break;
		}	
		//redisplay menu
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
	//end playgame function
	}

// introductory menu
int main(int argc, const char*argv[])
{

	int iMenuChoice;

	//place menu here and get users choice
	system("cls");
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
		case 1: //Play Game 
			{
			PlayGame();
			}
			break;
		case 2: //Instructions
			{
			system("cls");
			cout << "------" <<endl;
			cout << "Instructions" <<endl;
			cout << "------" <<endl;
			cout << "The aim of the Lemonade Stand Game is to make $5,000 profit" <<endl;
			cout << "The Player must make jugs of Lemonade to sell before customers will come" <<endl;
			cout << "The Player must manage stock and finances" <<endl;
			cout << "If the Player's Cash On Hand falls below $1, the Player will become Bankrupt" <<endl;
			cout<<endl;
			}
			break;
		case 3: //credits
			{
			const int DEV_YEAR = 2016;
			int iGameVersion = 2;
			//about the game
			system("cls");
			cout << "------" <<endl;
			cout << "The Lemonade Stand Game" <<endl;
			cout << "------" <<endl;
			cout << "Game Version: " << iGameVersion <<endl;
			cout << "Company: Twoitle Games" <<endl;
			cout << "Created in " << DEV_YEAR << " by Audrey Kay, an avid Lemongrab enthusiast." <<endl;
			cout<<endl;
			}
			break;
		case 4: //exit game
			{
			system("cls");
			cout << "Player has exited the game" <<endl;
			system("pause");
			return 0; //exits the program
			}
			break;
		default: //invalid choice
			{
			cout << "Please choose a valid number! "<<endl;
			system("pause");
			system("cls");
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

