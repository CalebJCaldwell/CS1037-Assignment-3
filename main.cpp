#include "stdafx.h"
#include <string>
#include <iostream>
#include "MatchGame.h"
#include "MatchPlayer.h"
#include "queue.h"

using namespace std;

int main()
{
	unsigned int players;
	unsigned int rank;

	cout << "Welcome to MATCH" << endl;
	cout << "Enter number of players: ";
	cin >> players;
	cout << "Enter maximum card rank: ";
	cin >> rank;

	MatchGame game(players, rank);
	game.play();

	return 0;


}
