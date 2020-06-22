#ifndef MAIN_H_
#define MAIN_H_

#include <vector>
#include "card.h"

void deckSort (std::vector<Card> & deck);
void inverseDeckSort (vector<Card> & deck);
void deckSort2 (std::vector<Card> & deck);
bool linearSearchSO(vector<int> & inputArr, int searchKey);

void printDeck(vector<Card> &deck);
void printArray (vector<int> inputArr);

#endif