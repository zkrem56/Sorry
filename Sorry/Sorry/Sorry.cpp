#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>
#include <conio.h>
#include "Card.h"
#include "Teams.h"
#include "Thomes.h"
#include "SGraphics.h"
using namespace std;

struct teams
{
	int plyx;
	int plyy;
	bool pstart;
	bool phome;
	char plyPie;
};
const int Num = 16;
const int Num2 = 20;
const int homc = 5;
const int NineTeen = Num2 - 1;
string origGrid[Num][Num2], board[Num][Num2];
string name1, name2, name3, name4;
string tem1, tem2, tem3, tem4;
int ones = 0, two = 0, three = 0, four = 0, five = 0, seven = 0, eight = 0, ten = 0, eleven = 0, twelve = 0, srry = 0, x = 0, y = 0, computers = 0;
bool redt = false, bluet = false, yellowt = false, greent = false, redh = false, blueh = false, yellowh = false, greenh = false;
bool c1 = false, c2 = false, c3 = false, c4 = false;
bool ai = false, ac = false, comp1 = false, comp2 = false, comp3 = false, comp4 = false, adv = false;//adv = advance sorry
int redd = 0, greenn = 0, yelloww = 0, bluee = 0;
teams red[4], blue[4], yellow[4], green[4];
cards card1;
team team1;
homes home1;
sgraph graphs;

void sorry();//Is main driver method for the program
void runMethod();//Is the main recaller method for if the user wants to play the game again this method the method that is the beginning of the program
void plyAssignH(int, int);
void moveBackwards(int);//Moves the peices backwards
void resetCorners();//Will assign the corners of the board for moving and for regular so that the corners of the board look like corners
void reset();//Will reset all of the variables so that the user can play another game if they choose
void rules();//Says the rules for the game selected
void congradulations();//Congradulates team on winning the game and asks if they want to play again
void storeNames(int);//Will store the names of the players that are playing and not computers that are playing
void checkBoarders(int);
int randNum();
bool checkForComp(string);//Will return a boolean to see if there is a computer on a certain team
void endGame();//Will see if all four peices are at home
void moveHome(int, int);//Will move the pieces down the home stretch to home
void rStart(int, int);
void bStart(int, int);
void gStart(int, int);
void compNameAssign(int, int);
void yStart(int, int);
void assignTeamNames(int, int);//Will assign each team the name that the players enter
void resetBoarders();
bool friendlySrry(int);//Will see if one of the team members on a team hits another team member
void setconsolecolor(int, int);//Sets color of the program
void boardSetUp();//Sets up the amount of players if there is computers and which verson of the program they want to play
void playerBump();//Is the method that switches the players of the team that drew the sorry card with another member of another team
void assignTurn(int, int);//Will assign the turn for each team
void printGrid();//Will print the sorry board
bool checkSryy(int);//Will check to see if a member from one team bumps a member of another team back to start (only in Advanced version of program)
void setUpGrid();//Will setup the sorry board
void move(int);//Goes to the according methods whether a card is a 1, 2 or greater
void plySelect();//Player select which peice on his team that he wants to move
void plyAssign(int);//Will assign a peice from the player who drew a one or two outside there start
void teamSetup();//Sets up the teams and which teams are being used and the order of the teams.
void checkCard();//Makes sure that the card that is drawn is not out meaning that the amount of that type of card is still in the deck
void chooseTeam(int);//user will choose the team they want to be
void moveSpaces(int);//moves the peices forward
void teamInput(int);//sets up the team variables
string getNum();//Gets the numbers for the cards into strings

int main()
{
	runMethod();
	return 0;
}

void runMethod()
{
	int z = 0;
	boardSetUp();
	home1.setVars();
	card1.setCardB();

	if(computers == 0)
	{
		cout<<"Do you want the game to run on its own or do you manually want to play the game? (1 auto, 2 manual): ";
		cin>>z;
		if(z == 1)
			ai = true;
	}
	sorry();
}

void sorry()
{
		card1.drawCard();
		checkCard();
		if(card1.getCard() == 6 || card1.getCard() == 9 || card1.getCard() == 0 && card1.checkCard(card1.getCard()) == true)
		{
				playerBump();
				graphs.bigSrry();
		}
		else
		{
			if(card1.getCard() == 2)
			{
				for(int i = 0; i < 2; i++)
				{
					if(i == 1)
					{
						card1.drawCard();
						checkCard();
					}
					if(card1.getCard() == 6 || card1.getCard() == 9 || card1.getCard() == 0 && card1.checkCard(card1.getCard()) == true)
					{
						playerBump();
						graphs.bigSrry();
					}
					else
					{
						printGrid();
						plySelect();
					}
				}
			}
			else
			{
				printGrid();
				plySelect();
			}
		}
		team1.incrementTurn();
		Sleep(500);
		endGame();
	if(redh == true || blueh == true || greenh == true || yellowh == true)
	{
		printGrid();
		congradulations();
		return;
	}
	else
		sorry();
}

void setUpGrid()
{
	int num = 196;
	//a = - b = |
	char a = 196, b = 179, c = 218, d = 191, e = 192, f = 217;

	for (int i = 0; i < Num; i++)
	{
		origGrid[i][NineTeen] = b;
		origGrid[i][0] = b;
	}
	
	for (int i = 0; i < Num2; i++)
	{
		origGrid[0][i] = a;
		origGrid[Num - 1][i] = a;
	}
	
	for (int i = 1; i < Num-1; i++)
	{
		for (int n = 1; n < Num2-1; n++)
			origGrid[i][n] = a;
	}

	origGrid[0][0] = c;
	origGrid[0][Num2-1] = d;
	origGrid[Num-1][0] = e;
	origGrid[Num-1][Num2-1] = f;

	for (int i = 0; i < Num; i++)
	{
		for (int n = 0; n < Num2; n++)
			board[i][n] = origGrid[i][n];
	}
}

void printGrid()
{
	board[7][9] = getNum();
	for (int i = 0; i < Num; i++)
	{
		for (int n = 0; n < Num2; n++)
		{
			if(board[i][n] == "r")//makes r for red team the color red
				setconsolecolor(12, 7);
			else if(board[i][n] == "b")//makes b for blue team the color blue
				setconsolecolor(9, 7);
			else if(board[i][n] == "g")//makes g for green team the color green
				setconsolecolor(10, 7);
			else if(board[i][n] == "y")//makes y for yellow team the color yellow
				setconsolecolor(14, 7);
			else
				setconsolecolor(0,7);//defualt color for the board bright white
			resetCorners();
			cout << board[i][n];
		}
		cout << endl;
	}
}

void move(int ply)
{
	char a = 196;
	
	if(redt == true && redd == team1.teamTurn())
	{
		if(red[ply-1].pstart == true && (card1.getCard() == 1 || card1.getCard() == 2))
		{
				board[red[ply-1].plyy][red[ply-1].plyx] = a;
				if(ply-1 == 0 || ply-1 == 2)
					red[ply-1].plyy = 0;
				else
				{
					red[ply-1].plyy = 0;
					red[ply-1].plyx -= 1;
				}
				if (checkSryy(ply-1) == true)
					graphs.bigSrry();
				plyAssign(ply);
		}
		else if((red[ply-1].plyy == 0 && red[ply-1].plyx == 2) || red[ply-1].phome == true)
		{
			moveHome(ply-1,card1.getCard());
		}
		else if(card1.getCard() == 4 && red[ply-1].pstart == false)
			moveBackwards(ply);
		else if(card1.getCard() != 6 && card1.getCard() != 9 && red[ply-1].pstart == false)
			moveSpaces(ply);
	}
	else if(bluet == true && bluee == team1.teamTurn())
	{
		if(blue[ply-1].pstart == true && (card1.getCard() == 1 || card1.getCard() == 2))
		{
				board[blue[ply-1].plyy][blue[ply-1].plyx] = a;
				if(ply-1 == 0 || ply-1 == 2)
					blue[ply-1].plyx = 19;
				else
				{
					blue[ply-1].plyx = 19;
					blue[ply-1].plyy -= 1;
				}
				if (checkSryy(ply-1) == true)
					graphs.bigSrry();
				plyAssign(ply);
		}
		else if((blue[ply-1].plyy == 2 && blue[ply-1].plyx == Num2-1) || blue[ply-1].phome == true)
			moveHome(ply-1,card1.getCard());
		else if(card1.getCard() == 4 && blue[ply-1].pstart == false)
			moveBackwards(ply);
		else if(card1.getCard() != 6 && card1.getCard() != 9 && blue[ply-1].pstart == false)
			moveSpaces(ply);
	}
	else if(greent == true && greenn == team1.teamTurn())
	{
		if(green[ply-1].pstart == true && (card1.getCard() == 1 || card1.getCard() == 2))
		{
				board[green[ply-1].plyy][green[ply-1].plyx] = a;
				if(ply-1 == 0 || ply-1 == 2)
					green[ply-1].plyx = 0;
				else
				{
					green[ply-1].plyx = 0;
					green[ply-1].plyy -= 1;
				}
				if (checkSryy(ply-1) == true)
					graphs.bigSrry();
				plyAssign(ply);
		}
		else if((green[ply-1].plyy == 13 && green[ply-1].plyx == 0) || green[ply-1].phome == true)
			moveHome(ply-1,card1.getCard());
		else if(card1.getCard() == 4 && green[ply-1].pstart == false)
			moveBackwards(ply);
		else if(card1.getCard() != 6 && card1.getCard() != 9 && green[ply-1].pstart == false)
			moveSpaces(ply);
	}
	else if(yellowt == true && yelloww == team1.teamTurn())
	{
		if(yellow[ply-1].pstart == true && (card1.getCard() == 1 || card1.getCard() == 2))
		{
				board[yellow[ply-1].plyy][yellow[ply-1].plyx] = a;

				if(ply-1 == 0 || ply-1 == 2)
					yellow[ply-1].plyy = 15;
				else
				{
					yellow[ply-1].plyy = 15;
					yellow[ply-1].plyx += 1;
				}
				if (checkSryy(ply-1) == true)
					graphs.bigSrry();
				plyAssign(ply);
		}
		else if((yellow[ply-1].plyy == Num-1 && yellow[ply-1].plyx == 17) || yellow[ply-1].phome == true)
			moveHome(ply-1,card1.getCard());
		else if(card1.getCard() == 4 && yellow[ply-1].pstart == false)
			moveBackwards(ply);
		else if(card1.getCard() != 6 && card1.getCard() != 9 && yellow[ply-1].pstart == false)
			moveSpaces(ply);
	}
}

void teamSetup()
{
	//red team set up
	red[0].plyx = 4;
	red[0].plyy = 1;
	red[0].plyPie = 'r';
	red[0].phome = false;
	red[0].pstart = true;
	red[1].plyx = 5;
	red[1].plyy = 1;
	red[1].plyPie = 'r';
	red[1].phome = false;
	red[1].pstart = true;
	red[2].plyx = 4;
	red[2].plyy = 2;
	red[2].plyPie = 'r';
	red[2].phome = false;
	red[2].pstart = true;
	red[3].plyx = 5;
	red[3].plyy = 2;
	red[3].plyPie = 'r';
	red[3].phome = false;
	red[3].pstart = true;

	//Blue team set up
	blue[0].plyx = 18;
	blue[0].plyy = 4;
	blue[0].plyPie = 'b';
	blue[0].phome = false;
	blue[0].pstart = true;
	blue[1].plyx = 18;
	blue[1].plyy = 5;
	blue[1].plyPie = 'b';
	blue[1].phome = false;
	blue[1].pstart = true;
	blue[2].plyx = 17;
	blue[2].plyy = 4;
	blue[2].plyPie = 'b';
	blue[2].phome = false;
	blue[2].pstart = true;
	blue[3].plyx = 17;
	blue[3].plyy = 5;
	blue[3].plyPie = 'b';
	blue[3].phome = false;
	blue[3].pstart = true;

	//Green team setup
	green[0].plyx = 1;
	green[0].plyy = 10;
	green[0].plyPie = 'g';
	green[0].phome = false;
	green[0].pstart = true;
	green[1].plyx = 1;
	green[1].plyy = 11;
	green[1].plyPie = 'g';
	green[1].phome = false;
	green[1].pstart = true;
	green[2].plyx = 2;
	green[2].plyy = 10;
	green[2].plyPie = 'g';
	green[2].phome = false;
	green[2].pstart = true;
	green[3].plyx = 2;
	green[3].plyy = 11;
	green[3].plyPie = 'g';
	green[3].phome = false;
	green[3].pstart = true;

	//Yellow team setup
	yellow[0].plyx = 15;
	yellow[0].plyy = 14;
	yellow[0].plyPie = 'y';
	yellow[0].phome = false;
	yellow[0].pstart = true;
	yellow[1].plyx = 14;
	yellow[1].plyy = 14;
	yellow[1].plyPie = 'y';
	yellow[1].phome = false;
	yellow[1].pstart = true;
	yellow[2].plyx = 15;
	yellow[2].plyy = 13;
	yellow[2].plyPie = 'y';
	yellow[2].phome = false;
	yellow[2].pstart = true;
	yellow[3].plyx = 14;
	yellow[3].plyy = 13;
	yellow[3].plyPie = 'y';
	yellow[3].phome = false;
	yellow[3].pstart = true;
}

void teamInput(int n)
{
	char a = ' ';
	a = 179;
		if(yellowt == true)
		{
			board[yellow[0].plyy][yellow[0].plyx] = yellow[0].plyPie;
			board[yellow[1].plyy][yellow[1].plyx] = yellow[0].plyPie;
			board[yellow[2].plyy][yellow[2].plyx] = yellow[0].plyPie;
			board[yellow[3].plyy][yellow[3].plyx] = yellow[0].plyPie;
		}
		
		if(greent == true)
		{
			board[green[0].plyy][green[0].plyx] = green[0].plyPie;
			board[green[1].plyy][green[1].plyx] = green[0].plyPie;
			board[green[2].plyy][green[2].plyx] = green[0].plyPie;
			board[green[3].plyy][green[3].plyx] = green[0].plyPie;

		
		}
		if(bluet == true)
		{
			board[blue[0].plyy][blue[0].plyx] = blue[0].plyPie;
			board[blue[1].plyy][blue[1].plyx] = blue[0].plyPie;
			board[blue[2].plyy][blue[2].plyx] = blue[0].plyPie;
			board[blue[3].plyy][blue[3].plyx] = blue[0].plyPie;

		
		}
		if(redt == true)
		{
			board[red[0].plyy][red[0].plyx] = red[0].plyPie;
			board[red[1].plyy][red[1].plyx] = red[0].plyPie;
			board[red[2].plyy][red[2].plyx] = red[0].plyPie;
			board[red[3].plyy][red[3].plyx] = red[0].plyPie;
		}

		//red home
		for(int i = 1; i < 6; i++)
			board[i][2] = a;
		board[6][2] = 'x';
		board[6][1] = 'x';
		board[7][2] = 'x';
		board[7][1] = 'x';

		//blue home
		for(int i = 14; i < 19; i++)
			board[2][i] = a;

		board[2][13] = 'x';
		board[2][12] = 'x';
		board[1][13] = 'x';
		board[1][12] = 'x';

		//green home
		for(int i = 1; i < 6; i++)
			board[13][i] = a;
		board[13][6] = 'x';
		board[14][6] = 'x';
		board[13][7] = 'x';
		board[14][7] = 'x';
		//yellow home
		for(int i = 10; i < 15; i++)
			board[i][17] = a;
		board[9][17] = 'x';
		board[9][18] = 'x';
		board[8][17] = 'x';
		board[8][18] = 'x';
}

