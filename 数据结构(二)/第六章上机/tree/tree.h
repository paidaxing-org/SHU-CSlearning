#pragma once
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

template <class T>
struct TreeNode {
    T data;
    TreeNode<T>* child;
    TreeNode<T>* sibling;
    TreeNode(T val) : data(val), child(NULL), sibling(NULL) {}
};

template <class T>
class Tree {
private:
    TreeNode<T>* root;

    TreeNode<T>* buildTree(const string& pre, int preStart, int preEnd,
        const string& in, int inStart, int inEnd) 
    {
        if (preStart > preEnd || inStart > inEnd)
        {
            return nullptr;
        }
        int rootP, lSize;
        TreeNode<T>* root = new TreeNode<T>(pre[preStart]);
        rootP = in.find(pre[preStart]);
        lSize = rootP - inStart;
        root->child = buildTree(pre, preStart + 1, preStart + lSize,
            in, inStart, rootP - 1);
        root->sibling = buildTree(pre, preStart + lSize + 1, preEnd,
            in, rootP + 1, inEnd);
        return root;
    }

    int getHeight(TreeNode<T>* node) {
        if (!node) return 0;
        int maxHeight = 0;
        for (TreeNode<T>* c = node->child; c; c = c->sibling)
            maxHeight = max(maxHeight, getHeight(c));
        return 1 + maxHeight;
    }

    int countChildren(TreeNode<T>* node) {
        int count = 0;
        for (TreeNode<T>* c = node->child; c; c = c->sibling) count++;
        return count;
    }

    int getDegree(TreeNode<T>* node) {
        if (!node) return 0;
        int maxDegree = countChildren(node);
        for (TreeNode<T>* c = node->child; c; c = c->sibling)
            maxDegree = max(maxDegree, getDegree(c));
        return maxDegree;
    }

public:
    Tree() : root(nullptr) {}

    void build(const string& pre, const string& in) {
        root = buildTree(pre, 0, pre.size() - 1, in, 0, in.size() - 1);
    }

    int height() {
        return getHeight(root);
    }

    int degree() {
        return getDegree(root);
    }

    void preOrder(TreeNode<T>* a) 
    {
        if (a!=NULL) {
            cout << a->data << " ";
            preOrder(a->child);
            preOrder(a->sibling);
        }
    }

    TreeNode<T>* getRoot()
    {
        return root;
    }
};
