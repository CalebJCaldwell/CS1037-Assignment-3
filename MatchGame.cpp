#include "stdafx.h"
#include "MatchGame.h"
#include <cstdlib>
#include <ctime>
#include <string>
#include <iostream>
#include "MatchPlayer.h"

MatchGame::MatchGame(unsigned int numPlayers = 4, unsigned int maxRank = 10) {

	srand(time(NULL));
	MatchCard * cardsArray = new MatchCard[4 * maxRank];

	//Populating the cardsArray array with all the cards from ace to max rank for each suit
	for (int i = 0; i < maxRank; i++) cardsArray[i] = MatchCard(Spades, i + 1);
	for (int i = maxRank; i < 2 * maxRank; i++) cardsArray[i] = MatchCard(Hearts, i + 1 - maxRank);
	for (int i = 2 * maxRank; i < 3 * maxRank; i++) cardsArray[i] = MatchCard(Clubs, i + 1 - 2 * maxRank);
	for (int i = 3 * maxRank; i < 4 * maxRank; i++) cardsArray[i] = MatchCard(Diamonds, i + 1 - 3 * maxRank);

	/*
	shuffler algorithm: takes the array and randomly puts it at the head or tail of a linked list
	then the data of the linked list is passed back to the array, and is randomly used to repopulate
	the linked list a second time. this is passed to the deck queue and the original array is deleted.
	the queue will dequeue a random num of nodes 0 to (4*maxRank-1) and enqueue them at the end of the deck.
	the deck is now shuffled.
	*/

	LinkedList<MatchCard> shuffler;

	for (int i = 0; i < 4 * maxRank; i++) {
		bool choose = (rand() % 2);
		if (choose) shuffler.addHead(cardsArray[i]);
		else shuffler.addTail(cardsArray[i]);
	}

	for (int i = 0; i < 4 * maxRank; i++) cardsArray[i] = shuffler.removeHead();

	for (int i = 0; i < 4 * maxRank; i++) {
		bool choose = (rand() % 2);
		if (choose) shuffler.addHead(cardsArray[i]);
		else shuffler.addTail(cardsArray[i]);
	}
	unsigned int shift = rand() % (4 * maxRank);
	for (int i = 0; i < shift; i++) shuffler.addTail(shuffler.removeHead());
	for (int i = 0; i < 4 * maxRank; i++) deck.enqueue(shuffler.removeTail());

	delete[] cardsArray;



	int numCards = 6; //can be changed by the programmer to specify the number of cards a player's hand contains

	for (int i = 0; i <= numPlayers; i++) { //populates queue with as many players as numPlayers specifies and then adds 6 cards to each of their hands
		MatchPlayer * player = new MatchPlayer();
		playerOrder.enqueue(player);
	}


	for (int i = 0; i <= numPlayers; i++) {
		MatchPlayer * player = playerOrder.dequeue();
		for (int j = 0; j < numCards; j++) player->addCard(deck.dequeue());
		playerOrder.enqueue(player);
	}

	for (int i = 0; i < numPlayers; i++) { playerOrder.enqueue(playerOrder.dequeue()); };
	playerOrder.dequeue(); //I hate that this works

	pile.push(deck.dequeue()); //puts one card face-up on the pile
}

MatchGame :: ~MatchGame() {
}

void MatchGame::play() {

	bool resolved = 0;

	do {
		MatchPlayer * currentPlayer = playerOrder.dequeue();

		std::cout << currentPlayer->getName() << " is taking their turn, ";

		std::cout << pile.peek() << " is the face-up card" << std::endl << std::endl;

		std::cout << currentPlayer->getName() << "'s hand:" << std::endl;
		for (int i = 1; i <= currentPlayer->getHandSize(); i++) {
			std::cout << currentPlayer->getCardAt(i) << "   ";
			if (!(i % 2)) { std::cout << std::endl; }
		}

		if (currentPlayer->getHandSize() % 2) { std::cout << std::endl; }

		std::cout << std::endl;

		int rankIndex = currentPlayer->searchRank(pile.peek());
		int suitIndex = currentPlayer->searchSuit(pile.peek());

		if (suitIndex != -1 && rankIndex != -1) {
			if (rankIndex > suitIndex) {
				pile.push(currentPlayer->getCardAt(suitIndex));
				currentPlayer->removeCard(suitIndex);
			}
			else {
				pile.push(currentPlayer->getCardAt(rankIndex));
				currentPlayer->removeCard(rankIndex);
			}
			std::cout << currentPlayer->getName() << " found a card. They played " << pile.peek() << std::endl;

		}
		else if (suitIndex != -1) {
			pile.push(currentPlayer->getCardAt(suitIndex));
			currentPlayer->removeCard(suitIndex);
			std::cout << currentPlayer->getName() << " found a card. They played " << pile.peek() << std::endl;
		}

		else if (rankIndex != -1) {
			pile.push(currentPlayer->getCardAt(rankIndex));
			currentPlayer->removeCard(rankIndex);
			std::cout << currentPlayer->getName() << " found a card. They played " << pile.peek() << std::endl;
		}

		else {
			std::cout << currentPlayer->getName() << " did not find a card, they drew " << deck.peek() << " from the deck." << std::endl;
			currentPlayer->addCard(deck.dequeue());
		}


		if (deck.isEmpty()) {

			Stack<MatchCard> faceDown;
			MatchCard saveCard = pile.pop();


			while (!(pile.isEmpty())) faceDown.push(pile.pop());
			while (!(faceDown.isEmpty())) deck.enqueue(faceDown.pop());

			pile.push(saveCard);
		}

		if (currentPlayer->getHandSize() == 1) {
			std::cout << currentPlayer->getName() << " has one card left!" << std::endl;
		}

		if (currentPlayer->getHandSize() == 0) {
			std::cout << currentPlayer->getName() << " has emptied their hand! They win!" << std::endl;
			resolved = 1;
		}


		std::cout << "------------------------------" << std::endl;
		playerOrder.enqueue(currentPlayer); //rotate player order

	} while (!resolved);
}