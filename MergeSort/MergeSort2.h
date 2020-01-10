//
// Created by changfx on 2020/1/9.
//
/*
 * 老师的实现
 * */

#ifndef MERGESORT_MERGESORT2_H
#define MERGESORT_MERGESORT2_H

#include "SortTestHelper.h"

template<typename T>
void __merge(T arr[], int l, int mid, int r) {
    /*  [l,mid]   [mid+1,r]  进行 merge 操作
     *
     *
     *
     * */


    T aux[r-l+1];
    // copy data aux 中
    for( int i = l ; i <= r; i ++ )
        aux[i-l] = arr[i];


    int i, j, k;

    // 初始化，i指向左半部分的起始索引位置l；j指向右半部分起始索引位置mid+1
    i = l;
    j = mid + 1;

    for (k = l; k <= r; k++) {
        if (i > mid) {// 如果左半部分元素已经全部处理完毕
            // 注意这里有个偏移量
            arr[k] = aux[j-l];
            j++;

        } else if (j > r) {// 如果右半部分元素已经全部处理完毕
            arr[k] = aux[i - l];
            i++;
        }
        else if (aux[i-l] <= aux[j-l]) {
            // 左半部分所指元素 < 右半部分所指元素
            // 注意这里有个偏移量
            arr[k] = aux[i-l];
            i++;

        } else {
            // 这里为啥要有偏移量??
            arr[k] = aux[j-l];
            j++;
        }

    }

//    delete[]  aux;
}


template<typename T>
void __mergeSort(T arr[], int l, int r) {
    /*
     * [l,r] 区间的数据 进行 mergeSort 操作 .
     *
     *
     * */
    if (l >= r) {
        return;
    }

    int mid = l + (r - l) / 2;
    __mergeSort(arr, l, mid);
    __mergeSort(arr, mid + 1, r);
    __merge(arr, l, mid, r);
}


template<typename T>
void mergeSort(T arr[], int len) {

    __mergeSort(arr, 0, len - 1);

}

#endif //MERGESORT_MERGESORT2_H
