class homes
{
public:
	void setTimes(int);//will set the proper bool variable true for a team mate going around the board
	bool getBord(int, int);//will get the bool so that when they are in front of home they can go in
	void setVars();
	void addCount(int);
	void changeh(int, int);//will change the bools to true
	int getTcount(int);//will get the number of players for each team for the amount of players that are at home
	homes();

private:
	bool r1, r2, r3, r4, b1, b2, b3, b4, g1, g2, g3, g4, y1, y2, y3, y4;
	int rcount, bcount, gcount, ycount;
};