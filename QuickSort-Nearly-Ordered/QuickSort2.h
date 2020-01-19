//
// Created by changfx on 2020/1/19.
//

#ifndef QUICKSORT_QUICKSORT2_H
#define QUICKSORT_QUICKSORT2_H

#include <ctime>


template<typename T>
int __partition2(T arr[], int l, int r) {
    /*
     *  // 双路快速排序的partition
        // 返回p, 使得arr[l...p-1] <= arr[p] ; arr[p+1...r] >= arr[p]
        // 双路快排处理的元素正好等于arr[p]的时候要注意，详见下面的注释：）
     * */
    // 随机在arr[l...r]的范围中, 选择一个数值作为标定点pivot
    swap(arr[l], arr[rand() % (r - l + 1) + l]);
    T v = arr[l];


//    arr[l+1 ,i) <=v ; arr(j,r] >=v
    int i = l + 1, j = r;
    while (true) {
        // 注意这里的边界, arr[i] < v, 不能是arr[i] <= v
        // 思考一下为什么?
        while (i <= r && arr[i] < v)
            i++;

        // 注意这里的边界, arr[j] > v, 不能是arr[j] >= v
        // 思考一下为什么?
        while (j >= l + 1 && arr[j] > v)
            j--;

        if (i > j)
            break;

        swap(arr[i], arr[j]);
        i++;
        j--;
    }

    // 要好好理解一下 , j 的位置才是最后一个 <=v 的位置
    swap(arr[l], arr[j]);
    return j;
}


template<typename T>
void __quickSort2(T arr[], int left, int right) {
    /* 快速排序
     * */


    if (right - left <= 15) {
        // 对于小数组  采用插入排序的方法
        insertionSort(arr, left, right);
        return;
    }
    // 返回一个分界点
    int pos = __partition2(arr, left, right);
    __quickSort2(arr, left, pos - 1);
    __quickSort2(arr, pos + 1, right);

}


template<typename T>
void quickSort2(T arr, int len) {
    /* 快速排序
     * */

    srand(time(NULL));

    __quickSort2(arr, 0, len - 1);

}


#endif //QUICKSORT_QUICKSORT2_H
