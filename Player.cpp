#include "Player.h"

Player::Player(const string &name) : name(name), score(0) {}

string Player::getName() const {
    return name;
}

void Player::addScore(int points) {
    score += points;
}

int Player::getScore() const {
    return score;
}
