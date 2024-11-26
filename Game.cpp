#include "Game.h"

Game::Game() {
    int choice;
    cout << "Menu:\n";
    cout << "Dots & Boxes\n";
    cout << "~~~~~~~~~~~~\n";
    cout << "1. Tablero 6 x 6\n";
    cout << "2. Tablero 10 x 10\n";
    cout << "0. Salir\n";
    cout << "Seleccione la opcion: ";
    cin >> choice;

    if (choice == 1) {
        board = new Board(6);
    } else if (choice == 2) {
        board = new Board(10);
    } else {
        exit(0);
    }

    player1 = new Player("A");
    player2 = new Player("B");
    currentPlayer = player1;
}

Game::~Game() {
    delete board;
    delete player1;
    delete player2;
}

void Game::switchPlayer() {
  if (currentPlayer == player1) {
    currentPlayer = player2;
  } else {
    currentPlayer = player1;
  }
}

void Game::run() {
    while (!board->isFull()) {
        board->display();
        cout << currentPlayer->getName() << ", es tu turno.\n";
        int x1, y1, x2, y2;

	do{
        cout << "Ingrese origen: ";
        cin >> x1 >> y1;
        cout << "Ingrese destino: ";
        cin >> x2 >> y2;
	if(x1 > 6 || x2 > 6 || y1 > 6 || y2 > 6)
		cout << "Movimiento invalido. Ingrese de nuevo los valores." << endl;
	}while(x1 > 6 || x2 > 6 || y1 > 6 || y2 > 6);

        if (board->addLine(x1, y1, x2, y2, currentPlayer->getName())) {
            if (!board->checkAndMarkBoxes(currentPlayer->getName())) {
                switchPlayer();
            }
        } else {
            cout << "Movimiento invalido. Intenta de nuevo.\n";
        }
    }

    board->display();
    cout << "Juego terminado.\n";
    cout << player1->getName() << ": " << player1->getScore() << " puntos\n";
    cout << player2->getName() << ": " << player2->getScore() << " puntos\n";

    if (player1->getScore() > player2->getScore()) {
        cout << "El ganador es " << player1->getName() << "!\n";
    } else if (player2->getScore() > player1->getScore()) {
        cout << "El ganador es " << player2->getName() << "!\n";
    } else {
        cout << "Es un empate!\n";
    }
}
