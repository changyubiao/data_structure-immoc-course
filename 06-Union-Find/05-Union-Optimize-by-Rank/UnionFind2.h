//
// Created by CHANGFX on 2020/2/23.
//

#ifndef INC_03_QUICK_UNION_UNIONFIND2_H
#define INC_03_QUICK_UNION_UNIONFIND2_H


namespace UF2 {
    class UnionFind {
    private:
        int *parent;         // parent[i]表示第i个元素所指向的父节点

        int count;

    public:

        explicit UnionFind(int count) {

            parent = new int[count];
            this->count  = count;

            // 初始化, 每一个parent[i]指向自己, 表示每一个元素自己自成一个集合
            for (int i = 0; i < count; i++) {
                parent[i] = i;
            }
        }

        ~UnionFind() {
            delete[]  parent;
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
            parent[pRoot] = qRoot;

        }
    };

}


#endif //INC_03_QUICK_UNION_UNIONFIND2_H
