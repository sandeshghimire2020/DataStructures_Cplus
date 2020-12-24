
#include <iostream>
#include "Part.h"
using namespace std;

Partition::Partition(){ //the constructor
for (int i=0;i<N;++i)
    {
    p[i]=-1;
    }

}
int Partition::uf_find(int x)//find function
{
    while (p[x] != x)//starting loop

              x = p[x];//put the value in x

       return x;//return x
}
void Partition::uf_union(int x, int y)//unifing the tree
{
    int root= uf_find(x);//call find function

       int new_child = uf_find(y);

       p[root] = new_child;//keep value inside array
}
void Partition::kruskal(int N, int cst[][100])//Kruskal algorithm

{

       int minWeight = 0;

       for (int i = 0; i < N; i++)//initaizing the value

              p[i] = i;

       int count = 0;

       cout << "Minimum spanning tree is:" << endl;

       while (count < N - 1)//starting the pre condition

       {

              int Min = INT_MAX, value = -1, value2 = -1;

              for (int i = 0; i < N; i++)//starting the for loop

              {


                      for (int j = 0; j < N; j++)//nested for loop

                      {


                             if (uf_find(i) != uf_find(j) && cst[i][j] < Min) { //applying condition to check min value

                                    Min = cst[i][j];//put the main value here

                                    value = i;//edge

                                    value2 = j;//edge

                             }

                      }

              }

              uf_union(value, value2);//calling union function

              count++;

              cout <<  "(v" << value << ",v" << value2 << "); cost = " << Min << endl;//desplaying the message

              minWeight += Min;

       }

       cout<<"Total weight = "<< minWeight;//output the total cost

}
