#pragma once
#include <iostream>

enum Suit { Spades = 1, Hearts = 2, Clubs = 3, Diamonds = 4 };

class MatchCard {
private:
	Suit suit;                                                               // Denotes the suit of the card
	int rank;                                                                // Denotes the card rank (ace/1, 2, etc)
	friend std::ostream& operator<<(std::ostream& os, const MatchCard &c);   // Overriding the operator <<

public:
	MatchCard();                                                             // Default constructor creates ace of spades (rip lemmy)
	MatchCard(Suit s, int r);                                                // Constructor with initialized values
	~MatchCard();                                                            // Destructor

	inline Suit getSuit() const { return suit; };                            // Returns the suit of a given card
	inline int getRank() const { return rank; };							 // Returns the rank of a given card

};

inline bool operator==(MatchCard& a, MatchCard& b) {                         // Overrides the == operator to compare two cards, checking if 
	return (a.getRank() == b.getRank() && a.getSuit() == b.getSuit());		 // the suit and rank of the cards are the same
}

inline bool operator<(const MatchCard& a, const MatchCard& b) {
	if (a.getSuit() == b.getSuit()) return (a.getRank()<b.getRank());
	else                            return (a.getSuit()<b.getSuit());
}

inline bool operator>(const MatchCard& a, const MatchCard& b) {
	if (a.getSuit() == b.getSuit()) return (a.getRank()>b.getRank());
	else                            return (a.getSuit()>b.getSuit());
}
