#include <iostream>
#include <algorithm>
using namespace std;

template <typename T>
class Tree
{
private:
    struct Node
    {
        T data;
        Node* firstChild;  // 指向第一个子节点
        Node* nextSibling; // 指向下一个兄弟节点

        Node(const T& val) : data(val), firstChild(nullptr), nextSibling(nullptr) {}
    };

    Node* root; // 树的根节点

    void clear(Node* node)
    {
        if (!node)
            return;
        clear(node->firstChild);
        clear(node->nextSibling);
        delete node;
    }

    int getHeight(Node* node) const
    {
        if (!node)
            return 0;
        int height = 0;
        Node* child = node->firstChild;
        while (child)
        {
            height = max(height, getHeight(child));
            child = child->nextSibling;
        }
        return height + 1;
    }

    // 递归遍历所有节点计算最大度数
    void getDu(Node* node, int& maxdu) const
    {
        if (node == NULL)
            return;
        int du = 0;
        Node* child = node->firstChild;
        while (child != NULL)
        {
            du++;
            child = child->nextSibling;
        }
        maxdu = max(maxdu, du);
        getDu(node->firstChild, maxdu);
        getDu(node->nextSibling, maxdu);
    }

public:
    // 构造函数
    Tree() : root(nullptr) {}
    explicit Tree(const T& rootData) : root(new Node(rootData)) {}

    // 析构函数
    ~Tree()
    {
        clear(root);
    }

    // 禁止拷贝构造和赋值
    Tree(const Tree&) = delete;
    Tree& operator=(const Tree&) = delete;

    // 获取根节点指针（常量版本和非常量版本）
    Node* getRoot() { return root; }
    const Node* getRoot() const { return root; }

    // 插入子节点到指定父节点的子节点列表末尾
    Node* insertNode(Node* parent, const T& data)
    {
        if (!parent)
            return nullptr;

        Node* newNode = new Node(data);
        if (!parent->firstChild)
        {
            parent->firstChild = newNode;
        }
        else
        {
            // 找到最后一个兄弟节点
            Node* lastSibling = parent->firstChild;
            while (lastSibling->nextSibling)
            {
                lastSibling = lastSibling->nextSibling;
            }
            lastSibling->nextSibling = newNode;
        }
        return newNode;
    }

    // 计算树的高度
    int height() const
    {
        return getHeight(root);
    }

    // 计算树的度（所有节点中度最大的值）
    int degree() const
    {
        int maxDegree = 0;
        getDu(root, maxDegree);
        return maxDegree;
    }
};

int main()
{

    Tree<int> a(1);
    auto* root = a.getRoot();
    auto* cha1 = a.insertNode(root, 2);
    auto* cha2 = a.insertNode(root, 3);
    auto* cha3 = a.insertNode(root, 4);
    auto* cha4 = a.insertNode(cha2, 5);
    auto* cha5 = a.insertNode(cha2, 6);
    a.insertNode(cha5, 7);
    a.insertNode(cha5, 8);
    a.insertNode(cha5, 9);

    cout << "树的高度为： " << a.height() << endl;
    cout << "树的度为： " << a.degree() << endl;

    return 0;
}
