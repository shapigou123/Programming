//
// Created by liuyubobobo on 9/21/16.
//

#ifndef INC_02_GRAPH_REPRESENTATION_DENSEGRAPH_H
#define INC_02_GRAPH_REPRESENTATION_DENSEGRAPH_H

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

// 稠密图 - 邻接矩阵
class DenseGraph{

private:
    //n为顶点，m为边
    int n, m;       // 节点数和边数
    bool directed;  // 是否为有向图
    //二维矩阵，每一个位置存储的数据类型
    //为bool，用来表示是否存在边
    vector<vector<bool>> g; // 图的具体数据

public:
    // 构造函数
    DenseGraph( int n , bool directed ){
        assert( n >= 0 );
        this->n = n;
        this->m = 0;    // 初始化没有任何边
        this->directed = directed;
        // g初始化为n*n的布尔矩阵, 每一个g[i][j]均为false, 
        // 表示没有任和边
        g = vector<vector<bool>>(n, vector<bool>(n, false));
        #if 0
        for(int i=0; i<n; i++)
            //每次push传入一个vector，这个vector有n个元素
            //每一个元素都是false
            g.push_back(vector<bool>(n, false));
        #endif
    }

    ~DenseGraph(){ }

    int V(){ return n;} // 返回节点个数
    int E(){ return m;} // 返回边的个数

    // 向图中添加一个边
    // v 和 w 是两个顶点相应的索引
    // 添加从v到w的边
    // 我们用邻接矩阵来实现稠密图时，平行边被自动忽略
    void addEdge( int v , int w ){

        assert( v >= 0 && v < n );
        assert( w >= 0 && w < n );
        //平行边被忽略了
        if( hasEdge( v , w ) )
            return;

        g[v][w] = true;
        if( !directed )
            //无向图
            g[w][v] = true;

        m ++;
    }

    // 验证图中是否有从v到w的边
    // 时间复杂度是O(1)级别的
    bool hasEdge( int v , int w ){
        assert( v >= 0 && v < n );
        assert( w >= 0 && w < n );
        return g[v][w];
    }
};

#endif //INC_02_GRAPH_REPRESENTATION_DENSEGRAPH_H
