/* -----------------------------------------------------------------------------------
 * [class name]: Rectangle
 * [class description ]:  This class is responsible for maintaining information about every Node(x,y) of a rectangle
 * as lower_left point and upper_right points
   ------------------------------------------------------------------------------------*/

#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Node.h"

using namespace std;

class Rectangle {
    // rectangle if defined by 2 point: lower_left and upper_right
    Node* ll;
    Node* ur;


public:
    Rectangle(Node *ll, Node *ur);

    Rectangle();

    ~Rectangle();

    Node *getLl() ;

    void setLl(Node *ll);

    Node *getUr();

    void setUr(Node *ur);

    bool doOverlap(Rectangle *r);
};



#endif //RECTANGLE_H
