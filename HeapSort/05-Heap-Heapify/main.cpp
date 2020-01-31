#include <iostream>
#include "Heap.h"
#include "SortTestHelper.h"

/*
 *
 * 比较 两种 堆排序 ，
 * 1 初始化的时候 ，就把堆 建立好
 * 2 一个一个插入 ，就把堆 建立好
 *
 *
 * 时间复杂度 分析
    一个一个插入的时间复杂度 是 O(nlogn)
    heapify 的过程，算法时间复杂度 O(n)
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

    MaxHeap<T> maxHeap = MaxHeap<T>(arr,len);

    for (int i=len-1;i>=0;i--){
        arr[i] = maxHeap.pop();
    }
}




int main01() {
    std::cout << "Hello, World! heapify" << std::endl;

    int arr[10] = {1,3,4,6,8, 7,9,12,30,34};
    MaxHeap<int > maxHeap = MaxHeap<int > (arr,10) ;
    maxHeap.printHeap();
    return 0;
}



int main() {

    int n = 1500000;
    int *arr1 = nullptr;
    int *arr2 = nullptr;


    cout << "Test for random array, size = " << n << ", random range [0, " << n << "]" << endl;
    arr1 = SortTestHelper::generateRandomArray(n, 0, n);
    arr2 = SortTestHelper::copyIntArray(arr1, n);


    SortTestHelper::testSort("heapSort1 ",heapSort1 , arr1, n);
    SortTestHelper::testSort("heapSort2 ",heapSort2 , arr2, n);

    delete[] arr1;
    delete[] arr2;

    cout << endl;
    return 0;
}
