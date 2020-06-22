#include "card.h"

Card::Card() {
  cardRank = 0;
  cardSuit = Joker;
}

Card::Card(int rank, Suit suit) {
  cardRank = rank;
  cardSuit = suit;
}

void Card::setRank(int rank) {
  cardRank = rank;
}

void Card::setSuit(Suit suit) {
  cardSuit = suit;
}

int Card::getRank() const{
  return cardRank;
}

Suit Card::getSuit() const {
  return cardSuit;
}

bool Card::operator!= (const Card & c2) {
  if ((static_cast<int>(cardSuit) != static_cast<int>(c2.getSuit())) || (cardRank != c2.getRank())) {
    return true;
  }
  
  return false;
}
bool Card::operator > (const Card & c2)
{
	if (getSuit() > c2.getSuit())
	{
		return true;
	}
	if (getSuit() == c2.getSuit() && getRank() > c2.getRank())
	{
		return true;
	}
	return false;
}

ostream& operator << (ostream & out, Card card) {
  out << card.cardRank;
  switch (card.cardSuit) {
    case (Spade)    : out << "S"; break;
    case (Heart)    : out << "H"; break;
    case (Club)     : out << "C"; break;
    case (Diamond)  : out << "D"; break;
    default         : out << "Joker"; break;
  }
  
  return out;
}