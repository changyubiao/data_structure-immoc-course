#include <iostream>
#include "Heap.h"
#include "SortTestHelper.h"
#include "HeapSort.h"


template <typename T>
void __shiftDown(T arr[],int len,int k){

    // 首先要判断有没有左孩子，有左孩子 就说明 还没有到堆的最后一层
    // 左孩子 不能越界 ,所以这里应该是 小于
    while (2 * k +1 <len) {

        // 初始化  为左孩子
        // 此轮循环中 要找到 孩子中较大的那个 索引的位置，即为 j,  arr[j] 和 arr[k] 进行交换
        int j = 2 * k +1 ;//此轮 循环 是要找到哪个 节点应该和j 的位置互换

        if (j + 1 < len && arr[j + 1] > arr[j]) {
            j = j + 1;
        }

        if (arr[j] <= arr[k]) {
            // 说明 已经 是大顶堆了，不用继续寻找下去了。
            break;
        }

        swap(arr[j], arr[k]);

        // 更新k
        k = j;
    }



}


template <typename T>
void heapSort3(T arr[], int len){
    /*
     * 此时 索引 从0 开始
     *
     * 第一个非叶子节点    （len-1 -1）/2
     *
     *  parent   = i
     *
     *  left  child  2*i +1
     *  right child  2*i +1  +1
     *
     *
     *  已知一个节点 索引 k  ,  parent  = (i-1)/2
     * */

    MaxHeap<T> maxHeap = MaxHeap<T>(arr,len) ;

    //heapify 操作
    for( int i = (len-1-1)/2 ; i >= 0 ; i -- )
        __shiftDown(arr, len, i);

    for (int i = len-1;i>0;i--){
        swap(arr[i],arr[0]);
        __shiftDown(arr, i, 0);
    }

}


int main1() {

    int n = 100000;
    int *arr1 = nullptr;
    int *arr2 = nullptr;
    int *arr3 = nullptr;


    cout << "Test for random array, size = " << n << ", random range [0, " << n << "]" << endl;
    arr1 = SortTestHelper::generateRandomArray(n, 0, n);
    arr2 = SortTestHelper::copyIntArray(arr1, n);
    arr3 = SortTestHelper::copyIntArray(arr1, n);


    SortTestHelper::testSort("heapSort1 ",heapSort1 , arr1, n);
    SortTestHelper::testSort("heapSort2 ",heapSort2 , arr2, n);
    SortTestHelper::testSort("heapSort3 ",heapSort3 , arr3, n);


    delete[] arr1;
    delete[] arr2;
    delete[] arr3;

    cout << endl;
    return 0;
}

// 比较 Merge Sort, 三种 Quick Sort 和本节介绍的三种 Heap Sort 的性能效率
// 注意, 这几种排序算法都是 O(nlogn) 级别的排序算法
int main() {

    int n = 1000000;

    // 测试1 一般性测试
    cout<<"Test for random array, size = "<<n<<", random range [0, "<<n<<"]"<<endl;
    int* arr1 = SortTestHelper::generateRandomArray(n,0,n);
//    int* arr2 = SortTestHelper::copyIntArray(arr1, n);
//    int* arr3 = SortTestHelper::copyIntArray(arr1, n);
//    int* arr4 = SortTestHelper::copyIntArray(arr1, n);
    int* arr5 = SortTestHelper::copyIntArray(arr1, n);
    int* arr6 = SortTestHelper::copyIntArray(arr1, n);
    int* arr7 = SortTestHelper::copyIntArray(arr1, n);


    SortTestHelper::testSort("Heap Sort 1", heapSort1, arr5, n);
    SortTestHelper::testSort("Heap Sort 2", heapSort2, arr6, n);
    SortTestHelper::testSort("Heap Sort 3", heapSort3, arr7, n);

    delete[] arr1;

    delete[] arr5;
    delete[] arr6;
    delete[] arr7;

    cout<<endl;


    // 测试2 测试近乎有序的数组
    int swapTimes = 100;
    cout<<"Test for nearly ordered array, size = "<<n<<", swap time = "<<swapTimes<<endl;
    arr1 = SortTestHelper::generateNearlyOrderedArray(n,swapTimes);

    arr5 = SortTestHelper::copyIntArray(arr1, n);
    arr6 = SortTestHelper::copyIntArray(arr1, n);
    arr7 = SortTestHelper::copyIntArray(arr1, n);


    SortTestHelper::testSort("Heap Sort 1", heapSort1, arr5, n);
    SortTestHelper::testSort("Heap Sort 2", heapSort2, arr6, n);
    SortTestHelper::testSort("Heap Sort 3", heapSort3, arr7, n);

    delete[] arr1;

    delete[] arr5;
    delete[] arr6;
    delete[] arr7;

    cout<<endl;


    // 测试3 测试存在包含大量相同元素的数组
    cout<<"Test for random array, size = "<<n<<", random range [0,10]"<<endl;
    arr1 = SortTestHelper::generateRandomArray(n,0,10);

    arr5 = SortTestHelper::copyIntArray(arr1, n);
    arr6 = SortTestHelper::copyIntArray(arr1, n);
    arr7 = SortTestHelper::copyIntArray(arr1, n);

    // 这种情况下, 普通的QuickSort退化为O(n^2)的算法, 不做测试
    SortTestHelper::testSort("Heap Sort 1", heapSort1, arr5, n);
    SortTestHelper::testSort("Heap Sort 2", heapSort2, arr6, n);
    SortTestHelper::testSort("Heap Sort 3", heapSort3, arr7, n);

    delete[] arr1;

    delete[] arr5;
    delete[] arr6;
    delete[] arr7;


    return 0;
}