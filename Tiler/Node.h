//
// Created by Bryan Tsai on 30 May 2017
//

#ifndef NODE_H
#define NODE_H

#include <stdio.h>

enum ORIENTATION {
    northwest,
    northeast,
    southwest,
    southeast,
    none,
};

class Node {
    private:
        size_t x;
        size_t y;
        Node* parent;
        Node* northwest;
        Node* northeast;
        Node* southwest;
        Node* southeast;
        ORIENTATION orientation;
        char colour;

    public:
        Node ();
        Node (Node*);
        Node (Node*, ORIENTATION);
        Node (Node*, ORIENTATION, char);
        Node (Node*, ORIENTATION, size_t, size_t);
};



#endif
