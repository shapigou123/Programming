#include <iostream>
#include <iomanip>
#include "DenseGraph.h"
#include "SparseGraph.h"
#include "ReadGraph.h"

using namespace std;

// 测试有权图和有权图的读取
int main() {

    string filename = "testG1.txt";
    int V = 8;
    //设置输出的精度为2位小数
    cout<<fixed<<setprecision(2);

    // Test Weighted Dense Graph
    // template <typename Weight>
    // class DenseGraph
    DenseGraph<double> g1 = DenseGraph<double>(V, false);
    // template <typename Graph, typename Weight>
    // class ReadGraph
    ReadGraph<DenseGraph<double>,double> readGraph1(g1, filename);
    g1.show();
    cout<<endl;

    // Test Weighted Sparse Graph
    SparseGraph<double> g2 = SparseGraph<double>(V, false);
    ReadGraph<SparseGraph<double>,double> readGraph2(g2, filename);
    g2.show();
    cout<<endl;

    return 0;
}