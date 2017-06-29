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
    myTiler.makeAndPrintTiledBoard();

    std::cout << "Making a 32x32 abstract tiler with 0,0 and printing." << std::endl;

    AbstractTiler myTiler2(5,0,0);
    myTiler2.printAbstract();
    myTiler2.makeAndPrintTiledBoard();

    std::cout << "Making a 8x8 abstract tiler with 7,3 and printing." << std::endl;

    AbstractTiler myTiler3(3,7,3);
    myTiler3.printAbstract();
    myTiler3.makeAndPrintTiledBoard();


    std::cout << "Making a 8x8 abstract tiler with 7,2 and printing." << std::endl;
    AbstractTiler myTiler4(3,7,2);
    myTiler4.printAbstract();
    myTiler4.makeAndPrintTiledBoard();


    std::cout << "Making a 8x8 abstract tiler with 6,2 and printing." << std::endl;
    AbstractTiler myTiler5(3,6,2);
    myTiler5.printAbstract();
    myTiler5.makeAndPrintTiledBoard();


    std::cout << "Making a 8x8 abstract tiler with 5,2 and printing." << std::endl;
    AbstractTiler myTiler6(3,5,2);
    myTiler6.printAbstract();
    myTiler6.makeAndPrintTiledBoard();


    std::cout << "Making a 8x8 abstract tiler with 6,1 and printing." << std::endl;
    AbstractTiler myTiler7(3,6,1);
    myTiler7.printAbstract();
    myTiler7.makeAndPrintTiledBoard();


    std::cout << "Making a 8x8 abstract tiler with 5,1 and printing." << std::endl;
    AbstractTiler myTiler8(3,5,1);
    myTiler8.printAbstract();
    myTiler8.makeAndPrintTiledBoard();

    return 0;
}
