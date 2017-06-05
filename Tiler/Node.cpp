//
// Created by Bryan Tsai on 30 May 2017
//

#include "Node.h"

Node::Node () {
    parent = NULL;
    northwest = NULL;
    northeast = NULL;
    southwest = NULL;
    southeast = NULL;
    orientation = none;
    colour = NULL;
}

Node::Node (Node* progenitor) {
    Node();
    parent = progenitor;
}

Node::Node (Node* progenitor, ORIENTATION toFace) {
    Node();
    parent = progenitor;
    orientation = toFace;
}

Node::Node (Node* progenitor, ORIENTATION toFace, char toBePainted) {
    Node();
    parent = progenitor;
    orientation = toFace;
    colour = toBePainted;
}

Node::Node (Node* progenitor, ORIENTATION toFace, size_t newX, size_t newY) {
    Node();
    parent = progenitor;
    orientation = toFace;
    x = newX;
    y = newY;
}

