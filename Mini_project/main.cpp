/*------------------------------------------------------------------------------------
 * [FILE NAME]: <main.cpp>
 * [AUTHOR]: <Eslam Tarek>
 * [DATE CREATED]: <22/10/2019>
  ------------------------------------------------------------------------------------*/

#include "Simulator.h"
#include <bits/stdc++.h>

using namespace std;

int main() {
    printf("Getting minimium groups of non overlapping rectangles \n");
    printf("----------------------------------------------------- \n");
    clock_t start = clock(); // setting start time
    Simulator s;
    string file;
    printf("please enter path of the file \n");//getting path of input file
    cin>>file;
    s.Load(file);
    clock_t stop = clock();// setting end time of program
    double time_taken = double(stop - start)/CLOCKS_PER_SEC;// calculating time taken by the program
    printf("Time taken by program is : %f sec",time_taken);
    return 0;
}