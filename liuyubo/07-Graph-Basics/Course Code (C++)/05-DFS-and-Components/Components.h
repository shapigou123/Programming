//
// Created by liuyubobobo on 9/22/16.
//

#ifndef INC_05_DFS_AND_COMPONENTS_COMPONENTS_H
#define INC_05_DFS_AND_COMPONENTS_COMPONENTS_H

#include <iostream>
#include <cassert>
using namespace std;


// 求无权图的联通分量
// 模板类，由用户传入稀疏图或者稠密图
template <typename Graph>
class Component{

private:
    Graph &G;       // 图的引用
    bool *visited;  // 记录dfs的过程中节点是否被访问
    int ccount;     // 记录联通分量个数
    //相连的节点的id相同！
    int *id;        // 每个节点所对应的联通分量标记

    // 图的深度优先遍历
    void dfs( int v ){

        visited[v] = true;
        //初始时ccount为0，第一次运行dfs时，只需要
        //将遍历到的v的id值设置为ccount的值
        //当遍历第一个联通分量时，ccount的值为0
        //遍历第二个联通分量时，ccount++值变为1
        id[v] = ccount;
        //typename显示声明adjIterator为Graph中的一个类
        //遍历G这个图中与V所有相邻的节点
        typename Graph::adjIterator adj(G, v);
        for( int i = adj.begin() ; !adj.end() ; i = adj.next() ){
            if( !visited[i] )
                dfs(i);
        }
    }

public:
    // 构造函数, 求出无权图的联通分量
    Component(Graph &graph): G(graph){

        // 算法初始化
        // G.V[]为图中顶点的个数
        visited = new bool[G.V()];
        id = new int[G.V()];
        ccount = 0;
        for( int i = 0 ; i < G.V() ; i ++ ){
            visited[i] = false;
            id[i] = -1;
        }

        // 求图的联通分量
        // 遍历图中的每一个节点
        for( int i = 0 ; i < G.V() ; i ++ )
            if( !visited[i] ){
                //若节点没有被遍历过，则对该节点进行深度优先遍历
                //对i和i所有相连接的节点进行遍历
                //没遍历的节点则在另外的联通分量中
                dfs(i);
                ccount ++;
            }
    }

    // 析构函数
    ~Component(){
        delete[] visited;
        delete[] id;
    }

    // 返回图的联通分量个数
    int count(){
        return ccount;
    }

    // 查询点v和点w是否联通
    bool isConnected( int v , int w ){
        assert( v >= 0 && v < G.V() );
        assert( w >= 0 && w < G.V() );
        return id[v] == id[w];
    }
};

#endif //INC_05_DFS_AND_COMPONENTS_COMPONENTS_H
