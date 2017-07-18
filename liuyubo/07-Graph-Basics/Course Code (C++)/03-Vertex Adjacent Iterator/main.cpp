#include <iostream>
#include "SparseGraph.h"
#include "DenseGraph.h"
#include <stdlib.h>
using namespace std;


int main() {

    int N = 20;
    int M = 100;

    srand( time(NULL) );


    // Sparse Graph
    // 随机生成20个节点 100条边的无向图
    SparseGraph g1(N , false);
    for( int i = 0 ; i < M ; i ++ ){
        int a = rand()%N;
        int b = rand()%N;
        g1.addEdge( a , b );
    }

    // O(E)
    // 打印节点的所有邻边
    for( int v = 0 ; v < N ; v ++ ){
        cout<<v<<" : ";
        //对于每一个节点都声明一个g1这个图对于v这个
        //节点的邻边迭代器
        SparseGraph::adjIterator adj( g1 , v );
        for( int w = adj.begin() ; !adj.end() ; w = adj.next() )
            cout<<w<<" ";
        cout<<endl;
    }

    cout<<endl;


    // Dense Graph
    DenseGraph g2(N , false);
    for( int i = 0 ; i < M ; i ++ ){
        int a = rand()%N;
        int b = rand()%N;
        g2.addEdge( a , b );
    }

    // O(V^2)
    for( int v = 0 ; v < N ; v ++ ){
        cout<<v<<" : ";
        DenseGraph::adjIterator adj( g2 , v );
        for( int w = adj.begin() ; !adj.end() ; w = adj.next() )
            cout<<w<<" ";
        cout<<endl;
    }

    return 0;
}