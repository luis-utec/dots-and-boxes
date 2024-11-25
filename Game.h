#ifndef GAME_H
#define GAME_H

#include "Board.h"
#include "Player.h"

class Game {
private:
    Board *board;
    Player *player1;
    Player *player2;
    Player *currentPlayer;

    void switchPlayer();

public:
    Game();
    ~Game();
    void run();
};

#endif // GAME_H
