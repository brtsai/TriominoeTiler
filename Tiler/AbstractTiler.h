//
// Created by Bryan Tsai on 30 May 2017
//

#ifndef ABSTRACTTILER_H
#define ABSTRACTTILER_H

#include "Node.h"
#include "Board.h"
#include <math.h>
#include <assert.h>

class AbstractTiler {
    private:
        Node* root;
        Node* presidingNode;
        size_t power;
        size_t dimension;
        size_t x;
        size_t y;

        Node* recCreateNetwork(Node*, size_t, size_t, size_t, ORIENTATION);
        void createNetwork();
        void solveNetwork();
        void printPresidingNodeCoords();
    public:
        AbstractTiler(size_t power, size_t x, size_t y);
        void printAbstract();

};

#endif
