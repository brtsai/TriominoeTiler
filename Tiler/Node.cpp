//
// Created by Bryan Tsai on 30 May 2017
//
// TODO
//  check for bug with descentation


#include "Node.h"

std::unordered_map<ORIENTATION, ORIENTATION> orientationOpposites =  
{
    {northwest, southeast},
    {northeast, southwest},
    {southwest, northeast},
    {southeast, northwest},
    {none, none},
};

ORIENTATION
negateOrientation (ORIENTATION toNegate) {
    return orientationOpposites.at(toNegate);
}

Node::Node () {
    parent = NULL;
    northwest = NULL;
    northeast = NULL;
    southwest = NULL;
    southeast = NULL;
    orientation = none;
    colour = '\0';
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

Node::Node (Node* progenitor, ORIENTATION descentar, size_t newX, size_t newY, size_t newRadius) {
    Node();
    parent = progenitor;
    descentation = descentar;
    orientation = descentar;
    x = newX;
    y = newY;
    radius = newRadius;
}

void 
Node::setNorthwest (Node* node) {
    northwest = node;
}

void 
Node::setNortheast (Node* node) {
    northeast = node;
}

void 
Node::setSouthwest (Node* node) {
    southwest = node;
}

void 
Node::setSoutheast (Node* node) {
    southeast = node;
}

Node* 
Node::getNorthwest () {
    return northwest;
}

Node* 
Node::getNortheast () {
    return northeast;
}

Node* 
Node::getSouthwest () {
    return southwest;
}

Node* 
Node::getSoutheast () {
    return southeast;
}

Node*
Node::getParent () {
    return parent;
}

size_t 
Node::getX () {
    return x;
}

size_t 
Node::getY () {
    return y;
}

size_t
Node::getRadius () {
    return radius;
}

ORIENTATION 
Node::getOrientation () {
    return orientation;
}

char 
Node::getOrientationAsChar () {
    if (orientation == ORIENTATION::northwest) return '1';
    if (orientation == ORIENTATION::northeast) return '2';
    if (orientation == ORIENTATION::southwest) return '3';
    if (orientation == ORIENTATION::southeast) return '4';
    return '0';
}

void 
Node::setOrientation (ORIENTATION o) {
    orientation = o;
}

ORIENTATION
Node::getDescentation () {
    return descentation;
}

bool 
Node::isLeaf () {
    return northwest == NULL;    
}

ORIENTATION
Node::getOrientationTo (size_t oX, size_t oY) {
    return (oX >= x) ?
          ((oY >= y) ? (ORIENTATION::southeast) : (ORIENTATION::northeast)) :
          ((oY >= y) ? (ORIENTATION::southwest) : (ORIENTATION::northwest)) ;
}

void
Node::orientTo (size_t oX, size_t oY) {
    orientation = getOrientationTo(oX, oY);
}
