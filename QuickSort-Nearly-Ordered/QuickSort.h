//
// Created by changfx on 2020/1/19.
//

#ifndef QUICKSORT_QUICKSORT_H
#define QUICKSORT_QUICKSORT_H

#include <ctime>


template<typename T>
int __partition(T arr[], int left, int right) {
    /*
     * partition process
     * 在 [left,right]
     *返回一个位置 p   arr[l..p-1] < arr[p] , arr[p+1] > arr[p]
     * */

    int index = rand() % (right - left + 1) + left;
    // 交换一下位置
    swap(arr[left], arr[index]);


    T v = arr[left];


    int j = left;

    // arr[left+1 ...j] <=v ;  arr[j+1,i) >v
    for (int i = left + 1; i <= right; i++) {
        //  arr[i]>v  do nothig 只要 i++ 即可
        if (arr[i] < v) {
            j++;
            swap(arr[j], arr[i]);

        }
    }
    swap(arr[j], arr[left]);
    return j;
}




template<typename T>
void __quickSort(T arr[], int left, int right) {
    /* 快速排序
     * */


    if (right - left <= 15) {
        // 对于小数组  采用插入排序的方法
        insertionSort(arr, left, right);
        return;
    }
    // 返回一个分界点
    int pos = __partition(arr, left, right);
    __quickSort(arr, left, pos - 1);
    __quickSort(arr, pos + 1, right);

}


template<typename T>
void quickSort(T arr, int len) {
    /* 快速排序
     * */


    srand(time(NULL));

    __quickSort(arr, 0, len - 1);

}


#endif //QUICKSORT_QUICKSORT_H
