//include matching header
#include "Defines.h"
#include "MainGameLoop.h"
#include "Customer.h"
#include "DayCycle.h"
#include "Lemonade.h"

//include iostream and namespace (needed for each header)
#include <iostream>
#include <fstream>
#include <windows.h>
#include <string>
#include <conio.h>
using namespace std;


unsigned long startTime_;

void startTime()
{
  startTime_ = GetTickCount();
}

unsigned int calculateElapsedTime()
{
  unsigned int diffInMilliSeconds = GetTickCount() - startTime_;
  return diffInMilliSeconds;
}

int mystrlen(char *s)
{
    int i = 0;
    while (*s++)
        ++i;
    return i;
}


void randomEvent()
{
	int iRandomEvent = rand()%4;

	switch (iRandomEvent)
	{
	case 0:
		{
			int iRandomSugar = rand()%(3)+1;
			cout<<"Rats spoiled "<<iRandomSugar<<" bag(s) of sugar!"<<endl;
			fSugarLoss += iRandomSugar;
			fStockSugar -= iRandomSugar;
		}
		break;
	case 1:
		{
			int iRandomIce = rand()%(2)+1;
			cout<<iRandomIce<<" bag(s) of ice melted!"<<endl;
			fIceLoss += iRandomIce;
			fStockIce -= iRandomIce;
		}
		break;
	case 2:
		{
			int iRandomLemon = rand()%(4)+1;
			cout<<iRandomLemon<<" lemon(s) went bad!"<<endl;
			fIceLoss += iRandomLemon;
			fStockIce -= iRandomLemon;
		}
		break;
	case 3:
		{
		int iRandomLemonade = rand()%(5)+1;
		cout<<"Kids threw a ball at your stand and knocked over "<<iRandomLemonade<< " cups of Lemonade!" <<endl;
		fStockLemonade -= iRandomLemonade;
		}
		break;
	}
	
}

char msg[] = "this is the message to display forever and ever and ever!";

unsigned int diffTime = 0, lastTime = 0, newTime = 0;

int dayTimer()
{
	static int timeAtStartOfLastUpdate = GetTickCount();
	
	int i;
	int len = mystrlen(msg);
	int start = len - 40;
	int istart = start;

	

	system("cls");

	while (true)
	{

		//find difference in time
		int timeNow = GetTickCount();
		int dt = timeNow - timeAtStartOfLastUpdate;

		//reset time to find next dt update
		timeAtStartOfLastUpdate = timeNow;
		
		

		--istart;
		for (i=0; i < 80; ++i)
		{
			if ((istart + i) >= len)
			{
				fputc(msg[(istart + i) - len], stdout);
			}
			else
			{
				fputc(msg[istart + i], stdout);
			}
		}
	startTime();
		if (istart == 0) istart = len;
		fflush(NULL);
		Sleep(100);
		system("cls");
	//cout<< "time Elapsed: " <<endl;
	 
		newTime = calculateElapsedTime();
		 diffTime = newTime + lastTime;
		 cout<<"Time after 100ms Sleep = "<<newTime<<", Difference = "<<diffTime<<endl;
		 unsigned timeLeft = (10000 - diffTime)/1000;
		 cout<<"time left " <<timeLeft<<endl;
		 lastTime = lastTime + newTime;
	if(timeLeft >= 10000)//exit when timer runs out
	{
		return 0;
	}
		
	cout<< "deltatime: "<< dt <<endl;
	}
}
