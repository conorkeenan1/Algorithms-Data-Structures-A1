#include <iostream>
#include <algorithm> // for random_shuffle
#include <cstdlib>
#include <ctime>
#include <vector>
#include "card.h"
#include "main.hpp"

using namespace std;

void printDeck(vector<Card> &deck) {
  for (int i = 0; i < 52; i++) {
    std::cout << deck[i] << ", ";
  }
  std::cout << std::endl;
}

void deckSort (vector<Card> & deck) {
  /* In this function add the code for answering the Question 1 in the assignment.
  The sorted deck of cards should be present in the parameter deck passed to this function.
  */
	for (int i = 0; i < deck.size()-1; i++)
	{
		for (int j = 0; j < deck.size() - i - 1; j++)
		{
			if (deck[j].getSuit() > deck[j+1].getSuit())
			{
				swap(deck[j], deck[j+1]);
			}
			else if(deck[j].getSuit() == deck[j+1].getSuit() && deck[j].getRank() > deck[j+1].getRank())
			{
				swap(deck[j], deck[j+1]);
			}
		}
	}
}

void inverseDeckSort (vector<Card> & deck) {
  /* In this function add the code for answering the Question 3 in the assignment.
  The sorted deck of cards should be present in the parameter deck passed to this function.
  */
	for (int i = 0; i < deck.size() - 1; i++)
	{
		for (int j = 0; j < deck.size() - i - 1; j++)
		{
			if (deck[j].getSuit() > deck[j + 1].getSuit())
			{
				swap(deck[j], deck[j + 1]);
			}
			else if (deck[j].getSuit() == deck[j + 1].getSuit() && deck[j].getRank() < deck[j + 1].getRank())//less than sign will sort in inverse order
			{
				swap(deck[j], deck[j + 1]);
			}
		}
	}
}

void deckSort2 (vector<Card> & deck) {
  /* In this function add the code for answering the Question 2 in the assignment.
  The sorted deck of cards should be present in the parameter deck passed to this function.
  */
	for (int i = 0; i < deck.size() - 1; i++)
	{
		for (int j = 0; j < deck.size() - i - 1; j++)
		{
			if (deck[j] > deck[j + 1])
			{
				swap(deck[j], deck[j + 1]);
			}
		}
	}
}

bool linearSearchSO(vector<int> & inputArr, int searchKey) {
  /*In this function we will find the number and then shift it to first poiction*/
	for (int i = 0; i < inputArr.size(); i++)
	{
		if (inputArr[i] == searchKey)
		{
			for (int j = i; j > 0; j--)
			{
				swap(inputArr[j], inputArr[j - 1]);
			}
			return true;
		}
	}
  return false;
}

void printArray (vector<int> inputArr) {
  for (int i = 0; i < inputArr.size(); i++) {
    cout << inputArr[i] << ", ";
  }
  cout << endl;
}