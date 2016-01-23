//include matching header
#include "Defines.h"
#include "MainGameLoop.h"
#include "Customer.h"
#include "DayCycle.h"
#include "Lemonade.h"

//include iostream and namespace (needed for each header)
#include <iostream>
#include <fstream>
#include <sstream>
#include <windows.h>
#include <string>
#include <conio.h>
using namespace std;

//RE triggers
bool eventLemon = false;
bool eventSugar = false;
bool eventIce = false;
bool eventLemonade = false;

//start timer
unsigned long startTime_;
void startTime()
{
  startTime_ = GetTickCount();
}
//calculating elapsed milliseconds
unsigned int calculateElapsedTime()
{
  unsigned int diffInMilliSeconds = GetTickCount() - startTime_;
  return diffInMilliSeconds;
}

//testing message length
int mystrlen(char *s)
{
    int i = 0;
    while (*s++)
        ++i;
    return i;
}

//Random Event 
void randomEvent()
{
	int iRandomEvent = rand()%4;

	switch (iRandomEvent)
	{
	case 0:
		{
			eventSugar = true;
			int iRandomSugar = rand()%(3)+1;
			//cout<<"Rats spoiled "<<iRandomSugar<<" bag(s) of sugar!"<<endl;
			fSugarLoss += iRandomSugar;
			fStockSugar -= iRandomSugar;
		}
		break;
	case 1:
		{
			eventIce = true;
			int iRandomIce = rand()%(2)+1;
			//cout<<iRandomIce<<" bag(s) of ice melted!"<<endl;
			fIceLoss += iRandomIce;
			fStockIce -= iRandomIce;
		}
		break;
	case 2:
		{
			eventLemon = true;
			int iRandomLemon = rand()%(4)+1;
			//cout<<iRandomLemon<<" lemon(s) went bad!"<<endl;
			fLemonLoss += iRandomLemon;
			fStockIce -= iRandomLemon;
		}
		break;
	case 3:
		{
			eventLemonade = true;
			int iRandomLemonade = rand()%(5)+1;
			//cout<< "Kids threw a ball at your stand and knocked over "<< iRandomLemonade<< " cups of Lemonade!";
			fLemonadeLoss += iRandomLemonade;
			fStockLemonade -= iRandomLemonade;
		}
		break;
	}
	
}

char msgLemon[] = " LEMONS WENT BAD! ";
char msgSugar[] = " SUGAR SPOILED! ";
char msgIce[] = " ICE MELTED! ";
char msgLemonade[] = " LEMONADE GOT KNOCKED OVER! ";

unsigned int diffTime = 0, lastTime = 0, newTime = 0;



int dayTimer()
{
	bool bNewDay=true;

	static int timeAtStartOfLastUpdate = GetTickCount();

	//lem msg
	int i;
	int lenLemon = mystrlen(msgLemon);
	int startLemon = lenLemon - 20;
	int istartLemon = startLemon;
	//sugar msg
	int lenSugar = mystrlen(msgSugar);
	int startSugar = lenSugar - 20;
	int istartSugar = startSugar;
	//ice msg
	int lenIce = mystrlen(msgIce);
	int startIce = lenIce - 20;
	int istartIce = startIce;
	//lemonade msg
	int lenLemonade = mystrlen(msgLemonade);
	int startLemonade = lenLemonade - 20;
	int istartLemonade = startLemonade;
	//customerRE
	/*int lenCustomer = mystrlen(msgCustomer);
	int startCustomer = lenCustomer - 40;
	int istartCustomer = startCustomer;*/

	//system("cls");
	
	//
	while (bNewDay==true)
	{
		//call random event
		randomEvent();
		updateCustomerTimer();
		//find difference in time
		int timeNow = GetTickCount();
		int dt = timeNow - timeAtStartOfLastUpdate;

		//reset time to find next dt update
		timeAtStartOfLastUpdate = timeNow;

		//if lemonade event triggered, display message
		if(eventLemonade==true)
		{
		--istartLemonade;
		for (i=0; i < 80; ++i)
		{
			if ((istartLemonade + i) >= lenLemonade)
			{
				fputc(msgLemon[(istartLemonade + i) - lenLemonade], stdout);
			}
			else
			{
				fputc(msgLemon[istartLemonade + i], stdout);
			}
		}
		}
		//else lemon event triggered
		else if(eventLemon==true)
		{
		--istartLemon;
		for (i=0; i < 80; ++i)
		{
			if ((istartLemon + i) >= lenLemon)
			{
				fputc(msgLemon[(istartLemon + i) - lenLemon], stdout);
			}
			else
			{
				fputc(msgLemon[istartLemon + i], stdout);
			}
		}
		}
		//else sugar event triggered
		else if(eventSugar==true)
		{
		--istartSugar;
		for (i=0; i < 80; ++i)
		{
			if ((istartSugar + i) >= lenSugar)
			{
				fputc(msgSugar[(istartSugar + i) - lenSugar], stdout);
			}
			else
			{
				fputc(msgSugar[istartSugar + i], stdout);
			}
		}
		}
		//else ice event triggered
		else if(eventIce==true)
		{
		--istartIce;
		for (i=0; i < 80; ++i)
		{
			if ((istartIce + i) >= lenIce)
			{
				fputc(msgIce[(istartIce + i) - lenIce], stdout);
			}
			else
			{
				fputc(msgIce[istartIce + i], stdout);
			}
		}
		}
	//text length max
	startTime();

	if (istartLemon == 0) istartLemon = lenLemon;
	if (istartSugar == 0) istartSugar = lenSugar;
	if (istartIce == 0) istartIce = lenIce;
	if (istartLemonade == 0) istartLemonade = lenLemonade;

	//clear input
	fflush(NULL);
	//pause text scroll (++slow down)
	Sleep(100);
	//clear screen
	system("cls");
	/*cout<< "deltatime: "<< dt <<endl;
	cout<< "time Elapsed: " <<endl;*/

	//TIMER
	newTime = calculateElapsedTime();

	diffTime = newTime + lastTime;
	//diff time is seconds counting up
	cout<<"Time after 100ms Sleep = "<<newTime<<", Difference = "<<diffTime<<endl;
	//time left is set 10 second count down/up (millisecond)
	unsigned secondsPassed = (diffTime)/1000; //seconds counting up
	
	cout<<"time elapsed: " <<secondsPassed<<" second(s)"<<endl;
	cout<<"Lemons spoiled: " <<fLemonLoss<<endl;
	cout<<"Sugar spoiled: " <<fSugarLoss<<endl;
	cout<<"Ice melted: " <<fIceLoss<<endl;
	cout<<"Lemonade wasted: "<<fLemonadeLoss<<endl;
	cout<<"Cash on hand: " <<fMoneyOnHand<<endl;
	lastTime = lastTime + newTime;

	//if dayTime greater than 10secs, exit
	if(secondsPassed==10)
	{
		return 0;
	}

}

}
