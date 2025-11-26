#include <iostream>
#include "BST.h"
using namespace std;
    int main() {
        BSTree<int> tree;
        int a[10] = { 31, 15, 9, 5, 4, 7, 8, 50, 42, 2 };
        for (int op : a) tree.Insert(op); 
        tree.Delete(15);
        tree.Delete(99);
        tree.Insert(15);
        tree.Insert(15);

        return 0;
    }
