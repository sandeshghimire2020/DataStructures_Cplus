#include <iostream>
#ifndef PART_H
#define PART_H

using namespace std;

class Partition{
public://public functions of the class
    static const int N=100;//static constant
    Partition();//constructor
    int uf_find(int x);//find function
    void uf_union(int x, int y);//function to unify the tree
    void kruskal(int , int[][100]);//the main algorithm

private:
    int p[N];//array that contains the values

};


#endif // PART_H
