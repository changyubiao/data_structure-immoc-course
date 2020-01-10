#include <iostream>
#include "SortTestHelper.h"
#include "SelectionSort.h"

using namespace std;

template<typename T>
void insertSort1(T arr[], int len) {

    for (int i = 1; i < len; i++) {

        // 寻找合适的位置
        // arr[i]  合适的插入 位置
        for (int j = i; j > 0; j--) {
            if (arr[j] < arr[j - 1]) {
                swap(arr[j], arr[j - 1]);
            } else
                break;
        }

    }

}


template<typename T>
void insertSort2(T arr[], int len) {
    /*
     * 每次都交换 不够优化
     * */

    for (int i = 1; i < len; i++) {

        // 寻找合适的位置
        // arr[i]  合适的插入 位置
        for (int j = i; j > 0 && arr[j] < arr[j - 1]; j--) {
            swap(arr[j], arr[j - 1]);

        }

    }

}


template<typename T>
void insertSort(T arr[], int len) {
    /*
     *
     * */

    for (int i = 1; i < len; i++) {

        // 寻找合适的位置
        // arr[i]  合适的插入 位置

        T tmp = arr[i];
        int j;

        for (j = i; j > 0 && tmp < arr[j - 1]; j--) {
            arr[j] = arr[j - 1];
        }
        arr[j] = tmp ;
    }
}


int main() {


    int n = 100000;

    int *arr = SortTestHelper::generateNearlyOrderArray(n, 20);

    int * arr2 =  SortTestHelper::copyIntArray(arr,n);



    SortTestHelper::testSort("Insert Sort", insertSort, arr, n);
    SortTestHelper::testSort("Section Sort",selectSort,arr2,n);



    delete[]   arr;
    delete []   arr2;

    cout << "Hello, World!" << endl;
    return 0;
}