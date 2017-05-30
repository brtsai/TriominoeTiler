//
// Created by Bryan Tsai on 30 May 2017
//

#ifndef NODE_H
#define NODE_H

#include <stdio.h>

enum Orientation {
    northwest,
    northeast,
    southwest,
    southeast,
    none,
};

class Node {
    private:
        Node* parent;
        Node* northwest;
        Node* northeast;
        Node* southwest;
        Node* southeast;
        Orientation orientation;
        char colour;

    public:
        Node();
        Node(Node*);
        Node(Node*, Orientation, char);
};



#endif
