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

//dayPassed VAR
int iDaysPassed;
const int DAY_LENGTH = 10;
bool bDayCycle=false;
int iWeatherCounter;

//RE triggers
bool eventLemon = false;
bool eventSugar = false;
bool eventIce = false;
bool eventLemonade = false;

//access RECIPESTRUCT
extern struct RecipeStruct sLemonadeRecipe;

//weather functionality
int iWeatherTemp;


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
			if(fStockSugar >= 1 && fStockSugar >= iRandomSugar)
			{
			fSugarLoss += iRandomSugar;
			fStockSugar -= iRandomSugar;
			}
		}
		break;
	case 1:
		{
			eventIce = true;
			int iRandomIce = rand()%(2)+1;
			//cout<<iRandomIce<<" bag(s) of ice melted!"<<endl;
			if(fStockIce >= 1 && fStockIce >= iRandomIce)
			{
			fIceLoss += iRandomIce;
			fStockIce -= iRandomIce;
			}
		}
		break;
	case 2:
		{
			eventLemon = true;
			int iRandomLemon = rand()%(4)+1;
			//cout<<iRandomLemon<<" lemon(s) went bad!"<<endl;
			if(fStockLemon >= 1 && fStockLemon >= iRandomLemon)
			{
			fLemonLoss += iRandomLemon;
			fStockLemon -= iRandomLemon;
			}
		}
		break;
	case 3:
		{
			eventLemonade = true;
			int iRandomLemonade = rand()%(5)+1;
			//cout<< "Kids threw a ball at your stand and knocked over "<< iRandomLemonade<< " cups of Lemonade!";
			if (fStockLemonade >= 1 && fStockLemonade >= iRandomLemonade)
			{
			fLemonadeLoss += iRandomLemonade;
			fStockLemonade -= iRandomLemonade;
			}
		}
		break;
	}
	
}
//RE MESSAGES
char msgLemon[] = " LEMONS WENT BAD! ";
char msgSugar[] = " SUGAR SPOILED! ";
char msgIce[] = " ICE MELTED! ";
char msgLemonade[] = " LEMONADE GOT KNOCKED OVER! ";

//RE CUSTOMER MESSAGES
char msgCustomerSatisfied[] = " ANOTHER SATISFIED CUSTOMER! ";
char msgCustomerCheap[] =  " ''YOUR LEMONADE IS TOO EXPENSIVE'' ";
char msgCustomerTasteSour[] = " ''YOUR LEMONADE IS TOO SOUR'' ";
char msgCustomerTasteSweet[] = " ''YOUR LEMONADE IS TOO SWEET'' ";
char msgCustomerNoStock[] = " YOU ARE OUT OF LEMONADE AND NEED TO MAKE MORE! ";
char msgCustomerLast[] = " THE CUSTOMER BOUGHT ALL YOUR LEMONADE LEFT! ";

unsigned int diffTime = 0, lastTime = 0, newTime = 0;



