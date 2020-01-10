#include <iostream>
#include "SortTestHelper.h"
#include "MergeSort2.h"
#include "InsertSort.h"

using namespace std;


int main() {

    int n = 10000;

    int *arr1 = SortTestHelper::generateRandomArray(n, 0, n);
    int *arr2 = SortTestHelper::copyIntArray(arr1, n);


    // 测试1 一般性测试
    cout << "Test for random array, size = " << n << ", random range [0, " << n << "]" << endl;
    SortTestHelper::testSort("Merge Sort", mergeSort, arr1, n);
    SortTestHelper::testSort("Insertion Sort", insertionSort, arr2, n);

    delete[]  arr1;
    delete[]  arr2;
    cout << endl;

    // 测试2 测试近乎有序的数组
    // 对于近乎有序的数组, 数组越有序, InsertionSort的时间性能越趋近于O(n)
    // 所以可以尝试, 当swapTimes比较大时, MergeSort更快
    // 但是当swapTimes小到一定程度, InsertionSort变得比MergeSort快
    int swapTimes = 10;
    assert(swapTimes >= 0);

    cout << "Test for nearly ordered array, size = " << n << ", swap time = " << swapTimes << endl;
    arr1 = SortTestHelper::generateNearlyOrderedArray(n, swapTimes);
    arr2 = SortTestHelper::copyIntArray(arr1, n);

    SortTestHelper::testSort("Insertion Sort", mergeSort, arr1, n);
    SortTestHelper::testSort("Merge Sort", insertionSort, arr2, n);

    delete[] arr1;
    delete[] arr2;

}