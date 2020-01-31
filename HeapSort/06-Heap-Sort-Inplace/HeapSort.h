//
// Created by CHANGFX on 2020/1/30.
//

#ifndef INC_06_HEAP_SORT_INPLACE_HEAPSORT_H
#define INC_06_HEAP_SORT_INPLACE_HEAPSORT_H

#include "Heap.h"

/*
 *
 * 比较 两种 堆排序 ，
 * 1 初始化的时候 ，就把堆 建立好
 * 2 一个一个插入 ，就把堆 建立好
 *
 *
 * 时间复杂度 分析
    一个一个插入的时间复杂度 是 O(nlogn)
    heapify 的过程  ， 算法时间复杂度 O(n)
 * */
template <typename T>
void heapSort1(T arr[], int len){

    MaxHeap<T> maxHeap = MaxHeap<T>(len) ;

    for (int i =0;i<len;i++){
        maxHeap.push(arr[i]);
    }


    for (int i=len-1;i>=0;i--){
        arr[i] = maxHeap.pop();
    }
}


template <typename T>
void heapSort2(T arr[], int len){

    MaxHeap<T> maxHeap = MaxHeap<T>(arr,len) ;

    for (int i=len-1;i>=0;i--){
        arr[i] = maxHeap.pop();
    }
}


#endif //INC_06_HEAP_SORT_INPLACE_HEAPSORT_H
