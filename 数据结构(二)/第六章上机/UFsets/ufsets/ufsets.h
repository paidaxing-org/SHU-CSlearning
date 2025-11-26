#pragma once
#include <iostream>
#include <algorithm>
using namespace std;

template <class T>
struct Node {
	T data;                                         //数值域，记录当前结点的数值
	int parent;                                     //双亲域，用于记录与当前结点的在一个集合中的“父结点”的下标
};


template <class T>
class UFsets {
protected:
	Node<T>* p;	                                    // 存储结点的双亲
	int maxsize;					                // 结点个数

public:
	// 并查集的函数成员:
	UFsets(T a[], int num);	                        // 构造n个孤立等价类，每个等价类双亲域为-1
	//virtual ~UFsets();				            // 析构函数
	T GetElem(int x)const;                          // 根据指定下标取元素值
	int GetOrder(T elem)const;                      // 取指定元素在数组中的下标 
	void Union(T a, T b);	                        // 合并a与b所在的等价类(每次将下标靠左的作为父结点)
	void HeightPriUnion(T a, T b);                  // 高度优先合并（合并时将高度高的作为根）
	int getHeight(T a);                             // 获取元素a所在的集合的高度
	//void WeightedUnion(T a, T b);	                // 根据结点多少合并a与b所在的等价类
	bool Differ(T a, T b);                          // 判断元素a、b是否在同一个等价类
	UFsets(const UFsets& copy);		                // 复制构造函数
	UFsets& operator =(const UFsets& copy);	        // 赋值运算符
	int Find(T elem) const;		                    // 查找元素e所在等价类的根
	int getParent(T a);                             // 查找元素a的父结点

};

template <class T>
UFsets<T>::UFsets(T a[], int num) {             
	maxsize = num;
	p = new Node<T>[maxsize];
	for (int i = 0; i < maxsize; i++)
	{
		p[i].data = a[i];
		p[i].parent = -1;
	}
}

template <class T>
T UFsets<T>::GetElem(int x) const {

	return p[x].data;

}

template <class T>
int UFsets<T>::GetOrder(T elem) const {
	int s = 0;
	while (s < maxsize && p[s].data != elem)
		s++;
	if (s >= maxsize)
		return -1;
	return s;
}

template <class T>
int UFsets<T>::Find(T elem) const {
	int xiabiao = GetOrder(elem);
	if (xiabiao == -1)                                //说明没找到elem这个元素
		return -1;
	while (p[xiabiao].parent > 0)                     //如果parent域为正，那么就继续访问parent域为下标的parent，直到parent为负数，说明找到了根
		xiabiao = p[xiabiao].parent;
	return xiabiao;
}

template <class T>
bool UFsets<T>::Differ(T a, T b) {
	if (Find(a) == Find(b))                           //两个元素根一样，则可以说明两者在一个集合中
		return 1;
	return 0;
}

template <class T>
UFsets<T>::UFsets(const UFsets& copy) {
	this->maxsize = copy.maxsize;
	p = new Node<T>[maxsize];
	for (int i = 0; i < maxsize; i++)
	{
		p[i].data = copy.p[i].data;
		p[i].parent = copy.p[i].parent;
	}
}

template <class T>
UFsets<T>& UFsets<T>::operator=(const UFsets<T>& copy)
{
	this->maxsize = copy.maxsize;
	delete[]p;
	p = new Node<T>[maxsize];
	for (int i = 0; i < maxsize; i++)
	{
		p[i].data = copy.p[i].data;
		p[i].parent = copy.p[i].parent;
	}
	return *this;
}

template <class T>
void UFsets<T>::Union(T a, T b)
{
	int aRoot = Find(a), bRoot = Find(b);
	if (aRoot == bRoot) return;
	if (p[aRoot].parent > p[bRoot].parent) { 
		p[aRoot].parent += p[bRoot].parent;
		p[bRoot].parent = aRoot;
	}
	else {
		p[bRoot].parent += p[aRoot].parent;
		p[aRoot].parent = bRoot;
	}
	/*int aPos = GetOrder(a);
	int bPos = GetOrder(b);
	if (aPos < bPos)
	{
		if(p[aPos].parent<0)
			p[aPos].parent += p[bPos].parent;
		p[bPos].parent = aPos;
	}
	else if(aPos > bPos)
	{
		if (p[bPos].parent < 0)
			p[bPos].parent += p[aPos].parent;
		p[aPos].parent = bPos;
	}*/
}

template <class T>
int UFsets<T>::getHeight(T a)
{
	int aPos = GetOrder(a),height=1;
	while (p[aPos].parent > 0 && aPos >= 0 && aPos < maxsize)
	{
		height++;
		aPos = p[aPos].parent;
	}
	return height;
}


template <class T>
void UFsets<T>::HeightPriUnion(T a, T b)
{
	int aRoot, bRoot, aHeight, bHeight;
	aRoot = Find(a);
	bRoot = Find(b);
	if (aRoot == bRoot) return; 
	aHeight = -p[aRoot].parent;
	bHeight = -p[bRoot].parent;
	if (aHeight > bHeight) 
	{
		p[bRoot].parent = aRoot; 
	}
	else if (aHeight < bHeight) 
	{
		p[aRoot].parent = bRoot;
	}
	else 
	{
		p[bRoot].parent = aRoot;
		p[aRoot].parent = -(aHeight + 1);
	}
}
/*int aHeight, bHeight, aZuxian, bZuxian;
	aHeight = getHeight(a);
	bHeight = getHeight(b);
	aZuxian = Find(a);
	bZuxian = Find(b);
	if (aHeight >= bHeight)
	{
		if (p[aZuxian].parent < 0)
			p[aZuxian].parent += p[bZuxian].parent;
		p[bZuxian].parent = aZuxian;
	}
	else
	{
		if (p[bZuxian].parent < 0)
			p[bZuxian].parent += p[aZuxian].parent;
		p[aZuxian].parent = bZuxian;
	}*/
template<class T>
int UFsets<T>::getParent(T a)
{
	int aPos = GetOrder(a);
	return p[aPos].parent;
}