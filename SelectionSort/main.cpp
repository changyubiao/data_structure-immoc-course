#include <iostream>
#include "SortTestHelper.h"
#include "Student.h"

using namespace std;

// 使用模板的方式
template<typename T>
void selectSort(T arr[], int len) {

    for (int i = 0; i < len; i++) {
        // 寻找[i, n)区间里的最小值
        int minIndex = i;

        for (int j = i + 1; j < len; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }

        }

        if (minIndex != i) {
            swap(arr[i], arr[minIndex]);
        }
    }
}



int main_01() {

    int array[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int len = sizeof(array) / sizeof(*array);

    selectSort(array, len);
    SortTestHelper::printArray(array, len);
    return 0;
}


int main() {

    int n = 1000000;

    int *array = SortTestHelper::generateRandomArray(n, 1, n);

    int len = n;


    SortTestHelper::testSort("Section Sort",selectSort,array,len );


    // 释放内存空间
    delete[]  array;
    return 0;
}


int main_03() {

    int array[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int len = sizeof(array) / sizeof(*array);

    selectSort(array, len);
    printArray(array, len);


    float b[] = {6.5, 5.4, 5.2, 4.3, 3.1, 2.4, 2.1, 1.4};
    len = sizeof(b) / sizeof(*b);

    selectSort(b, len);
    printArray(b, len);


    string c[5] = {"E", "D", "C", "B", "A"};
    len = 5;
    selectSort(c, len);
    printArray(c, len);


    Student s[5] = {{"A", 40},
                    {"B", 30},
                    {"C", 80},
                    {"B", 60},
                    {"F", 60},
    };


    len = 5 ;

    selectSort(s, len);
    printArray(s, len);

    return 0;

}