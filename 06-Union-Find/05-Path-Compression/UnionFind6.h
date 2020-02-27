//
// Created by CHANGFX on 2020/2/26.
//
/*
 *  路径压缩 find的时候完成 路径压缩。
 *
 *  递归的方式 实现路径压缩算法
 *
 * */

#ifndef INC_05_UNION_OPTIMIZE_BY_RANK_UNIONFIND6_H
#define INC_05_UNION_OPTIMIZE_BY_RANK_UNIONFIND6_H

#include <cassert>

namespace UF6 {

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

            if(p != parent[p]){
                parent[p] = find(parent[p]);
            }

            return parent[p];

        }


        // 查看元素p和元素q是否所属一个集合
        // O(h)复杂度, h为树的高度
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


#endif //INC_05_UNION_OPTIMIZE_BY_RANK_UNIONFIND6_H
