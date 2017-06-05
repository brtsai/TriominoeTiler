//
// Created by Bryan Tsai on 30 May 2017
//

#include "AbstractTiler.h"

void AbstractTiler::recCreateNetwork(Node* parent, size_t nextX, size_t nextY, size_t nextPower) {
    if(nextPower == 0) return;
}

void AbstractTiler::createNetwork() {
    Node newRoot(NULL, ORIENTATION::none, dimension/2, dimension/2);
    root = &newRoot;
    
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


