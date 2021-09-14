class cards
{
public:
	void drawCard();
	int getCard()const;
	void countCard(int);
	bool checkCard(int);
	bool getSO();
	void setCardB();
	void showSorry();
	void showFS();
	void reShuffle();
	void reShuffleCard();
	cards();

private:
	int card, one, two, three, four, five, seven, eight, ten, eleven, tweleve, sorry;
	bool o, tw, th, fo, fi, se, ei, te, el, twe, so;
};