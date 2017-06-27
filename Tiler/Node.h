//
// Created by Bryan Tsai on 30 May 2017
//

#ifndef NODE_H
#define NODE_H

#include <stdio.h>
#include <unordered_map>

enum ORIENTATION {
    northwest,
    northeast,
    southwest,
    southeast,
    none,
};

ORIENTATION negateOrientation (ORIENTATION);

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
        ORIENTATION descentation;
        char colour;

    public:
        Node ();
        Node (Node*);
        Node (Node*, ORIENTATION descentar);
        Node (Node*, ORIENTATION descentar, char);
        Node (Node*, ORIENTATION descentar, size_t, size_t);
        void setNorthwest(Node*);
        void setNortheast(Node*);
        void setSouthwest(Node*);
        void setSoutheast(Node*);
        Node* getNorthwest();
        Node* getNortheast();
        Node* getSouthwest();
        Node* getSoutheast();
        Node* getParent();
        size_t getX();
        size_t getY();
        ORIENTATION getOrientation();
        char getOrientationAsChar();
        void setOrientation(ORIENTATION);
        ORIENTATION getDescentation();
        bool isLeaf();
        ORIENTATION getOrientationTo (size_t, size_t);
};

#endif
