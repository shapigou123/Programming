//
// Created by liuyubobobo on 9/21/16.
//

#ifndef INC_02_GRAPH_REPRESENTATION_SPARSEGRAPH_H
#define INC_02_GRAPH_REPRESENTATION_SPARSEGRAPH_H

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

// 稀疏图 - 邻接表
class SparseGraph{

private:
    int n, m;       // 节点数和边数
    bool directed;  // 是否为有向图
    //g[i]里面存储的是和i这个顶点
    //相连的所有顶点的编号，故用int表示
    vector<vector<int>> g;  // 图的具体数据

public:
    // 构造函数
    SparseGraph( int n , bool directed ){
        assert( n >= 0 );
        this->n = n;
        this->m = 0;    // 初始化没有任何边
        this->directed = directed;
        // g初始化为n个空的vector, 表示每一个g[i]都为空,
        // 即没有任和边相连。 我们也可以用链表来实现，
        // 链表实现时删除的时候会更方便
        g = vector<vector<int>>(n, vector<int>());
        #if 0
        for(int i=0; i<n; i++)
            //每次push传入一个空的vector
            g.push_back(vector<int>());
        #endif
    }

    ~SparseGraph(){ }

    int V(){ return n;} // 返回节点个数
    int E(){ return m;} // 返回边的个数

    // 向图中添加一个边
    // 如果我们在这里进行hasEdge,那么它也会变成O(n)
    // 所以在邻接表中先不管平行边，即允许平行边
    void addEdge( int v, int w ){

        assert( v >= 0 && v < n );
        assert( w >= 0 && w < n );

        //向g[v]中添加w，表示v和w相连
        g[v].push_back(w);
        //处理自环边和有向图。
        //v和w一致的话只需要push一次即可
        if( v != w && !directed )
            g[w].push_back(v);

        m ++;
    }

    // 验证图中是否有从v到w的边
    // 时间复杂度在最坏情况下是O(n)级别的
    bool hasEdge( int v , int w ){

        assert( v >= 0 && v < n );
        assert( w >= 0 && w < n );

        for( int i = 0 ; i < g[v].size() ; i ++ )
            if( g[v][i] == w )
                //找到了从v到w的边
                return true;
        return false;
    }
};

#endif //INC_02_GRAPH_REPRESENTATION_SPARSEGRAPH_H
