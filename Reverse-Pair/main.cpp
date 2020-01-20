#include <iostream>

using namespace std;


template<typename T>
int getReversePair(T arr[], int n) {
    /*
     * 获取数组的逆序对 数量
     * 暴力解法
     * */

    int i, j = 0;

    int count = 0;
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[i]) {
                count++;
            }
        }
    }

    return count;


}


int main() {
    cout << "Hello, World!" << std::endl;

    int arr[6] = {1, 3, 2, 5, 7, 9};


    int num = getReversePair(arr, 6);
    cout << "num: " << num << endl;


    return 0;
}
