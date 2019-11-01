//
// Created by solari on ٢٢‏/١٠‏/٢٠١٩.
//

#include "Rectangle.h"
#include <iostream>

//constructors
Rectangle::Rectangle() {
    ll = NULL;
    ur = NULL;
}
Rectangle::Rectangle(Node *ll, Node *ur) {
    setLl(ll);
    setUr(ur);
}

//destructor
Rectangle::~Rectangle() {}

//setters and getters of nodes of rectangle
Node *Rectangle::getLl() {
    return ll;
}

void Rectangle::setLl(Node *ll) {
    Rectangle::ll = ll;
}

Node *Rectangle::getUr() {
    return ur;
}

void Rectangle::setUr(Node *ur) {
    Rectangle::ur = ur;
}

// Returns true if two rectangles (ll1, ur1) and (ll2, ur2) overlap
bool Rectangle::doOverlap(Rectangle *r){
    // If one rectangle is on left side of other
    if((this->getLl()->getX() > r->getUr()->getX()) || (r->getLl()->getX() > this->getUr()->getX()))
        return false;
    // If one rectangle is above other
    if((this->getUr()->getY() < r->getLl()->getY()) || (r->getUr()->getY() < this->getLl()->getY()))
        return false;
    return true;
}