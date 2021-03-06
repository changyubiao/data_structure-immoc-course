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
    int capacity; // 记录堆的最大容量， 这里的堆是不可扩展的堆，初始化后 最大容量就已经确定了。



public:
    // 构造函数, 构造一个空堆, 可容纳capacity个元素
    explicit MaxHeap(int capacity) {

        data = new Item[capacity + 1];
        count = 0;
        this->capacity = capacity;
        data[0] = 0;

    }

    // 析构函数
    ~MaxHeap() {

        delete[]  data;
    }



private:

    /* 将索引为k 的 数组，调整成一个 大顶堆的操作。
     * */
    void shiftUp(int k) {
        /*
         * parent 索引：   k/2
         * current 索引 ：  k
         * 循环条件k 值 大于1 即可 且   当前 的索引位置元素 小于 父亲结点的元素
         * ，就交换两个值，
         * 同时 更新 k  的值 变成 父亲的索引
         *
         * */

        while (k >= 2 && data[k / 2] < data[k]) {

            swap(data[k], data[k / 2]);
            k = k / 2;
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
        cout << "data[0]: "<<data[0]<<endl;
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

    // 插入一个元素
    void push(Item item) {

        // 防止插入太多的元素 ，越界了。
        assert(count + 1 <= capacity);
        // 从小标 为1 的位置 ，开始放入元素
        data[count + 1] = item;
        shiftUp(count + 1);
        // 注意在这里维护 count 的值 自增1
        count++;

    }


    // 返回堆中的元素个数
    int size() {
        return count;
    }

    bool isEmpty() {

        return count == 0;
    }


    void printArray() {

        for (int i = 1; i <= this->size(); i++) {
            cout << data[i] << " ";
        }
        cout << endl;
    }

};

int main() {
    srand(time(NULL));
    MaxHeap<int> maxHeap = MaxHeap<int>(50);

    for (int i = 1; i <= 10; i++) {
        maxHeap.push(rand() % 100);
    }

    maxHeap.printHeap();

    return 0;
}


