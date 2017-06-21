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

void Node::setNortheast (Node* node) {
    northeast = node;
}

void Node::setSouthwest (Node* node) {
    southwest = node;
}

void Node::setSoutheast (Node* node) {
    southeast = node;
}

Node* Node::getNorthwest () {
    return northwest;
}

Node* Node::getNortheast () {
    return northeast;
}

Node* Node::getSouthwest () {
    return southwest;
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

ORIENTATION Node::getOrientation() {
    return orientation;
}

char Node::getOrientationAsChar() {
    if (orientation == ORIENTATION::northwest) return '1';
    if (orientation == ORIENTATION::northeast) return '2';
    if (orientation == ORIENTATION::southwest) return '3';
    if (orientation == ORIENTATION::southeast) return '4';
    return '0';
}

