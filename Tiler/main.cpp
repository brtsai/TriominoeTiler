//
// Created by Bryan Tsai on 26/05/2017
//

#include "Board.h"
#include "Node.h"
#include "AbstractTiler.h"

int main(int argc, char* argv[]) {

    std::cout << "Making a 4x4 board of Xs." << std::endl;

    Board myBoard(2);

    myBoard.fillBoard('X');
    myBoard.printBoard();

    std::cout << "Inserting Y into (1,2)" << std::endl;

    myBoard.insert('Y', 1, 2);
    myBoard.printBoard();

    std::cout << "Making a 4x4 abstract tiler with 0,0 and printing." << std::endl;

    AbstractTiler myTiler(5,0,0);
    myTiler.printAbstract();

    return 0;
}
