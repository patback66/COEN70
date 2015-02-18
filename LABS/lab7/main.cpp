#include <iostream>
#include "HumanPlayer.h"
#include "ComputerPlayer.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void play() {
    int randNum;
    bool stop = false;
    bool playing  = true;
    bool guessed = false;
    HumanPlayer hm;
    ComputerPlayer hm;
    
    srand (time(NULL));
    
    //loop for entire game
    while(playing) {
        cout << "Do you want to play? Y/N ";
        char input;
        cin << input;
        input = toLower(input);
        
        if(input == 'y')
            playing = true;
        else {
            playing = false;
            return;
        }
        
        ranNunm = rand()%100;
        while(!guessed) {
            int hmGuess = hm.getGuess();
            
        }
            
        //loop for current guess
        
    }
    
    
     
}

int main {
    
}