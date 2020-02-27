//
// Created by CHANGFX on 2020/2/26.
//
/*
 *  路径压缩 find的时候完成 路径压缩。
 *
 *  每次 走 两步,同时 修改parent 数组的值
 *
 * */

#ifndef INC_05_UNION_OPTIMIZE_BY_RANK_UNIONFIND5_H
#define INC_05_UNION_OPTIMIZE_BY_RANK_UNIONFIND5_H

#include <cassert>

namespace UF5 {

    class UnionFind {

    public:
        int count;    // 当前并查集 元素个数
        int *rank;    //rank[i] 表示结点为i 的 树高度
        int *parent;  // parent[i]表示第i个元素所指向的父节点


        UnionFind(int count) {

            parent = new int[count];
            rank = new int[count];

            this->count = count;

            for (int i = 0; i < count; i++) {
                parent[i] = i;
                rank[i] = 1;
            }

        }


        ~UnionFind() {
            delete[]  parent;
            delete[] rank;
        }


        int find(int p) {
            assert(p >= 0 && p < count);
            while (p != parent[p]) {
                // 一直 跳两步，跳完后 把路径变短了。修改parent 数组 让路径变短了。
                parent[p] = parent[parent[p]];
                p = parent[p];
            }
            return p;
        }


        bool isConnected(int p, int q) {
            return find(p) == find(q);
        }


        void unionElements(int p, int q) {

            int pRoot = find(p);
            int qRoot = find(q);
            if (pRoot == qRoot) {
                // 不需要union 操作
                return;
            }

            if (rank[pRoot] < rank[qRoot]) {
                parent[pRoot] = qRoot;
                // 这里不需要更新 rank 数组

            } else if (rank[qRoot] < rank[pRoot]) {
                parent[qRoot] = pRoot;

            } else {
                //  rank[qRoot] == rank[pRoot]
                parent[pRoot] = qRoot;
                rank[qRoot] += 1;
            }

        }


        int size() {
            return count;
        }


    };

}


#endif //INC_05_UNION_OPTIMIZE_BY_RANK_UNIONFIND5_H
