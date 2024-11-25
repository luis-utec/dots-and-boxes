#ifndef BOARD_H
#define BOARD_H

#include "Def.h"

class Board {
private:
    int size;
    vector<vector<char>> horizontalLines;
    vector<vector<char>> verticalLines;
    vector<vector<char>> boxes;

public:
    Board(int size);
    void display();
    bool addLine(int x1, int y1, int x2, int y2, const string &player);
    bool checkAndMarkBoxes(const string &player);
    bool isFull();
};

#endif // BOARD_H
