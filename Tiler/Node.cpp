//
// Created by Bryan Tsai on 30 May 2017
//

#include "Node.h"

Node::Node() {
    parent = NULL;
    northwest = NULL;
    northeast = NULL;
    southwest = NULL;
    southeast = NULL;
    orientation = none;
    colour = NULL;
}

Node::Node(Node* progenitor) {
    Node();
    parent = progenitor;
}

Node::Node(Node* progenitor, Orientation toFace, char toBePainted) {
    Node();
    parent = progenitor;
    orientation = toFace;
    colour = toBePainted;
}

