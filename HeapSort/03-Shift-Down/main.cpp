#include <iostream>

#include <algorithm>
#include <string>
#include <ctime>
#include <cmath>
#include <cassert>

using namespace std;

/*

The max heap size is: 10
data[0]: 0
Data in the max heap: 70 44 51 31 27 41 25 10 18 22

           70
      /          \
     44          51
   /    \      /    \
  31    27    41    25
 / \   / \   / \   / \
10 18 22
current top = 70
pop item = 70
The max heap size is: 9
data[0]: 0
Data in the max heap: 51 44 41 31 27 22 25 10 18

           51
      /          \
     44          41
   /    \      /    \
  31    27    22    25
 / \   / \   / \   / \
10 18
current top = 51


 *
*/
template<typename Item>
class MaxHeap {


private:
    Item *data;  // 定义一个数组存放堆，从下标 1 开始
    int count;  // 记录当前堆的元素的个数
    int capacity; // 记录堆的最大容量， 这里的堆是不可扩展的堆，初始化后 最大容量就已经确定了。



public:
    // 构造函数, 构造一个空堆, 可容纳capacity个元素
    explicit MaxHeap(int capacity) {

        data = new Item[capacity + 1];
        count = 0;
        this->capacity = capacity;
        // 0号位置不使用
        data[0] = 0;

    }

    // 析构函数
    ~MaxHeap() {
        delete[]  data;
    }


private:

    void shiftUp(int k) {
        /*
         * 上移元素把 元素调整成大顶堆 ，尝试调整 k 索引对应的元素，调整成 大顶堆
         * */

        while (k >= 2 && data[k / 2] < data[k]) {

            swap(data[k], data[k / 2]);

            k = k / 2;
        }

    }


    void shiftDown(int k) {
        /*
        * 下移 元素把 元素调整成大顶堆 ，尝试调整 k 索引对应的元素，调整成 大顶堆
        * */

        // 首先要判断有没有做孩子，有左孩子 就说明 还没有到堆的最后一层
        while (2 * k <= count) {

            // 初始化 任务左孩子
            int j = 2 * k;//此轮 循环 是要找到 data[k]节点应该和 j的位置 互换

            if (j + 1 <= count && data[j + 1] > data[j]) {
                j = j + 1;  // 寻找较大的儿子结点
            }

            if (data[j] <= data[k]) {
                // 说明 已经 是大顶堆了，不用继续寻找下去了。
                break;
            }
            swap(data[j], data[k]);
            // 更新k
            k = j;

        }

    }

public:
    // 以树状打印整个堆结构
    void printHeap() {

        // 我们的testPrint只能打印100个元素以内的堆的树状信息
        if (size() >= 100) {
            cout << "This print function can only work for less than 100 int";
            return;
        }

        // 我们的testPrint只能处理整数信息
        if (typeid(Item) != typeid(int)) {
            cout << "This print function can only work for int item";
            return;
        }

        cout << "The max heap size is: " << size() << endl;
        cout << "data[0]: " << data[0] << endl;
        cout << "Data in the max heap: ";
        for (int i = 1; i <= size(); i++) {
            // 我们的testPrint要求堆中的所有整数在[0, 100)的范围内
            assert(data[i] >= 0 && data[i] < 100);
            cout << data[i] << " ";
        }
        cout << endl;
        cout << endl;

        int n = size();
        int max_level = 0;
        int number_per_level = 1;
        while (n > 0) {
            max_level += 1;
            n -= number_per_level;
            number_per_level *= 2;
        }

        int max_level_number = int(pow(2, max_level - 1));
        int cur_tree_max_level_number = max_level_number;
        int index = 1;
        for (int level = 0; level < max_level; level++) {
            string line1 = string(max_level_number * 3 - 1, ' ');

            int cur_level_number = min(count - int(pow(2, level)) + 1, int(pow(2, level)));
            bool isLeft = true;
            for (int index_cur_level = 0; index_cur_level < cur_level_number; index++, index_cur_level++) {
                putNumberInLine(data[index], line1, index_cur_level, cur_tree_max_level_number * 3 - 1, isLeft);
                isLeft = !isLeft;
            }
            cout << line1 << endl;

            if (level == max_level - 1)
                break;

            string line2 = string(max_level_number * 3 - 1, ' ');
            for (int index_cur_level = 0; index_cur_level < cur_level_number; index_cur_level++)
                putBranchInLine(line2, index_cur_level, cur_tree_max_level_number * 3 - 1);
            cout << line2 << endl;

            cur_tree_max_level_number /= 2;
        }
    }

private:
    void putNumberInLine(int num, string &line, int index_cur_level, int cur_tree_width, bool isLeft) {

        int sub_tree_width = (cur_tree_width - 1) / 2;
        int offset = index_cur_level * (cur_tree_width + 1) + sub_tree_width;
        assert(offset + 1 < line.size());
        if (num >= 10) {
            line[offset + 0] = '0' + num / 10;
            line[offset + 1] = '0' + num % 10;
        } else {
            if (isLeft)
                line[offset + 0] = '0' + num;
            else
                line[offset + 1] = '0' + num;
        }
    }

