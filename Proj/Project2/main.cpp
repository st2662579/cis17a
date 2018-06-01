/* 
 * File:   main.cpp
 * Author: Seth Tyler
 * Purpose: Project 2: Blackjack
 * Created on May 28, 2018
 */

// System Libraries
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <ctime>
#include <vector>
#include "Card.h"
#include "NormalCard.h"
#include "SpecialCard.h"
#include "Deck.h"

using namespace std;

// Function prototypes
void saveMoney(int&);
void readMoney(int&);
void intro();
void getBet(int&, int);
void results(int, int, int&, int&, vector<int>&);

int main() {
    
    srand(time(NULL));
    
    // Read in player's money from file
    int balance;
    readMoney(balance);
    
    // Run the game
    intro();
    
    // Create the main deck
    Deck mainDeck(52);
    mainDeck.fill();
    
    vector<int> wins;
    
    // Declare playAgain variable
    char playAgain = 'Y';
    
    do {
        
        char hit = 'N';
        int bet = 0;
        
        // Ask the player for their bet
        getBet(bet, balance);
        
        // Tell player that the dealer is going to shuffle and deal
        cout << "The dealer will now shuffle the deck and deal out the cards." << endl
                << "Shuffling...\n";
        //mainDeck.shuffle();
        mainDeck.shuffle();
        
        cout << endl <<"The dealer will now deal out the cards.\n";
       
        // Create the player's deck
        Deck player(2);
        player.deal(mainDeck);
        
        Deck dealer(2);
        dealer.deal(mainDeck);
        
        cout << endl << "---------- DEALER'S CARDS -----------\n";
        cout << dealer.cards[0].getReadable();
        cout << endl << "ONE CARD STILL FACE DOWN\n";
        cout << "TOTAL SUM (SO FAR): " << dealer.cards[0].getValue() << "\n";
        cout << "-------------------------------------\n";
        
        cout << endl << "------------ YOUR CARDS -------------\n";
        for (int i = 0; i < player.size; i++) {
            cout << player.cards[i].getReadable() << endl;
        }
        player.showSum();
        cout << "-------------------------------------\n\n";

        int best = 0;
    
        // Ask player if they want to stay or hit
        do {
            cout << endl << "Would you like to stay (keep your cards) or hit (request another card)? Press 1 to stay and 2 to hit: ";
            cin >> hit;

            if (hit == '2') {
                player.addCard(mainDeck);     
                cout << endl << "------------ YOUR CARDS -------------\n";
                for (int i = 0; i < player.size; i++) {
                    cout << player.cards[i].getReadable() << endl;
                }
                player.showSum();
                cout << "-------------------------------------\n\n";
            }
            
            best = player.bestSum();
        } while (hit == '2' && best <= 21);
        
        // Check if the player busted
        bool bust = false;
        if (best > 21) {
            bust = true;
            balance -= bet;
            cout << "BUST! You lose. Dealer wins.\n";
            cout << "You now have $" << balance << ".00" << endl;
            saveMoney(balance);
        }
        
        // Play the dealer's turn
        if (!bust) { 
            cout << endl << "Dealer's turn...\n";
            
            cout << endl << "---------- DEALER'S CARDS ----------\n";
            for (int i = 0; i < dealer.size; i++) {
                cout << dealer.cards[i].getReadable() << endl;
            }
            dealer.showSum();
            cout << "-------------------------------------\n\n";
 
            int dealerSum = dealer.bestSum();
            while (dealerSum <= 12) {
                cout << "DEALER HIT!\n";
                dealer.addCard(mainDeck);
                dealerSum = dealer.bestSum();
                for (int i = 0; i < dealer.size; i++) {
                    cout << dealer.cards[i].getReadable() << endl
                            << "-------------------------------------\n";
                }
            }
            cout << "DEALER STAYED\n\n";
            
            results(dealerSum, best, balance, bet, wins);
        }
        
        // Ask to play again if money is sufficient
        if (balance >= 6) {
            cout << endl << "Would you like to play again? Enter Y for YES and N for NO: ";
            cin >> playAgain;
        }
        
    } while ((playAgain == 'Y' || playAgain == 'y') && (balance >= 6));
    
    return 0;
}

void saveMoney(int &balance) {
    // Write balance to money.dat
    fstream outFile("money.dat", ios::out | ios::binary);
    outFile.write(reinterpret_cast<char *>(&balance), sizeof(balance));
    outFile.close();
}

void readMoney(int &balance) {
    // Default balance
    int dfltMny = 100;
    
    // Read in the balance from money.dat
    fstream inFile("money.dat", ios::in | ios::binary);
    inFile.read(reinterpret_cast<char *>(&balance), sizeof(balance));
    inFile.close();
    
    // Set balance to default if less than 6
    if (balance < 6) {
        balance = dfltMny;
        saveMoney(balance);
    }
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

void getBet(int &bet, int bal) {
    cout << "Please place your bet. (Minimum bet: $6 | Current balance: $" << bal << ".00) : ";
    cin >> bet;
    // Input validation for bet
    if (bet < 6 || bet > bal) {
        cout << "Your bet must be at least $6 and no more than your current balance. Enter a new bet: ";
        cin >> bet;
        cout << endl;
        getBet(bet, bal);
    } else {
        cout << "You bet $" << bet << ".00\n";
    }
}

template <class T>
T showWins(T &wins) {
    cout << wins.size();
    return wins.size();
}

void results(int dealerSum, int best, int &cash, int &bet, vector<int> &wins) {
    // Show results
    cout << "DEALER: " << dealerSum << "; YOU: " << best << endl;
    if (dealerSum > 21) {
        cout << "The dealer busted! You win!\n";
        cash += bet;
        cout << "You now have $" << cash << ".00" << endl;
        wins.push_back(1);
    } else if (dealerSum == best) {
        cout << "Draw! You take your bet back.\n";
    } else if (dealerSum < best) {
        cout << "You have the better number. You win!\n";
        cash += bet;
        cout << "You now have $" << cash << ".00" << endl;
        wins.push_back(1);
    } else if (dealerSum > best) {
        cout << "The dealer wins!\n";
        cash -= bet;
        cout << "You now have $" << cash << ".00" << endl;
    }
}