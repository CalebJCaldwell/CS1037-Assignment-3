#include "stdafx.h"
#include "MatchPlayer.h"
#include <string>

int MatchPlayer::num = 0;

MatchPlayer::MatchPlayer() {
	num++;
	name = "Player " + std::to_string(num);
	hand = OrderedList<MatchCard>();
}

MatchPlayer::~MatchPlayer() {

}

unsigned int MatchPlayer::searchRank(MatchCard match) {

	unsigned int sz = hand.getLength();

	for (int i = 1; i <= sz; i++) {
		if (match.getRank() == hand.retrieve(i).getRank()) {
			return i;
		}
	}
	return -1;
}

unsigned int MatchPlayer::searchSuit(MatchCard match) {

	unsigned int sz = hand.getLength();

	for (int i = 1; i <= sz; i++) {
		if (match.getSuit() == hand.retrieve(i).getSuit()) {
			return i;
		}
	}
	return -1;
}

void MatchPlayer::removeCard(unsigned int index) {
	hand.remove(index);
}

void MatchPlayer::addCard(MatchCard card) {
	hand.insert(card);
}

std::ostream& operator<<(std::ostream &os, const MatchPlayer &p) {     // Implementation for the << operator override
	int handSize = p.getHandSize();
	std::string name = p.getName();

	os << name;

	return os;
}