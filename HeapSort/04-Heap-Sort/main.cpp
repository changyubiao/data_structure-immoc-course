#include <iostream>
#include "HeapSort.h"
#include "SortTestHelper.h"
#include "MergeSort.h"
#include "QuickSort.h"

using namespace std;

template<typename T>
void heapSort1(T arr[], int len) {

    MaxHeap<T> maxHeap = MaxHeap<T>(len);

    for (int i = 0; i < len; i++) {
        maxHeap.push(arr[i]);
    }


    for (int i = len - 1; i >= 0; i--) {
        arr[i] = maxHeap.pop();
    }
}


int main12() {

    int n = 1000000;
//    int n = 10;
    int *arr1 = nullptr;
    int *arr2 = nullptr;
    int *arr3 = nullptr;
    int *arr4 = nullptr;
    cout << "Test for random array, size = " << n << ", random range [0, " << n << "]" << endl;

    // 测试1 测试 任意的数组

    arr1 = SortTestHelper::generateRandomArray(n, 0, n);
    arr2 = SortTestHelper::copyIntArray(arr1, n);
    arr3 = SortTestHelper::copyIntArray(arr1, n);

//    SortTestHelper::testSort("quickSort", quickSort, arr1, n);
    SortTestHelper::testSort("mergeSort", mergeSort, arr2, n);
    SortTestHelper::testSort("heapSort1", heapSort1, arr3, n);


    delete[] arr1;
    delete[] arr2;
    delete[] arr3;
    cout << endl;

    // 测试2 测试近乎有序的数组
    // 加入了随机选择标定点的步骤后, 我们的快速排序可以轻松处理近乎有序的数组
    // 但是对于近乎有序的数组, 其效率比优化后的归并排序要低, 但完全再容忍范围里
    // 思考一下为什么对于近乎有序的数组, 快排的性能比优化后的归并排序低? :)
    int swapTimes = 10;
    cout << "Test for nearly ordered array, size = " << n << ", swap time = " << swapTimes << endl;
    arr1 = SortTestHelper::generateNearlyOrderedArray(n, swapTimes);
    arr2 = SortTestHelper::copyIntArray(arr1, n);
    arr3 = SortTestHelper::copyIntArray(arr1, n);


    SortTestHelper::testSort("Merge Sort", mergeSort, arr1, n);
//    SortTestHelper::testSort("Quick Sort", quickSort, arr2, n);
    SortTestHelper::testSort("heapSort1", heapSort1, arr3, n);


    delete[] arr1;
    delete[] arr2;
    delete[] arr3;
    cout << endl;



    // 测试3 测试存在包含大量相同元素的数组
    // 使用双快速排序后, 我们的快速排序算法可以轻松的处理包含大量元素的数组
    cout << "Test for random array, size = " << n << ", random range [0,10]" << endl;
    arr1 = SortTestHelper::generateRandomArray(n, 0, 10);
    arr2 = SortTestHelper::copyIntArray(arr1, n);
    arr3 = SortTestHelper::copyIntArray(arr1, n);
    arr4 = SortTestHelper::copyIntArray(arr1, n);


    SortTestHelper::testSort("Merge Sort", mergeSort, arr1, n);
//    SortTestHelper::testSort("Quick Sort", quickSort, arr2, n);
    SortTestHelper::testSort("heapSort1", heapSort1, arr3, n);

    delete[] arr1;
    delete[] arr2;
    delete[] arr3;
    delete[] arr4;

    cout << endl;
    return 0;
}


int main() {

//    int n = 100000;
    int n = 15;
    int *arr1 = nullptr;
    int *arr2 = nullptr;


    cout << "Test for random array, size = " << n << ", random range [0, " << n << "]" << endl;
    arr1 = SortTestHelper::generateRandomArray(n, 0, 100);
    arr2 = SortTestHelper::copyIntArray(arr1, n);


    SortTestHelper::testSort("heapSort1 ", heapSort1, arr1, n);
    SortTestHelper::testSort("quickSort ", quickSort, arr2, n);


    SortTestHelper::printArray(arr1, n);
    SortTestHelper::printArray(arr2, n);

    delete[] arr1;
    delete[] arr2;

    cout << endl;
    return 0;
}


