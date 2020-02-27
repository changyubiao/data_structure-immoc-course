//
// Created by CHANGFX on 2020/2/23.
//

#ifndef INC_03_QUICK_UNION_UNIONFIND3_H
#define INC_03_QUICK_UNION_UNIONFIND3_H


namespace UF3 {
    class UnionFind {
    private:
        int *parent;  // parent[i]表示第i个元素所指向的父节点
        int *sz;    // sz[i]表示以i为根的集合中元素个数
        int count;    // 当前并查集 元素个数

    public:

        explicit UnionFind(int count) {

            parent = new int[count];
            sz = new int[count];

            this->count = count;

            // 初始化, 每一个parent[i]指向自己, 表示每一个元素自己自成一个集合
            for (int i = 0; i < count; i++) {
                parent[i] = i;
                sz[i] = 1;
            }
        }


        /*
         * 析构函数
         * 释放 parent，sz 数组
         * */
        ~UnionFind() {
            delete[]  parent;
            delete[]  sz;
        }


    public:

        int size() {
            return count;
        }

        /*
         * 返回p 所在的根
         * */
        int find(int p) {
            // 注意p 不要越界
            assert(p >= 0 && p < this->count);
            while (p != parent[p]) {
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
                //在同一颗树上，不需要合并
                return;
            }

            // 这里改一下,每次都让小的 树 向大的树 进行合并
            if (sz[pRoot] < sz[qRoot]) {
                // 谁的size 小，就把他 合并到另外一个根上
                parent[pRoot] = qRoot;
                sz[qRoot] += sz[pRoot];
            } else {
                // sz[pRoot] >= sz[qRoot]
                parent[qRoot] = pRoot;
                sz[pRoot] += sz[qRoot];
            }

        }
    };

}


#endif //INC_03_QUICK_UNION_UNIONFIND3_H
