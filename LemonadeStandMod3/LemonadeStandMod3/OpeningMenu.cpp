//include this file once only
#pragma once

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

extern void displayBuyStock();
int displayMainMenu()
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
				displayBuyStock();
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