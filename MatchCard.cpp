#include "stdafx.h"
#include "MatchCard.h"

MatchCard::MatchCard() {                                             // Default constructor w/ ace of spades (as a (((best practices))) thing)
	suit = Spades;
	rank = 1;
}

MatchCard::MatchCard(Suit s, int r) {                                // Suit and rank to be set with this constructor
	suit = s;
	rank = r;
}

MatchCard::~MatchCard() {
}

std::ostream& operator<<(std::ostream& os, const MatchCard &c) {     // Implementation for the << operator override
	int suit = c.getSuit();
	int rank = c.getRank();

	if (rank == 1) os << "Ace";                                      // Ace will be in the ostream obj if rank is 1
	else os << rank;                                                 // Else the rank number will be used directly


	switch (suit) {                                                  // Switch statement to add a given suit to ostream obj based on enum
	case 1:
		os << " of Spades";
		break;
	case 2:
		os << " of Hearts";
		break;
	case 3:
		os << " of Clubs";
		break;
	default:
		os << " of Diamonds";
	}
	return os;
}