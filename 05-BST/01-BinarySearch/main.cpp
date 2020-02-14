#include <iostream>
#include <algorithm>
#include <ctime>
#include <cassert>

using namespace std;


// 二分查找法,在有序数组arr中,查找target
// 如果找到target,返回相应的索引index
// 如果没有找到target,返回-1
template<typename T>
int binarySearch(T arr[], int n, int target) {

    // 在arr[l...r]之中查找target
    int l = 0, r = n-1;


    // 在arr[l,r] 范围内寻找 target
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (arr[mid] == target) {
            return mid;// 找到了
        }

        if (target > arr[mid]) {
            // 在 [mid+1,r] 范围内继续寻找
            l = mid + 1;
        } else {
            //  target < arr[mid]
            //在 [0, mid-1] 范围内继续寻找
            r = mid - 1;
        }
    }

    return -1;
}


// 二分查找法,在有序数组arr中,查找target
// 如果找到target,返回相应的索引index
// 如果没有找到target,返回-1
//  递归实现版本
template<typename T>
int _binarySearch2(T arr[], int l, int r, int target) {

    // 递归基线条件，说明没有找到 直接返回 -1
    if (l > r) {
        return -1;
    }

//    int  mid = (r - l) / 2;
    int mid = l + (r-l)/2;

    if (target == arr[mid]) {
        return mid;
    }else if  (target > arr[mid]) {
        return _binarySearch2(arr, mid + 1, r, target);
    } else {
        return _binarySearch2(arr, l, mid - 1, target);
    }

}


template<typename T>
int binarySearch2(T arr[], int n, int target) {

    return _binarySearch2(arr, 0, n - 1, target);

}


int main01() {
    std::cout << "Hello, World!" << std::endl;
    int arr[] = {1, 2, 4, 26, 34, 55, 87, 92, 98, 99, 101};
//    int t = max({1,2,4,26,34,55,87,92,98,99,101});

//    cout<<"t = "<<t<<endl;
    cout << binarySearch(arr, 11, 5) << endl;
    return 0;
}


// 比较非递归和递归写法的二分查找的效率
// 非递归算法在性能上有微弱优势
int main() {

    int n = 1000000;
    int *a = new int[n];
    for (int i = 0; i < n; i++)
        a[i] = i;

    // 测试非递归二分查找法
    clock_t startTime = clock();

    // 对于我们的待查找数组[0...N)
    // 对[0...N)区间的数值使用二分查找，最终结果应该就是数字本身
    // 对[N...2*N)区间的数值使用二分查找，因为这些数字不在arr中，结果为-1
    for (int i = 0; i < 2 * n; i++) {
        int v = binarySearch(a, n, i);
        if (i < n)
            assert(v == i);
        else
            assert(v == -1);
    }
    clock_t endTime = clock();
    cout << "Binary Search (Without Recursion): " << double(endTime - startTime) / CLOCKS_PER_SEC << " s" << endl;


    // 测试递归的二分查找法
    startTime = clock();

    // 对于我们的待查找数组[0...N)
    // 对[0...N)区间的数值使用二分查找，最终结果应该就是数字本身
    // 对[N...2*N)区间的数值使用二分查找，因为这些数字不在arr中，结果为-1
    for (int i = 0; i < 2 * n; i++) {
        int v = binarySearch2(a, n, i);
        if (i < n)
            assert(v == i);
        else
            assert(v == -1);
    }
    endTime = clock();
    cout << "Binary Search (Recursion): " << double(endTime - startTime) / CLOCKS_PER_SEC << " s" << endl;

    delete[] a;

    return 0;
}