void boardSetUp()
{
	 int plyA = 0, c = 0, n = 0, q = 0, w = 0;//hold the amount of players

	setUpGrid();
	teamSetup();

	setconsolecolor(0, 7);
	cout<<"Welcome to the game of sorry do you want to play Advanced Sorry or Classic sorry? (0)Advance, (1)Classic: ";
	cin>>q;

	if(q == 0)
		adv = true;

	rules();

	cout<<"Enter (1)Two players, (2)Three players, (3)Four players: ";
	cin>>plyA;

	cout<<"Do you want to play with computers? (1 yes, 2 no): ";
	cin>>c;
		
	if(c == 1)
	{
		cout<<"How many computers do you want to play with?: ";
		cin>>n;

		if(n == 1)
			computers = 1;
		else if(n == 2)
			computers = 2;
		else if(n == 3)
			computers = 3;
		else if(n == 4)
			computers = 4;
		else
			computers = 0;
	}

	cout<<"Do you want to be able to see the card the computer drew? (1 yes, 2 no): ";
	cin>>w;

	if(w == 1)
		ac = true;

	team1.setTeamAmount(plyA+1);

	if (plyA == 1 && computers == 0)
	{
		storeNames(2);
		chooseTeam(2);
	}
	else if(plyA == 1 && computers == 1)
	{
		storeNames(1);
		compNameAssign(1, plyA);
		chooseTeam(2);
	}
	else if(plyA == 1 && computers == 2)
	{
		compNameAssign(2, plyA);
		chooseTeam(2);
	}
	else if (plyA == 2 && computers == 0)
	{
		storeNames(3);
		chooseTeam(3);
	}
	else if(plyA == 2 && computers == 1)
	{
		storeNames(2);
		compNameAssign(1, plyA);
		chooseTeam(3);
	}
	else if(plyA == 2 && computers == 2)
	{
		storeNames(1);
		compNameAssign(2, plyA);
		chooseTeam(3);
	}
	else if(plyA == 2 && computers == 3)
	{
		compNameAssign(3, plyA);
		chooseTeam(3);
	}
	else if (plyA == 3 && computers == 0)
	{
		storeNames(4);
		chooseTeam(4);
	}
	else if(plyA == 3 && computers == 1)
	{
		storeNames(3);
		compNameAssign(1, plyA);
		chooseTeam(4);
	}
	else if(plyA == 3 && computers == 2)
	{
		storeNames(2);
		compNameAssign(2, plyA);
		chooseTeam(4);
	}
	else if(plyA == 3 && computers == 3)
	{
		storeNames(1);
		compNameAssign(3, plyA);
		chooseTeam(4);
	}
	else if(plyA == 3 && computers == 4)
	{
		compNameAssign(4, plyA);
		chooseTeam(4);
	}
}

void plySelect()
{
	int piece  = 0;
	setconsolecolor(0, 7);
	if(yellowt == true && yelloww == team1.teamTurn())
	{
		cout<<"Team: "<<tem4<<" (color yellow)"<<endl
			<<"Game piece 1: Bottom right(1)"<<endl
			<<"Game piece 2: Bottom left(2)"<<endl
			<<"Game piece 3: Top right(3)"<<endl
			<<"Game piece 4: Top left(4)"<<endl
			<<"please select a piece you want move: ";
		if(ai == true || checkForComp(tem4) == true)
		{
			piece = randNum();
			cout<<piece<<endl;
			if(ac == false)
				Sleep(900);
			else
				system("pause");
		}
		else
			cin>>piece;
	}
	else if(greent == true && greenn == team1.teamTurn())
	{
		cout<<"Team: "<<tem3<<" (color green)"<<endl
			<<"Game piece 1: Top left(1)"<<endl
			<<"Game piece 2: Bottom left(2)"<<endl
			<<"Game piece 3: Top right(3)"<<endl
			<<"Game piece 4: Bottom right(4)"<<endl
			<<"please select a piece you want move: ";
		if(ai == true || checkForComp(tem3) == true)
		{
			piece = randNum();
			cout<<piece<<endl;
			if(ac == false)
				Sleep(900);
			else
				system("pause");
		}
		else
			cin>>piece;
	}
	else if(bluet == true && bluee == team1.teamTurn())
	{
		cout<<"Team: "<<tem2<<" (color blue)"<<endl
			<<"Game piece 1: Top right(1)"<<endl
			<<"Game piece 2: Bottom right(2)"<<endl
			<<"Game piece 3: Top left(3)"<<endl
			<<"Game piece 4: Bottom left(4)"<<endl
			<<"please select a piece you want move: ";
		if(ai == true || checkForComp(tem2) == true)
		{
			piece = randNum();
			cout<<piece<<endl;
			if(ac == false)
				Sleep(900);
			else
				system("pause");
		}
		else
			cin>>piece;
	}
	else if(redt == true && redd == team1.teamTurn())
	{
		cout<<"Team: "<<tem1<<" (color red)"<<endl
			<<"Game piece 1: Top left(1)"<<endl
			<<"Game piece 2: Top right(2)"<<endl
			<<"Game piece 3: Bottom left(3)"<<endl
			<<"Game piece 4: Bottom right(4)"<<endl
			<<"please select a piece you want move: ";
		if(ai == true || checkForComp(tem1) == true)
		{
			piece = randNum();
			cout<<piece<<endl;
			if(ac == false)
				Sleep(900);
			else
				system("pause");
		}
		else
			cin>>piece;
	}
	if(piece < 1 || piece > 4)
	{
		cout<<"Number out of range please enter a number that will be the piece that you move."<<endl;
			plySelect();
	}
	move(piece);
}

void plyAssign(int pie)
{
	if(redt == true && redd == team1.teamTurn())
	{
		if(red[pie-1].pstart == true)
		{
			red[pie-1].pstart = false;
			board[red[pie-1].plyy][red[pie-1].plyx] = red[0].plyPie;
		}
	}
	else if(bluet == true && bluee == team1.teamTurn())
	{
		if(blue[pie-1].pstart == true)
		{
			blue[pie-1].pstart = false;
			board[blue[pie-1].plyy][blue[pie-1].plyx] = blue[0].plyPie;
		}
	}
	else if(greent == true && greenn == team1.teamTurn())
	{
		if(green[pie-1].pstart == true)
		{
			green[pie-1].pstart = false;
			board[green[pie-1].plyy][green[pie-1].plyx] = green[0].plyPie;
		}
	}
	else if(yellowt == true && yelloww == team1.teamTurn())
	{
		if(yellow[pie-1].pstart == true)
		{
			yellow[pie-1].pstart = false;
			board[yellow[pie-1].plyy][yellow[pie-1].plyx] = yellow[0].plyPie;
		}
	}
}

string getNum()
{
	int n = card1.getCard();

	if(n == 1)
		return "1";
	else if(n == 2)
		return "2";
	else if(n == 3)
		return "3";
	else if(n == 4)
		return "4";
	else if(n == 5)
		return "5";
	else if(n == 7)
		return "7";
	else if(n == 8)
		return "8";
	else if(n == 10)
		return "10";
	else if(n == 11)
		return "11";
	else if(n == 12)
		return "12";
	else
		return "0";
}
/*
* moving left = 2
* moving right = 0
* moving up = 1
* moving down = 3
*/
void moveSpaces(int p)
{
	char a = 196, b = 179;

	if(redt == true && redd == team1.teamTurn())
	{
		for(int i = 0; i < card1.getCard(); i++)
		{
			if(adv == true && checkSryy(p-1) == true)
				graphs.bigSrry();
			else if(friendlySrry(p-1) == true)
			{
				card1.showFS();
				graphs.bigSrry();
			}

			if(red[p-1].plyx == 2 && red[p-1].plyy == 0)
				break;
			else if(red[p-1].plyx + 1 <= Num2-1 && red[p-1].plyy == 0)
			{
				board[red[p-1].plyy][red[p-1].plyx] = a;
				red[p-1].plyx ++;
				board[red[p-1].plyy][red[p-1].plyx] = red[0].plyPie;
			}
			else if(red[p-1].plyy - 1 >= 0 && red[p-1].plyx == 0)
			{
				board[red[p-1].plyy][red[p-1].plyx] = b;
				red[p-1].plyy --;
				board[red[p-1].plyy][red[p-1].plyx] = red[0].plyPie;
			}
			else if(red[p-1].plyx - 1 >= 0 && red[p-1].plyy == Num-1)
			{
				board[red[p-1].plyy][red[p-1].plyx] = a;
				red[p-1].plyx--;
				board[red[p-1].plyy][red[p-1].plyx] = red[0].plyPie;
			}
			else if(red[p-1].plyy + 1 <= Num-1 && red[p-1].plyx == Num2-1)
			{
				board[red[p-1].plyy][red[p-1].plyx] = b;
				red[p-1].plyy++;
				board[red[p-1].plyy][red[p-1].plyx] = red[0].plyPie;
			}

			if(adv == true && checkSryy(p-1) == true)
				graphs.bigSrry();
			else if(friendlySrry(p-1) == true)
			{
				card1.showFS();
				graphs.bigSrry();
			}
			
			checkBoarders(p-1);
			printGrid();
			Sleep(500);
		}
	}
	else if(bluet == true && bluee == team1.teamTurn())
	{
		for(int i = 0; i < card1.getCard(); i++)
		{
			
			if(adv == true && checkSryy(p-1) == true)
				graphs.bigSrry();
			else if(friendlySrry(p-1) == true)
			{
				card1.showFS();
				graphs.bigSrry();
			}

			if(blue[p-1].plyx == Num2-1 && blue[p-1].plyy == 2)
				break;
			else if(blue[p-1].plyx + 1 <= Num2-1 && blue[p-1].plyy == 0)
			{
				board[blue[p-1].plyy][blue[p-1].plyx] = a;
				blue[p-1].plyx ++;
				board[blue[p-1].plyy][blue[p-1].plyx] = blue[0].plyPie;
			}
			else if(blue[p-1].plyy - 1 >= 0 && blue[p-1].plyx == 0)
			{
				board[blue[p-1].plyy][blue[p-1].plyx] = b;
				blue[p-1].plyy --;
				board[blue[p-1].plyy][blue[p-1].plyx] = blue[0].plyPie;
			}
			else if(blue[p-1].plyx - 1 >= 0 && blue[p-1].plyy == Num-1)
			{
				board[blue[p-1].plyy][blue[p-1].plyx] = a;
				blue[p-1].plyx--;
				board[blue[p-1].plyy][blue[p-1].plyx] = blue[0].plyPie;
			}
			else if(blue[p-1].plyy + 1 <= Num-1 && blue[p-1].plyx == Num2-1)
			{
				board[blue[p-1].plyy][blue[p-1].plyx] = b;
				blue[p-1].plyy ++;
				board[blue[p-1].plyy][blue[p-1].plyx] = blue[0].plyPie;
			}
			if(adv == true && checkSryy(p-1) == true)
				graphs.bigSrry();
			else if(friendlySrry(p-1) == true)
			{
				card1.showFS();
				graphs.bigSrry();
			}
			
			checkBoarders(p-1);
			printGrid();
			Sleep(500);
		}
	}
	else if(greent == true && greenn == team1.teamTurn())
	{
		for(int i = 0; i < card1.getCard(); i++)
		{
			
			if(adv == true && checkSryy(p-1) == true)
				graphs.bigSrry();
			else if(friendlySrry(p-1) == true)
			{
				card1.showFS();
				graphs.bigSrry();
			}

			if(green[p-1].plyy == 13 && green[p-1].plyx == 0)
				break;
			else if(green[p-1].plyx + 1 <= Num2-1 && green[p-1].plyy == 0)
			{
				board[green[p-1].plyy][green[p-1].plyx] = a;
				green[p-1].plyx ++;
				board[green[p-1].plyy][green[p-1].plyx] = green[0].plyPie;
			}
			else if(green[p-1].plyy - 1 >= 0 && green[p-1].plyx == 0)
			{
				board[green[p-1].plyy][green[p-1].plyx] = b;
				green[p-1].plyy --;
				board[green[p-1].plyy][green[p-1].plyx] = green[0].plyPie;
			}
			else if(green[p-1].plyx - 1 >= 0 && green[p-1].plyy == Num-1)
			{
				board[green[p-1].plyy][green[p-1].plyx] = a;
				green[p-1].plyx--;
				board[green[p-1].plyy][green[p-1].plyx] = green[0].plyPie;
			}
			else if(green[p-1].plyy + 1 <= Num-1 && green[p-1].plyx == Num2-1)
			{
				board[green[p-1].plyy][green[p-1].plyx] = b;
				green[p-1].plyy ++;
				board[green[p-1].plyy][green[p-1].plyx] = green[0].plyPie;
			}
			if(adv == true && checkSryy(p-1) == true)
				graphs.bigSrry();
			else if(friendlySrry(p-1) == true)
			{
				card1.showFS();
				graphs.bigSrry();
			}
			checkBoarders(p-1);
			printGrid();
			Sleep(500);
		}
	}
	else if(yellowt == true && yelloww == team1.teamTurn())
	{
		for(int i = 0; i < card1.getCard(); i++)
		{
			
			if(adv == true && checkSryy(p-1) == true)
				graphs.bigSrry();
			else if(friendlySrry(p-1) == true)
			{
				card1.showFS();
				graphs.bigSrry();
			}

			if(yellow[p-1].plyy == Num-1 && yellow[p-1].plyx == 17)
				break;
			else if(yellow[p-1].plyx + 1 <= Num2-1 && yellow[p-1].plyy == 0)
			{
				board[yellow[p-1].plyy][yellow[p-1].plyx] = a;
				yellow[p-1].plyx ++;
				board[yellow[p-1].plyy][yellow[p-1].plyx] = yellow[0].plyPie;
			}
			else if(yellow[p-1].plyy - 1 >= 0 && yellow[p-1].plyx == 0)
			{
				board[yellow[p-1].plyy][yellow[p-1].plyx] = b;
				yellow[p-1].plyy --;
				board[yellow[p-1].plyy][yellow[p-1].plyx] = yellow[0].plyPie;
			}
			else if(yellow[p-1].plyx - 1 >= 0 && yellow[p-1].plyy == Num-1)
			{
				board[yellow[p-1].plyy][yellow[p-1].plyx] = a;
				yellow[p-1].plyx--;
				board[yellow[p-1].plyy][yellow[p-1].plyx] = yellow[0].plyPie;
			}
			else if(yellow[p-1].plyy + 1 <= Num-1 && yellow[p-1].plyx == Num2-1)
			{
				board[yellow[p-1].plyy][yellow[p-1].plyx] = b;
				yellow[p-1].plyy ++;
				board[yellow[p-1].plyy][yellow[p-1].plyx] = yellow[0].plyPie;
			}
			if(adv == true && checkSryy(p-1) == true)
				graphs.bigSrry();
			else if(friendlySrry(p-1) == true)
			{
				card1.showFS();
				graphs.bigSrry();
			}
			checkBoarders(p-1);
		
				printGrid();
				Sleep(500);
		}
	}

	if(checkSryy(p-1) == true)
	{
		graphs.bigSrry();
		Sleep(500);
		printGrid();
	}
}

void checkCard()
{
	int card = card1.getCard();
	do
	{
		card1.drawCard();
		card = card1.getCard();
	}while(card1.checkCard(card) == false);
	card1.countCard(card);
}

