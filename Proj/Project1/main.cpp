/* 
 * File:   main.cpp
 * Author: Seth Tyler
 * Purpose: Project 1: Blackjack
 * Created on April 22, 2018
 */

// System libraries
#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>
#include <ctime>
#include <cstdlib>
#include <string.h>
#include <sstream>
#include <vector>
#include <fstream>
using namespace std;

// Structures
#include "Card.h"
#include "Deck.h"

// Function prototypes
void intro();
void filDeck(Card*);
int getBet(int&, int);
void shuffle(Deck&);
void removeFromDeck(Deck&);
void deal(int amount, Deck&, Deck&);
void readable(Card);
void showSum(Deck&);
void addCard(Deck&, Deck&);
int bestSum(Deck);
void results(int, int, int&, int&);

int main() {
    
    srand(time(NULL));
    
    // Player's cash
    int cash = 100;
    
    fstream dataFile;
    dataFile.open("money.txt", ios::in | ios::out);
    if (dataFile.fail()) {
        cash = 100;
    } else {
       dataFile >> cash; 
    }
    dataFile.close();
    
    // Repeat the game until player enters something other than Y or y.
    char playAgain = 'Y';
    
    // Run the intro
    intro();
    
    // Run the game
    do {
        
        char hit;
        
        // Create the deck
        Deck deck;
        deck.size = 52;
        deck.cards = new Card[deck.size];
        filDeck(deck.cards);
        
        int bet = 0;
        cout << "Please place your bet. (Minimum bet: $6 | Current balance: $" << cash << ".00 : ";
        cin >> bet;
        getBet(bet, cash);
        cout << endl << "You bet $" << bet << ".00\n"
                << "The dealer will now shuffle the deck and deal out the cards.\n";
        
        cout << "Shuffling...\n";
        shuffle(deck);
        
        cout << "The dealer will now deal out the cards.\n";
        
        // Create decks for dealer and player
        Deck hand;
        hand.size = 2;
        hand.cards = new Card[hand.size];
  
        Deck dealer;
        dealer.size = 2;
        dealer.cards = new Card[dealer.size];
        
        int best = 0;
        
        deal(2, hand, deck);
        deal(2, dealer, deck);
        
        // Display decks
        cout << endl << "---------- DEALER'S CARDS ----------\n";
        readable(dealer.cards[0]);
        cout << "ONE CARD STILL FACE DOWN\n";
        cout << "TOTAL SUM (SO FAR): " << dealer.cards[0].value << "\n";
        cout << "-------------------------------------\n";
        
        cout << endl << "---------- YOUR CARDS ----------\n";
        for (int i = 0; i < hand.size; i++) {
            readable(hand.cards[i]);
        }
        showSum(hand);
        cout << "--------------------------------\n";
        
        // Ask player if they want to stay or hit
        do {
            cout << endl << "Would you like to stay (keep your cards) or hit (request another card)? Press 1 to stay and 2 to hit: ";
            cin >> hit;

            if (hit == '2') {
                addCard(hand, deck);
                cout << endl << "---------- YOUR CARDS ----------\n";
                for (int i = 0; i < hand.size; i++) {
                    readable(hand.cards[i]);
                }
                showSum(hand);
                cout << "--------------------------------\n";
            }
            
            best = bestSum(hand);
        } while (hit == '2' && best <= 21);
        
        // Check if the player busted
        bool bust = false;
        if (best > 21) {
            bust = true;
            cash -= bet;
            cout << endl << "BUST! You lose. Dealer wins.\n";
            cout << "You now have $" << cash << ".00" << endl;
        }
        
        // Play the dealer's turn
        if (!bust) { 
            cout << endl << "Dealer's turn...\n";
            
            cout << endl << "---------- DEALER'S CARDS ----------\n";
            for (int i = 0; i < dealer.size; i++) {
                readable(dealer.cards[i]);
            }
            showSum(dealer);
            cout << "-------------------------------------\n";
 
            int dealerSum = bestSum(dealer);
            while (dealerSum <= 12) {
                addCard(dealer, deck);
                dealerSum = bestSum(dealer);
            }
            
            results(dealerSum, best, cash, bet);
        }
        
        // Ask to play again if money is sufficient
        if (cash >= 6) {
            cout << endl << "Would you like to play again? Enter Y for YES and N for NO: ";
            cin >> playAgain;
        }

    } while ((playAgain == 'Y' || playAgain == 'y') && (cash >= 6));
    
    cout << "Goodbye!";
    
    return 0;
}

void intro() {
    char tutorial = 'N';
    
    // Output the intro text
    cout << "Welcome to Blackjack!\n"
            << "This game uses one standard 52 card deck.\n"
            << "Would you like to learn how to play? Enter Y for YES and N for NO: ";
    cin >> tutorial;
    
    // Display the instructions if user inputs Y or y
    if (tutorial == 'Y' || tutorial == 'y') {
        cout << endl << "You will be dealt two cards. The objective of the game is to get the sum of your cards to be as close to 21 as possible.\n"
                << "If the sum of your cards goes over 21, you will bust and lose your money.\n"
                << "In this game, it is you versus the dealer. If the sum of your cards is lower than the dealer's, you lose.\n"
                << "If the sum of your cards is equal to the dealer's, the round will be over and you will take back your bet.\n";
    }
    
    cout << endl << "Please note that in this game, there is no splitting, insurance, or doubling.\n";
    cout << "Let's get started.\n\n";
}

