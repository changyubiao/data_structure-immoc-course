# 二叉搜索树

二叉搜索树  Binary Search Tree  是一种特殊的二叉树，又叫 二叉查找树，二叉排序树。


定义：  
1.要么二叉查找树 是一颗空树  
2.要么二叉查找树是由根节点，左子树，右子树组成， 其中 左子树 和右子树都是二叉查找树，且左子树上所有结点的数据域 都要 小于等于根结点的数据域，右子树所有结点的的数据域都要大于根结点的数据域。


从定义可以看出，二叉查找树 是一颗数据域有序的二叉树
并且 是一个二叉树 。 但不一定是一颗 完全二叉树。 



##结构定义 

![bst01](./images/bst-01.png)




## 接口说明 

1. size() 获取当前二叉树的大小 
2. isEmpty() 判断是否为空树
3. insert(Key key,Value value)  
4. contain(key) # todo 
5. search(key) # todo 

6. inOrder() 中序遍历二叉搜索树
7. preOrder() 前序遍历二叉搜索树
8. postOrder() 后序遍历二叉搜索树
9. destroy() 方法实现 
10. levelOrder() 层序遍历二叉搜索树 
11. maximum()  寻找二分搜索树的最大的键值
12. minimum()  寻找二分搜索树的最小的键值
13. removeMin()  删除 二分搜索树中 最小的结点 
14. removeMax()  删除 二分搜索树中 最大的结点 


---

### 05-06详解 levelOrder

二叉搜索树 层序遍历，需要 借助 队列。

思路分析 ： 

1. 首先 先把 root 放进队列里面， 
2. 只要队列不为空，获取队列队首元素，进行访问访问，然后出队列 ， 然后看 有没有左孩子，如果有 进入队列 。 之后 再看 有没有 右孩子，如果有 放入队列中 。
3. 循环第二步 ，判断队列有没有空，没有空的话，继续第二步操作。


代码 如下
```c++
 /* 层序遍历 二叉搜索树 */
    void levelOrder() {
        //注意  不加空值检查 会有问题
        queue<Node *> q;

        if (root != nullptr) {
            q.push(root);
        } else {
            return;
        }
        while (!q.empty()) {
            Node *front = q.front();
            cout << "node <key,value> = " << "<" << front->key << "," << front->key << ">" << endl;
            // 删除 队列 首部元素
            q.pop();

            if (front->left) {
                q.push(front->left);
            }

            if (front->right) {
                q.push(front->right);
            }
        }
    }

```
 
 图片演示 如何通过这样 可以实现 
 
![img-bst-06-02](./images/bst-06-02.PNG)
![img-bst-06-02](./images/bst-06-03.PNG)
![img-bst-06-02](./images/bst-06-04.PNG)
![img-bst-06-02](./images/bst-06-05.PNG)
![img-bst-06-02](./images/bst-06-06.PNG)
![img-bst-06-02](./images/bst-06-07.PNG)
![img-bst-06-02](./images/bst-06-08.PNG)
![img-bst-06-02](./images/bst-06-09.PNG)
![img-bst-06-02](./images/bst-06-10.PNG)
![img-bst-06-02](./images/bst-06-11.PNG)



### 05-07 寻找二叉搜索树 最大的key，最小的key

![img07-01](./images/bs-07-1.PNG)

如何找到 最大的结点呢？  
如果一个二叉搜索树，如下图，那么最大值，最小值必须在图中 的位置 
![img07-02](./images/bs-07-2.PNG)

最小值 一定在 最左面的位置 
![img07-04](./images/bs-07-4.PNG)


最大值 一定在 最右面的位置 
![img07-05](./images/bs-07-5.png)



**代码实现**  
有两种方式 一种是 递归的方式，一种非递归的方式。


寻找最小值  
递归写法 
```c++
    /*
     * 返回 以node 为根结点 二叉搜索树 的最小结点
     *
     * 递归写法
     * */
    Node *minimum(Node *node) {

        if (node->left == nullptr) {
            return node;
        }
        return minimum(node->left);

    }
```

非递归写法 

```c++
    /*
      * 返回 以node 为根结点 二叉搜索树 的最小结点
      *
      * 非递归实现
      * */
    Node * minimum2(Node *node){
        while (node->left) {
            node  = node->left;
        }
        return node;
    }

```

寻找最大值 类似  
完整代码 见 [main.py->maximum ](main.cpp)


### 05-08 删除二叉搜索树 最大的结点，最小的结点 

如何删除 最小值的结点呢？ 

图[08-1]
![bst-08-1](./images/bst-08-1.PNG)

最小值的结点没有左右子树，直接删除 这样的话，肯定 还是二叉搜索树
![bst-08-2](./images/bst-08-2.PNG)

最小值结点有 右子树 ,首先 获取右子树，然后删除最小值，最后 把右子树放到 最小值的位置  
![bst-08-3](./images/bst-08-3.PNG)

![bst-08-4](./images/bst-08-4.PNG)


以删除最小结点为例 
代码示例：
```c++
    /*
     删除掉以node为根的二分搜索树中的最小节点
     返回删除节点后新的二分搜索树的根
     * */
    Node *removeMin(Node *node) {
        if (node->left == nullptr) {
            Node *rightNode = node->right;
            // 释放node 结点
            delete node;
            count--;
            // 返回新的根
            return rightNode;
        }
        node->left = removeMin(node->left);
        return node;
    }
```
上面的图示的两种情况，可以写成一种情况 ， 如果 当前的结点 没有左孩子，那说明已经找到了 最小值
这个时候 只要 先把 这个结点的 右子树 先保存好，防止 删除的时候 丢掉 右子树 ，
删除后 直接把 右子树的 指针 直接返回 。 
 
如果 没有找到 最小值 继续 左子树上 删除 左子树的最小值
并且把删除后返回的结点 交给 node 的左孩子 。最后 返回 node  即 二叉搜索树的根 即可。 

如果 右子树 没有的话，那么 返回的结点 就是空指针，也没有任何影响。

删除最大值是类似的逻辑



删除最大结点代码
```c++
    /*
       删除掉以node为根的二分搜索树中的最大节点
       返回删除节点后新的二分搜索树的根
       采用递归的方法
    */
    Node *removeMax(Node *node) {

        if (node->right == nullptr) {
            Node *leftNode = node->left;
            delete node;
            count--;
            return leftNode;
        }
        node->right = removeMax(node->right);
        return node;
    }
```



完整代码  [main.py->removeMin](main.cpp)