void chooseTeam(int a)
{
	int t = 1, select = 0;
	bool check = false;
	do
	{
		switch (t)
		{
		case 1:
			cout << "Team: " << name1 << " please enter the number for the color you want to be: " << endl;
			break;
		case 2:
			cout << "Team: " << name2 << " please enter the number for the color that you want to be: " << endl;
			break;
		case 3:
			cout << "Team: " << name3 << " please enter the number for the color that you want to be: " << endl;
			break;
		case 4:
			cout << "Team: " << name4 << " please enter the number for the color that you want to be: " << endl;
			break;
		}
		setconsolecolor(12, 7);//sets text color red
		cout<<"(1)Red"<<endl;
		setconsolecolor(9, 7);//sets text color blue
		cout<<"(2)Blue"<<endl;
		setconsolecolor(10, 7);//sets text color green
		cout<<"(3)Green"<<endl;
		setconsolecolor(14, 7);//sets tex color yellow
		cout<<"(4)Yellow"<<endl;
		setconsolecolor(0, 7);
		cout<<"Please select the color team you want to be: ";
		cin>>select;

		if (select == 1 && redt == false)
		{
			assignTeamNames(t, select);
			redt = true;
			check = true;
		}
		else if (select == 2 && bluet == false)
		{
			assignTeamNames(t, select);
			bluet = true;
			check = true;
		}
		else if (select == 3 && greent == false)
		{
			assignTeamNames(t, select);
			greent = true;
			check = true;
		}
		else if (select == 4 && yellowt == false)
		{
			assignTeamNames(t, select);
			yellowt = true;
			check = true;
		}

		if (check == true)
		{
			assignTurn(select, t);
			t++;
			check = false;
		}
		else
		{
			switch (select)
			{
			case 1:
				cout << "Red team has already been selected." << endl;
				break;
			case 2:
				cout << "Blue team has already been selected." << endl;
				break;
			case 3:
				cout << "Green team has already been selected." << endl;
				break;
			case 4:
				cout << "Yellow team has already been selected." << endl;
			}
		}
	}while(t <= a);
	teamInput(a);
}

void assignTurn(int a, int b)//a = the team being selected and b = the turn assigned to the team that is selected
{
	if(a == 1)
	{
		if(b == 1)
			redd = 0;
		else if(b == 2)
			redd = 1;
		else if(b == 3)
			redd = 2;
		else if(b == 4)
			redd = 3;
	}
	else if(a == 2)
	{
		if(b == 1)
			bluee = 0;
		else if(b == 2)
			bluee = 1;
		else if(b == 3)
			bluee = 2;
		else if(b == 4)
			bluee = 3;
	}
	else if(a == 4)
	{
		if(b == 1)
			yelloww = 0;
		else if(b == 2)
			yelloww = 1;
		else if(b == 3)
			yelloww = 2;
		else if(b == 4)
			yelloww = 3;
	}
	else if(a == 3)
	{
		if(b == 1)
			greenn = 0;
		else if(b == 2)
			greenn = 1;
		else if(b == 3)
			greenn = 2;
		else if(b == 4)
			greenn = 3;
	}
}

void moveBackwards(int p)
{
	char a = 196, b = 179;

	if(redt == true && redd == team1.teamTurn())
	{
		for(int i = 0; i < card1.getCard(); i++)
		{
			if(adv == true && checkSryy(p-1) == true)
				graphs.bigSrry();
			else if(friendlySrry(p-1) == true)
			{
				card1.showFS();
				graphs.bigSrry();
			}
			else if(red[p-1].plyx - 1 >= 0 && red[p-1].plyy == 0)
			{
				board[red[p-1].plyy][red[p-1].plyx] = a;
				red[p-1].plyx --;
				board[red[p-1].plyy][red[p-1].plyx] = red[0].plyPie;
			}
			else if(red[p-1].plyy + 1 <= Num-1 && red[p-1].plyx == 0)
			{
				board[red[p-1].plyy][red[p-1].plyx] = b;
				red[p-1].plyy ++;
				board[red[p-1].plyy][red[p-1].plyx] = red[0].plyPie;
			}
			else if(red[p-1].plyx + 1 <= Num2-1 && red[p-1].plyy == Num-1)
			{
				board[red[p-1].plyy][red[p-1].plyx] = a;
				red[p-1].plyx++;
				board[red[p-1].plyy][red[p-1].plyx] = red[0].plyPie;
			}
			else if(red[p-1].plyy - 1 >= 0 && red[p-1].plyx == Num2-1)
			{
				board[red[p-1].plyy][red[p-1].plyx] = b;
				red[p-1].plyy--;
				board[red[p-1].plyy][red[p-1].plyx] = red[0].plyPie;
			}

			if(adv == true && checkSryy(p-1) == true)
				graphs.bigSrry();
			else if(friendlySrry(p-1) == true)
			{
				card1.showFS();
				graphs.bigSrry();
			}

			checkBoarders(p-1);
			printGrid();
			Sleep(500);
		}
	}
	else if(bluet == true && bluee == team1.teamTurn())
	{
		for(int i = 0; i < card1.getCard(); i++)
		{
			if(adv == true && checkSryy(p-1) == true)
				graphs.bigSrry();
			else if(friendlySrry(p-1) == true)
			{
				card1.showFS();
				graphs.bigSrry();
			}
			else if(blue[p-1].plyx - 1 >= 0 && blue[p-1].plyy == 0)
			{
				board[blue[p-1].plyy][blue[p-1].plyx] = a;
				blue[p-1].plyx --;
				board[blue[p-1].plyy][blue[p-1].plyx] = blue[0].plyPie;
			}
			else if(blue[p-1].plyy + 1 <= Num-1 && blue[p-1].plyx == 0)
			{
				board[blue[p-1].plyy][blue[p-1].plyx] = b;
				blue[p-1].plyy ++;
				board[blue[p-1].plyy][blue[p-1].plyx] = blue[0].plyPie;
			}
			else if(blue[p-1].plyx + 1 <= Num2-1 && blue[p-1].plyy == Num-1)
			{
				board[blue[p-1].plyy][blue[p-1].plyx] = a;
				blue[p-1].plyx++;
				board[blue[p-1].plyy][blue[p-1].plyx] = blue[0].plyPie;
			}
			else if(blue[p-1].plyy - 1 >= 0 && blue[p-1].plyx == Num2-1)
			{
				board[blue[p-1].plyy][blue[p-1].plyx] = b;
				blue[p-1].plyy --;
				board[blue[p-1].plyy][blue[p-1].plyx] = blue[0].plyPie;
			}
			if(adv == true && checkSryy(p-1) == true)
				graphs.bigSrry();
			else if(friendlySrry(p-1) == true)
			{
				card1.showFS();
				graphs.bigSrry();
			}

			checkBoarders(p-1);
			printGrid();
			Sleep(500);
		}
	}
	else if(greent == true && greenn == team1.teamTurn())
	{
		for(int i = 0; i < card1.getCard(); i++)
		{
			if(adv == true && checkSryy(p-1) == true)
				graphs.bigSrry();
			else if(friendlySrry(p-1) == true)
			{
				card1.showFS();
				graphs.bigSrry();
			}
			else if(green[p-1].plyx - 1 >= 0 && green[p-1].plyy == 0)
			{
				board[green[p-1].plyy][green[p-1].plyx] = a;
				green[p-1].plyx --;
				board[green[p-1].plyy][green[p-1].plyx] = green[0].plyPie;
			}
			else if(green[p-1].plyy + 1 <= Num-1 && green[p-1].plyx == 0)
			{
				board[green[p-1].plyy][green[p-1].plyx] = b;
				green[p-1].plyy ++;
				board[green[p-1].plyy][green[p-1].plyx] = green[0].plyPie;
			}
			else if(green[p-1].plyx + 1 <= Num2-1 && green[p-1].plyy == Num-1)
			{
				board[green[p-1].plyy][green[p-1].plyx] = a;
				green[p-1].plyx++;
				board[green[p-1].plyy][green[p-1].plyx] = green[0].plyPie;
			}
			else if(green[p-1].plyy - 1 >= 0 && green[p-1].plyx == Num2-1)
			{
				board[green[p-1].plyy][green[p-1].plyx] = b;
				green[p-1].plyy --;
				board[green[p-1].plyy][green[p-1].plyx] = green[0].plyPie;
			}
			if(adv == true && checkSryy(p-1) == true)
				graphs.bigSrry();
			else if(friendlySrry(p-1) == true)
			{
				card1.showFS();
				graphs.bigSrry();
			}

			checkBoarders(p-1);
			printGrid();
			Sleep(500);
		}
	}
	else if(yellowt == true && yelloww == team1.teamTurn())
	{
		for(int i = 0; i < card1.getCard(); i++)
		{
			if(adv == true && checkSryy(p-1) == true)
				graphs.bigSrry();
			else if(friendlySrry(p-1) == true)
			{
				card1.showFS();
				graphs.bigSrry();
			}
			else if(yellow[p-1].plyx - 1 >= 0 && yellow[p-1].plyy == 0)
			{
				board[yellow[p-1].plyy][yellow[p-1].plyx] = a;
				yellow[p-1].plyx --;
				board[yellow[p-1].plyy][yellow[p-1].plyx] = yellow[0].plyPie;
			}
			else if(yellow[p-1].plyy + 1 <= Num-1 && yellow[p-1].plyx == 0)
			{
				board[yellow[p-1].plyy][yellow[p-1].plyx] = b;
				yellow[p-1].plyy ++;
				board[yellow[p-1].plyy][yellow[p-1].plyx] = yellow[0].plyPie;
			}
			else if(yellow[p-1].plyx + 1 <= Num2-1 && yellow[p-1].plyy == Num-1)
			{
				board[yellow[p-1].plyy][yellow[p-1].plyx] = a;
				yellow[p-1].plyx++;
				board[yellow[p-1].plyy][yellow[p-1].plyx] = yellow[0].plyPie;
			}
			else if(yellow[p-1].plyy - 1 >= 0 && yellow[p-1].plyx == Num2-1)
			{
				board[yellow[p-1].plyy][yellow[p-1].plyx] = b;
				yellow[p-1].plyy --;
				board[yellow[p-1].plyy][yellow[p-1].plyx] = yellow[0].plyPie;
			}
			if(adv == true && checkSryy(p-1) == true)
				graphs.bigSrry();
			else if(friendlySrry(p-1) == true)
			{
				card1.showFS();
				graphs.bigSrry();
			}

			checkBoarders(p-1);
			printGrid();
			Sleep(500);
		}
	}

	if(checkSryy(p-1) == true)
		graphs.bigSrry();
}

void setconsolecolor(int tc, int bgc)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (tc + (bgc * 16)));
}

void resetBoarders()
{
	char a = 196, b = 179;
	if(redt == true && redd == team1.teamTurn())
	{
		for(int i = 0; i < 4; i++)
		{
			if(red[i].plyx == 0 || red[i].plyx == Num2-1)
			{
					board[red[i].plyy][red[i].plyx] = b;
					break;
			}
			else if(red[i].plyy == 0 || red[i].plyy == Num-1)
			{
					board[red[i].plyy][red[i].plyx] = a;
					break;
			}
		}
	}
	else if(bluet == true && bluee == team1.teamTurn())
	{
		for(int i = 0; i < 4; i++)
		{
			if(blue[i].plyx == 0 || blue[i].plyx == Num2-1)
			{
				board[blue[i].plyy][blue[i].plyx] = b;
				break;
			}
			else if(blue[i].plyy == 0 || blue[i].plyy == Num-1)
			{
				board[blue[i].plyy][blue[i].plyx] = a;
				break;
			}
		}
	}
	else if(greent == true && greenn == team1.teamTurn())
	{
		for(int i = 0; i < 4; i++)
		{
			if(green[i].plyx == 0 || green[i].plyx == Num2-1)
			{
				board[green[i].plyy][green[i].plyx] = b;
				break;
			}
			else if(green[i].plyy == 0 || green[i].plyy == Num-1)
			{
				board[green[i].plyy][green[i].plyx] = a;
				break;
			}
		}
	}
	else if(yellowt == true && yelloww == team1.teamTurn())
	{
		for(int i = 0; i < 4; i++)
		{
			if(yellow[i].plyx == 0 || yellow[i].plyx == Num2-1)
			{
				board[yellow[i].plyy][yellow[i].plyx] = b;
				break;
			}
			else if(yellow[i].plyy == 0 || yellow[i].plyy == Num-1)
			{
				board[yellow[i].plyy][yellow[i].plyx] = a;
				break;
			}
		}
	}
}

void resetCorners()
{
	char c = 218, d = 191, e = 192, f = 217;
	for(int i = 0; i < 4; i++)
	{
		if(red[i].pstart == false || blue[i].pstart == false || green[i].pstart == false || yellow[i].pstart == false)
		{
			if(board[0][0] != "r" && board[0][0] != "b" && board[0][0] != "g" && board[0][0] != "y")
				board[0][0] = c;
			if(board[0][Num2-1] != "r" && board[0][Num2-1] != "b" && board[0][Num2-1] != "g" && board[0][Num2-1] != "y")
				board[0][Num2-1] = d;
			if(board[Num-1][0] != "r" && board[Num-1][0] != "b" && board[Num-1][0] != "g" && board[Num-1][0] != "y")
				board[Num-1][0] = e;
			if(board[Num-1][Num2-1] != "r" && board[Num-1][Num2-1] != "b" && board[Num-1][Num2-1] != "g" && board[Num-1][Num2-1] != "y")
				board[Num-1][Num2-1] = f;
		}
	}
}

