//
// Created by Bryan Tsai on 30 May 2017
//

#include "AbstractTiler.h"

Node* 
AbstractTiler::recCreateNetwork(Node* parent, size_t nextX, size_t nextY, size_t nextDimension, ORIENTATION descent) {
    if(nextDimension == 0) return NULL;

    size_t halfDim = nextDimension/2;
    size_t north = nextY - halfDim;
    size_t east = nextX + halfDim;
    size_t south = nextY + halfDim;
    size_t west = nextX - halfDim;
    Node* parentNode = (descent == none? NULL : parent);
    Node* newNode = new Node(parentNode, descent, nextX, nextY);
    
    newNode -> setNorthwest(recCreateNetwork (newNode, west, north, halfDim, northwest));
    newNode -> setNortheast(recCreateNetwork (newNode, east, north, halfDim, northeast));
    newNode -> setSouthwest(recCreateNetwork (newNode, west, south, halfDim, southwest));
    newNode -> setSoutheast(recCreateNetwork (newNode, east, south, halfDim, southeast));
    
    return newNode;
}

void 
AbstractTiler::createNetwork() {
    size_t halfDim = dimension/2;
    root = recCreateNetwork(NULL, halfDim, halfDim, halfDim, none);
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
    if (diffX < 2 && diffY < 2)
    return false;
}

Node* 
findPresidingNode (Node* curr, size_t x, size_t y, size_t magnitude) {
    if (magnitude == 1) return curr;

    size_t nX = curr -> getX();
    size_t nY = curr -> getY();

    if (isUnderCurr(nX, nY, x, y)) return curr;

    Node* next = (x > nX) ? 
                ((y > nY) ? curr -> getSoutheast() : curr -> getNortheast()) : 
                ((y > nY) ? curr -> getSouthwest() : curr -> getNorthwest());
    return findPresidingNode (next, x, y, magnitude - 1);
}

void 
recWipeOrientation(Node* curr) {

}

void 
AbstractTiler::orientNetwork () {
    //TODO
    assert(x < dimension);
    assert(y < dimension);
    assert(power != 0);
    presidingNode = findPresidingNode(root, x, y, power);
    printPresidingNodeCoords();
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
    orientNetwork();
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
