#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <Windows.h>
#include "Card.h"
using namespace std;

const int main = 4;
const int ones = 5;
void cards::drawCard()
{
	srand (time(NULL));

	card = rand() % 12 + 1;


		if(o == false && tw == false && th == false && fo == false && fi == false && se == false && ei == false && te == false && el == false && twe == false && so == false)
		{
			cout<<"Shuffling cards"<<endl;
			Sleep(1000);
			reShuffle();
		}
}

int cards::getCard()const
{
	return card;
}

//will increment the variable that keeps track of the cards
void cards::countCard(int i)
{
	switch(i)
	{
	case 1:
		one++;
		break;
	case 2:
		two++;
		break;
	case 3:
		three++;
		break;
	case 4:
		four++;
		break;
	case 5:
		five++;
		break;
	case 7:
		seven++;
		break;
	case 8:
		eight++;
		break;
	case 10:
		ten++;
		break;
	case 11:
		eleven++;
		break;
	case 12:
		tweleve++;
		break;
	default:
		sorry++;
		break;
	}
}

//will make sure that no card is drawn more than the amount of a certian type of card is allowed
bool cards::checkCard(int c)
{
	if(c == 1 && one == ones)
	{
		o = false;
		return false;
	}
	else if(c == 2 && two == main)
	{
		tw = false;
		return false;
	}
	else if(c == 3 && three == main)
	{
		th = false;
		return false;
	}
	else if(c == 4 && four == main)
	{
		fo = false;
		return false;
	}
	else if(c == 5 && five == main)
	{
		fi = false;
		return false;
	}
	else if(c == 7 && seven == main)
	{
		se = false;
		return false;
	}
	else if(c == 8 && eight == main)
	{
		ei = false;
		return false;
	}
	else if(c == 10 && ten == main)
	{
		te = false;
		return false;
	}
	else if(c == 11 && eleven == main)
	{
		el = false;
		return false;
	}
	else if(c == 12 && tweleve == main)
	{
		twe = false;
		return false;
	}
	else if((c == 6 || c == 9 || c == 0) && sorry == main)
	{
		so = false;
		return false;
	}
	else
		return true;
}

void cards::showSorry()
{
	cout<<"Sorry!!!!"<<endl;
	Sleep(500);
}

bool cards::getSO()
{
	return so;
}

void cards::setCardB()
{
	o = true;
	tw = true;
	th = true;
	fo = true;
	fi = true;
	se = true;
	ei = true;
	te = true;
	el = true;
	twe = true;
	so = true;
	one = 0;
	two = 0;
	three = 0;
	four = 0;
	five = 0;
	seven = 0;
	eight = 0;
	ten = 0;
	eleven = 0;
	tweleve = 0;
	sorry = 0;
}

void cards::reShuffle()
{
	setCardB();
}

void cards::showFS()
{
	cout<<"Friendly Sorry!!!"<<endl;
	Sleep(800);
}

cards::cards()
{
	card = 0;
}