/*Key
Blue team = 1
Green team = 2
Yellow team = 3
Red Team = 0
*/
bool checkSryy(int t)
{
	for(int i = 0; i < 4; i++)
	{
		//red, blue, green, yellow
		if(redt == true && bluet == true && greent == true && yellowt == true)
		{
			//red team
			if(redd == team1.teamTurn())
			{
				if((red[t].plyx == blue[i].plyx) && (red[t].plyy == blue[i].plyy))
				{
					rStart(1,i);
					return true;
				}
				else if((red[t].plyx == green[i].plyx) && (red[t].plyy == green[i].plyy))
				{
					rStart(2,i);
					return true;
				}
				else if((red[t].plyx == yellow[i].plyx) && (red[t].plyy == yellow[i].plyy))
				{
					rStart(3,i);
					return true;
				}
			}
			//blue team
			else if(bluee == team1.teamTurn())
			{
				if((blue[t].plyx == red[i].plyx) && (blue[t].plyy == red[i].plyy))
				{
					bStart(0,i);
					return true;
				}
				else if((blue[t].plyx == green[i].plyx) && (blue[t].plyy == green[i].plyy))
				{
					bStart(2,i);
					return true;
				}
				else if((blue[t].plyx == yellow[i].plyx) && (blue[t].plyy == yellow[i].plyy))
				{
					bStart(3,i);
					return true;
				}
			}
			//green team
			else if(greenn == team1.teamTurn())
			{
				if((green[t].plyx == red[i].plyx) && (green[t].plyy == red[i].plyy))
				{
					gStart(0,i);
					return true;
				}
				else if((green[t].plyx == blue[i].plyx) && (green[t].plyy == blue[i].plyy))
				{
					gStart(1,i);
					return true;
				}
				else if((green[t].plyx == yellow[i].plyx) && (green[t].plyy == yellow[i].plyy))
				{
					gStart(3,i);
					return true;
				}
			}
			//yellow team
			else if(yelloww == team1.teamTurn())
			{
				if((yellow[t].plyx == red[i].plyx) && (yellow[t].plyy == red[i].plyy))
				{
					yStart(0,i);
					return true;
				}
				else if((yellow[t].plyx == blue[i].plyx) && (yellow[t].plyy == blue[i].plyy))
				{
					yStart(1,i);
					return true;
				}
				else if((yellow[t].plyx == green[i].plyx) && (yellow[t].plyy == green[i].plyy))
				{
					yStart(2,i);
					return true;
				}
			}
		}
		//red, blue, green
		else if(redt == true && bluet == true && greent == true)
		{
			//red team
			if(redd == team1.teamTurn())
			{
				if((red[t].plyx == blue[i].plyx) && (red[t].plyy == blue[i].plyy))
				{
					rStart(1,i);
					return true;
				}
				else if((red[t].plyx == green[i].plyx) && (red[t].plyy == green[i].plyy))
				{
					rStart(2,i);
					return true;
				}
			}
			//blue team
			else if(bluee == team1.teamTurn())
			{
				if((blue[t].plyx == red[i].plyx) && (blue[t].plyy == red[i].plyy))
				{
					bStart(0,i);
					return true;
				}
				else if((blue[t].plyx == green[i].plyx) && (blue[t].plyy == green[i].plyy))
				{
					bStart(2,i);
					return true;
				}
			}
			//green team
			else if(greenn == team1.teamTurn())
			{
				if((green[t].plyx == red[i].plyx) && (green[t].plyy == red[i].plyy))
				{
					gStart(0,i);
					return true;
				}
				else if((green[t].plyx == blue[i].plyx) && (green[t].plyy == blue[i].plyy))
				{
					gStart(1,i);
					return true;
				}
			}
		}
		//red, blue, yellow
		else if(redt == true && bluet == true && yellowt == true)
		{
			//red team
			if(redd == team1.teamTurn())
			{
				if((red[t].plyx == blue[i].plyx) && (red[t].plyy == blue[i].plyy))
				{
					rStart(1,i);
					return true;
				}
				else if((red[t].plyx == yellow[i].plyx) && (red[t].plyy == yellow[i].plyy))
				{
					rStart(3,i);
					return true;
				}
			}
			//blue team
			else if(bluee == team1.teamTurn())
			{
				if((blue[t].plyx == red[i].plyx) && (blue[t].plyy == red[i].plyy))
				{
					bStart(0,i);
					return true;
				}
				else if((blue[t].plyx == yellow[i].plyx) && (blue[t].plyy == yellow[i].plyy))
				{
					bStart(3,i);
					return true;
				}
			}
			//yellow team
			else if(yelloww == team1.teamTurn())
			{
				if((yellow[t].plyx == red[i].plyx) && (yellow[t].plyy == red[i].plyy))
				{
					yStart(0,i);
					return true;
				}
				else if((yellow[t].plyx == blue[i].plyx) && (yellow[t].plyy == blue[i].plyy))
				{
					yStart(1,i);
					return true;
				}
			}
		}
		//red, green, yellow
		else if(redt == true && greent == true && yellowt == true)
		{
			//red team
			if(redd == team1.teamTurn())
			{
				if((red[t].plyx == green[i].plyx) && (red[t].plyy == green[i].plyy))
				{
					rStart(2,i);
					return true;
				}
				else if((red[t].plyx == yellow[i].plyx) && (red[t].plyy == yellow[i].plyy))
				{
					rStart(3,i);
					return true;
				}
			}
			//green team
			else if(greenn == team1.teamTurn())
			{
				if((green[t].plyx == red[i].plyx) && (green[t].plyy == red[i].plyy))
				{
					gStart(0,i);
					return true;
				}
				else if((green[t].plyx == yellow[i].plyx) && (green[t].plyy == yellow[i].plyy))
				{
					gStart(3,i);
					return true;
				}
			}
			//yellow team
			else if(yelloww == team1.teamTurn())
			{
				if((yellow[t].plyx == red[i].plyx) && (yellow[t].plyy == red[i].plyy))
				{
					yStart(0,i);
					return true;
				}
				else if((yellow[t].plyx == green[i].plyx) && (yellow[t].plyy == green[i].plyy))
				{
					yStart(2,i);
					return true;
				}
			}
		}
		//blue, green and yellow
		else if(bluet == true && greent == true && yellowt == true)
		{
			//blue team
			if(bluee == team1.teamTurn())
			{
				if((blue[t].plyx == green[i].plyx) && (blue[t].plyy == green[i].plyy))
				{
					bStart(2,i);
					return true;
				}
				else if((blue[t].plyx == yellow[i].plyx) && (blue[t].plyy == yellow[i].plyy))
				{
					bStart(3,i);
					return true;
				}
			}
			//green team
			else if(greenn == team1.teamTurn())
			{
				if((green[t].plyx == blue[i].plyx) && (green[t].plyy == blue[i].plyy))
				{
					gStart(1,i);
					return true;
				}
				else if((green[t].plyx == yellow[i].plyx) && (green[t].plyy == yellow[i].plyy))
				{
					gStart(3,i);
					return true;
				}
			}
			//yellow team
			else if(yelloww == team1.teamTurn())
			{
				if((yellow[t].plyx == blue[i].plyx) && (yellow[t].plyy == blue[i].plyy))
				{
					yStart(1,i);
					return true;
				}
				else if((yellow[t].plyx == green[i].plyx) && (yellow[t].plyy == green[i].plyy))
				{
					yStart(2,i);
					return true;
				}
			}
		}
		//blue and yellow
		else if(bluet == true && yellowt == true)
		{
			//blue team
			if(bluee == team1.teamTurn())
			{
				if((blue[t].plyx == yellow[i].plyx) && (blue[t].plyy == yellow[i].plyy))
				{
					bStart(3,i);
					return true;
				}
			}
			//yellow team
			else if(yelloww == team1.teamTurn())
			{
				if((yellow[t].plyx == blue[i].plyx) && (yellow[t].plyy == blue[i].plyy))
				{
					yStart(1,i);
					return true;
				}
			}
		}
		//blue and green
		else if(bluet == true && greent == true)
		{
			//blue team
			if(bluee == team1.teamTurn())
			{
				if((blue[t].plyx == green[i].plyx) && (blue[t].plyy == green[i].plyy))
				{
					bStart(2,i);
					return true;
				}
			}
			//green team
			else if(greenn == team1.teamTurn())
			{
				if((green[t].plyx == blue[i].plyx) && (green[t].plyy == blue[i].plyy))
				{
					gStart(1,i);
					return true;
				}
			}
		}
		//green and yellow
		else if(greent == true && yellowt == true)
		{
			//green team
			if(greenn == team1.teamTurn())
			{
				if((green[t].plyx == yellow[i].plyx) && (green[t].plyy == yellow[i].plyy))
				{
					gStart(3,i);
					return true;
				}
			}
			//yellow team
			else if(yelloww == team1.teamTurn())
			{
				if((yellow[t].plyx == green[i].plyx) && (yellow[t].plyy == green[i].plyy))
				{
					yStart(2,i);
					return true;
				}
			}
		}
		//green and red
		else if(greent == true && redt == true)
		{
			//green team
			if(greenn == team1.teamTurn())
			{
				if((green[t].plyx == red[i].plyx) && (green[t].plyy == red[i].plyy))
				{
					gStart(0,i);
					return true;
				}
			}
			//red team
			else if(redd == team1.teamTurn())
			{
				if((red[t].plyx == green[i].plyx) && (red[t].plyy == green[i].plyy))
				{
					rStart(2,i);
					return true;
				}
			}
		}
		//red and yellow
		else if(redt == true && yellowt == true)
		{
			//red team
			if(redd == team1.teamTurn())
			{
				if((red[t].plyx == yellow[i].plyx) && (red[t].plyy == yellow[i].plyy))
				{
					rStart(3,i);
					return true;
				}
			}
			//yellow team
			else if(yelloww == team1.teamTurn())
			{
				if((yellow[t].plyx == red[i].plyx) && (yellow[t].plyy == red[i].plyy))
				{
					yStart(0,i);
					return true;
				}
			}
		}
		//red and blue
		else if(redt == true && bluet == true)
		{
			//red team
			if(redd == team1.teamTurn())
			{
				if((red[t].plyx == blue[i].plyx) && (red[t].plyy == blue[i].plyy))
				{
					rStart(1,i);
					return true;
				}
			}
			//blue team
			else if(bluee == team1.teamTurn())
			{
				if((blue[t].plyx == red[i].plyx) && (blue[t].plyy == red[i].plyy))
				{
					bStart(0,i);
					return true;
				}
			}
		}
	}

	return false;
}

void rStart(int t, int p)
{
	if(bluet == true && yellowt == true && greent == true)//with the all teams
	{
		if(t == 1)//blue team
		{
			switch(p)
			{
				case 0:
					blue[0].plyx = 18;
					blue[0].plyy = 4;
					board[blue[0].plyy][blue[0].plyx] = 'b';
					blue[0].pstart = true;
					break;
				case 1:
					blue[1].plyx = 18;
					blue[1].plyy = 5;
					board[blue[1].plyy][blue[1].plyx] = 'b';
					blue[1].pstart = true;
					break;
				case 2:
					blue[2].plyx = 17;
					blue[2].plyy = 4;
					board[blue[2].plyy][blue[2].plyx] = 'b';
					blue[2].pstart = true;
					break;
				case 3:
					blue[3].plyx = 17;
					blue[3].plyy = 5;
					board[blue[3].plyy][blue[2].plyx] = 'b';
					blue[3].pstart = true;
					break;
			}
		}
		else if(t == 2)//green team
		{
			switch(p)
			{
				case 0:
					green[0].plyx = 1;
					green[0].plyy = 10;
					board[green[0].plyy][green[0].plyx] = 'g';
					green[0].pstart = true;
					break;
				case 1:
					green[1].plyx = 1;
					green[1].plyy = 11;
					board[green[1].plyy][green[1].plyx] = 'g';
					green[1].pstart = true;
					break;
				case 2:
					green[2].plyx = 2;
					green[2].plyy = 10;
					board[green[2].plyy][green[2].plyx] = 'g';
					green[2].pstart = true;
					break;
				case 3:
					green[3].plyx = 2;
					green[3].plyy = 11;
					board[green[3].plyy][green[3].plyx] = 'g';
					green[3].pstart = true;
					break;
			}
		}
		else if(t == 3)//yellow team
		{
			switch(p)
			{
				case 0:
					yellow[0].plyx = 15;
					yellow[0].plyy = 14;
					board[yellow[0].plyy][yellow[0].plyx] = 'y';
					yellow[0].pstart = true;
					break;
				case 1:
					yellow[1].plyx = 14;
					yellow[1].plyy = 14;
					board[yellow[1].plyy][yellow[1].plyx] = 'y';
					yellow[1].pstart = true;
					break;
				case 2:
					yellow[2].plyx = 15;
					yellow[2].plyy = 13;
					board[yellow[2].plyy][yellow[2].plyx] = 'y';
					yellow[2].pstart = true;
					break;
				case 3:
					yellow[3].plyx = 14;
					yellow[3].plyy = 13;
					board[yellow[3].plyy][yellow[3].plyx] = 'y';
					yellow[3].pstart = true;
					break;
			}
		}
	}
	else if(bluet == true && greent == true)//for g,b and r teams
	{
		if(t == 1)
		{
			switch(p)
			{
				case 0:
					blue[0].plyx = 18;
					blue[0].plyy = 4;
					board[blue[0].plyy][blue[0].plyx] = 'b';
					blue[0].pstart = true;
					break;
				case 1:
					blue[1].plyx = 18;
					blue[1].plyy = 5;
					board[blue[1].plyy][blue[1].plyx] = 'b';
					blue[1].pstart = true;
					break;
				case 2:
					blue[2].plyx = 17;
					blue[2].plyy = 4;
					board[blue[2].plyy][blue[2].plyx] = 'b';
					blue[2].pstart = true;
					break;
				case 3:
					blue[3].plyx = 17;
					blue[3].plyy = 5;
					board[blue[3].plyy][blue[2].plyx] = 'b';
					blue[3].pstart = true;
					break;
			}
		}
		else if(t == 2)
		{
			switch(p)
			{
				case 0:
					green[0].plyx = 1;
					green[0].plyy = 10;
					board[green[0].plyy][green[0].plyx] = 'g';
					green[0].pstart = true;
					break;
				case 1:
					green[1].plyx = 1;
					green[1].plyy = 11;
					board[green[1].plyy][green[1].plyx] = 'g';
					green[1].pstart = true;
					break;
				case 2:
					green[2].plyx = 2;
					green[2].plyy = 10;
					board[green[2].plyy][green[2].plyx] = 'g';
					green[2].pstart = true;
					break;
				case 3:
					green[3].plyx = 2;
					green[3].plyy = 11;
					board[green[3].plyy][green[3].plyx] = 'g';
					green[3].pstart = true;
					break;
			}
		}
	}
	else if(bluet == true && yellowt == true)//b,y and r teams
	{
		if(t == 1)
		{
			switch(p)
			{
				case 0:
					blue[0].plyx = 18;
					blue[0].plyy = 4;
					board[blue[0].plyy][blue[0].plyx] = 'b';
					blue[0].pstart = true;
					break;
				case 1:
					blue[1].plyx = 18;
					blue[1].plyy = 5;
					board[blue[1].plyy][blue[1].plyx] = 'b';
					blue[1].pstart = true;
					break;
				case 2:
					blue[2].plyx = 17;
					blue[2].plyy = 4;
					board[blue[2].plyy][blue[2].plyx] = 'b';
					blue[2].pstart = true;
					break;
				case 3:
					blue[3].plyx = 17;
					blue[3].plyy = 5;
					board[blue[3].plyy][blue[2].plyx] = 'b';
					blue[3].pstart = true;
					break;
			}
		}
		else if(t == 3)
		{
			switch(p)
			{
				case 0:
					yellow[0].plyx = 15;
					yellow[0].plyy = 14;
					board[yellow[0].plyy][yellow[0].plyx] = 'y';
					yellow[0].pstart = true;
					break;
				case 1:
					yellow[1].plyx = 14;
					yellow[1].plyy = 14;
					board[yellow[1].plyy][yellow[1].plyx] = 'y';
					yellow[1].pstart = true;
					break;
				case 2:
					yellow[2].plyx = 15;
					yellow[2].plyy = 13;
					board[yellow[2].plyy][yellow[2].plyx] = 'y';
					yellow[2].pstart = true;
					break;
				case 3:
					yellow[3].plyx = 14;
					yellow[3].plyy = 13;
					board[yellow[3].plyy][yellow[3].plyx] = 'y';
					yellow[3].pstart = true;
					break;
			}
		}
	}
	else if(greent == true && yellowt == true)//r,g and y teams
	{
		if(t == 2)
		{
			switch(p)
			{
				case 0:
					green[0].plyx = 1;
					green[0].plyy = 10;
					board[green[0].plyy][green[0].plyx] = 'g';
					green[0].pstart = true;
					break;
				case 1:
					green[1].plyx = 1;
					green[1].plyy = 11;
					board[green[1].plyy][green[1].plyx] = 'g';
					green[1].pstart = true;
					break;
				case 2:
					green[2].plyx = 2;
					green[2].plyy = 10;
					board[green[2].plyy][green[2].plyx] = 'g';
					green[2].pstart = true;
					break;
				case 3:
					green[3].plyx = 2;
					green[3].plyy = 11;
					board[green[3].plyy][green[3].plyx] = 'g';
					green[3].pstart = true;
					break;
			}
		}
		else if(t == 3)
		{
			switch(p)
			{
				case 0:
					yellow[0].plyx = 15;
					yellow[0].plyy = 14;
					board[yellow[0].plyy][yellow[0].plyx] = 'y';
					yellow[0].pstart = true;
					break;
				case 1:
					yellow[1].plyx = 14;
					yellow[1].plyy = 14;
					board[yellow[1].plyy][yellow[1].plyx] = 'y';
					yellow[1].pstart = true;
					break;
				case 2:
					yellow[2].plyx = 15;
					yellow[2].plyy = 13;
					board[yellow[2].plyy][yellow[2].plyx] = 'y';
					yellow[2].pstart = true;
					break;
				case 3:
					yellow[3].plyx = 14;
					yellow[3].plyy = 13;
					board[yellow[3].plyy][yellow[3].plyx] = 'y';
					yellow[3].pstart = true;
					break;
			}
		}
	}
	else if(bluet == true)//b and r teams
	{
		switch(p)
			{
				case 0:
					blue[0].plyx = 18;
					blue[0].plyy = 4;
					board[blue[0].plyy][blue[0].plyx] = 'b';
					blue[0].pstart = true;
					break;
				case 1:
					blue[1].plyx = 18;
					blue[1].plyy = 5;
					board[blue[1].plyy][blue[1].plyx] = 'b';
					blue[1].pstart = true;
					break;
				case 2:
					blue[2].plyx = 17;
					blue[2].plyy = 4;
					board[blue[2].plyy][blue[2].plyx] = 'b';
					blue[2].pstart = true;
					break;
				case 3:
					blue[3].plyx = 17;
					blue[3].plyy = 5;
					board[blue[3].plyy][blue[2].plyx] = 'b';
					blue[3].pstart = true;
					break;
			}
	}
	else if(yellowt == true)//y and r teams
	{
		switch(p)
			{
				case 0:
					yellow[0].plyx = 15;
					yellow[0].plyy = 14;
					board[yellow[0].plyy][yellow[0].plyx] = 'y';
					yellow[0].pstart = true;
					break;
				case 1:
					yellow[1].plyx = 14;
					yellow[1].plyy = 14;
					board[yellow[1].plyy][yellow[1].plyx] = 'y';
					yellow[1].pstart = true;
					break;
				case 2:
					yellow[2].plyx = 15;
					yellow[2].plyy = 13;
					board[yellow[2].plyy][yellow[2].plyx] = 'y';
					yellow[2].pstart = true;
					break;
				case 3:
					yellow[3].plyx = 14;
					yellow[3].plyy = 13;
					board[yellow[3].plyy][yellow[3].plyx] = 'y';
					yellow[3].pstart = true;
					break;
			}
	}
	else if(greent == true)//g and r teams
	{
		switch(p)
		{
			case 0:
					green[0].plyx = 1;
					green[0].plyy = 10;
					board[green[0].plyy][green[0].plyx] = 'g';
					green[0].pstart = true;
					break;
			case 1:
					green[1].plyx = 1;
					green[1].plyy = 11;
					board[green[1].plyy][green[1].plyx] = 'g';
					green[1].pstart = true;
					break;
			case 2:
					green[2].plyx = 2;
					green[2].plyy = 10;
					board[green[2].plyy][green[2].plyx] = 'g';
					green[2].pstart = true;
					break;
			case 3:
					green[3].plyx = 2;
					green[3].plyy = 11;
					board[green[3].plyy][green[3].plyx] = 'g';
					green[3].pstart = true;
					break;
				
		}
	}
	
}

