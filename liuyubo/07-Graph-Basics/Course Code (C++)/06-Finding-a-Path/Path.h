//
// Created by liuyubobobo on 9/22/16.
//

#ifndef INC_06_FINDING_A_PATH_PATH_H
#define INC_06_FINDING_A_PATH_PATH_H

#include <vector>
#include <stack>
#include <iostream>
#include <cassert>

using namespace std;

// 路径查询
template <typename Graph>
class Path{

private:
    Graph &G;   // 图的引用
    int s;      // 起始点
    bool* visited;  // 记录dfs的过程中节点是否被访问
    // 记录我们当前遍历的节点是从哪个节点来的
    int * from;     // 记录路径, from[i]表示查找的路径上i的上一个节点

    // 图的深度优先遍历
    void dfs( int v ){

        visited[v] = true;

        //初始化迭代器，从V开始迭代遍历
        typename Graph::adjIterator adj(G, v);
        //i的初始值为与V相连的第一个顶点
        for( int i = adj.begin() ; !adj.end() ; i = adj.next() ){
            if( !visited[i] ){
                //表示当前访问的节点是从V节点过来的！
                from[i] = v;
                //递归依次遍历
                dfs(i);
            }
        }
    }

public:
    // 构造函数, 寻路算法, 寻找图graph从s点到其他点的路径
    Path(Graph &graph, int s):G(graph){

        // 算法初始化
        assert( s >= 0 && s < G.V() );

        visited = new bool[G.V()];
        from = new int[G.V()];
        for( int i = 0 ; i < G.V() ; i ++ ){
            visited[i] = false;
            from[i] = -1;
        }
        this->s = s;

        // 寻路算法
        dfs(s);
    }

    // 析构函数
    ~Path(){

        delete [] visited;
        delete [] from;
    }

    // 查询从s点到w点是否有路径
    bool hasPath(int w){
        assert( w >= 0 && w < G.V() );
        //为true说明从s通过dfs访问到了w，则一定存在路径
        return visited[w];
    }

    // 查询从s点到w点的路径, 存放在vec中
    // c从w倒推回去
    void path(int w, vector<int> &vec){

        assert( hasPath(w) );

        //将倒推的节点都放入到stack中
        stack<int> s;
        // 通过from数组逆向查找到从s到w的路径, 存放到栈中
        int p = w;
        //while循环的条件为什么是-1？？
        //因为from数组的初始值为-1
        while( p != -1 ){
            s.push(p);
            p = from[p];
        }

        // 从栈中依次取出元素, 获得顺序的从s到w的路径
        vec.clear();
        //为空返回true
        //不为空时执行循环
        while( !s.empty() ){
            vec.push_back( s.top() );
            s.pop();
        }
    }

    // 打印出从s点到w点的路径
    void showPath(int w){

        assert( hasPath(w) );

        vector<int> vec;
        path( w , vec );
        for( int i = 0 ; i < vec.size() ; i ++ ){
            cout<<vec[i];
            if( i == vec.size() - 1 )
                cout<<endl;
            else
                cout<<" -> ";
        }
    }
};

#endif //INC_06_FINDING_A_PATH_PATH_H
