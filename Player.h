#ifndef PLAYER_H
#define PLAYER_H

#include "Def.h"

class Player {
private:
    string name;
    int score;

public:
    Player(const string &name);
    string getName() const;
    void addScore(int points);
    int getScore() const;
};

#endif // PLAYER_H
// PLAYER_H