void bStart(int t, int p)
{
	if(redt == true && yellowt == true && greent == true)//for all teams
	{
		//red team
		if(t == 0)
		{
			switch(p)
			{
				case 0:
					red[0].plyx = 4;
					red[0].plyy = 1;
					board[red[0].plyy][red[0].plyx] = 'r';
					red[0].pstart = true;
					break;
				case 1:
					red[1].plyx = 5;
					red[1].plyy = 1;
					board[red[1].plyy][red[1].plyx] = 'r';
					red[1].pstart = true;
					break;
				case 2:
					red[2].plyx = 4;
					red[2].plyy = 2;
					board[red[2].plyy][red[2].plyx] = 'r';
					red[2].pstart = true;
					break;
				case 3:
					red[3].plyx = 5;
					red[3].plyy = 2;
					board[red[3].plyy][red[3].plyx] = 'r';
					red[3].pstart = true;
					break;
			}
		}
		//green Team
		else if(t == 2)
		{
			switch(p)
			{
				case 0:
					green[0].plyx = 1;
					green[0].plyy = 10;
					board[green[0].plyy][green[0].plyx] = 'g';
					green[0].pstart = true;
					break;
				case 1:
					green[1].plyx = 1;
					green[1].plyy = 11;
					board[green[1].plyy][green[1].plyx] = 'g';
					green[1].pstart = true;
					break;
				case 2:
					green[2].plyx = 2;
					green[2].plyy = 10;
					board[green[2].plyy][green[2].plyx] = 'g';
					green[2].pstart = true;
					break;
				case 3:
					green[3].plyx = 2;
					green[3].plyy = 11;
					board[green[3].plyy][green[3].plyx] = 'g';
					green[3].pstart = true;
					break;
			}
		}
		//yellow team
		else if(t == 3)
		{
			switch(p)
			{
				case 0:
					yellow[0].plyx = 15;
					yellow[0].plyy = 14;
					board[yellow[0].plyy][yellow[0].plyx] = 'y';
					yellow[0].pstart = true;
					break;
				case 1:
					yellow[1].plyx = 14;
					yellow[1].plyy = 14;
					board[yellow[1].plyy][yellow[1].plyx] = 'y';
					yellow[1].pstart = true;
					break;
				case 2:
					yellow[2].plyx = 15;
					yellow[2].plyy = 13;
					board[yellow[2].plyy][yellow[2].plyx] = 'y';
					yellow[2].pstart = true;
					break;
				case 3:
					yellow[3].plyx = 14;
					yellow[3].plyy = 13;
					board[yellow[3].plyy][yellow[3].plyx] = 'y';
					yellow[3].pstart = true;
					break;
			}
		}
	}
	else if(redt == true && yellowt == true)//b, r and y teams
	{
		//red Team
		if(t == 0)
		{
			switch(p)
			{
				case 0:
					red[0].plyx = 4;
					red[0].plyy = 1;
					board[red[0].plyy][red[0].plyx] = 'r';
					red[0].pstart = true;
					break;
				case 1:
					red[1].plyx = 5;
					red[1].plyy = 1;
					board[red[1].plyy][red[1].plyx] = 'r';
					red[1].pstart = true;
					break;
				case 2:
					red[2].plyx = 4;
					red[2].plyy = 2;
					board[red[2].plyy][red[2].plyx] = 'r';
					red[2].pstart = true;
					break;
				case 3:
					red[3].plyx = 5;
					red[3].plyy = 2;
					board[red[3].plyy][red[3].plyx] = 'r';
					red[3].pstart = true;
					break;
			}
		}
		//yellow team
		else if(t == 3)
		{
			switch(p)
			{
				case 0:
					yellow[0].plyx = 15;
					yellow[0].plyy = 14;
					board[yellow[0].plyy][yellow[0].plyx] = 'y';
					yellow[0].pstart = true;
					break;
				case 1:
					yellow[1].plyx = 14;
					yellow[1].plyy = 14;
					board[yellow[1].plyy][yellow[1].plyx] = 'y';
					yellow[1].pstart = true;
					break;
				case 2:
					yellow[2].plyx = 15;
					yellow[2].plyy = 13;
					board[yellow[2].plyy][yellow[2].plyx] = 'y';
					yellow[2].pstart = true;
					break;
				case 3:
					yellow[3].plyx = 14;
					yellow[3].plyy = 13;
					board[yellow[3].plyy][yellow[3].plyx] = 'y';
					yellow[3].pstart = true;
					break;
			}
		}
	}
	else if(redt == true && greent == true)//b, r and g
	{
		//red Team
		if(t == 0)
		{
			switch(p)
			{
				case 0:
					red[0].plyx = 4;
					red[0].plyy = 1;
					board[red[0].plyy][red[0].plyx] = 'r';
					red[0].pstart = true;
					break;
				case 1:
					red[1].plyx = 5;
					red[1].plyy = 1;
					board[red[1].plyy][red[1].plyx] = 'r';
					red[1].pstart = true;
					break;
				case 2:
					red[2].plyx = 4;
					red[2].plyy = 2;
					board[red[2].plyy][red[2].plyx] = 'r';
					red[2].pstart = true;
					break;
				case 3:
					red[3].plyx = 5;
					red[3].plyy = 2;
					board[red[3].plyy][red[3].plyx] = 'r';
					red[3].pstart = true;
					break;
			}
		}
		//green Team
		else if(t == 2)
		{
			switch(p)
			{
				case 0:
					green[0].plyx = 1;
					green[0].plyy = 10;
					board[green[0].plyy][green[0].plyx] = 'g';
					green[0].pstart = true;
					break;
				case 1:
					green[1].plyx = 1;
					green[1].plyy = 11;
					board[green[1].plyy][green[1].plyx] = 'g';
					green[1].pstart = true;
					break;
				case 2:
					green[2].plyx = 2;
					green[2].plyy = 10;
					board[green[2].plyy][green[2].plyx] = 'g';
					green[2].pstart = true;
					break;
				case 3:
					green[3].plyx = 2;
					green[3].plyy = 11;
					board[green[3].plyy][green[3].plyx] = 'g';
					green[3].pstart = true;
					break;
			}
		}
	}
	else if(greent == true && yellowt == true)//b, y and g
	{
		//green team
		if(t == 2)
		{
			switch(p)
			{
				case 0:
					green[0].plyx = 1;
					green[0].plyy = 10;
					board[green[0].plyy][green[0].plyx] = 'g';
					green[0].pstart = true;
					break;
				case 1:
					green[1].plyx = 1;
					green[1].plyy = 11;
					board[green[1].plyy][green[1].plyx] = 'g';
					green[1].pstart = true;
					break;
				case 2:
					green[2].plyx = 2;
					green[2].plyy = 10;
					board[green[2].plyy][green[2].plyx] = 'g';
					green[2].pstart = true;
					break;
				case 3:
					green[3].plyx = 2;
					green[3].plyy = 11;
					board[green[3].plyy][green[3].plyx] = 'g';
					green[3].pstart = true;
					break;
			}
		}
		//yellow
		else if(t == 3)
		{
			switch(p)
			{
				case 0:
					yellow[0].plyx = 15;
					yellow[0].plyy = 14;
					board[yellow[0].plyy][yellow[0].plyx] = 'y';
					yellow[0].pstart = true;
					break;
				case 1:
					yellow[1].plyx = 14;
					yellow[1].plyy = 14;
					board[yellow[1].plyy][yellow[1].plyx] = 'y';
					yellow[1].pstart = true;
					break;
				case 2:
					yellow[2].plyx = 15;
					yellow[2].plyy = 13;
					board[yellow[2].plyy][yellow[2].plyx] = 'y';
					yellow[2].pstart = true;
					break;
				case 3:
					yellow[3].plyx = 14;
					yellow[3].plyy = 13;
					board[yellow[3].plyy][yellow[3].plyx] = 'y';
					yellow[3].pstart = true;
					break;
			}
		}
	}
	else if(redt == true)//b and r
	{
		//red team
		if(t == 0)
		{
			switch(p)
			{
				case 0:
					red[0].plyx = 4;
					red[0].plyy = 1;
					board[red[0].plyy][red[0].plyx] = 'r';
					red[0].pstart = true;
					break;
				case 1:
					red[1].plyx = 5;
					red[1].plyy = 1;
					board[red[1].plyy][red[1].plyx] = 'r';
					red[1].pstart = true;
					break;
				case 2:
					red[2].plyx = 4;
					red[2].plyy = 2;
					board[red[2].plyy][red[2].plyx] = 'r';
					red[2].pstart = true;
					break;
				case 3:
					red[3].plyx = 5;
					red[3].plyy = 2;
					board[red[3].plyy][red[3].plyx] = 'r';
					red[3].pstart = true;
					break;
			}
		}
	}
	else if(greent == true)//b and g
	{
		if(t == 2)
		{
			switch(p)
			{
				case 0:
					green[0].plyx = 1;
					green[0].plyy = 10;
					board[green[0].plyy][green[0].plyx] = 'g';
					green[0].pstart = true;
					break;
				case 1:
					green[1].plyx = 1;
					green[1].plyy = 11;
					board[green[1].plyy][green[1].plyx] = 'g';
					green[1].pstart = true;
					break;
				case 2:
					green[2].plyx = 2;
					green[2].plyy = 10;
					board[green[2].plyy][green[2].plyx] = 'g';
					green[2].pstart = true;
					break;
				case 3:
					green[3].plyx = 2;
					green[3].plyy = 11;
					board[green[3].plyy][green[3].plyx] = 'g';
					green[3].pstart = true;
					break;
			}
		}
	}
	else if(yellowt == true)//b and y
	{
		if(t == 3)
		{
			switch(p)
			{
				case 0:
					yellow[0].plyx = 15;
					yellow[0].plyy = 14;
					board[yellow[0].plyy][yellow[0].plyx] = 'y';
					yellow[0].pstart = true;
					break;
				case 1:
					yellow[1].plyx = 14;
					yellow[1].plyy = 14;
					board[yellow[1].plyy][yellow[1].plyx] = 'y';
					yellow[1].pstart = true;
					break;
				case 2:
					yellow[2].plyx = 15;
					yellow[2].plyy = 13;
					board[yellow[2].plyy][yellow[2].plyx] = 'y';
					yellow[2].pstart = true;
					break;
				case 3:
					yellow[3].plyx = 14;
					yellow[3].plyy = 13;
					board[yellow[3].plyy][yellow[3].plyx] = 'y';
					yellow[3].pstart = true;
					break;
			}
		}
	}
}

