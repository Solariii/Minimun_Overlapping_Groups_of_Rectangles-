/* -----------------------------------------------------------------------------------
 * [class name]: Simulator
 * [class description ]:  This class is responsible for adding new rectangles, changing nodes of rectangles by reading
 * inputs from the input file  and getting minimum number of groups
   ------------------------------------------------------------------------------------*/


#ifndef SIMULATOR_H
#define SIMULATOR_H

#include "Rectangle.h"
#include <vector>
#include <string>

class Simulator {
    vector<Rectangle *>RA;
    vector<Node *>NA;
public:
    Simulator();

    ~Simulator();

    long long getRS();

    long long getNS();

    Node* FindNode(long long x , long long y);

    Node* AddNode(long long x ,long long y );

    Node* FindOrAddNode(long long x ,long long y);

    Rectangle* AddRectangle(Node* ll , Node* ur);

    void Load(string FileName);

    void Sim();

    void minGroups();

    void sortX();

    void sortY();

    bool isNumber(string s);

};


#endif //SIMULATOR_H
