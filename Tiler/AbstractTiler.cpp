//
// Created by Bryan Tsai on 30 May 2017
//

#include "AbstractTiler.h"

void AbstractTiler::recCreateNetwork(Node* parent, size_t nextX, size_t nextY, size_t nextDimension, ORIENTATION descent) {
    size_t quarterDim = dimension/4;
    size_t halfDim = dimension/2;
    size_t threeQuarterDim = 3 * quarterDim;

    Node* parentNode = (descent == none? NULL : parent);
    Node newRoot(parentNode, descent, halfDim, halfDim);
    root = &newRoot;

    if(dimension == 1) return;

    // TODO branch recursively in four directions    
}

void AbstractTiler::createNetwork() {
    if(dimension == 0) return;

    size_t halfDim = dimension/2;
    recCreateNetwork(NULL, halfDim, halfDim, halfDim, none);
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


