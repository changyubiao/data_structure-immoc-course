#include <iostream>
#include "SortTestHelper.h"
#include "MergeSort2.h"
#include "InsertSort.h"

using namespace std;


int main() {

    // Merge Sort是我们学习的第一个O(nlogn)复杂度的算法
    // 可以在1秒之内轻松处理100万数量级的数据
    // 注意：不要轻易尝试使用SelectionSort, InsertionSort或者BubbleSort处理100万级的数据
    // 否则，你就见识了O(n^2)的算法和O(nlogn)算法的本质差异：）
    int n = 1000;


    int *arr1 = SortTestHelper::generateRandomArray(n, 0, 30);
    int *arr2 = SortTestHelper::copyIntArray(arr1, n);


    // 测试1 一般性测试
    cout << "Test for random array, size = " << n << ", random range [0, " << n << "]" << endl;
    SortTestHelper::testSort("Merge Sort", mergeSort, arr1, n);
    SortTestHelper::testSort("Insertion Sort", insertionSort, arr2, n);



    delete[] arr1;
    delete[] arr2;

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

    return 0;
}


int main_01(){


    cout<<"Angel I Love You so much!"  <<endl;

    cout<<"hello world"<<endl;
    return  0;
}