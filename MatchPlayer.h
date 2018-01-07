#pragma once
#include "OrderedList.h"
#include "MatchCard.h"
#include <iostream>

class MatchPlayer {

private:
	std::string name;
	OrderedList<MatchCard> hand;
	static int num;

public:
	MatchPlayer();
	~MatchPlayer();

	unsigned int searchRank(MatchCard match);
	unsigned int searchSuit(MatchCard match);
	void removeCard(unsigned int index);
	void addCard(MatchCard card);

	inline int getHandSize() const { return hand.getLength(); };
	inline MatchCard getCardAt(int x) { return hand.retrieve(x); }
	inline std::string getName() const { return name; };
};