void filDeck(Card* deck) {
    int cardNum = 0;
    for (int suit = 1; suit <= 4; suit++) {
        
        // Create the standard 1-10 numeric cards
        for (int val = 2; val <= 10; val++) {
            Card newCard;
            newCard.suit = suit;
            newCard.value = val;
            newCard.type = 0;
            deck[cardNum] = newCard;
            cardNum++;
        }
        
        // Create the 3 face cards and an ace
        for (int type = 1; type <= 4; type++) {
            Card newCard;
            newCard.suit = suit;
            newCard.value = (type == 4 ? 11 : 10);
            newCard.type = type;
            deck[cardNum] = newCard;
            cardNum++;
        }
    }
}

int getBet(int &bet, int cash) {
    // Input validation for bet
    if (bet < 6 || bet > cash) {
        cout << "Your bet must be at least $6 and no more than $100. Enter a new bet: ";
        cin >> bet;
        cout << endl;
        getBet(bet, cash);
    }
    return bet;
}

void shuffle(Deck &crdDeck) {
    // Shuffle the deck
    for (int i = 0; i < crdDeck.size; i++) {
        int r = rand() % crdDeck.size;
        Card temp = crdDeck.cards[i];
        crdDeck.cards[i] = crdDeck.cards[r];
        crdDeck.cards[r] = temp;
    }
}

void removeFromDeck(Deck &crdDeck) {
    // Remove the first card from the deck and shift everything -1
    for (int i = 1; i <= crdDeck.size; i++) {
        crdDeck.cards[i - 1] = crdDeck.cards[i];
    }
    crdDeck.size -= 1;
}

void deal(int amount, Deck &crdDeck, Deck &mainDeck) {
    // Establish the first deck
    for (int i = 0; i < amount; i++) {
        crdDeck.cards[i] = mainDeck.cards[0];
        removeFromDeck(mainDeck);
    }
}

void readable(Card card) {
    // Output a card into a readable format for the player
    switch (card.type) {
        case 0: cout << card.value << " OF ";
            break;
        case 1: cout << "JACK OF ";
            break;
        case 2: cout << "QUEEN OF ";
            break;
        case 3: cout << "KING OF ";
            break;
        case 4: cout << "ACE OF ";
            break;
        default: "INVALID";
            break;
    }
    
    switch (card.suit) {
        case 1: cout << "HEARTS";
            break;
        case 2: cout << "CLUBS";
            break;
        case 3: cout << "SPADES";
            break;
        case 4: cout << "DIAMONDS";
            break;
        default: "INVALID";
            break;
    }
    
    cout << " (VALUE: ";
    
    if (card.value < 11) {
        cout << card.value;
    } else {
        cout << "1 / 11";
    }
    
    cout << ")" << endl;
}

int bestSum(Deck crdDeck) {
    // Calculate the best sum of a hand
    int sum = 0;
    int aceSum = 0;
    int numAces = 0;
    for (int i = 0; i < crdDeck.size; i++) {
        Card thisCard = crdDeck.cards[i];
        if (thisCard.type == 4) {
            sum += (numAces == 0 ? 11 : 1);
            aceSum += 1;
            numAces += 1;
        } else {
            sum += thisCard.value;
            aceSum += thisCard.value;
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

void showSum(Deck &crdDeck) {
    // Output the total and best sum of a hand
    int sum = 0;
    int aceSum = 0;
    int numAces = 0;
    for (int i = 0; i < crdDeck.size; i++) {
        Card thisCard = crdDeck.cards[i];
        if (thisCard.type == 4) {
            sum += (numAces == 0 ? 11 : 1);
            aceSum += 1;
            numAces += 1;
        } else {
            sum += thisCard.value;
            aceSum += thisCard.value;
        }
    }
    
    if (numAces == 0) {
        cout << "TOTAL SUM: " << sum << endl;
    } else {
        cout << "TOTAL SUM: " << sum << " / " << aceSum << endl;
    }
    cout << "BEST SUM: " << bestSum(crdDeck) << endl;
}

void addCard(Deck &crdDeck, Deck &mainDeck) {
    // Append a card to a deck
    crdDeck.size += 1;
    crdDeck.cards[crdDeck.size - 1] = mainDeck.cards[0];
    removeFromDeck(mainDeck);
}

void results(int dealerSum, int best, int &cash, int &bet) {
    // Show results
    cout << "DEALER: " << dealerSum << "; YOU: " << best << endl;
    if (dealerSum > 21) {
        cout << "The dealer busted! You win!\n";
        cash += bet;
        cout << "You now have $" << cash << ".00" << endl;
    } else if (dealerSum == best) {
        cout << "Draw! You take your bet back.\n";
    } else if (dealerSum < best) {
        cout << "You have the better number. You win!\n";
        cash += bet;
        cout << "You now have $" << cash << ".00" << endl;
    } else if (dealerSum > best) {
        cout << "The dealer wins!\n";
        cash -= bet;
        cout << "You now have $" << cash << ".00" << endl;
    }
}