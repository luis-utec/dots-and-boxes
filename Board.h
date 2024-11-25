#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <string>

class Board {
private:
    int size;
    std::vector<std::vector<char>> horizontalLines;
    std::vector<std::vector<char>> verticalLines;
    std::vector<std::vector<char>> boxes;

public:
    Board(int size);
    void display();
    bool addLine(int x1, int y1, int x2, int y2, const std::string &player);
    bool checkAndMarkBoxes(const std::string &player);
    bool isFull();
};

#endif // BOARD_H
