//
// Created by Bryan Tsai on 30 May 2017
//

#include "AbstractTiler.h"

Node* 
AbstractTiler::recCreateNetwork(Node* parent, size_t nextX, size_t nextY, size_t nextRadius, ORIENTATION descent) {
    if(nextRadius == 0) return NULL;

    size_t halfRad = nextRadius/2;
    size_t north = nextY - halfRad;
    size_t east = nextX + halfRad;
    size_t south = nextY + halfRad;
    size_t west = nextX - halfRad;
    Node* parentNode = (descent == none? NULL : parent);
    Node* newNode = new Node(parentNode, descent, nextX, nextY, nextRadius);
    
    newNode -> setNorthwest(recCreateNetwork (newNode, west, north, halfRad, northwest));
    newNode -> setNortheast(recCreateNetwork (newNode, east, north, halfRad, northeast));
    newNode -> setSouthwest(recCreateNetwork (newNode, west, south, halfRad, southwest));
    newNode -> setSoutheast(recCreateNetwork (newNode, east, south, halfRad, southeast));
    
    return newNode;
}

void 
AbstractTiler::createNetwork() {
    size_t radius = dimension/2;
    root = recCreateNetwork(NULL, radius, radius, radius, none);
}

size_t 
abs_diff (size_t a, size_t b) {
    return (a > b) ? a - b : b - a;
}

bool 
isUnderCurr (size_t nX, size_t nY, size_t x, size_t y) {
    if (x > nX || y > nY) return false;

    size_t diffX = abs_diff (x, nX);
    size_t diffY = abs_diff (y, nY);
    if (diffX < 2 && diffY < 2) return true;
    return false;
}

Node* 
findPresidingNode (Node* curr, size_t x, size_t y, size_t magnitude) {
    if (magnitude == 1) return curr;

    size_t nX = curr -> getX();
    size_t nY = curr -> getY();

    if (isUnderCurr(nX, nY, x, y)) return curr;

    /**
    std::cout << x << " > " << nX << " " << (x>nX)
              << " and " << y << " >= " << nY << " " << (y>=nY)
              << std::endl;
    */

    Node* next = (x > nX) ? 
                ((y >= nY) ? curr -> getSoutheast() : curr -> getNortheast()) : 
                ((y >= nY) ? curr -> getSouthwest() : curr -> getNorthwest()) ;
    return findPresidingNode (next, x, y, magnitude - 1);
}

void 
recWipeOrientation (Node* curr) {
    if (curr == NULL) return;
    curr -> setOrientation (none);
    recWipeOrientation (curr -> getNorthwest());
    recWipeOrientation (curr -> getNortheast());
    recWipeOrientation (curr -> getSouthwest());
    recWipeOrientation (curr -> getSoutheast());
}

void recSolveFor (Node* curr, size_t x, size_t y) {
    if (curr == NULL) return;

    size_t cX = curr -> getX();
    size_t cY = curr -> getY();
    size_t r = curr -> getRadius();
    size_t west = cX - 1;
    size_t east = cX;
    size_t north = cY - 1;
    size_t south = cY;
    if (curr -> isLeaf()) curr -> orientTo(x,y);
    assert (x >= cX - r && x < cX + r);
    assert (y >= cY - r && y < cY + r);
    curr -> orientTo(x,y);
    ORIENTATION quadrantTo = curr -> getOrientationTo(x,y);
   
    if (quadrantTo == none) throw "quadrantTo == none";
    (quadrantTo != northwest) ? (recSolveFor (curr -> getNorthwest(), west, north)) :
                                (recSolveFor (curr -> getNorthwest(), x, y));
    (quadrantTo != northeast) ? (recSolveFor (curr -> getNortheast(), east, north)) :
                                (recSolveFor (curr -> getNortheast(), x, y));
    (quadrantTo != southwest) ? (recSolveFor (curr -> getSouthwest(), west, south)) :
                                (recSolveFor (curr -> getSouthwest(), x, y));
    (quadrantTo != southeast) ? (recSolveFor (curr -> getSoutheast(), east, south)) :
                                (recSolveFor (curr -> getSoutheast(), x, y));

}

void 
AbstractTiler::solveNetwork () {
    assert(x < dimension);
    assert(y < dimension);
    assert(power != 0);
    presidingNode = findPresidingNode(root, x, y, power);
    printPresidingNodeCoords();
    recSolveFor(root, x, y);
}

void 
AbstractTiler::printPresidingNodeCoords () {
    std::cout << "Presiding Node at coords (" << presidingNode -> getX() << ","
              << presidingNode -> getY() << ")" << std::endl;
}

AbstractTiler::AbstractTiler (size_t newPower, size_t xOfRemoved, size_t yOfRemoved) {
    power = newPower;
    dimension = pow(2,power);
    x = xOfRemoved;
    y = yOfRemoved;
    createNetwork();
    solveNetwork();
}

void 
recAddToBoard (Node* curr, Board* board) {
    if (curr == NULL) return;
    board -> insert(curr -> getOrientationAsChar(), curr -> getX(), curr -> getY());
    recAddToBoard(curr -> getNorthwest(), board);
    recAddToBoard(curr -> getNortheast(), board);
    recAddToBoard(curr -> getSouthwest(), board);
    recAddToBoard(curr -> getSoutheast(), board);
}

void 
AbstractTiler::printAbstract () {
    Board* board = new Board(power);
    recAddToBoard(root, board);
    board->printBoard();
}
