#include <iostream>

#include <algorithm>
#include <string>

using namespace std;


template<typename Item>
class MaxHeap {


private:
    Item *data;  // 定义一个数组存放堆，从下标 1 开始
    int count;  // 记录当前堆的元素的个数

public:

    // 构造函数, 构造一个空堆, 可容纳capacity个元素
    explicit MaxHeap(int capacity) {
        // 这里预留一个空间 数组小标为0 的暂时不用
        data = new Item[capacity + 1];
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
    MaxHeap<int> maxHeap = MaxHeap<int>(10);

    cout << "size = " << maxHeap.size() << endl;

    return 0;
}
