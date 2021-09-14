#include <iostream>
#include "Teams.h"
using namespace std;

void team::setTeamAmount(int num)
{
	teamAmoun = num;
}

int team::teamTurn()
{
	return turns % teamAmoun;
}

void team::incrementTurn()
{
	turns++;
}

int team::getTurn()
{
	return turns;
}

team::team()
{
	turns = 0;
}