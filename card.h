#ifndef CARD_H_
#define CARD_H_

#include<iostream>

using namespace std;

// Don't change the order of suits in this enum
// To keep things simple, we are going to assume the order of suits in this enum
// as the order of suits in the sorted deck
enum Suit {Joker, Spade, Heart, Club, Diamond};

class Card {
private:
  int cardRank;
  Suit cardSuit;
public:
  Card();
  Card(int rank, Suit suit);
  
  void setRank(int rank);
  void setSuit(Suit suit);
  int getRank() const;
  Suit getSuit() const;
  
  bool operator!= (const Card & c2);
  bool operator > (const Card & c2);
  friend ostream& operator<< (ostream &out, Card card);
};

#endif