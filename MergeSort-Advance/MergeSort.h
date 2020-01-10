//
// Created by changfx on 2020/1/9.
//

#ifndef MERGESORT_MERGESORT_H
#define MERGESORT_MERGESORT_H

/*
 *  todo  说明 文档  我的实现
 *
 *
 *
 * */

template<typename T>
void __merge(T arr[], int l, int m, int r) {
    /* [l,m]   [m+1,r]  进行 merge 操作
     *
     * */

    int l_len = m - l + 1;
    int r_len = r - m;

    int i, j = 0;
    int k = 0;

    T *L = new T[l_len];
    T *R = new T[r_len];


    // copy 数据 到 L
    for (i = 0; i < l_len; i++) {
        L[i] = arr[i + l];
    }

    // copy 数据 到 L
    for (j = 0; j < r_len; j++) {
        R[j] = arr[j + m + 1];
    }

    // 重置 i,j 的值
    i = j = 0;
    // 即将要插入的位置, 从l 开始插入
    k = l;
    while (i != l_len && j != r_len) {

        if (L[i] <= R[j]) {
            arr[k] = L[i];
            k++;
            i++;
        } else {
            arr[k] = R[j];
            k++;
            j++;
        }
    }

    while (i < l_len) {
        // L 有一部分没有 归并 ,直接拷贝到数组中
        arr[k++] = L[i++];
    }

    while (j < r_len) {
        // R 有一部分没有 归并 ,直接拷贝到数组中
        arr[k++] = R[j++];
    }


    // 释放内存
    delete[]  L;
    delete[]  R;


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

#endif //MERGESORT_MERGESORT_H
