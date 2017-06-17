//
// Created by Bryan Tsai on 30 May 2017
//

#ifndef ABSTRACTTILER_H
#define ABSTRACTTILER_H

#include "Node.h"
#include <math.h>

class AbstractTiler {
    private:
        Node* root;
        size_t power;
        size_t dimension;
        size_t x;
        size_t y;

        void recCreateNetwork(Node*, size_t, size_t, size_t, ORIENTATION);
        void createNetwork();
        void orientNetwork();
    public:
        AbstractTiler(size_t, size_t, size_t);


};

#endif
