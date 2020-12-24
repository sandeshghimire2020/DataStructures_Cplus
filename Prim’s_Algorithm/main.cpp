#include <iostream>
#include<iomanip>
#include<cstdlib>
#include <cmath>
#include <fstream>

using namespace std;
void prim ( int n, int g[][100],int []);


void prim ( int n, int g[][100],int lowcost[])
{

  int closest[n];
  bool connected[n];
  int k, min, Cost = 0;
  int i,j;

  connected[0] = true;         // v0 is in the spanning tree.
  for (int i=1; i<n; ++i)
  {
    connected[i] = false;     // for false the vertex is not connected
    closest[i] = 0;       // unconnected vertex i

  }

  // Finding the MST the MST.
  cout << "Minimum cost spanning tree:" << endl;

  for (i=1; i<n; ++i)
  {
    // Finding the value of k not closest.
    min = INFINITY;
    for (j=1; j<n; ++j)
      if ( !connected[j] && lowcost[j] < min)
      {
        min = lowcost[j];
        k = j;
      }

    // Displaying the edges
    cout << "  edge = (v" << k << ",v" << closest[k] << "); cost = "
         << lowcost[k] << endl;
    Cost = Cost + lowcost[k];
    connected[k] = true;

    // updating the values
    for (j=1; j<n; ++j)
      if ( !connected[j] && g[k][j] < lowcost[j] )
      {
        lowcost[j] = g[k][j];
        closest[j] = k;
      }
  }
  cout << "Total cost = " << Cost << endl;
}

int main(){//The main function

   int i, j;
   int inp;
   int cost[7][100];//matrix
   int lowcost[7];
   int  data;
    ifstream myfile;
    cout<<"ENter the number of vertices you want: ";//asking input to the user
    cin>>inp;

 //initializing

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
              lowcost[i]=data;//Keeping the weight

       }

    myfile.close();//closing the file

prim(inp,cost,lowcost);//calling the function to evaulate prime

return 0;

}



