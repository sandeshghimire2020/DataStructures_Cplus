#include <iostream>
#include "Part.h"
#include"Part.cpp"
#include<iomanip>
#include<cstdlib>
#include <cmath>
#include <fstream>

using namespace std;

int main(){//The main function
    int inp, x;
     int j, i, data;
     Partition p; //declaring object of class

    ifstream myfile;
    cout<<"ENter the number of vertices you want: ";//asking input to the user
    cin>>inp;
 int cost[7][100];//matrix
      for (i = 0; i<inp; i++) { //starting the loop

              for (j = 0; j<inp; j++) {

                      cost[i][j] = INT_MAX;

              }

       }

    myfile.open ("vertex.txt");//opening the file


   if (!myfile) {//display error message
        cout << "Unable to open file";
        exit(1); // terminate with error
    }
 while (!myfile.eof())//starting loop if there is no error

       {

              myfile >> i;//loading data from txt file


              myfile >> j;

              myfile >> data;

              cost[i][j] = data;//keeping the weight in matrix

              cost[j][i] = data;

       }

    myfile.close();//closing the file



p.kruskal(inp, cost);//calling the function
return 0;
}



