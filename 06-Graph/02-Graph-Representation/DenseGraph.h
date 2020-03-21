//
// Created by CHANGFX on 2020/3/2.
//

#ifndef INC_02_GRAPH_REPRESENTATION_DENSEGRAPH_H
#define INC_02_GRAPH_REPRESENTATION_DENSEGRAPH_H

#include <algorithm>
#include <cassert>
#include <vector>

using namespace std;

class DenseGraph {

private:
    int m;// 边
    int n; // 结点
    bool directed; //  是否有方向
    vector<vector<bool>> g;


public:

    DenseGraph(int n, bool directed) {

        this->n = n;
        this->m = 0;  // 初始化 没有任何边
        this.directed = directed;

        for (int i = 0; i < n; i++) {

            g.push_back(vector<bool>(n, false));
        }


    }

    ~DenseGraph() {}


    // 返回节点个数
    int V() {
        return n;
    }

    // 返回边的个数
    int E() {
        return m;
    }

    void addEdge(int v, int w) {

        assert(v >= 0 && v < n);
        assert(w >= 0 && w < n);
        if (hasEdge(v, w)) {
            return;
        }

        g[v][w] = true;
        if (!this->directed) {
            g[w][v] = true;
        }

        m++;

    }

    bool hasEdge(int v, int w) {
        assert(v >= 0 && v < n);
        assert(w >= 0 && w < n);
        return g[v][w];
    }

};

//  12min   7-2 视频 位置

#endif //INC_02_GRAPH_REPRESENTATION_DENSEGRAPH_H
