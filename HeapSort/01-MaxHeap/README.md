# 堆的数据结构

## MaxHeap 数据结构定义  

> 第一个是 存放数据的数组，第二是 数据数量用 count 表示

```c++
template<typename Item>
class MaxHeap {


private:
    Item *data;  // 定义一个数组存放堆，从下标 1 开始
    int count;  // 记录当前堆的元素的个数
}
```

## 接口定义 

1.返回堆中的元素个数
size() 这个来获取


2.判断是否为空队列 
isEmpty()

## 代码详见main.cpp 