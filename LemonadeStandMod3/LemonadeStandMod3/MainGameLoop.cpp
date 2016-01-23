//include matching header
#include "Defines.h"
#include "MainGameLoop.h"
#include "Customer.h"
#include "DayCycle.h"
#include "Lemonade.h"

//include iostream etc and namespace
#include <iostream>
#include <fstream>
#include <conio.h>
#include <windows.h>
#include <string>
using namespace std;

//access GAMESTATE
extern enum GAMESTATE;

extern struct RecipeStruct sLemonadeRecipe;

//game loop
bool bGameOver = false;
//set startup
bool bStartUp = false;
//set rand recipe
bool bRecipeSet=false;

//access the instruction text file
void displayInstructions()
{
	char cReadString[80];
	fstream fMyFile;
	
	fMyFile.open("Instructions.txt", ios::in);

	if( fMyFile.is_open() )
	{
		while (fMyFile.getline( cReadString, 80) )
		{
			cout<<cReadString<<endl;
		}
		fMyFile.close();
		fMyFile.clear();
	}

}


int playGame()
{
	//access enum
	GAMESTATE stateGame = MAIN_MENU;

	//player menu choice
	int iChoice;

	//MYSTERIOUS BENEFACTOR
		if(bStartUp==false)
	{
		fMoneyOnHand +=(rand()%(100-25))+25;
		fStockLemon +=(rand()%(25-10))+10;
		fStockSugar +=(rand()%(25-10))+10;
		fStockIce +=(rand()%(25-10))+10;
		bStartUp=true;
	}
		
	//RANDOM RECIPE
	if(bRecipeSet==false)
	{
		sLemonadeRecipe.fLemonRecipe +=(rand()%(3-1))+1;
		sLemonadeRecipe.fSugarRecipe +=(rand()%(3-1))+1;
		sLemonadeRecipe.fIceRecipe +=(rand()%(3-1))+1;
		sLemonadeRecipe.fLemonadePrice +=(rand()%(3-1))+1;
		bRecipeSet=true;
	}


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
	while(!bGameOver)
	{
		switch(iChoice)
		{
		case 1: //View Stock/Finances
			stateGame=VIEW_FINANCES;
			{
			system("cls");
			displayStock();
			displayFinances();
			system("pause");
			}
			break;
		case 2: //Buy Stock
			stateGame=VIEW_STOCK;
			{
			system("cls");
			shopMenu();
			stateGame=MAIN_MENU;
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
		case 4: //Change recipe
			stateGame=CHANGE_RECIPE;
			{
			system("cls");
			changeRecipe();
			}
			break;
		case 5: // Start The Day Cycle
			stateGame=DAY_CYCLE;
			{
			//diffTime=newTime;
			system("cls");
			dayTimer();
			}
			break;
		case 6: //Exit to Main Menu
			stateGame=EXIT_GAME;
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
				playGame();
			}
			break;
		case 2: //Instructions
			{
				system("cls");
				displayInstructions();
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