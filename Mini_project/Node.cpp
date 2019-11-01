//
// Created by solari on ٢٢‏/١٠‏/٢٠١٩.
//

#include "Node.h"

//constructors
Node::Node(){
    setX(0);
    setY(0);
}

Node::Node(long long  x, long long  y) { // initializing x,y of point
    setX(x);
    setY(y);
}

long long Node::getX() {
    return x;
}

//setters and getters of x,,y of a point
void Node::setX(long long int x) {
    Node::x = x;
}

long long  Node::getY() {
    return y;
}

void Node::setY(long long  y) {
    Node::y = y;
}
