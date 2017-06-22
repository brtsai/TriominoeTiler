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

    AbstractTiler myTiler(2,0,0);
    myTiler.printAbstract();

    std::cout << "Making a 32x32 abstract tiler with 0,0 and printing." << std::endl;

    AbstractTiler myTiler2(5,0,0);
    myTiler2.printAbstract();

    std::cout << "Making a 8x8 abstract tiler with 7,3 and printing." << std::endl;

    AbstractTiler myTiler3(3,7,3);
    myTiler3.printAbstract();

    std::cout << "Making a 8x8 abstract tiler with 7,2 and printing." << std::endl;
    // TODO currently fails this test
    AbstractTiler myTiler4(3,7,2);
    myTiler4.printAbstract();


    return 0;
}