int dayTimer()
{
	//set the weather
	iWeatherTemp = rand()%3;
	//bool bDayCycle=true;
	
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
	//satisfied msg
	int lenSat = mystrlen(msgCustomerSatisfied);
	int startSat = lenSat - 20;
	int istartSat = startSat;
	//customer too cheap msg
	int lenCheap = mystrlen(msgCustomerCheap);
	int startCheap = lenCheap - 20;
	int istartCheap = startCheap;
	//too sour msg
	int lenSour = mystrlen(msgCustomerTasteSour);
	int startSour = lenSour - 20;
	int istartSour = startSour;
	//too sweet msg
	int lenSweet = mystrlen(msgCustomerTasteSweet);
	int startSweet = lenSweet - 20;
	int istartSweet = startSweet;
	//no stock msg
	int lenNoStock = mystrlen(msgCustomerNoStock);
	int startNoStock = -2;
	int istartNoStock = startNoStock;
	//last customermsg
	int lenLast = mystrlen(msgCustomerLast);
	int startLast = lenLast - 20;
	int istartLast = startLast;
	
	while (true)
	{
		iWeatherCounter+=1;
		//call customers& random event
		//if customer has been called 10 times, random event
		if(iUpdateCounter%10==0)
		{
			gotoxy(0,12);
			randomEvent();
		}
		//weather conditions
		if(iWeatherTemp==0) //weather is cold
		{
			if(iWeatherCounter%6==0)
			{
				gotoxy(0,11);
				updateCustomerTimer();
			}
		}
		else if(iWeatherTemp==1) //weather is average
		{
			if(iWeatherCounter%4==0)
			{
				gotoxy(0,11);
				updateCustomerTimer();
			}
		}
		else if(iWeatherTemp==2) //weather is hot
		{
			if(iWeatherCounter%2==0)
			{
				gotoxy(0,11);
				updateCustomerTimer();
			}
		}


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
	if(eCustomerSatisfied==true)
	{
		--istartSat;
		for (i=0; i < 80; ++i)
		{
			if ((istartSat + i) >= lenSat)
			{
				fputc(msgCustomerSatisfied[(istartSat + i) - lenSat], stdout);
			}
			else
			{
				fputc(msgCustomerSatisfied[istartSat + i], stdout);
			}
		}
	}
	else if(eCustomerCheap==true)
	{
		iCustomerCountCheap+=1;
		--istartCheap;
		for (i=0; i < 80; ++i)
		{
			if ((istartCheap + i) >= lenCheap)
			{
				fputc(msgCustomerCheap[(istartCheap + i) - lenCheap], stdout);
			}
			else
			{
				fputc(msgCustomerCheap[istartCheap + i], stdout);
			}
		}
	}
	else if(eCustomerTasteSweet==true)
	{
		iCustomerCountSweet+=1;
		--istartSweet;
		for (i=0; i < 80; ++i)
		{
			if ((istartSweet + i) >= lenSweet)
			{
				fputc(msgCustomerTasteSweet[(istartSweet + i) - lenSweet], stdout);
			}
			else
			{
				fputc(msgCustomerTasteSweet[istartCheap + i], stdout);
			}
		}
	}
	else if(eCustomerTasteSour==true)
	{
		iCustomerCountSour+=1;
		--istartSour;
		for (i=0; i < 80; ++i)
		{
			if ((istartSour + i) >= lenSour)
			{
				fputc(msgCustomerTasteSour[(istartSour + i) - lenSour], stdout);
			}
			else
			{
				fputc(msgCustomerTasteSour[istartCheap + i], stdout);
			}
		}
	}
	else if(eCustomerNoStock==true)
	{
		--istartNoStock;
		for (i=0; i < 80; ++i)
		{
			if ((istartNoStock + i) >= lenNoStock)
			{
				fputc(msgCustomerNoStock[(istartSat + i) - lenNoStock], stdout);
				
			}
			else
			{
				fputc(msgCustomerNoStock[istartNoStock + i], stdout);
				
			}
		}
	}
	else if(eCustomerLast==true)
	{
		--istartLast;
		for (i=0; i < 80; ++i)
		{
			if ((istartLast + i) >= lenLast)
			{
				fputc(msgCustomerLast[(istartLast + i) - lenLast], stdout);
			}
			else
			{
				fputc(msgCustomerLast[istartLast + i], stdout);
			}
		}
	}
	//text length max
	startTime();

	if (istartLemon == 0) istartLemon = lenLemon;
	if (istartSugar == 0) istartSugar = lenSugar;
	if (istartIce == 0) istartIce = lenIce;
	if (istartLemonade == 0) istartLemonade = lenLemonade;
	if (istartSat == 0) istartSat = lenSat;
	if (istartCheap == 0) istartCheap = lenCheap;
	if (istartSweet == 0) istartSweet = lenSweet;
	if (istartSour == 0) istartSour = lenSour;
	if (istartNoStock == 0) istartNoStock = lenNoStock;
	if (istartLast == 0) istartLast = lenLast;

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
	//diff time in seconds counting up
	diffTime = newTime + lastTime;
	//cout<<"Time after 100ms Sleep = "<<newTime<<", Difference = "<<diffTime<<endl;
	//time left is set to CONST DAY_LENGTH (seconds)
	unsigned secondsPassed = (diffTime)/1000; //seconds counting up
	int timeLeft = (DAY_LENGTH) - secondsPassed;
	
	lastTime = lastTime + newTime;



	//display day events to player
	if(iWeatherTemp==0) //weather is cold
		{
			cout<<"It's COLD today!"<<endl;
		}
		else if(iWeatherTemp==1) //weather is average
		{
			cout<<"It's AVERAGE today!"<<endl;
		}
		else if(iWeatherTemp==2) //weather is hot
		{
			cout<<"It's HOT today!"<<endl;
		}
	cout<<"time left in day: " <<timeLeft<<" second(s)"<<endl;
	cout<<endl;
	cout<<"Lemonade sold: "<<iLemonadeSold<<" cups"<<endl;
	if(fStockLemonade<=0)
	{
		cout<<"YOU HAVE RUN OUT OF LEMONADE"<<endl;
	}
	cout<<"Customers served: "<<iCustomerCount<<endl;
	cout<<"Lemons spoiled: " <<fLemonLoss<<endl;
	cout<<"Sugar lost to rats: " <<fSugarLoss<<" cups"<<endl;
	cout<<"Ice melted: " <<fIceLoss<<" cups"<<endl;
	cout<<"Lemonade stolen by hoodlums: "<<fLemonadeLoss<<" cups"<<endl;
	cout<<"Cash on hand: " <<fMoneyOnHand<<endl;
	
	
	//if dayTime greater than 10secs, exit
	if(secondsPassed==DAY_LENGTH)
	{
		//iCustomerCount
		system("cls");
		//INSERT WEATHER FAX HERE
		cout<<"You served "<<iCustomerCount<<" customers today!"<<endl;
		cout<<"You sold "<<iLemonadeSold<<" cups of Lemonade totalling $"<<(iLemonadeSold*sLemonadeRecipe.fLemonadePrice)<<endl;
		cout<<endl;
		cout<<"You lost "<<fLemonLoss<<" lemon(s) today"<<endl;
		cout<<"You lost "<<fSugarLoss<<" cup(s) of sugar today"<<endl;
		cout<<"You lost "<<fIceLoss<<" cup(s) of ice today"<<endl;
		cout<<fLemonadeLoss<<" cups of Lemonade were stolen"<<endl;
		cout<<fStockLemonade<<" cups of Lemonade were wasted at the end of the day"<<endl;
		cout<<endl;
		cout<<iCustomerCountCheap<<" customer(s) thought your lemonade was too expensive!"<<endl;
		cout<<iCustomerCountSweet<<" customer(s) thought your lemonade was too sweet!"<<endl;
		cout<<iCustomerCountSour<<" customer(s) thought your lemonade was too sour!"<<endl;

		system("pause");
		//TODO; display end of day report, clear var (lemonadestock, daily wastes)
		bDayCycle=false;
		lastTime = 0;
		iDaysPassed += 1;
		return 0;
		//clear values
		fStockLemonade=0;
		fLemonLoss=0;
		fSugarLoss=0;
		fIceLoss=0;
		iUpdateCounter=0;
		iWeatherCounter=0;
	}

}

}
