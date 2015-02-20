/*
 Addison Fattor & Matthew Koken
 COEN 70L - Monday 5:10
 Lab 7
 */
#include <iostream>
#include "guess.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void play() {
    int randNum;
    bool stop = false;
    bool playing  = true;
    bool guessed = false;
    srand (time(NULL));
    
    //loop for entire game
    while(playing) {
        //check if we want to play
        cout << "Do you want to play? Y/N ";
        char input;
        cin >> input;
        input = tolower(input);
        cin.clear();		//Clear buffer
        cin.ignore(250,'\n');	//Make sure the enter key is not read into cin.getline
        if(input == 'y')
            playing = true;
        else {
            playing = false;
            return;
        }
        
        cout << "How many humans? (0-2)";
        int players;
        cin >> players;
        cin.clear();		//Clear buffer
        cin.ignore(250,'\n');	//Make sure the enter key is not read into cin.getline
        
        randNum = rand()%100;
        //case is number of players
        Player* hm;
        Player* cm;
        int hmG = 0;
        int cmG = 0;
        
        switch (players) {
            case 0:
                hm = new ComputerPlayer();
                cm = new ComputerPlayer();
                break;
            case 1:
                hm = new HumanPlayer();
                cm = new ComputerPlayer();
                break;
            case 2:
                hm = new HumanPlayer();
                cm = new HumanPlayer();
            default:
                hm = new HumanPlayer();
                cm = new ComputerPlayer();
                break;
        }
        while(!guessed) {
            //check for hm answer
            int hmGuess = hm->getGuess();
            hmG++;
            if(hmGuess == randNum) {
                cout << "Correct! Player 1 took " << hmG << " guesses." << endl;
                guessed = true;
                break;
            } else {
                if(hmGuess > randNum) {
                    cout << "Too high" << endl;
                    cm->opponentsGuess(hmGuess, true);
                    hm->lastWasTooHigh(true);
                } else {
                    cout << "Too low" << endl;
                    cm->opponentsGuess(hmGuess, false);
                    hm->lastWasTooHigh(true);
                }
            }
            
            //check for cm answer
            int cmGuess = cm->getGuess();
            cmG++;
            cout << "Computer guessed: " << cmGuess << endl;
            if(cmGuess == randNum ) {
                cout << "Correct! Player 2 took " << cmG << " guesses." << endl;
                guessed = true;
                break;
            } else {
                if(cmGuess > randNum) {
                    cout << "Too high" << endl;
                    hm->opponentsGuess(cmGuess, true);
                    cm->lastWasTooHigh(true);
                } else {
                    cout << "Too low" << endl;
                    hm->opponentsGuess(cmGuess, false);
                    cm->lastWasTooHigh(false);
                }
            }
            
        }

        
        
    }
    
    
    
}

int main (){
    play();
}