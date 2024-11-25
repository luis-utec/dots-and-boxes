#ifndef PLAYER_H
#define PLAYER_H

#include <string>

class Player {
private:
    std::string name;
    int score;

public:
    Player(const std::string &name);
    std::string getName() const;
    void addScore(int points);
    int getScore() const;
};

#endif // PLAYER_H
// PLAYER_H
