//
// Created by Bryan Tsai on 30 May 2017
//

#include "AbstractTiler.h"

Node* AbstractTiler::recCreateNetwork(Node* parent, size_t nextX, size_t nextY, size_t nextDimension, ORIENTATION descent) {
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
