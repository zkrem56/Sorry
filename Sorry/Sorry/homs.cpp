#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <Windows.h>
#include "Thomes.h"
using namespace std;

void homes::setTimes(int a)
{
	switch(a)
	{
	case 1:
		r1 = true;
		break;
	case 2:
		r2 = true;
		break;
	case 3:
		r3 = true;
		break;
	case 4:
		r4 = true;
		break;
	case 5:
		b1 = true;
		break;
	case 6:
		b2 = true;
		break;
	case 7:
		b3 = true;
		break;
	case 8:
		b4 = true;
		break;
	case 9:
		g1 = true;
		break;
	case 10:
		g2 = true;
		break;
	case 11:
		g3 = true;
		break;
	case 12:
		g4 = true;
		break;
	case 13:
		y1 = true;
		break;
	case 14:
		y2 = true;
		break;
	case 15:
		y3 = true;
		break;
	case 16:
		y4 = true;
		break;
	}
}

bool homes::getBord(int t, int p)
{
	if(t == 0)
	{
		switch(p)
		{
		case 0:
			return r1;
			break;
		case 1:
			return r2;
			break;
		case 2:
			return r3;
			break;
		case 3:
			return r4;
			break;
		}
	}
	else if(t == 1)
	{
		switch(p)
		{
		case 0:
			return b1;
			break;
		case 1:
			return b2;
			break;
		case 2:
			return b3;
			break;
		case 3:
			return b4;
			break;
		}
	}
	else if(t == 2)
	{
		switch(p)
		{
		case 0:
			return g1;
			break;
		case 1:
			return g2;
			break;
		case 2:
			return g3;
			break;
		case 3:
			return g4;
			break;
		}
	}
	else if(t == 3)
	{
		switch(p)
		{
		case 0:
			return y1;
			break;
		case 1:
			return y2;
			break;
		case 2:
			return y3;
			break;
		case 3:
			return y4;
			break;
		}
	}
}

void homes::setVars()
{
	r1 = false;
	r2 = false;
	r3 = false;
	r4 = false;
	b1 = false;
	b2 = false;
	b3 = false;
	b4 = false;
	g1 = false;
	g2 = false;
	g3 = false;
	g4 = false;
	y1 = false;
	y2 = false;
	y3 = false;
	y4 = false;
	rcount = 0;
	bcount = 0;
	gcount = 0;
	ycount = 0;
}

void homes::changeh(int t, int p)
{
	if(t == 0)
	{
		switch(p)
		{
		case 0:
			r1 = true;
			break;
		case 1:
			r2 = true;
			break;
		case 2:
			r3 = true;
			break;
		case 3:
			r4 = true;
			false;
		}
	}
	else if(t == 1)
	{
		switch(p)
		{
		case 0:
			b1 = true;
			break;
		case 1:
			b2 = true;
			break;
		case 2:
			b3 = true;
			break;
		case 3:
			b4 = true;
			break;
		}
	}
	else if(t == 2)
	{
		switch(p)
		{
		case 0:
			g1 = true;
			break;
		case 1:
			g2 = true;
			break;
		case 2:
			g3 = true;
			break;
		case 3:
			g4 = true;
			break;
		}
	}
	else if(t == 3)
	{
		switch(p)
		{
		case 0:
			y1 = true;
			break;
		case 1:
			y2 = true;
			break;
		case 2:
			y3 = true;
			break;
		case 3:
			y4 = true;
			break;
		}
	}
}

void homes::addCount(int a)
{
	if(a == 0)
		rcount++;
	else if(a == 1)
		bcount++;
	else if(a == 2)
		gcount++;
	else if(a == 3)
		ycount++;
}

int homes::getTcount(int t)
{
	if(t == 0)
		return rcount;
	else if(t == 1)
		return bcount;
	else if(t == 2)
		return gcount;
	else if(t == 3)
		return ycount;
}

homes::homes()
{
}