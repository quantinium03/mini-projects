#include <iostream>
#include <cstdlib>
#include <limits>

void drawBoard();
int checkwin();

char square[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};

int main() {
    int player = 1, choice, i;
    char mark;

    do {
        drawBoard();
        player = (player % 2) ? 1 : 2;
        std::cout << "Player " << player << ", enter the number: ";
        std::cin >> choice;

        mark = (player == 1) ? 'X' : 'O';

        if (choice >= 1 && choice <= 9 &&
            square[(choice - 1) / 3][(choice - 1) % 3] == '0' + choice) {
            square[(choice - 1) / 3][(choice - 1) % 3] = mark;
            i = checkwin();
            player++;
        } else {
            std::cout << "INVALID MOVE" << std::endl;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin.get();
        }
    } while (i == -1);

    drawBoard();

    if (i == 1) {
        std::cout << "Congratulations! Player " << --player << " Wins!"
                  << std::endl;
    } else {
        std::cout << "Game Draw" << std::endl;
    }

    std::cin.ignore();
    std::cin.get();

    return 0;
}

int checkwin() {
    for (int i = 0; i < 3; i++) {
        if (square[i][0] == square[i][1] && square[i][1] == square[i][2] ||
            square[0][i] == square[1][i] && square[1][i] == square[2][i]) {
            return 1;
        }
    }

    if (square[0][0] == square[1][1] && square[1][1] == square[2][2] ||
        square[0][2] == square[1][1] && square[1][1] == square[2][0]) {
        return 1;
    } else if (square[0][0] != '1' && square[0][1] != '2' &&
               square[0][2] != '3' && square[1][0] != '4' &&
               square[1][1] != '5' && square[1][2] != '6' &&
               square[2][0] != '7' && square[2][1] != '8' &&
               square[2][2] != '9') {
        return 0;
    } else {
        return -1;
    }
}

void drawBoard() {
    system("clear");
    std::cout << "\n\n\t Tic Tac Toe Game\n";
    std::cout << "Player 1(X) - Player 2(O)\n\n";

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            std::cout << " " << square[i][j] << " ";
            if (j < 2)
                std::cout << "|";
        }
        std::cout << std::endl;
        if (i < 2)
            std::cout << "-----------" << std::endl;
    }
}
