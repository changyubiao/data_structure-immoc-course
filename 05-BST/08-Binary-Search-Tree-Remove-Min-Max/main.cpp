#include <iostream>
#include <ctime>
#include <cassert>
#include <queue>

using namespace std;

template<typename Key, typename Value>
class BST {
private:
    struct Node {
        // 树中的节点为私有的结构体, 外界不需要了解二分搜索树节点的具体实现
        Key key;  // 要比较的key
        Value value; // key对应的value
        Node *left;  // 左孩子指针
        Node *right; // 右孩子指针

        Node(Key key, Value value) {
            this->key = key;
            this->value = value;

            this->left = nullptr;
            this->right = nullptr;
        }

    };

    int count; // 记录当前 二叉查找树的大小
    Node *root;  // 根结点 指针

public:
    BST() {

        count = 0;
        root = nullptr;
    }


    ~BST() {
        // 析构函数

        destroy(root);
    }


    bool isEmpty() {

        return count == 0;
    }

    int size() {
        return count;

    }

public:
    // 清空 所有 结点
    void clean() {

        destroy(root);

    }


    // 寻找二分搜索树的最小的键值
    Key minimum() {
        // 返回 二叉搜索树 中  最小的键值
        assert(count > 0);
        Node *node = minimum(root);
        return node->key;
    }


    // 寻找二分搜索树的最大的键值
    Key maximum() {
        assert(count > 0);

        Node *node = maximum(root);
        return node->key;
    }


    void insert(Key key, Value value) {

        root = insert(root, key, value);

    }


    bool contain(Key key) {
        // 判断二叉查找树中 是否包含 键值为key 的 元素，返回布尔值
        return contain(root, key);
    }

    Value *search(Key key) {

        search(root, key);

    }


    /* 中序 遍历二叉搜索树
     * */
    void inOrder() {

        inOrder(root);
    }

    /* 前序 遍历二叉搜索树
     * */
    void preOrder() {

        preOrder(root);
    }


    /*
     * 后序 遍历二叉搜索树
     */
    void postOrder() {

        postOrder(root);
    }


    /* 层序遍历 二叉搜索树 */
    void levelOrder() {
        queue<Node *> q;

        if (root != nullptr) {
            q.push(root);
        } else {
            return;
        }
        while (!q.empty()) {
            Node *now = q.front();
            cout << "node <key,value> = " << "<" << now->key << "," << now->key << ">" << endl;
            // 删除 队列 首部元素
            q.pop();

            if (now->left) {
                q.push(now->left);
            }
            if (now->right) {
                q.push(now->right);
            }
        }
    }


public:
    // delete  operation

    void removeMin() {
        if (root) {
            root = removeMin(root);
        }
    }

    void removeMax() {
        if (root) {
            root = removeMax(root);
        }

    }


private:
    // 向以node为根的二叉查找树 中, 插入节点(key, value), 使用递归算法
    // 返回 插入新结点点的二叉查找树的根
    /*
     * 递归知识点补充 ：
     *
     * 递归 要有两个  1  base  case  基线条件
     *               2  recursive  case  递归条件·
     *    每个递归函数都有两部分：基线条件（ base case）和递归条件（ recursive case） 。
     *    递归条件指的是函数调用自己，
     *    而基线条件则指的是函数不再调用自己，从而避免形成无限循环
     * */
    Node *insert(Node *node, Key key, Value value) {


        if (node == nullptr) {
            count++;
            return new Node(key, value);
        }

        if (key == node->key) {
            // 替换 value
            node->value = value;
        } else if (key < node->key) {
            //  key < node->key  插入 左子树
            node->left = insert(node->left, key, value);
        } else {
            //  key > node->key 插入 右子树
            node->right = insert(node->right, key, value);
        }

        return node;
    }


    /*
     *  向以node为根的二叉查找树 中,判断 节点为key,是否在 二叉查找树中，使用递归算法
        返回 布尔值
     * */
    bool contain(Node *node, Key key) {
        // 基线条件
        if (node == nullptr) {
            return false;
        }

        // 递归条件
        if (node->key == key) {
            return true;
        } else if (node->key < key) {
            return contain(node->left, key);
        } else {
            return contain(node->right, key);
        }
    }


