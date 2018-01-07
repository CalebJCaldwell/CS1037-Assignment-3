#pragma once
#include "MatchPlayer.h"
#include "MatchCard.h"
#include "Stack.h"
#include "Queue.h"
#include "LinkedList.h"
class MatchGame {
private:
	Stack<MatchCard> pile;
	Queue<MatchCard> deck;
	Queue<MatchPlayer*> playerOrder;

public:
	MatchGame(unsigned int numPlayers, unsigned int maxRank);
	~MatchGame();
	void play();
};

