//
// Created by solari on ٢٢‏/١٠‏/٢٠١٩.
//

#include "Simulator.h"
#include <iostream>
#include <fstream>
/* ---------------------------------------------------------------------------------------------------------
 * [Function Name] : isNumber
 * [Description] : This function is responsible to determine if input is Number or not
 * [Args] :
 * [s]  string s
 * [Returns] : indicate if number or not
    ---------------------------------------------------------------------------------------------------------*/
bool Simulator::isNumber(string s)
{
    for (int i = 0; i < s.length(); i++) {
        if(s[i]=='-' || s[i]=='+' || s[i]=='.') continue;
        else if (isdigit(s[i]) == false)
            return false;
    }

    return true;
}

Simulator::Simulator() {}

/* ---------------------------------------------------------------------------------------------------------
 * [Function Name] : ~Simulator
 * [Description] : This function is responsible to remove dynamically allocated memory to prevent memory leakage problem
 */
Simulator::~Simulator() {

    for(long long i=0 ; i<getNS(); i++)
        delete NA[i];
    for(long long i=0 ; i<getRS(); i++)
        delete RA[i];
}

/* ---------------------------------------------------------------------------------------------------------
 * [Function Name] : getRs
 * [Description] : This function is responsible to calculate number of rectangles
 * [Returns] : Number of rectangles
    ---------------------------------------------------------------------------------------------------------*/
long long Simulator::getRS() {
    return RA.size();
}


/* ---------------------------------------------------------------------------------------------------------
 * [Function Name] : getNs
 * [Description] : This function is responsible to calculate number of nodes
 * [Returns] : Number of nodes
    ---------------------------------------------------------------------------------------------------------*/
long long Simulator::getNS() {
    return NA.size();
}

/* ---------------------------------------------------------------------------------------------------------
 * [Function Name] : FindNode
 * [Description] : This function is responsible to check if there is a point with this x and y values
 * [Args] :
 * [x]  long long x
 * [y]  long long y
 * [Returns] : Return address of this node if exist
    ---------------------------------------------------------------------------------------------------------*/
Node* Simulator::FindNode(long long x , long long y) {
    for(int i=0; i<getNS(); i++)
    {
        if(NA[i]->getX() == x && NA[i]->getY() == y)
            return NA[i];
    }
    return NULL;
}

/* ---------------------------------------------------------------------------------------------------------
 * [Function Name] : AddNode
 * [Description] : This function is responsible to add a new node to rectangle
 * [Args] :
 * [x]  long long x
 * [y]  long long y
 * [Returns] : address of added node
    ---------------------------------------------------------------------------------------------------------*/
Node* Simulator::AddNode(long long x , long long y){
    Node * p = new Node(x,y);
    NA.push_back(p);
    return p;
}

Node* Simulator::FindOrAddNode(long long x , long long y){
    Node *N = FindNode(x,y);
    if(N != NULL)
        return N;
    else
        return AddNode(x,y);
}

/* ---------------------------------------------------------------------------------------------------------
 * [Function Name] : AddRectangle
 * [Description] : This function is responsible to add a new rectangle
 * [Args] :
 * [ll]  Node* ll
 * [ur]  Node* ur
 * [Returns] : address of added rectangle
    ---------------------------------------------------------------------------------------------------------*/
Rectangle* Simulator::AddRectangle(Node* ll, Node* ur) {
    Rectangle *r = new Rectangle(ll,ur);
    RA.push_back(r);
    return r;

}


/* ---------------------------------------------------------------------------------------------------------
 * [Function Name] : Load
 * [Description] : This function is responsible to read inputs(nodes of each rectangle) from input file
 * [Args] :
 * [FileName]  string FileName
    ---------------------------------------------------------------------------------------------------------*/
void Simulator::Load(string FileName) {
    ifstream f1;
    long long x1,y1,x2,y2,p,count=0;
    string in;
    Node * p1;
    Node* p2;
    Rectangle* r;
    f1.open(FileName);
    while (!(f1.eof())) {
        try { //check if input is in correct format(Number)
            f1>>in;
            if (!isNumber(in))
            {
                throw "Wrong input format you must enter integer number";
            }
            p=stoi(in);
        }
        catch (const char *msg ) {
            printf("%50s \n",msg);
            break;
        }
        if(count%4==0) x1=p;
        else if(count%4==1) y1=p;
        else if(count%4==2) x2=p;
        else if(count%4==3){
            y2=p;
            p1 =AddNode(x1,y1);
            p2 =AddNode(x2,y2);
            r = AddRectangle(p1,p2);
        }
        count++;
    }
    f1.close();
    printf("Number of inputs: ");
    printf("%lld \n",count/4);//number of rectangles in this input file
    Sim();
}

