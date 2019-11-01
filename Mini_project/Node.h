/* -----------------------------------------------------------------------------------
 * [class name]: Node
 * [class description ]:  This class is responsible for maintaining information about x,y values of point of a rectangle
 *
   ------------------------------------------------------------------------------------*/

#ifndef NODE_H
#define NODE_H

using namespace std;

class Node {
    long long x , y; // x and y of a point
public:
    Node();

    Node(long long  x, long long  y);

    long long  getX() ;

    void setX(long long  x);

    long long  getY() ;

    void setY(long long  y);

};


#endif //NODE_H
