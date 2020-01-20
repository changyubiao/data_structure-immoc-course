//
// Created by changfx on 2020/1/19.
/*
 * 三路 路快排 方法
 *
 * */
//

#ifndef QUICKSORT_QUICKSORT3_H
#define QUICKSORT_QUICKSORT3_H

#include <ctime>


template<typename T>
void __quickSort3Ways(T arr[], int l, int r) {
    /*
     * 三路快排
     *
     *  arr[l+1,lt] < v      [lt+1,..,i-1] ==v ,   [gt,r] >v
     *
     *  i 为当前考察的元素
     * */

    // 对于小规模数组, 使用插入排序进行优化
    if (r - l <= 15) {
        insertionSort(arr, l, r);
        return;
    }

    // 随机在arr[l...r]的范围中,选择一个数值作为标定点pivot
    swap(arr[l], arr[rand() % (r - l + 1) + l]);
    T v = arr[l];


    int lt = l;
    int gt = r + 1;
    int i = l + 1;

    /*
     * 初始值的确认
     * [l+1,lt]     lt -->  l
     *
     * [lt+1,i-1]   i ---> l+1
     *
     * [gt , r]   gt ---> r+1
     * */

    for (; i < gt;) {
        // 注意for 循环的条件
        if (arr[i] > v) {
            swap(arr[i], arr[gt - 1]);
            gt--;
        } else if (arr[i] < v) {
            swap(arr[i], arr[lt + 1]);
            i++;
            lt++;
        } else {
            // arr[i] ==v
            i++;
        }
    }

    swap(arr[l], arr[lt]);

    __quickSort3Ways(arr, l, lt - 1);
    __quickSort3Ways(arr, gt, r);
}


template<typename T>
void quickSort3(T arr, int len) {
    /*  三路快排 快速排序
     * */

    srand(time(NULL));

    __quickSort3Ways(arr, 0, len - 1);

}


#endif //QUICKSORT_QUICKSORT3_H
