/* 
 * File:   main.cpp
 * Author: Seth Tyler
 * Purpose: Deck class
 * Created on May 28, 2018
 */

#include "Card.h"
#include "NormalCard.h"
#include "SpecialCard.h"
#include "Deck.h"
#include <iostream>
using namespace std;

Deck::Deck(int size) {
    this->size = size;
}

Deck::~Deck() {
    delete []cards;
}

void Deck::deal(Deck &takeFrom) {
    cards = new Card[size];
    for (int i = 0; i < size; i++) {
       cards[i] = takeFrom.cards[0];
       
       // Remove the first card from the deck and shift everything -1
       for (int j = 0; j < (takeFrom.size - 1); j++) {
           takeFrom.cards[j] = takeFrom.cards[j + 1];
       }
       
       // Copy the current deck on to the new, smaller deck
       Card *newDeck = new Card[takeFrom.size - 1];
       for (int j = 0; j < (takeFrom.size - 1); j++) {
           newDeck[j] = takeFrom.cards[j];
       }
       delete []takeFrom.cards;
       takeFrom.cards = newDeck;
       takeFrom.size -= 1;
    }
}

int Deck::numCards = 0;

void Deck::fill() {
    int cardNum = 0;
    cards = new Card[size];
    for (int suit = 1; suit <= 4; suit++) {
        
        // Create the standard 1-10 numeric cards
        for (int val = 2; val <= 10; val++) {
            cards[cardNum] = NormalCard(suit, val);
            cardNum++;
            numCards++;
        }
        
        // Create the 3 face cards and an ace
        for (int type = 1; type <= 4; type++) {            
            cards[cardNum] = SpecialCard(suit, type);
            cardNum++;
            numCards++;
        }
    }
}

void Deck::show() {
    for (int i = 0; i < size; i++) {
        cout << cards[i].getReadable() << endl;
    }
}

void Deck::shuffle() {
    // Shuffle the deck
    for (int i = 0; i < size; i++) {
        int r = rand() % size;
        Card temp = cards[i];
        cards[i] = cards[r];
        cards[r] = temp;
    }
}

int Deck::bestSum() {
    // Calculate the best sum of a hand
    int sum = 0;
    int aceSum = 0;
    int numAces = 0;
    for (int i = 0; i < size; i++) {
        Card thisCard = cards[i];
        if (thisCard.getType() == 4) {
            sum += (numAces == 0 ? 11 : 1);
            aceSum += 1;
            numAces += 1;
        } else {
            sum += thisCard.getValue();
            aceSum += thisCard.getValue();
        }
    }
    
    if (sum <= 21 && aceSum <= 21) {
        return (sum > aceSum ? sum : aceSum);
    } else if (sum <= 21 && aceSum > 21) {
        return sum;
    } else if (sum > 21 && aceSum <= 21) {
        return aceSum;
    } else if (sum > 21 && aceSum > 21) {
        return (sum < aceSum ? sum : aceSum);
    }
}

void Deck::showSum() {
    // Output the total and best sum of a hand
    int sum = 0;
    int aceSum = 0;
    int numAces = 0;
    for (int i = 0; i < size; i++) {
        Card thisCard = cards[i];
        if (thisCard.getType() == 4) {
            sum += (numAces == 0 ? 11 : 1);
            aceSum += 1;
            numAces += 1;
        } else {
            sum += thisCard.getValue();
            aceSum += thisCard.getValue();
        }
    }
    
    if (numAces == 0) {
        cout << "TOTAL SUM: " << sum << endl;
    } else {
        cout << "TOTAL SUM: " << sum << " / " << aceSum << endl;
    }
    cout << "BEST SUM: " << bestSum() << endl;
}

void Deck::addCard(Deck &fromDeck) {
    Card *newDeck = new Card[size + 1];
    for (int i = 0; i < size; i++) {
        newDeck[i] = cards[i];
    }
    delete []cards;
    cards = newDeck;
    size += 1;
    cards[size - 1] = fromDeck.cards[0];
    
    Card *newCrds = new Card[fromDeck.size - 1];
    for (int i = 0; i < (fromDeck.size - 1); i++) {
        newCrds[i] = fromDeck.cards[i + 1];
    }
    delete []fromDeck.cards;
    fromDeck.cards = newCrds;
    fromDeck.size -= 1;
}

int Deck::operator +(Deck &right) {
    return (size + right.size);
}