/* ---------------------------------------------------------------------------------------------------------
 * [Function Name] : Sim
 * [Description] : This function is responsible to simulate our program to get overlapped rectangles and increase score
 * of two overlapped rectangles and sort them according to their score as by taking the highest score of overlapping
 * rectangle first, we decrease probability of overlapping and increase the chance that the remaining rectangles are not
 * overlapping so you can take as much as possible of them in one group and output rectangles in groups will not change
 * if we change sequence of input rectangles
    ---------------------------------------------------------------------------------------------------------*/
void Simulator::Sim(){
	long long size = getRS();
    vector<long long>overlap_score(size,0);

    for(long long j=0; j<getRS(); j++) {
        for (long long i = j + 1; i < getRS(); i++) {
            if (RA[j]->doOverlap(RA[i])) {
                overlap_score[i]++;
                overlap_score[j]++;
            }
        }
        //printf("%d \n",overlap_score[j]);
    }
    Rectangle *temp;
    for(long long i=0; i<getRS(); i++){
        for(long long j=i+1;j<getRS();j++ ){
            if(overlap_score[j]>=overlap_score[i]){
                temp = RA[i];
                RA[i]=RA[j];
                RA[j]=temp;
            }

        }
    }

    //sortY();
    //sortX();


    printf("\n");

    minGroups();
}

/* ---------------------------------------------------------------------------------------------------------
 * [Function Name] : sortX
 * [Description] : This function is responsible to sort rectangles according to their x_value
    ---------------------------------------------------------------------------------------------------------*/
void Simulator::sortX() {
    Rectangle *temp;
    for(long long i=0; i<getRS(); i++){
        for(long long j=i+1;j<getRS();j++ ){
            if(RA[i]->getLl()->getX()>=RA[j]->getLl()->getX()){
                temp = RA[i];
                RA[i]=RA[j];
                RA[j]=temp;
            }

        }
    }
}

/* ---------------------------------------------------------------------------------------------------------
 * [Function Name] : sortY
 * [Description] : This function is responsible to sort rectangles according to their y_value
    ---------------------------------------------------------------------------------------------------------*/
void Simulator::sortY() {
    Rectangle *temp;
    for(long long i=0; i<getRS(); i++){
        for(long long j=i+1;j<getRS();j++ ){
            if(RA[i]->getLl()->getY()>=RA[j]->getLl()->getY()){
                temp = RA[i];
                RA[i]=RA[j];
                RA[j]=temp;
            }

        }
    }
}

/* ---------------------------------------------------------------------------------------------------------
 * [Function Name] : minGroups
 * [Description] : This function is called after sorting rectangles according to max overlapping score to get minimum
 * number of groups by pushing the most overlapping rectangle at the beginning of each new rectangle, mark it as visited
 * and then check if next rectangle is not taken and not overlapping with another rectangle in the current group to push
 * if this is true or break and get the next rectangle if not true and write created minimum groups in the output file path
    ---------------------------------------------------------------------------------------------------------*/
void Simulator::minGroups() {
    ofstream f2;
    //f2.open("out.txt");
    long long count =0;
    int flag = 0;// to break from loop to get next rectangle if the current one is overlapped with
    int push =0;//indicate that this rectangle can be pushed to this group
    vector<Rectangle*>v(getRS());
    bool *taken = new bool[getRS()]; // Indicate if rectangle is taken in a group or not
    for(long long i=0; i<getRS(); i++){
        v.clear();
        push=0;
        if(!taken[i]){ // at the beginning of each new group, i push the first most overlapping rectangle
            v.push_back(RA[i]);
            taken[i]=1;
            push =1;
        }
        for(long long j=i+1; j<getRS(); j++){
            flag=0;
            if((!taken[j])){ // check if the next rectangle is not taken and not overlapping with any rectangle in this group then push it into this group
                for(long long k=0 ; k<v.size(); k++){
                    if(v[k]->doOverlap(RA[j])){
                        flag =1;
                        break;
                    }
                }
                if(flag==0){
                    v.push_back(RA[j]);
                    taken[j]=1;
                    push=1;
                }
            }
        }
        if(push) {
            count++;
            string filename = "data_set_15_G"+to_string(count)+".txt";
            f2.open(filename);
            f2<<"G"<<count<<":"<<"\n";
            for(int e=0 ; e<v.size() ; e++){
                f2<<v[e]->getLl()->getX()<<" "<<v[e]->getLl()->getY()<<" "<<v[e]->getUr()->getX()<<" "<<v[e]->getUr()->getY()<<"\n";
            }
            f2.close();
        }
    }
    //f2.close();
    printf("Number of output groups: ");
    printf("%lld \n", count);//minimum number of groups
}