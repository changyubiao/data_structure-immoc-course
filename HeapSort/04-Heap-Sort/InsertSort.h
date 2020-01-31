//
// Created by changfx on 2020/1/9.
//

#ifndef MERGESORT_INSERTSORT_H
#define MERGESORT_INSERTSORT_H

#include <iostream>

using namespace std;

template<typename T>
void insertionSort(T arr[], int n) {

    for (int i = 1; i < n; i++) {

        T tmp = arr[i];
        int j;
        for (j = i; j > 0 && arr[j - 1] > tmp; j--)
            arr[j] = arr[j - 1];
        arr[j] = tmp;
    }

}


template<typename T>
void insertionSort(T arr[], int left, int right) {
    /*
     * 对arr[left...right]范围的数组进行插入排序
     * */

    for (int i = left + 1; i <= right; i++) {
        T tmp = arr[i];
        int j;

        for (j = i; j > left && (tmp < arr[j - 1]); j--) {
            arr[j] = arr[j - 1];
        }
        arr[j] = tmp;

    }


}

#endif //MERGESORT_INSERTSORT_H


