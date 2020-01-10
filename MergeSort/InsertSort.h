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

#endif //MERGESORT_INSERTSORT_H