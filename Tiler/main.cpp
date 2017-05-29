//
// Created by Bryan Tsai on 26/05/2017
//

#include "Board.h"


int main(int argc, char* argv[]) {
    Board myBoard(2);

    myBoard.fillBoard('X');
    myBoard.printBoard();

    return 0;
}
