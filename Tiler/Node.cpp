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

void Node::setNorthwest (Node* node) {
    northwest = node;
}

Node* Node::getNorthwest () {
    return northwest;
}

void Node::setNortheast (Node* node) {
    northeast = node;
}

Node* Node::getNortheast () {
    return northeast;
}

void Node::setSouthwest (Node* node) {
    southwest = node;
}

Node* Node::getSouthwest () {
    return southwest;
}


void Node::setSoutheast (Node* node) {
    southeast = node;
}

Node* Node::getSoutheast () {
    return southeast;
}

size_t Node::getX() {
    return x;
}

size_t Node::getY() {
    return y;
}



