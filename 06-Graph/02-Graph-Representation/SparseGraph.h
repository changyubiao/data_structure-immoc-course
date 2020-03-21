//
// Created by CHANGFX on 2020/3/2.
//

#ifndef INC_02_GRAPH_REPRESENTATION_SPARSEGRAPH_H
#define INC_02_GRAPH_REPRESENTATION_SPARSEGRAPH_H

#include <cassert>
#include <vector>
#include <iostream>

using namespace std;

class SparseGraph {
/*稀疏图
 *  用邻接表 来表示
 *
 * */

private:

    int n;  // 结点
    int m;  //边
    bool directed;  // 是否有方向

    vector<vector<int>> g;  // 邻接表


public:
    SparseGraph(int n, bool directed) {
        this->n = n;
        this->directed = directed;

        for (int i = 0; i < n; i++) {

            g.push_back(vector<int>());
        }

    }


    ~SparseGraph() {};


    int V() { return n; }

    int E() { return m; }

    void addEdge(int v, int w) {
        assert(v >= 0 && v < n);
        assert(w >= 0 && w < n);

        g[v].push_back(w);
        if (v != w && !directed) {
            g[w].push_back(v);
        }

        m++;
    }


    bool hasEdge(int v, int w) {

        assert(v >= 0 && v < n);
        assert(w >= 0 && w < n);

        for (int i = 0; i < g[v].size(); i++) {
            if (g[v][i] == w) {
                return true;
            }
        }
        return false;
    }
};

#endif //INC_02_GRAPH_REPRESENTATION_SPARSEGRAPH_H