    void putBranchInLine(string &line, int index_cur_level, int cur_tree_width) {

        int sub_tree_width = (cur_tree_width - 1) / 2;
        int sub_sub_tree_width = (sub_tree_width - 1) / 2;
        int offset_left = index_cur_level * (cur_tree_width + 1) + sub_sub_tree_width;
        assert(offset_left + 1 < line.size());
        int offset_right = index_cur_level * (cur_tree_width + 1) + sub_tree_width + 1 + sub_sub_tree_width;
        assert(offset_right < line.size());

        line[offset_left + 1] = '/';
        line[offset_right + 0] = '\\';
    }


public:

/*
 * 判断 是否是heap 主要判断是 是否满足堆的性质
 *  data[i]>=data[2*i];  data[i]>=data[2*i +1 ]
 * */
    bool isHeap() {

        for (int i = 1; 2 * i <= size(); i++) {

            if (data[2 * i] > data[i]) {
                return false;

            }
            if ((2 * i + 1) <= count && data[2 * i + 1] > data[i]) {
                    return false;
            }

        }
        return true;

    }

public:

    // 入堆  插入一个元素
    void push(Item item) {
        // 防止插入太多的元素 ，越界了。
        assert(count + 1 <= capacity);
        // 从小标 为1 的位置 ，开始放入元素
        data[count + 1] = item;
        shiftUp(count + 1);
        count++;

    }

    Item pop() {
        /*
         *   Pop the largest item off the heap, maintaining the heap invariant.
         *   出堆
         *  从最大堆中取出堆顶元素, 即堆中所存储的最大数据
        */

        Item largestItem = data[1];

        swap(data[1], data[count]);
        this->count--;

        shiftDown(1);
        return largestItem;

    }

    Item getTop(){
        /* 获取当前堆的 堆顶元素（max）, 元素 不从堆中取出*/

        Item  top = data[1];

        return top ;


    }


    // 返回堆中的元素个数
    int size() {
        return count;
    }

    bool isEmpty() {

        return count == 0;
    }


};

int main11() {
    std::cout << "Hello, World!" << std::endl;
    srand(time(NULL));
    MaxHeap<int> maxHeap = MaxHeap<int>(50);

    for (int i = 1; i <= 10; i++) {
        maxHeap.push(rand() % 100);
    }

    maxHeap.printHeap();

    return 0;
}

int main() {
    MaxHeap<int> maxHeap = MaxHeap<int>(50);

    int arr [10]= {10,70, 41, 44,22,  51, 25, 18,  31, 27};
    for (int e : arr){
        maxHeap.push(e);

    }
    cout<<endl;

    maxHeap.printHeap();
    assert(maxHeap.isHeap());

    cout<< "current top = "<< maxHeap.getTop()<<endl;
    int item = maxHeap.pop();

    cout << "pop item = " << item << endl;

    maxHeap.printHeap();

    cout<< "current top = "<< maxHeap.getTop()<<endl;

    assert(maxHeap.isHeap());

    return 0;
}
