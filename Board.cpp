#include "Board.h"

Board::Board(int size) : size(size) {
    horizontalLines = vector<vector<char>>(size + 1, vector<char>(size, ' '));
    verticalLines = vector<vector<char>>(size, vector<char>(size + 1, ' '));
    boxes = vector<vector<char>>(size, vector<char>(size, ' '));
}

void Board::display() {
// Numeros de arriba
    for (int i = 1; i <= size; i++) {
        cout << setw(4) << i;
    }
    cout << endl;

    // Numero de +s
    for (int i = 0; i < size ; i++) { // Numeros de la izquierda
        cout << setw(2) << i + 1 << " ";
        for (int j = 0; j < size - 1; j++) { // Filas
            cout << "+";
	    if (horizontalLines[i][j] == '-') {
	      cout << "---";
	    } else {
	      cout << "   ";
}

	    
        }
        cout << "+\n";

        cout << setw(3) << " ";
        for (int j = 0; j < size + 1; j++) { // Columnas
	  if (verticalLines[i][j] == '|') {
	    cout << "|   ";
	  } else {
	    cout << "    ";
	  }
        }
        cout << endl;
    }
}

bool Board::addLine(int x1, int y1, int x2, int y2, const string &player) {
    if (x1 < 1 || x1 > size + 1 || y1 < 1 || y1 > size + 1 ||
        x2 < 1 || x2 > size + 1 || y2 < 1 || y2 > size + 1) {
        return false;
    }

    if (x1 == x2 && abs(y1 - y2) == 1) {
        if (horizontalLines[x1 - 1][min(y1, y2) - 1] == '-') return false;
        horizontalLines[x1 - 1][min(y1, y2) - 1] = '-';
        return true;
    }

    if (y1 == y2 && abs(x1 - x2) == 1) {
        if (verticalLines[min(x1, x2) - 1][y1 - 1] == '|') return false;
        verticalLines[min(x1, x2) - 1][y1 - 1] = '|';
        return true;
    }

    return false;
}

bool Board::checkAndMarkBoxes(const string &player) {
    bool marked = false;

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (boxes[i][j] == ' ' && horizontalLines[i][j] == '-' &&
                horizontalLines[i + 1][j] == '-' &&
                verticalLines[i][j] == '|' &&
                verticalLines[i][j + 1] == '|') {
                boxes[i][j] = player[0];
                marked = true;
            }
        }
    }

    return marked;
}

bool Board::isFull() {
    for (const auto &row : boxes) {
        for (const auto &box : row) {
            if (box == ' ') return false;
        }
    }
    return true;
}