void gStart(int t, int p)
{
	if(redt == true && bluet == true && yellowt == true)//all teams
	{
		//red team
		if(t == 0)
		{
			switch(p)
			{
				case 0:
					red[0].plyx = 4;
					red[0].plyy = 1;
					board[red[0].plyy][red[0].plyx] = 'r';
					red[0].pstart = true;
					break;
				case 1:
					red[1].plyx = 5;
					red[1].plyy = 1;
					board[red[1].plyy][red[1].plyx] = 'r';
					red[1].pstart = true;
					break;
				case 2:
					red[2].plyx = 4;
					red[2].plyy = 2;
					board[red[2].plyy][red[2].plyx] = 'r';
					red[2].pstart = true;
					break;
				case 3:
					red[3].plyx = 5;
					red[3].plyy = 2;
					board[red[3].plyy][red[3].plyx] = 'r';
					red[3].pstart = true;
					break;
			}
		}
		//blue team
		else if(t == 1)
		{
			switch(p)
			{
				case 0:
					blue[0].plyx = 18;
					blue[0].plyy = 4;
					board[blue[0].plyy][blue[0].plyx] = 'b';
					blue[0].pstart = true;
					break;
				case 1:
					blue[1].plyx = 18;
					blue[1].plyy = 5;
					board[blue[1].plyy][blue[1].plyx] = 'b';
					blue[1].pstart = true;
					break;
				case 2:
					blue[2].plyx = 17;
					blue[2].plyy = 4;
					board[blue[2].plyy][blue[2].plyx] = 'b';
					blue[2].pstart = true;
					break;
				case 3:
					blue[3].plyx = 17;
					blue[3].plyy = 5;
					board[blue[3].plyy][blue[2].plyx] = 'b';
					blue[3].pstart = true;
					break;
			}
		}
		//yellow team
		else if(t == 3)
		{
			switch(p)
			{
				case 0:
					yellow[0].plyx = 15;
					yellow[0].plyy = 14;
					board[yellow[0].plyy][yellow[0].plyx] = 'y';
					yellow[0].pstart = true;
					break;
				case 1:
					yellow[1].plyx = 14;
					yellow[1].plyy = 14;
					board[yellow[1].plyy][yellow[1].plyx] = 'y';
					yellow[1].pstart = true;
					break;
				case 2:
					yellow[2].plyx = 15;
					yellow[2].plyy = 13;
					board[yellow[2].plyy][yellow[2].plyx] = 'y';
					yellow[2].pstart = true;
					break;
				case 3:
					yellow[3].plyx = 14;
					yellow[3].plyy = 13;
					board[yellow[3].plyy][yellow[3].plyx] = 'y';
					yellow[3].pstart = true;
					break;
			}
		}
	}
	else if(redt == true && bluet == true)//g, r and b teams
	{
		//red team
		if(t == 0)
		{
			switch(p)
			{
				case 0:
					red[0].plyx = 4;
					red[0].plyy = 1;
					board[red[0].plyy][red[0].plyx] = 'r';
					red[0].pstart = true;
					break;
				case 1:
					red[1].plyx = 5;
					red[1].plyy = 1;
					board[red[1].plyy][red[1].plyx] = 'r';
					red[1].pstart = true;
					break;
				case 2:
					red[2].plyx = 4;
					red[2].plyy = 2;
					board[red[2].plyy][red[2].plyx] = 'r';
					red[2].pstart = true;
					break;
				case 3:
					red[3].plyx = 5;
					red[3].plyy = 2;
					board[red[3].plyy][red[3].plyx] = 'r';
					red[3].pstart = true;
					break;
			}
		}
		//blue team
		else if(t == 1)
		{
			switch(p)
			{
				case 0:
					blue[0].plyx = 18;
					blue[0].plyy = 4;
					board[blue[0].plyy][blue[0].plyx] = 'b';
					blue[0].pstart = true;
					break;
				case 1:
					blue[1].plyx = 18;
					blue[1].plyy = 5;
					board[blue[1].plyy][blue[1].plyx] = 'b';
					blue[1].pstart = true;
					break;
				case 2:
					blue[2].plyx = 17;
					blue[2].plyy = 4;
					board[blue[2].plyy][blue[2].plyx] = 'b';
					blue[2].pstart = true;
					break;
				case 3:
					blue[3].plyx = 17;
					blue[3].plyy = 5;
					board[blue[3].plyy][blue[2].plyx] = 'b';
					blue[3].pstart = true;
					break;
			}
		}
	}
	else if(redt == true && yellowt == true)//g, r, and y teams
	{
		//red team
		if(t == 0)
		{
			switch(p)
			{
				case 0:
					red[0].plyx = 4;
					red[0].plyy = 1;
					board[red[0].plyy][red[0].plyx] = 'r';
					red[0].pstart = true;
					break;
				case 1:
					red[1].plyx = 5;
					red[1].plyy = 1;
					board[red[1].plyy][red[1].plyx] = 'r';
					red[1].pstart = true;
					break;
				case 2:
					red[2].plyx = 4;
					red[2].plyy = 2;
					board[red[2].plyy][red[2].plyx] = 'r';
					red[2].pstart = true;
					break;
				case 3:
					red[3].plyx = 5;
					red[3].plyy = 2;
					board[red[3].plyy][red[3].plyx] = 'r';
					red[3].pstart = true;
					break;
			}
		}
		//yellow team
		else if(t == 3)
		{
			switch(p)
			{
				case 0:
					yellow[0].plyx = 15;
					yellow[0].plyy = 14;
					board[yellow[0].plyy][yellow[0].plyx] = 'y';
					yellow[0].pstart = true;
					break;
				case 1:
					yellow[1].plyx = 14;
					yellow[1].plyy = 14;
					board[yellow[1].plyy][yellow[1].plyx] = 'y';
					yellow[1].pstart = true;
					break;
				case 2:
					yellow[2].plyx = 15;
					yellow[2].plyy = 13;
					board[yellow[2].plyy][yellow[2].plyx] = 'y';
					yellow[2].pstart = true;
					break;
				case 3:
					yellow[3].plyx = 14;
					yellow[3].plyy = 13;
					board[yellow[3].plyy][yellow[3].plyx] = 'y';
					yellow[3].pstart = true;
					break;
			}
		}
	}
	else if(bluet == true && yellowt == true)//g, b and y teams
	{
		//blue team
		if(t == 1)
		{
			switch(p)
			{
				case 0:
					blue[0].plyx = 18;
					blue[0].plyy = 4;
					board[blue[0].plyy][blue[0].plyx] = 'b';
					blue[0].pstart = true;
					break;
				case 1:
					blue[1].plyx = 18;
					blue[1].plyy = 5;
					board[blue[1].plyy][blue[1].plyx] = 'b';
					blue[1].pstart = true;
					break;
				case 2:
					blue[2].plyx = 17;
					blue[2].plyy = 4;
					board[blue[2].plyy][blue[2].plyx] = 'b';
					blue[2].pstart = true;
					break;
				case 3:
					blue[3].plyx = 17;
					blue[3].plyy = 5;
					board[blue[3].plyy][blue[2].plyx] = 'b';
					blue[3].pstart = true;
					break;
			}
		}
		//yellow team
		else if(t == 3)
		{
			switch(p)
			{
				case 0:
					yellow[0].plyx = 15;
					yellow[0].plyy = 14;
					board[yellow[0].plyy][yellow[0].plyx] = 'y';
					yellow[0].pstart = true;
					break;
				case 1:
					yellow[1].plyx = 14;
					yellow[1].plyy = 14;
					board[yellow[1].plyy][yellow[1].plyx] = 'y';
					yellow[1].pstart = true;
					break;
				case 2:
					yellow[2].plyx = 15;
					yellow[2].plyy = 13;
					board[yellow[2].plyy][yellow[2].plyx] = 'y';
					yellow[2].pstart = true;
					break;
				case 3:
					yellow[3].plyx = 14;
					yellow[3].plyy = 13;
					board[yellow[3].plyy][yellow[3].plyx] = 'y';
					yellow[3].pstart = true;
					break;
			}
		}
	}
	else if(bluet == true)//g and b teams
	{
		//blue team
		if(t == 1)
		{
			switch(p)
			{
				case 0:
					blue[0].plyx = 18;
					blue[0].plyy = 4;
					board[blue[0].plyy][blue[0].plyx] = 'b';
					blue[0].pstart = true;
					break;
				case 1:
					blue[1].plyx = 18;
					blue[1].plyy = 5;
					board[blue[1].plyy][blue[1].plyx] = 'b';
					blue[1].pstart = true;
					break;
				case 2:
					blue[2].plyx = 17;
					blue[2].plyy = 4;
					board[blue[2].plyy][blue[2].plyx] = 'b';
					blue[2].pstart = true;
					break;
				case 3:
					blue[3].plyx = 17;
					blue[3].plyy = 5;
					board[blue[3].plyy][blue[2].plyx] = 'b';
					blue[3].pstart = true;
					break;
			}
		}
	}
	else if(redt == true)//g and r teams
	{
		//red team
		if(t == 0)
		{
			switch(p)
			{
				case 0:
					red[0].plyx = 4;
					red[0].plyy = 1;
					board[red[0].plyy][red[0].plyx] = 'r';
					red[0].pstart = true;
					break;
				case 1:
					red[1].plyx = 5;
					red[1].plyy = 1;
					board[red[1].plyy][red[1].plyx] = 'r';
					red[1].pstart = true;
					break;
				case 2:
					red[2].plyx = 4;
					red[2].plyy = 2;
					board[red[2].plyy][red[2].plyx] = 'r';
					red[2].pstart = true;
					break;
				case 3:
					red[3].plyx = 5;
					red[3].plyy = 2;
					board[red[3].plyy][red[3].plyx] = 'r';
					red[3].pstart = true;
					break;
			}
		}
	}
	else if(yellowt == true)//g and y teams
	{
		//yellow team
		if(t == 3)
		{
			switch(p)
			{
				case 0:
					yellow[0].plyx = 15;
					yellow[0].plyy = 14;
					board[yellow[0].plyy][yellow[0].plyx] = 'y';
					yellow[0].pstart = true;
					break;
				case 1:
					yellow[1].plyx = 14;
					yellow[1].plyy = 14;
					board[yellow[1].plyy][yellow[1].plyx] = 'y';
					yellow[1].pstart = true;
					break;
				case 2:
					yellow[2].plyx = 15;
					yellow[2].plyy = 13;
					board[yellow[2].plyy][yellow[2].plyx] = 'y';
					yellow[2].pstart = true;
					break;
				case 3:
					yellow[3].plyx = 14;
					yellow[3].plyy = 13;
					board[yellow[3].plyy][yellow[3].plyx] = 'y';
					yellow[3].pstart = true;
					break;
			}
		}
	}
}

void yStart(int t, int p)
{
	if(redt == true && bluet == true && greent == true)//all teams
	{
		//red team
		if(t == 0)
		{
			switch(p)
			{
				case 0:
					red[0].plyx = 4;
					red[0].plyy = 1;
					board[red[0].plyy][red[0].plyx] = 'r';
					red[0].pstart = true;
					break;
				case 1:
					red[1].plyx = 5;
					red[1].plyy = 1;
					board[red[1].plyy][red[1].plyx] = 'r';
					red[1].pstart = true;
					break;
				case 2:
					red[2].plyx = 4;
					red[2].plyy = 2;
					board[red[2].plyy][red[2].plyx] = 'r';
					red[2].pstart = true;
					break;
				case 3:
					red[3].plyx = 5;
					red[3].plyy = 2;
					board[red[3].plyy][red[3].plyx] = 'r';
					red[3].pstart = true;
					break;
			}
		}
		//blue team
		else if(t == 1)
		{
			switch(p)
			{
				case 0:
					blue[0].plyx = 18;
					blue[0].plyy = 4;
					board[blue[0].plyy][blue[0].plyx] = 'b';
					blue[0].pstart = true;
					break;
				case 1:
					blue[1].plyx = 18;
					blue[1].plyy = 5;
					board[blue[1].plyy][blue[1].plyx] = 'b';
					blue[1].pstart = true;
					break;
				case 2:
					blue[2].plyx = 17;
					blue[2].plyy = 4;
					board[blue[2].plyy][blue[2].plyx] = 'b';
					blue[2].pstart = true;
					break;
				case 3:
					blue[3].plyx = 17;
					blue[3].plyy = 5;
					board[blue[3].plyy][blue[2].plyx] = 'b';
					blue[3].pstart = true;
					break;
			}
		}
		//green team
		else if(t == 2)
		{
			switch(p)
			{
				case 0:
					green[0].plyx = 1;
					green[0].plyy = 10;
					board[green[0].plyy][green[0].plyx] = 'g';
					green[0].pstart = true;
					break;
				case 1:
					green[1].plyx = 1;
					green[1].plyy = 11;
					board[green[1].plyy][green[1].plyx] = 'g';
					green[1].pstart = true;
					break;
				case 2:
					green[2].plyx = 2;
					green[2].plyy = 10;
					board[green[2].plyy][green[2].plyx] = 'g';
					green[2].pstart = true;
					break;
				case 3:
					green[3].plyx = 2;
					green[3].plyy = 11;
					board[green[3].plyy][green[3].plyx] = 'g';
					green[3].pstart = true;
					break;
			}
		}
	}
	else if(redt == true && bluet == true)//y, r and b teams
	{
		//red team
		if(t == 0)
		{
			switch(p)
			{
				case 0:
					red[0].plyx = 4;
					red[0].plyy = 1;
					board[red[0].plyy][red[0].plyx] = 'r';
					red[0].pstart = true;
					break;
				case 1:
					red[1].plyx = 5;
					red[1].plyy = 1;
					board[red[1].plyy][red[1].plyx] = 'r';
					red[1].pstart = true;
					break;
				case 2:
					red[2].plyx = 4;
					red[2].plyy = 2;
					board[red[2].plyy][red[2].plyx] = 'r';
					red[2].pstart = true;
					break;
				case 3:
					red[3].plyx = 5;
					red[3].plyy = 2;
					board[red[3].plyy][red[3].plyx] = 'r';
					red[3].pstart = true;
					break;
			}
		}
		//blue team
		else if(t == 1)
		{
			switch(p)
			{
				case 0:
					blue[0].plyx = 18;
					blue[0].plyy = 4;
					board[blue[0].plyy][blue[0].plyx] = 'b';
					blue[0].pstart = true;
					break;
				case 1:
					blue[1].plyx = 18;
					blue[1].plyy = 5;
					board[blue[1].plyy][blue[1].plyx] = 'b';
					blue[1].pstart = true;
					break;
				case 2:
					blue[2].plyx = 17;
					blue[2].plyy = 4;
					board[blue[2].plyy][blue[2].plyx] = 'b';
					blue[2].pstart = true;
					break;
				case 3:
					blue[3].plyx = 17;
					blue[3].plyy = 5;
					board[blue[3].plyy][blue[2].plyx] = 'b';
					blue[3].pstart = true;
					break;
			}
		}
	}
	else if(redt == true && greent == true)//y, r and g teams
	{
		//red teams
		if(t == 0)
		{
			switch(p)
			{
				case 0:
					red[0].plyx = 4;
					red[0].plyy = 1;
					board[red[0].plyy][red[0].plyx] = 'r';
					red[0].pstart = true;
					break;
				case 1:
					red[1].plyx = 5;
					red[1].plyy = 1;
					board[red[1].plyy][red[1].plyx] = 'r';
					red[1].pstart = true;
					break;
				case 2:
					red[2].plyx = 4;
					red[2].plyy = 2;
					board[red[2].plyy][red[2].plyx] = 'r';
					red[2].pstart = true;
					break;
				case 3:
					red[3].plyx = 5;
					red[3].plyy = 2;
					board[red[3].plyy][red[3].plyx] = 'r';
					red[3].pstart = true;
					break;
			}
		}
		//green team
		else if(t == 2)
		{
			switch(p)
			{
				case 0:
					green[0].plyx = 1;
					green[0].plyy = 10;
					board[green[0].plyy][green[0].plyx] = 'g';
					green[0].pstart = true;
					break;
				case 1:
					green[1].plyx = 1;
					green[1].plyy = 11;
					board[green[1].plyy][green[1].plyx] = 'g';
					green[1].pstart = true;
					break;
				case 2:
					green[2].plyx = 2;
					green[2].plyy = 10;
					board[green[2].plyy][green[2].plyx] = 'g';
					green[2].pstart = true;
					break;
				case 3:
					green[3].plyx = 2;
					green[3].plyy = 11;
					board[green[3].plyy][green[3].plyx] = 'g';
					green[3].pstart = true;
					break;
			}
		}
	}
	else if(bluet == true && greent == true)//y, b and g teams
	{
		//blue team
		if(t == 1)
		{
			switch(p)
			{
				case 0:
					blue[0].plyx = 18;
					blue[0].plyy = 4;
					board[blue[0].plyy][blue[0].plyx] = 'b';
					blue[0].pstart = true;
					break;
				case 1:
					blue[1].plyx = 18;
					blue[1].plyy = 5;
					board[blue[1].plyy][blue[1].plyx] = 'b';
					blue[1].pstart = true;
					break;
				case 2:
					blue[2].plyx = 17;
					blue[2].plyy = 4;
					board[blue[2].plyy][blue[2].plyx] = 'b';
					blue[2].pstart = true;
					break;
				case 3:
					blue[3].plyx = 17;
					blue[3].plyy = 5;
					board[blue[3].plyy][blue[2].plyx] = 'b';
					blue[3].pstart = true;
					break;
			}
		}
		//green team
		else if(t == 2)
		{
			switch(p)
			{
				case 0:
					green[0].plyx = 1;
					green[0].plyy = 10;
					board[green[0].plyy][green[0].plyx] = 'g';
					green[0].pstart = true;
					break;
				case 1:
					green[1].plyx = 1;
					green[1].plyy = 11;
					board[green[1].plyy][green[1].plyx] = 'g';
					green[1].pstart = true;
					break;
				case 2:
					green[2].plyx = 2;
					green[2].plyy = 10;
					board[green[2].plyy][green[2].plyx] = 'g';
					green[2].pstart = true;
					break;
				case 3:
					green[3].plyx = 2;
					green[3].plyy = 11;
					board[green[3].plyy][green[3].plyx] = 'g';
					green[3].pstart = true;
					break;
			}
		}
	}
	else if(redt == true)//y and r
	{
		//red team
		if(t == 0)
		{
			switch(p)
			{
				case 0:
					red[0].plyx = 4;
					red[0].plyy = 1;
					board[red[0].plyy][red[0].plyx] = 'r';
					red[0].pstart = true;
					break;
				case 1:
					red[1].plyx = 5;
					red[1].plyy = 1;
					board[red[1].plyy][red[1].plyx] = 'r';
					red[1].pstart = true;
					break;
				case 2:
					red[2].plyx = 4;
					red[2].plyy = 2;
					board[red[2].plyy][red[2].plyx] = 'r';
					red[2].pstart = true;
					break;
				case 3:
					red[3].plyx = 5;
					red[3].plyy = 2;
					board[red[3].plyy][red[3].plyx] = 'r';
					red[3].pstart = true;
					break;
			}
		}
	}
	else if(bluet == true)//y and b
	{
		//blue team
		if(t == 1)
		{
			switch(p)
			{
				case 0:
					blue[0].plyx = 18;
					blue[0].plyy = 4;
					board[blue[0].plyy][blue[0].plyx] = 'b';
					blue[0].pstart = true;
					break;
				case 1:
					blue[1].plyx = 18;
					blue[1].plyy = 5;
					board[blue[1].plyy][blue[1].plyx] = 'b';
					blue[1].pstart = true;
					break;
				case 2:
					blue[2].plyx = 17;
					blue[2].plyy = 4;
					board[blue[2].plyy][blue[2].plyx] = 'b';
					blue[2].pstart = true;
					break;
				case 3:
					blue[3].plyx = 17;
					blue[3].plyy = 5;
					board[blue[3].plyy][blue[2].plyx] = 'b';
					blue[3].pstart = true;
					break;
			}
		}
	}
	else if(greent == true)//y and g
	{
		if(t == 2)
		{
			switch(p)
			{
				case 0:
					green[0].plyx = 1;
					green[0].plyy = 10;
					board[green[0].plyy][green[0].plyx] = 'g';
					green[0].pstart = true;
					break;
				case 1:
					green[1].plyx = 1;
					green[1].plyy = 11;
					board[green[1].plyy][green[1].plyx] = 'g';
					green[1].pstart = true;
					break;
				case 2:
					green[2].plyx = 2;
					green[2].plyy = 10;
					board[green[2].plyy][green[2].plyx] = 'g';
					green[2].pstart = true;
					break;
				case 3:
					green[3].plyx = 2;
					green[3].plyy = 11;
					board[green[3].plyy][green[3].plyx] = 'g';
					green[3].pstart = true;
					break;
			}
		}
	}
}

