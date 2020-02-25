//
// Created by CHANGFX on 2020/2/23.
//

#ifndef INC_01_QUICK_FIND_UNIONFIND1_H
#define INC_01_QUICK_FIND_UNIONFIND1_H

#include <cassert>
#include <iostream>
#include <cassert>

namespace UF1 {

    class UnionFind {


        private:
            int *id;
            int count; // 记录多少个元素


        public:
            UnionFind(int n) {
                count = n;
                id = new int[n];

                for (int i = 0; i < n; i++) {

                    id[i] = i;
                }
            }

            ~UnionFind() {
                delete[] id;
            }

            int find(int p) {

                assert(p >= 0 && p < count);
                return id[p];
            }

            /* 判断是否 连接在一起

            * 返回bool 值
             */
            bool isConnected(int p, int q) {


                return find(p) == find(q);
            }


            void unionElements(int p, int q) {

                int pID = find(p);
                int qID = find(q);

                if (pID == qID) {
                    // 本来就在一个组 ，不需要union 操作
                    return;
                }

                for (int i = 0; i < count; i++) {
                    if (id[i] == pID) {
                        id[i] = qID;
                    }
                }
            }

    };


}


#endif //INC_01_QUICK_FIND_UNIONFIND1_H
