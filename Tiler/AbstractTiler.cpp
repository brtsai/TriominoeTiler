//
// Created by Bryan Tsai on 30 May 2017
//

#include "AbstractTiler.h"

Node* AbstractTiler::recCreateNetwork(Node* parent, size_t nextX, size_t nextY, size_t nextDimension, ORIENTATION descent) {
    if(dimension == 0) return NULL;

    size_t quarterDim = dimension/4;
    size_t halfDim = dimension/2;
    size_t threeQuarterDim = 3 * quarterDim;
    Node* parentNode = (descent == none? NULL : parent);
    Node* newNode = new Node(parentNode, descent, halfDim, halfDim);
    
    newNode -> setNorthwest(recCreateNetwork (newNode, nextX - halfDim, nextY - halfDim, halfDim, northwest));
    newNode -> setNortheast(recCreateNetwork (newNode, nextX + halfDim, nextY - halfDim, halfDim, northeast));
    newNode -> setSouthwest(recCreateNetwork (newNode, nextX - halfDim, nextY + halfDim, halfDim, southwest));
    newNode -> setSoutheast(recCreateNetwork (newNode, nextX + halfDim, nextY + halfDim, halfDim, southeast));
    
    return newNode;
}

void AbstractTiler::createNetwork() {
    size_t halfDim = dimension/2;
    root = recCreateNetwork(NULL, halfDim, halfDim, halfDim, none);
}

void AbstractTiler::orientNetwork() {

}

AbstractTiler::AbstractTiler (size_t newPower, size_t xOfRemoved, size_t yOfRemoved) {
    power = newPower;
    dimension = pow(2,power);
    x = xOfRemoved;
    y = yOfRemoved;
    createNetwork();
    orientNetwork();
}



void AbstractTiler::printAbstract() {
    Board* board = new Board(power);


}
