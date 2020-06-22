#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "main.hpp"

void createDeck(vector<Card> & deck) {
  for(int i = 0; i < 52; i++) {
    int rank = (i % 13) + 1;
    int suit = (i / 13) + 1;
    
    Suit s;
    switch (suit) {
      case (1)    : s = Spade; break;
      case (2)    : s = Heart; break;
      case (3)    : s = Club; break;
      case (4)    : s = Diamond; break;
    }
    
    Card card(rank, s);
    deck.push_back(card);
  }
}

bool checkDeck(vector<Card> & deck) {
  for(int i = 0; i < 52; i++) {
    int rank = (i % 13) + 1;
    int suit = (i / 13) + 1;
    
    Suit s;
    switch (suit) {
      case (1)    : s = Spade; break;
      case (2)    : s = Heart; break;
      case (3)    : s = Club; break;
      case (4)    : s = Diamond; break;
    }
    
    Card card(rank, s);
    if (deck[i] != card) {
      return false;
    }
  }
  
  return true;
}

bool checkDeckInverse(vector<Card> & deck) {
  for(int i = 0; i < 52; i++) {
    int rank = 13 - (i % 13);
    int suit = (i / 13) + 1;
    
    Suit s;
    switch (suit) {
      case (1)    : s = Spade; break;
      case (2)    : s = Heart; break;
      case (3)    : s = Club; break;
      case (4)    : s = Diamond; break;
    }
    
    Card card(rank, s);
    if (deck[i] != card) {
      return false;
    }
  }
  
  return true;
}

bool linearSearch(vector<int> & inputArr, int searchKey) {
  for (int i = 0; i < inputArr.size(); i++) {
    if (inputArr[i] == searchKey) {
      return true;
    }
  }
  
  return false;
}

bool verifySearchArray (vector<int> searchArray) {
  for (int i = 0; i < searchArray.size(); i++) {
    bool result = linearSearch (searchArray, i + 1);
    if (result == false) {
      return false;
    }
  }
  
  return true;
}

TEST_CASE ("Deck Sorting") {
  vector<Card> deck;
  createDeck(deck);
  random_shuffle(deck.begin(), deck.end());
  
  deckSort(deck);
  
  REQUIRE (checkDeck(deck) == true);
}

TEST_CASE ("Inverse Deck Sorting") {
  vector<Card> deck;
  createDeck(deck);
  random_shuffle(deck.begin(), deck.end());
  
  inverseDeckSort(deck);
  printDeck(deck);
  
  REQUIRE (checkDeckInverse(deck) == true);
}

TEST_CASE ("Deck Sorting by Overloading > in Card Class") {
  vector<Card> deck;
  createDeck(deck);
  random_shuffle(deck.begin(), deck.end());
  
  deckSort2(deck);
  
  REQUIRE (checkDeck(deck) == true);
}

TEST_CASE ("Linear Search With Self-Organization 1") {
  int searchKey = 21;
  
  vector<int> searchArray(100);
  for (int i = 0; i < 100; i++) {
    searchArray[i] = i + 1;
  }
  // random_shuffle(searchArray.begin(), searchArray.end());
  
  bool result;
  result = linearSearchSO(searchArray, searchKey);
  
  REQUIRE (result == true);
  REQUIRE (verifySearchArray(searchArray) == true);
  REQUIRE (searchArray[0] == searchKey);
  REQUIRE (searchArray.size() == 100);
}

TEST_CASE ("Linear Search With Self-Organization 2") {
  srand(time(NULL));
  int searchKey = (rand() % 100) + 1;
  
  vector<int> searchArray(100);
  for (int i = 0; i < 100; i++) {
    searchArray[i] = i + 1;
  }
  random_shuffle(searchArray.begin(), searchArray.end());
  
  bool result;
  result = linearSearchSO(searchArray, searchKey);
  cout << searchKey << endl;
  
  REQUIRE (result == true);
  REQUIRE (verifySearchArray(searchArray) == true);
  REQUIRE (searchArray[0] == searchKey);
  REQUIRE (searchArray.size() == 100);
}

TEST_CASE ("Linear Search With Self-Organization 3") {
  int searchKey = 191;
  
  vector<int> searchArray(500);
  for (int i = 0; i < 500; i++) {
    searchArray[i] = i + 1;
  }
  random_shuffle(searchArray.begin(), searchArray.end());
  
  bool result, result2;
  result = linearSearchSO(searchArray, searchKey);
  int searchKey2 = 243;
  result2 = linearSearchSO(searchArray, searchKey2);

  REQUIRE (result == true);
  REQUIRE (result2 == true);
  REQUIRE (verifySearchArray(searchArray) == true);
  REQUIRE (searchArray[0] == searchKey2);
  REQUIRE (searchArray[1] == searchKey);
  REQUIRE (searchArray.size() == 500);
}
