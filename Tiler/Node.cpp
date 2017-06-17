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

Node::Node (Node* progenitor, ORIENTATION descentar) {
    Node();
    parent = progenitor;
    descentation = descentar;
}

Node::Node (Node* progenitor, ORIENTATION descentar, char toBePainted) {
    Node();
    parent = progenitor;
    descentation = descentar;
    colour = toBePainted;
}

Node::Node (Node* progenitor, ORIENTATION descentar, size_t newX, size_t newY) {
    Node();
    parent = progenitor;
    orientation = descentar;
    x = newX;
    y = newY;
}

