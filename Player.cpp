#include "Player.h"

Player::Player(const std::string &name) : name(name), score(0) {}

std::string Player::getName() const {
    return name;
}

void Player::addScore(int points) {
    score += points;
}

int Player::getScore() const {
    return score;
}