void moveHome(int p, int s)
{
	int m = 0;
	char a = 179;
	//red team
	if(redd == team1.teamTurn())
	{
		red[p].phome = true;
			m = s;
			if(red[p].plyy == 5 && m == 1)
			{
				plyAssignH(0,p);
				return;
			}
			else if(red[p].plyy == 6 && red[p].plyx == 1)
				return;
			else if(red[p].plyy == 6 && red[p].plyx == 2)
				return;
			else if(red[p].plyy == 7 && red[p].plyx == 1)
				return;
			else if(red[p].plyy == 7 && red[p].plyx == 2)
				return;
			for(int i = 0; i < m; i++)
			{
				home1.changeh(0,p);
				if(red[p].plyy == 5)
					break;
				else
				{
					red[p].plyy ++;
					board[red[p].plyy][red[p].plyx] = 'r';
					board[red[p].plyy-1][red[p].plyx] = a;
					printGrid();
					Sleep(500);
				}
			}
	}
	else if(bluee == team1.teamTurn())
	{
		blue[p].phome = true;
			m = s;
			if(blue[p].plyx == 14 && m == 1)
			{
				plyAssignH(1,p);
				return;
			}
			else if(blue[p].plyy == 1 && blue[p].plyx == 13)
				return;
			else if(blue[p].plyy == 1 && blue[p].plyx == 12)
				return;
			else if(blue[p].plyy == 2 && blue[p].plyx == 13)
				return;
			else if(blue[p].plyy == 2 && blue[p].plyx == 12)
				return;
			for(int i = 0; i < m; i++)
			{
				if(blue[p].plyx == 14)
					break;
				else
				{
					blue[p].plyx --;
					board[blue[p].plyy][blue[p].plyx] = 'b';
					board[blue[p].plyy][blue[p].plyx+1] = a;
					printGrid();
					Sleep(500);
				}
			}
	}
	else if(greenn == team1.teamTurn())
	{
		green[p].phome = true;
		
			m = s;
			if(green[p].plyx == 5 && m == 1)
			{
				plyAssignH(2,p);
				return;
			}
			else if(green[p].plyy == 13 && green[p].plyx == 7)
				return;
			else if(green[p].plyy == 14 && green[p].plyx == 7)
				return;
			else if(green[p].plyy == 13 && green[p].plyx == 6)
				return;
			else if(green[p].plyy == 14 && green[p].plyx == 6)
				return;
			for(int i = 0; i < m; i++)
			{
				if(green[p].plyx == 5)
					break;
				else
				{
					green[p].plyx++;
					board[green[p].plyy][green[p].plyx] = 'g';
					board[green[p].plyy][green[p].plyx-1] = a;
					printGrid();
					Sleep(500);
				}
			}
	}
	else if(yelloww == team1.teamTurn())
	{
		yellow[p].phome = true;
		
		m = s;
			if(yellow[p].plyy == 10 && m == 1)
			{
				plyAssignH(3,p);
				return;
			}
			else if(yellow[p].plyy == 9 && yellow[p].plyx == 17)
				return;
			else if(yellow[p].plyy == 9 && yellow[p].plyx == 18)
				return;
			else if(yellow[p].plyy == 8 && yellow[p].plyx == 17)
				return;
			else if(yellow[p].plyy == 8 && yellow[p].plyx == 18)
				return;
			for(int i = 0; i < m; i++)
			{
				if(yellow[p].plyy == 10)
					break;
				else
				{
					yellow[p].plyy--;
					board[yellow[p].plyy][yellow[p].plyx] = 'y';
					board[yellow[p].plyy+1][yellow[p].plyx] = a;
					printGrid();
					Sleep(500);
				}
			}
	}
}

void plyAssignH(int t, int p)
{
	char a = 179;
	if(t == 0)
	{
		switch(p)
		{
		case 0:
			red[0].plyy = 6;
			red[0].plyx = 1;
			break;
		case 1:
			red[1].plyy = 6;
			red[1].plyx = 2;
			break;
		case 2:
			red[2].plyy = 7;
			red[2].plyx = 1;
			break;
		case 3:
			red[3].plyy = 7;
			red[3].plyx = 2;
			break;
		}
		board[red[p].plyy][red[p].plyx] = 'r';
		board[5][2] = a;
		home1.addCount(0);
	}
	else if(t == 1)
	{
		switch(p)
		{
		case 0:
			blue[0].plyy = 1;
			blue[0].plyx = 13;
			break;
		case 1:
			blue[1].plyy = 1;
			blue[1].plyx = 12;
			break;
		case 2:
			blue[2].plyy = 2;
			blue[2].plyx = 13;
			break;
		case 3:
			blue[3].plyy = 2;
			blue[3].plyx = 12;
			break;
		}
		board[blue[p].plyy][blue[p].plyx] = 'b';
		board[2][14] = a;
		home1.addCount(1);
	}
	else if(t == 2)
	{
		switch(p)
		{
		case 0:
			green[0].plyy = 13;
			green[0].plyx = 7;
			break;
		case 1:
			green[1].plyy = 14;
			green[1].plyx = 7;
			break;
		case 2:
			green[2].plyy = 13;
			green[2].plyx = 6;
			break;
		case 3:
			green[3].plyy = 14;
			green[3].plyx = 6;
			break;
		}
		board[green[p].plyy][green[p].plyx] = 'g';
		board[13][5] = a;
		home1.addCount(2);
	}
	else if(t == 3)
	{
		switch(p)
		{
		case 0:
			yellow[0].plyy = 9;
			yellow[0].plyx = 17;
			break;
		case 1:
			yellow[1].plyy = 9;
			yellow[1].plyx = 18;
			break;
		case 2:
			yellow[2].plyy = 8;
			yellow[2].plyx = 17;
			break;
		case 3:
			yellow[3].plyy = 8;
			yellow[3].plyx = 18;
			break;
		}
		board[yellow[p].plyy][yellow[p].plyx] = 'y';
		board[10][17] = a;
		home1.addCount(3);
	}
}

void endGame()
{
	if (home1.getTcount(0) == 4)
		redh = true;
	else if (home1.getTcount(1) == 4)
		blueh = true;
	else if (home1.getTcount(2) == 4)
		greenh = true;
	else if (home1.getTcount(3) == 4)
		yellowh = true;
}

void storeNames(int a)
{
	cin.ignore(1, ' ');
	for (int i = 0; i < a; i++)
	{
		switch (i)
		{
		case 0:
			cout << "Player 1 please enter your team name: ";
			getline(cin, name1);
			break;
		case 1:
			cout << "Player 2 please enter your team name: ";
			getline(cin, name2);
			break;
		case 2:
			cout << "Player 3 please enter your team name: ";
			getline(cin, name3);
			break;
		case 3:
			cout << "Player 4 please enter your team name: ";
			getline(cin, name4);
			break;
		}
	}
}

void assignTeamNames(int a, int t)
{
	if (a == 1)
	{
		if (t == 1 && redt == false)
			tem1 = name1;
		else if (t == 2 && bluet == false)
			tem2 = name1;
		else if (t == 3 && greent == false)
			tem3 = name1;
		else if (t == 4 && yellowt == false)
			tem4 = name1;
	}
	else if (a == 2)
	{
		if (t == 1 && redt == false)
			tem1 = name2;
		else if (t == 2 && bluet == false)
			tem2 = name2;
		else if (t == 3 && greent == false)
			tem3 = name2;
		else if (t == 4 && yellowt == false)
			tem4 = name2;
	}
	else if (a == 3)
	{
		if (t == 1 && redt == false)
			tem1 = name3;
		else if (t == 2 && bluet == false)
			tem2 = name3;
		else if (t == 3 && greent == false)
			tem3 = name3;
		else if (t == 4 && yellowt == false)
			tem4 = name3;
	}
	else if (a == 4)
	{
		if (t == 1 && redt == false)
			tem1 = name4;
		else if (t == 2 && bluet == false)
			tem2 = name4;
		else if (t == 3 && greent == false)
			tem3 = name4;
		else if (t == 4 && yellowt == false)
			tem4 = name4;
	}
}

bool friendlySrry(int t)
{
	for(int i = 0; i < 4; i++)
	{
		if(redt == true && redd == team1.teamTurn())
		{
				if(i != t)
				{
					if((red[t].plyx == red[i].plyx) && (red[t].plyy == red[i].plyy))
					{
						if(red[i].phome == true)
							red[i].phome = false;
						switch(i)
						{
						case 0:
							red[0].plyx = 4;
							red[0].plyy = 1;
							board[red[0].plyy][red[0].plyx] = 'r';
							red[0].pstart = false;
							break;
						case 1:
							red[1].plyx = 5;
							red[1].plyy = 1;
							board[red[1].plyy][red[1].plyx] = 'r';
							red[1].pstart = false;
							break;
						case 2:
							red[2].plyx = 4;
							red[2].plyy = 2;
							board[red[2].plyy][red[2].plyx] = 'r';
							red[2].pstart = false;
							break;
						case 3:
							red[3].plyx = 5;
							red[3].plyy = 2;
							board[red[3].plyy][red[3].plyx] = 'r';
							red[3].pstart = false;
							break;
						}
						return true;
					}
				}
		}
		else if(bluet == true && bluee == team1.teamTurn())
		{
			if(i != t)
			{
				if((blue[t].plyx == blue[i].plyx) && (blue[t].plyy == blue[i].plyy))
				{
					if(blue[i].phome == true)
						blue[i].phome = false;
					switch(i)
					{
					case 0:
						blue[0].plyx = 18;
						blue[0].plyy = 4;
						board[blue[0].plyy][blue[0].plyx] = 'b';
						blue[0].pstart = false;
						break;
					case 1:
						blue[1].plyx = 18;
						blue[1].plyy = 5;
						board[blue[1].plyy][blue[1].plyx] = 'b';
						blue[1].pstart = false;
						break;
					case 2:
						blue[2].plyx = 17;
						blue[2].plyy = 4;
						board[blue[2].plyy][blue[2].plyx] = 'b';
						blue[2].pstart = false;
						break;
					case 3:
						blue[3].plyx = 17;
						blue[3].plyy = 5;
						board[blue[3].plyy][blue[3].plyx] = 'b';
						blue[3].pstart = false;
						break;
					}
					return true;
				}
			}
		}
		else if(greent == true && greenn == team1.teamTurn())
		{
			if(i != t)
			{
				if((green[t].plyx == green[i].plyx) && (green[t].plyy == green[i].plyy))
				{
					if(green[i].phome == true)
						green[i].phome = false;
					switch(i)
					{
					case 0:
						green[0].plyx = 1;
						green[0].plyy = 10;
						board[green[0].plyy][green[0].plyx] = 'g';
						green[0].pstart = false;
						break;
					case 1:
						green[1].plyx = 1;
						green[1].plyy = 11;
						board[green[1].plyy][green[1].plyx] = 'g';
						green[1].pstart = false;
						break;
					case 2:
						green[2].plyx = 2;
						green[2].plyy = 10;
						board[green[2].plyy][green[2].plyx] = 'g';
						green[2].pstart = false;
						break;
					case 3:
						green[3].plyx = 2;
						green[3].plyy = 11;
						board[green[3].plyy][green[3].plyx] = 'g';
						green[3].pstart = false;
						break;
					}
					return true;
				}
			}
		}
		else if(yellowt == true && yelloww == team1.teamTurn())
		{
			if(i != t)
			{
				if((yellow[t].plyx == yellow[i].plyx) && (yellow[t].plyy == yellow[i].plyy))
				{
					if(yellow[i].phome == true)
						yellow[i].phome = false;
					switch(i)
					{
					case 0:
						yellow[0].plyx = 15;
						yellow[0].plyy = 14;
						board[yellow[0].plyy][yellow[0].plyx] = 'y';
						yellow[0].pstart = false;
						break;
					case 1:
						yellow[1].plyx = 14;
						yellow[1].plyy = 14;
						board[yellow[1].plyy][yellow[1].plyx] = 'y';
						yellow[1].pstart = false;
						break;
					case 2:
						yellow[2].plyx = 15;
						yellow[2].plyy = 13;
						board[yellow[2].plyy][yellow[2].plyx] = 'y';
						yellow[2].pstart = false;
						break;
					case 3:
						yellow[3].plyx = 14;
						yellow[3].plyy = 13;
						board[yellow[3].plyy][yellow[3].plyx] = 'y';
						yellow[3].pstart = false;
						break;
					}
				}
			}
		}
	}
}

