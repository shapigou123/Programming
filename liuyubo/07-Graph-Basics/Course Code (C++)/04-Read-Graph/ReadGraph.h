//
// Created by liuyubobobo on 9/22/16.
//

#ifndef INC_04_READ_GRAPH_READGRAPH_H
#define INC_04_READ_GRAPH_READGRAPH_H

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cassert>

using namespace std;

// 读取图算法
// 对于ReadGraph这个类，我们都处理一个图
// 对于这个图我们不指定为稠密图或者稀疏图
template <typename Graph>
class ReadGraph{

public:
    // 从文件filename中读取图的信息, 存储进图graph中
    ReadGraph(Graph &graph, const string &filename){

        ifstream file(filename.c_str());
        string line;
        int V, E;

        assert( file.is_open() );

        // 第一行读取图中的节点个数和边的个数
        assert( getline(file, line) );
        stringstream ss(line);
        //将这个strintstream解析出点数和边数分别放入V和E中
        //将这个文件的点数和边数都读取了进来
        ss>>V>>E;

        //确认从文件中读取的点数和graph传进来的点数相同
        //因为图在构造的时候就需要传入点的数量
        assert( V == graph.V() );

        // 读取每一条边的信息
        for( int i = 0 ; i < E ; i ++ ){
            //读取file的一行放入line中
            assert( getline(file, line) );
            //将line的内容放入stringstream声明的对象中
            stringstream ss(line);

            int a,b;
            ss>>a>>b;
            assert( a >= 0 && a < V );
            assert( b >= 0 && b < V );
            graph.addEdge( a , b );
        }
    }
};

#endif //INC_04_READ_GRAPH_READGRAPH_H
