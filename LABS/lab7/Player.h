class Player {
    public:
    Player();
    virtual ~Player();
    virtual int getGuess();
    // Returns the players next guess, an integer between
    // 0 and 99 (inclusive)
    virtual void lastWasTooHigh(bool tooHigh);
    // Called to inform the player that their last guess
    // was too high (if the tooHigh argument is true) or
    // too low (if the tooHigh argument is false)
    virtual void opponentsGuess(int guess, bool tooHigh);
    // Called to tell the player what the opponent's last
    // guess was, and whether it was too high or too low.
    virtual void reset();
    // Called to reset the player at the end of the game.
    // Any stored state about the last guess should be cleared.
}; 