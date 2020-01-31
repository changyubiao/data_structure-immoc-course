#include <iostream>

#include <algorithm>
#include <string>
#include <ctime>
#include <cmath>
#include <cassert>
using namespace std;


template<typename Item>
class MaxHeap {


private:
    Item *data;  // 定义一个数组存放堆，从下标 1 开始
    int count;  // 记录当前堆的元素的个数

public:

    // 构造函数, 构造一个空堆, 可容纳capacity个元素
     explicit MaxHeap(int capacity) {

        data = new Item[capacity];
        count = 0;

    }

    ~MaxHeap() {

        delete[]  data;

    }


    // 返回堆中的元素个数
    int size() {

        return count;
    }

    bool isEmpty() {

        return count == 0;
    }


};

int main() {
    std::cout << "Hello, World!" << std::endl;

//    MaxHeap(int)<>
    MaxHeap<int> maxheap = MaxHeap<int>(10);

    cout << "size = " << maxheap.size() << endl;

    return 0;
}