int randNum()
{
	int z = 0;
	
	if(redt == true && redd == team1.teamTurn())
	{
		if(red[0].plyx != 1 || red[0].plyy != 6)
			return 1;
		else if(red[1].plyx != 2 || red[1].plyy != 6)
			return 2;
		else if(red[2].plyx != 1 || red[2].plyy != 7)
			return 3;
		else if(red[3].plyx != 2 || red[3].plyy != 7)
			return 4;
	}
	else if(bluet == true && bluee == team1.teamTurn())
	{
		if(blue[0].plyx != 13 || blue[0].plyy != 1)
			return 1;
		else if(blue[1].plyx != 12 || blue[1].plyy != 1)
			return 2;
		else if(blue[2].plyx != 13 || blue[2].plyy != 2)
			return 3;
		else if(blue[3].plyx != 12 || blue[3].plyy != 2)
			return 4;
	}
	else if(greent == true && greenn == team1.teamTurn())
	{
		if(green[0].plyx != 7 || green[0].plyy != 13)
			return 1;
		else if(green[1].plyx != 7 || green[1].plyy != 14)
			return 2;
		else if(green[2].plyx != 6 || green[2].plyy != 13)
			return 3;
		else if(green[3].plyx != 6 || green[3].plyy != 14)
			return 4;
	}
	else if(yellowt == true && yelloww == team1.teamTurn())
	{
		if(yellow[0].plyx != 17 || yellow[0].plyy != 9)
			return 1;
		else if(yellow[1].plyx != 18 || yellow[1].plyy != 9)
			return 2;
		else if(yellow[2].plyx != 17 || yellow[2].plyy != 8)
			return 3;
		else if(yellow[3].plyx != 18 || yellow[3].plyy != 8)
			return 4;
	}
}

void congradulations()
{
	int z = 0;
	if(redh == true)
		cout<<"Team "<<tem1<<" Wins"<<endl;
	else if(blueh == true)
		cout<<"Team "<<tem2<<" Wins"<<endl;
	else if(greenh == true)
		cout<<"Team "<<tem3<<" Wins"<<endl;
	else if(greenh == true)
		cout<<"Team "<<tem4<<" Wins"<<endl;

	cout<<"Do you want to play again? (1 yes, 2 no): ";
	cin>>z;

	if(z == 1)
	{
		reset();
		cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
		runMethod();
	}
	else
		cout<<"Thanks for playing."<<endl;
}

void compNameAssign(int a, int t)
{
	int b = 0;
	
	if(t == 1)
	{
		if(a == 1)
			name2 = "Computer Player 1";
		else if(a == 2)
		{
			name1 = "Computer Player 1";
			name2 = "Computer Player 2";
		}

	}
	else if(t == 2)
	{
		if(a == 1)
			name3 = "Computer Player 1";
		else if(a == 2)
		{
			name2 = "Computer Player 1";
			name3 = "Computer Player 2";
		}
		else if(a == 3)
		{
			name1 = "Computer Player 1";
			name2 = "Computer Player 2";
			name3 = "Computer Player 3";
		}
	}
	else if(t == 3)
	{
		if(a == 1)
			name4 = "Computer Player 1";
		else if(a == 2)
		{
			name3 = "Computer Player 1";
			name4 = "Computer Player 2";
		}
		else if(a == 3)
		{
			name2 = "Computer Player 1";
			name3 = "Computer Player 2";
			name4 = "Computer Player 3";
		}
		else if(a == 4)
		{
			name1 = "Computer Player 1";
			name2 = "Computer Player 2";
			name3 = "Computer Player 3";
			name4 = "Computer Player 4";
		}
	}
}

bool checkForComp(string a)
{
	if(a == "Computer Player 1")
		return true;
	else if(a == "Computer Player 2")
		return true;
	else if(a == "Computer Player 3")
		return true;
	else if(a == "Computer Player 4")
		return true;

	return false;
}

void reset()
{
	ones = 0, two = 0, three = 0, four = 0, five = 0, seven = 0, eight = 0, ten = 0, eleven = 0, twelve = 0, srry = 0, x = 0, y = 0, computers = 0;
	redt = false, bluet = false, yellowt = false, greent = false, redh = false, blueh = false, yellowh = false, greenh = false;
	c1 = false, c2 = false, c3 = false, c4 = false;
	ai = false, comp1 = false, comp2 = false, comp3 = false, comp4 = false, adv = false, ac = false;
	name1 = "", name2 = "", name3 = "", name4 = "";
	tem1 = "", tem2 = "", tem3 = "", tem4 = "";
	redd = 0, greenn = 0, yelloww = 0, bluee = 0;
}

void checkBoarders(int a)//To make sure that peices don't disappear after they are gone over
{
	for(int i = 0; i < 4; i++)
	{
		if(redt == true && redd == team1.teamTurn())
		{
			if(bluet == true)
				board[blue[i].plyy][blue[i].plyx] = 'b';
			if(greent == true)
				board[green[i].plyy][green[i].plyx] = 'g';
			if(yellowt == true)
				board[yellow[i].plyy][yellow[i].plyx] = 'y';
			board[red[i].plyy][red[i].plyx] = 'r';
		}
		else if(bluet == true && bluee == team1.teamTurn())
		{
			if(redt == true)
				board[red[i].plyy][red[i].plyx] = 'r';
			if(greent == true)
				board[green[i].plyy][green[i].plyx] = 'g';
			if(yellowt == true)
				board[yellow[i].plyy][yellow[i].plyx] = 'y';
			board[blue[i].plyy][blue[i].plyx] = 'b';
		}
		else if(greent == true && greenn == team1.teamTurn())
		{
			if(redt == true)
				board[red[i].plyy][red[i].plyx] = 'r';
			if(bluet == true)
				board[blue[i].plyy][blue[i].plyx] = 'b';
			if(yellowt == true)
				board[yellow[i].plyy][yellow[i].plyx] = 'y';
			board[green[i].plyy][green[i].plyx] = 'g';
		}
		else if(yellowt == true && yelloww == team1.teamTurn())
		{
			if(redt == true)
				board[red[i].plyy][red[i].plyx] = 'r';
			if(bluet == true)
				board[blue[i].plyy][blue[i].plyx] = 'b';
			if(greent == true)
				board[green[i].plyy][green[i].plyx] = 'g';
			board[yellow[i].plyy][yellow[i].plyx] = 'y';
		}
	}
}

void rules()
{
	if(adv == true)
	{
		cout<<"Important things to know about the for Advance Sorry of Program:"<<endl;
		Sleep(700);
		cout<<"1. You are able to \"Bump\" your own team members back to start even if they are on the stretch to home"<<endl;
		Sleep(700);
		cout<<"2. To get a peice out of start the card has to be a 1"<<endl;
		Sleep(700);
		cout<<"3. You are able to \"Bump\" another teams peice back to there start(If it does not work don't worry)"<<endl;
		Sleep(700);
		cout<<"4. Numbers 0, 6, and 9 are sorry cards"<<endl;
		Sleep(700);
		cout<<"5. The computer will put the piece out for you if you do draw a sorry card"<<endl;
		Sleep(700);
		cout<<"6. It may take a long time to finish playing the game"<<endl;
		Sleep(700);
		cout<<"7. If you think the card drawing is rigged at anytime during the game it is not. You just not getting a lucky draw."<<endl;
		Sleep(700);
		cout<<"8. You will not see your move for moving into the home square or out of start until the next card is drawn."<<endl;
		Sleep(700);
		cout<<"9. Drawing the 2 card allows you either move a person out of start(Only works the first time 2 is drawn) or moved forward two spaces."<<endl;
		Sleep(700);
		cout<<"10. Some of the Classic sorry rules do apply."<<endl;
		Sleep(700);
		cout<<"11. Make sure if you have any questions reference the Sorry Rules online before you click any button to continue onto the program."<<endl;
		Sleep(700);
		cout<<"12. There will be another question asked if you want to be able to see what the computer drew or not. Saying yes will pause the program for the computers turn to see the card."<<endl
			<<"No will have the program wait a second or two before moving on to the next person or computers move(will be harder to see what the computer drew)."<<endl;
		Sleep(700);
		cout<<"13. The word \"Friendly\" Sorry will show up breifly before the big sorry graphic starts to print meaning that you have bumped your team mate back to start."<<endl;
		Sleep(700);
		cout<<"14. If anything randomly changes colors don't worry about it because the colors will change back."<<endl;
		Sleep(700);
		cout<<"15. If a incorrect number that is higher or is not in the given range of number the program provides to enter. The program might not work as it should."<<endl;
		Sleep(700);
		cout<<"16. If a dot or character is entered into the program part that accepts an int it will start running on its own as a broken program."<<endl;
		Sleep(700);
		cout<<"Have fun and enjoy playing."<<endl;
		system("pause");
	}
	else
	{
		cout<<"Important things to know about the Classic Sorry Version of Program:"<<endl;
		Sleep(700);
		cout<<"1. You are able to \"Bump\" your own team members back to start even if they are on the stretch to home"<<endl;
		Sleep(700);
		cout<<"2. To get piece out of start the card can be a 1 or 2"<<endl;
		Sleep(700);
		cout<<"3. The computer will put the piece out for you if you do draw a sorry card"<<endl;
		Sleep(700);
		cout<<"4. Some of the special events of cards that are drawn may not be in the program like in a board game of sorry."<<endl;
		Sleep(700);
		cout<<"5. Game should be close to what classic sorry is."<<endl;
		Sleep(700);
		cout<<"6. If you think the card drawing is rigged at anytime during the game it is not. You just not getting a lucky draw."<<endl;
		Sleep(700);
		cout<<"7. Drawing the 2 card allows you either move a person out of start(Only works the first time 2 is drawn) or moved forward two spaces."<<endl;
		Sleep(700);
		cout<<"8. Numbers 0, 6, and 9 are sorry cards"<<endl;
		Sleep(700);
		cout<<"9. You will not see your move for moving into the home square or out of start until the next card is drawn."<<endl;
		Sleep(700);
		cout<<"10. There will be another question asked if you want to be able to see what the computer drew or not. Saying yes will pause the program for the computers turn to see the card."<<endl
			<<"No will have the program wait a second or two before moving on to the next person or computers move(will be harder to see what the computer drew)."<<endl;
		Sleep(700);
		cout<<"11. After making your move and it seems like the program is taking forever to load its most likely due to the program trying to draw a card. Could take a couple of seconds to do."<<endl;
		Sleep(700);
		cout<<"12. The word \"Friendly\" Sorry will show up breifly before the big sorry graphic starts to print meaning that you have bumped your team mate back to start."<<endl;
		Sleep(700);
		cout<<"13. It may take a long time to finish playing the game."<<endl;
		Sleep(700);
		cout<<"14. If anything randomly changes colors don't worry about it because the colors will change back."<<endl;
		Sleep(700);
		cout<<"15. If a incorrect number that is higher or is not in the given range of number the program provides to enter. The program might not work as it should."<<endl;
		Sleep(700);
		cout<<"16. If a dot or character is entered into the program part that accepts an int it will start running on its own as a broken program."<<endl;
		Sleep(700);
		cout<<"Have fun play Sorry"<<endl;
		system("pause");
	}
}

void playerBump()
{
	for(int i = 0; i < 4; i++)
	{
		if(redt == true && redd == team1.teamTurn())
		{
			if(red[i].pstart == true && red[i].phome == false)
			{
				for(int n = 0; n < 4; n++)
				{
					if(blue[n].pstart == false && blue[n].phome == false)
					{
						board[red[i].plyy][red[i].plyx] = '-';
						red[i].plyy = blue[n].plyy;
						red[i].plyx = blue[n].plyx;
						board[red[i].plyy][red[i].plyx] = 'r';
						red[i].pstart = false;
						rStart(1,n);
						return;
					}
					else if(green[n].pstart == false && green[n].phome == false)
					{
						board[red[i].plyy][red[i].plyx] = '-';
						red[i].plyy = green[n].plyy;
						red[i].plyx = green[n].plyx;
						board[red[i].plyy][red[i].plyx] = 'r';
						red[i].pstart = false;
						rStart(2,n);
						return;
					}
					else if(yellow[n].pstart == false && yellow[n].phome == false)
					{
						board[red[i].plyy][red[i].plyx] = '-';
						red[i].plyy = yellow[n].plyy;
						red[i].plyx = yellow[n].plyx;
						board[red[i].plyy][red[i].plyx] = 'r';
						red[i].pstart = false;
						rStart(3,n);
						return;
					}
				}
			}
		}
		else if(bluet == true && bluee == team1.teamTurn())
		{
			if(blue[i].pstart == true && blue[i].phome == false)
			{
				for(int n = 0; n < 4; n++)
				{
					if(red[n].pstart == false && red[n].phome == false)
					{
						board[blue[i].plyy][blue[i].plyx] = '-';
						blue[i].plyy = red[n].plyy;
						blue[i].plyx = red[n].plyx;
						board[blue[i].plyy][blue[i].plyx] = 'b';
						blue[i].pstart = false;
						bStart(0,n);
						return;
					}
					else if(green[n].pstart == false && green[n].phome == false)
					{
						board[blue[i].plyy][blue[i].plyx] = '-';
						blue[i].plyy = green[n].plyy;
						blue[i].plyx = green[n].plyx;
						board[blue[i].plyy][blue[i].plyx] = 'b';
						blue[i].pstart = false;
						bStart(2,n);
						return;
					}
					else if(yellow[n].pstart == false && yellow[n].phome == false)
					{
						board[blue[i].plyy][blue[i].plyx] = '-';
						blue[i].plyy = yellow[n].plyy;
						blue[i].plyx = yellow[n].plyx;
						board[blue[i].plyy][blue[i].plyx] = 'b';
						blue[i].pstart = false;
						bStart(3,n);
						return;
					}
				}
			}
		}
		else if(greent == true && greenn == team1.teamTurn())
		{
			if(green[i].pstart == true && green[i].phome == false)
			{
				for(int n = 0; n < 4; n++)
				{
					if(red[n].pstart == false && red[n].phome == false)
					{
						board[green[i].plyy][green[i].plyx] = '-';
						green[i].plyy = red[n].plyy;
						green[i].plyx = red[n].plyx;
						board[green[i].plyy][green[i].plyx] = 'g';
						green[i].pstart = false;
						gStart(0,n);
						return;
					}
					else if(blue[n].pstart == false && blue[n].phome == false)
					{
						board[green[i].plyy][green[i].plyx] = '-';
						green[i].plyy = blue[n].plyy;
						green[i].plyx = blue[n].plyx;
						board[green[i].plyy][green[i].plyx] = 'g';
						green[i].pstart = false;
						gStart(1,n);
						return;
					}
					else if(yellow[n].pstart == false && yellow[n].phome == false)
					{
						board[green[i].plyy][green[i].plyx] = '-';
						green[i].plyy = yellow[n].plyy;
						green[i].plyx = yellow[n].plyx;
						board[green[i].plyy][green[i].plyx] = 'g';
						green[i].pstart = false;
						gStart(3,n);
						return;
					}
				}
			}
		}
		else if(yellowt == true && yelloww == team1.teamTurn())
		{
			if(yellow[i].pstart == true && yellow[i].phome == false)
			{
				for(int n = 0; n < 4; n++)
				{
					if(red[n].pstart == false && red[n].phome == false)
					{
						board[yellow[i].plyy][yellow[i].plyx] = '-';
						yellow[i].plyy = red[n].plyy;
						yellow[i].plyx = red[n].plyx;
						board[yellow[i].plyy][yellow[i].plyx] = 'y';
						yellow[i].pstart = false;
						yStart(0,n);
						return;
					}
					else if(blue[n].pstart == false && blue[n].phome == false)
					{
						board[yellow[i].plyy][yellow[i].plyx] = '-';
						yellow[i].plyy = blue[n].plyy;
						yellow[i].plyx = blue[n].plyx;
						board[yellow[i].plyy][yellow[i].plyx] = 'y';
						yellow[i].pstart = false;
						yStart(1,n);
						return;
					}
					else if(green[n].pstart == false && green[n].phome == false)
					{
						board[yellow[i].plyy][yellow[i].plyx] = '-';
						yellow[i].plyy = green[n].plyy;
						yellow[i].plyx = green[n].plyx;
						board[yellow[i].plyy][yellow[i].plyx] = 'y';
						yellow[i].pstart = false;
						yStart(2,n);
						return;
					}
				}
			}
		}
	}
}