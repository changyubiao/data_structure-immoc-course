#include <iostream>

using namespace std;

template<typename T>
int lowerBound(T arr[], int n, T target) {
    /*
     * 返回第一个 大于等于 target 的索引
     *
     *  [1,3,3,3,6]  target=3    result  = 1
     *               target 6    result  = 4
     *               target =10  result  = 5
     *              如果 序列中没有target ,那么 假设 result 存在，target 应该在的位置
     *
     *
     * */

    int l, r, mid;

    l = 0;
    r = n;
    while (l < r) {
        mid = l + (r - l) / 2;
        if (arr[mid] >= target) {
            //[0,mid]
            r = mid;
        } else {
            // [mid+1,r]
            l = mid + 1;
        }
    }


    cout << endl;
//    cout << "lowerBound() , l = " << l << ", r = " << r << endl;

    // 此时 l == r  , 返回r 也是可以的。
    return l;
}

template<typename T>
int upperBound(T arr[], int n, T target) {

    /*  arr[]  递增序列 ，, 返回 第一个大于 target  元素的位置
     *
     *
     * */
    int l, r, mid;

    l = 0;
    r = n;

    while (l < r) {

        mid = l + (r - l) / 2;


        if (arr[mid] > target) {
            // [0,mid] 之间 继续寻找
            r = mid;
        } else {
            // target <= mid
            // [mid+1,r]  寻找
            l = mid + 1;
        }

    }
    cout << endl;
//    cout << "upperBound() , l = " << l << ", r = " << r << endl;
    return r;
}


int main() {
    std::cout << "Hello, World!" << std::endl;

    int arr[10] = {1, 2, 3, 3, 3,   3, 4, 5, 8, 9};

    for (int item :arr) {
        cout << item << " ";
    }
    cout << endl;
    int target = 3;

    cout << ">= target: " << lowerBound(arr, 10, target) << endl;

    cout << "> target: " << upperBound(arr, 10, target) << endl;

    return 0;
}
