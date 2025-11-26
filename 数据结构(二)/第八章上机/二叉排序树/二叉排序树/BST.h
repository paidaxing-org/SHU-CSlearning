#pragma once
#include <iostream>
#include <climits> // 添加 climits 头文件
using namespace std;

template <class T>
struct BinTreeNode {
    T data;
    BinTreeNode<T>* leftChild, * rightChild;
    BinTreeNode(T val) : data(val), leftChild(nullptr), rightChild(nullptr) {}
};

template <class T>
class BSTree {
private:
    BinTreeNode<T>* root;
    void Insert(const T& x, BinTreeNode<T>*& p);
    void Delete(BinTreeNode<T>*& p);
    bool IsBSTUtil(BinTreeNode<T>* node, T min_val, T max_val) const; // 参数名调整
public:
    BSTree() : root(nullptr) {}
    void Insert(const T& x) { Insert(x, root); }
    void Delete(const T& x);
    bool IsBST() const;
};

template <class T>
void BSTree<T>::Insert(const T& x, BinTreeNode<T>*& p) {
    if (p == nullptr) {
        p = new BinTreeNode<T>(x);
        cout << "插入成功！元素" << x << "被成功插入" << endl;
    }
    else if (x < p->data) {
        Insert(x, p->leftChild);
    }
    else if (x > p->data) {
        Insert(x, p->rightChild);
    }
    else {
        cout << x << "已存在，故不进行插入操作" << endl;
        return;
    }
}

// 公共删除函数实现
template <class T>
void BSTree<T>::Delete(const T& x) {
    BinTreeNode<T>** op = &root;
    while (*op != nullptr) {
        if (x < (*op)->data) {
            op = &(*op)->leftChild;
        }
        else if (x > (*op)->data) {
            op = &(*op)->rightChild;
        }
        else {
            Delete(*op);
            cout << "删除成功，节点" << x << "被删除" << endl;
            return;
        }
    }
    cout << "删除失败，节点 " << x << " 不存在" << endl;
}

// BST验证逻辑（修复溢出问题）
template <class T>
bool BSTree<T>::IsBST() const {
    return IsBSTUtil(root, numeric_limits<T>::min(), numeric_limits<T>::max());
}

template <class T>
bool BSTree<T>::IsBSTUtil(BinTreeNode<T>* node, T min_val, T max_val) const {
    if (node == nullptr) return true;
    if (node->data <= min_val || node->data >= max_val) return false;
    return IsBSTUtil(node->leftChild, min_val, node->data) &&
        IsBSTUtil(node->rightChild, node->data, max_val);
}

// 内部删除函数（保持原逻辑）
template <class T>
void BSTree<T>::Delete(BinTreeNode<T>*& p) {
    if (p->leftChild == NULL && p->rightChild == NULL) {
        delete p;
        p = NULL;
    }
    else if (p->leftChild == NULL) {
        BinTreeNode<T>* tmp = p;
        p = p->rightChild;
        delete tmp;
    }
    else if (p->rightChild == NULL) {
        BinTreeNode<T>* tmp = p;
        p = p->leftChild;
        delete tmp;
    }
    else {
        BinTreeNode<T>* parent = p;
        BinTreeNode<T>* maxNode = p->leftChild;
        while (maxNode->rightChild != NULL) {
            parent = maxNode;
            maxNode = maxNode->rightChild;
        }
        p->data = maxNode->data;
        if (parent != p) {
            parent->rightChild = maxNode->leftChild;
        }
        else {
            parent->leftChild = maxNode->leftChild;
        }
        delete maxNode;
    }
}