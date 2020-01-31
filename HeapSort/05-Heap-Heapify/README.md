# heap sort 两种实现

1.第一种实现 

第一种方式，每次生成一个空的堆，一个个进入堆中，然后在取出放入到数组中 。
直接构造一个空的堆， 第一个位置是不用的。
```c++
    explicit MaxHeap(int capacity) {

        data = new Item[capacity + 1];
        count = 0;
        this->capacity = capacity;
        // 0号位置不使用
        data[0] = 0;

    }
```

2.第二种实现 
第二种方式 直接传入一个数组生成一个堆，然后取出堆顶元素 放入到数组中。


下面是堆的构造函数，注意从 第一个非叶子结点开始，依次执行 shiftDown 操作 就可以调整一个 大顶堆了。
```c++
    MaxHeap(Item arr[], int n) {

        data = new Item[n + 1];
        capacity = n;
        // 赋值操作
        for (int i = 0; i < n; i++) {
            // 注意有一个偏移
            data[i + 1] = arr[i];
        }
        count = n;

        for (int i = count / 2; i >= 1; i--) {
            shiftDown(i);
        }

    }

```

有了两种方式 就可以 直接构造了一个最大堆，之后调用pop 方法 ，就可以获得一个最大值，取完后就完成了排序。


下面 是两种方式的实现 

```c++
template <typename T>
void heapSort1(T arr[], int len){

    MaxHeap<T> maxHeap = MaxHeap<T>(len) ;

    for (int i =0;i<len;i++){
        maxHeap.push(arr[i]);
    }

    for (int i=len-1;i>=0;i--){
        arr[i] = maxHeap.pop();
    }
}
```


```c++
template <typename T>
void heapSort2(T arr[], int len){

    MaxHeap<T> maxHeap = MaxHeap<T>(arr,len);

    for (int i=len-1;i>=0;i--){
        arr[i] = maxHeap.pop();
    }
}
```


  比较 两种 堆排序  
  1 初始化的时候 ，就把堆 建立好.  
  2 一个一个插入 ，就把堆 建立好
 
 
 时间复杂度 
    一个一个插入的时间复杂度 是 O(nlogn)  
    heapify 的过程，算法时间复杂度 O(n)



随机生成一组1000000数组，进行测试 
总体感觉还是建 堆的时候 一次建好 heapify 比较节约时间，尤其当数据量大的时候 ,第二种就比较快点 。也就快0.1 到0.2 s 这个其实人还是无法感知的。

测试结果如下： 
 
sort_type |size       | time  
---      |---         | ---    
heapsort1 | 1000000| 0.401
heapsort2| 1000000| 0.377


sort_type |size       | time  
---      |---         | ---    
heapsort1 | 1000000|  0.538
heapsort2| 1000000| 0.376


 
sort_type |size       | time  
---      |---         | ---    
heapsort1 | 1000000|  0.41
heapsort2| 1000000| 0.382