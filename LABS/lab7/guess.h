/*
Addison Fattor & Matthew Koken
COEN 70L - Monday 5:10
Lab 7
*/

#include <iostream>

using namespace std;

class Player {
	public:
		//Player();
		//virtual ~Player() = 0;
		virtual int getGuess() = 0;
		// Returns the players next guess, an integer between 0 and 99 (inclusive)
		virtual void lastWasTooHigh(bool tooHigh) = 0;
		// Called to inform the player that their last guess was too high (if the tooHigh argument is true)
		// or too low (if the tooHigh argument is false)
		virtual void opponentsGuess(int guess, bool tooHigh) = 0;
		// Called to tell the player what the opponent's las guess was,
		// and whether it was too high or too low.
		virtual void reset() = 0;
		//Called to reset the player at the end of the game.
		// Any stored state about the last guess should be cleared.
        int numGuesses;
};

class ComputerPlayer : public Player {
	protected:
		int g;
		int numGuesses;
		int upBound;
		int lowBound;
	public:
		ComputerPlayer() {
			numGuesses = 0;
			upBound = 99;
			lowBound = 0;
		}
		~ComputerPlayer() {
			//Nothing
		}
        int getGuesses() {return numGuesses;}
		int getGuess() {
            //binary search to the number -> use midpoints
            g = (upBound + lowBound)/2;
            numGuesses++;
			return g;
		}
		void lastWasTooHigh(bool tooHigh) {
            if(tooHigh) {
				upBound = g;
				return;
			}
			lowBound = g;
		}
		void opponentsGuess(int guess, bool tooHigh) {
			if (tooHigh) {
                if(guess < upBound)
                    upBound = guess;
				return;
			}
            if(guess > lowBound)
                lowBound = guess;
		}
		void reset() {
			g = -1;
			numGuesses = 0;
			upBound = 99;
			lowBound = 0;
		}
};


class HumanPlayer : public Player {
protected:
    int g;
    int numGuesses;
public:
    HumanPlayer() {
        numGuesses = 0;
    }
    ~HumanPlayer() {
        //Nothing
    }
    int getGuesses() {return numGuesses;}
    int getGuess() {
        bool wrong = true;
        //ensure the user guess is within the bounds
        while (wrong) {
            cout<<"What is your guess? (0 to 99 inclusive)"<<endl;
            cin>>g;
            
            if (g>=0 && g<100)
                wrong = false;
            else {
                cout<<"That guess is not between 0 and 99 (inclusive)"<<endl;
                wrong = true;
            }
            cin.clear();		//Clear buffer
            cin.ignore(250,'\n');	//Make sure the enter key is not read into cin.getline
        }
        numGuesses++;
        return g;

    }
    void lastWasTooHigh(bool tooHigh) {
        //doesn't do anything for a human
    }
    void opponentsGuess(int guess, bool tooHigh) {
        //doesn't do anything for a human
    }
    void reset() {
        g = -1;
        numGuesses = 0;
    }
};