    /*
     * 向以node为根的二叉查找树 中,判断 节点为key, 是否在 二叉查找树，
     *
     * 如果 在 二叉查找树种，返回 key 对应 value 的指针 ，如果不在 直接返回NULL;
     * */
    Value *search(Node *node, Key key) {

        if (node == nullptr) {
            return nullptr;
        }

        if (node->key == key) {
            // 找到了，直接返回value的地址
            return &(node->value);
        } else if (node->key < key) {
            // 在左子树 寻找 key
            return search(node->left, key);
        } else {
            // 在右子树 寻找 key
            return search(node->right, key);
        }
    }


    /*
      * 向以node为根的二叉查找树中,中序遍历二叉搜索树
      *
      * */
    void inOrder(Node *node) {

        if (node != nullptr) {
            inOrder(node->left);
            cout << "node <key,value> = " << "<" << node->key << "," << node->value << ">" << endl;
            inOrder(node->right);
        }

    }


    /*
  * 向以node为根的二叉查找树中,前序遍历二叉搜索树
  *
  * */
    void preOrder(Node *node) {

        if (node != nullptr) {

            cout << "node <key,value> = " << "<" << node->key << "," << node->value << ">" << endl;
            preOrder(node->left);
            preOrder(node->right);
        }

    }


    /*
   * 向以node为根的二叉查找树中,后序 遍历二叉搜索树
   *
   * */
    void postOrder(Node *node) {

        if (node != nullptr) {

            preOrder(node->left);
            preOrder(node->right);
            cout << "node <key,value> = " << "<" << node->key << "," << node->value << ">" << endl;

        }
    }


    /*
     释放以node为根的二分搜索树的所有节点
     采用后续遍历的递归算法
     * */
    void destroy(Node *node) {

        if (node != nullptr) {
            destroy(node->left);
            destroy(node->right);
            delete node;

            // 注意别忘记了，把count --
            count--;
        }

    }

    /*
     * 层序遍历 二叉搜索树
     * */
    void levelOrder(Node *node) {
        queue<Node *> q;
        if (node != nullptr) {
            q.push(node);
        } else {
            return;
        }
        while (!q.empty()) {
            Node *front = q.front();
            cout << "node <key,value> = " << "<" << front->key << "," << front->key << ">" << endl;

            if (front->left) {
                q.push(front->left);
            }

            if (front->right) {
                q.push(front->right);
            }
            // 删除 队列 首部元素
            q.pop();
        }
    }


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


    /*
  * 返回 以node 为根结点 二叉搜索树 的最大结点
  *
  * 递归写法
  * */
    Node *maximum(Node *node) {

        if (node->right == nullptr) {
            return node;
        }
        return maximum(node->right);
    }

    /*
    // 删除掉以node为根的二分搜索树中的最小节点
    // 返回删除节点后新的二分搜索树的根
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


    /*
      // 删除掉以node为根的二分搜索树中的最大节点
      // 返回删除节点后新的二分搜索树的根
      采用递归的方法
   * */
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
};


int main() {

    srand(time(NULL));
    BST<int, int> bst = BST<int, int>();

    // 取n个取值范围在[0...m)的随机整数放进二分搜索树中
    int n = 100;
    int m = 100;
    for (int i = 0; i < n; i++) {
        int key = rand() % m;
        // 为了后续测试方便,这里value值取和key值一样
        int value = key;
        //cout<<key<<" ";
        bst.insert(key, value);
    }
    // 注意, 由于随机生成的数据有重复, 所以bst中的数据数量大概率是小于n的

    // 测试 removeMin
    // 输出的元素应该是从小到大排列的
    cout << "Test removeMin: " << endl;
    while (!bst.isEmpty()) {
        cout << "min: " << bst.minimum() << " , ";
        bst.removeMin();
        cout << "After removeMin, size = " << bst.size() << endl;
    }
    cout << endl;


    for (int i = 0; i < n; i++) {
        int key = rand() % m;
        // 为了后续测试方便,这里value值取和key值一样
        int value = key;
        //cout<<key<<" ";
        bst.insert(key, value);
    }

    // 测试 removeMax
    // 输出的元素应该是从大到小排列的
    cout << "Test removeMax: " << endl;
    while (!bst.isEmpty()) {
        cout << "max: " << bst.maximum() << " , ";
        bst.removeMax();
        cout << "After removeMax, size = " << bst.size() << endl;
    }
    return 0;
}