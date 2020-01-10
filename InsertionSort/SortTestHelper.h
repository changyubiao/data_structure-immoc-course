//
// Created by frank on 2020/1/5.
//

#ifndef SELECTIONSORT_SORTTESTHELPER_H
#define SELECTIONSORT_SORTTESTHELPER_H

#include <iostream>
#include <ctime>
#include <cassert>

using namespace std;

namespace SortTestHelper {


    template<typename T>
    void printArray(T *arr, int len) {

        for (int i = 0; i < len; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;

    }


    int *generateRandomArray(int len, int rangeL, int rangeR) {
        /*
         * 生成  n个元素的 随机数组 [ rangeL, rangeR ]
         *
         *
         */




        assert (rangeL < rangeR);


        int *arr = new int[len];


        // 生成 随机 种子
        srand(time(NULL));


        for (int i = 0; i < len; i++) {

            arr[i] = (rand() % (rangeR - rangeL + 1)) + rangeL;
        }

        return arr;
    }


    int *generateNearlyOrderArray(int len, int swaptimes) {

        int *arr = new int[len];
        for (int i = 0; i < len; i++)
            arr[i] = i;


        srand(time(NULL));

        int posx = rand() % len;
        int posy = rand() % len;

        for (int i = 0; i < swaptimes; i++) {

            swap(arr[posx], arr[posy]);
        }

        return arr;
    }

    template<typename T>
    bool isSorted(T array[], int len) {
        /*
         * 判断 是否已经排序成功
         * */

        for (int i = 0; i < len - 1; i++) {
            if (array[i] > array[i + 1]) {
                return false;
            }
        }
        return true;

    }

    template<typename T>
    void testSort(string funtionName, void (*sort)(T [], int), T arr[], int len) {


        clock_t start = clock();

        sort(arr, len);
        clock_t end = clock();

        assert(isSorted(arr, len));

        cout << " " << funtionName << "cost time: " << double(end - start) / CLOCKS_PER_SEC << " s" << endl;
        return;

    }


    int *copyIntArray(int a[], int len) {


        int *arr = new int[len];
//        copy(arr,arr+len,arry);

        copy(a, a + len, arr);

        return arr;

    }

}


#endif //SELECTIONSORT_SORTTESTHELPER_H
