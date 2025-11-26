#include "ufsets.h"
#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	cout << "--------------------*普通合并测试：*--------------------"<<endl;
	int a[12] = { 0,1,2,3,4,5,6,7,8,9.10,11 };
	int b[12] = { 0,1,2,3,4,5,6,7,8,9,10,11 };
	UFsets<int> k1(a, 12);
	UFsets<int> k2(b, 12);
	//cout << "4的下标为：" << k.Find(4) << endl;
	k1.Union(3, 4);
	k1.Union(5, 6);
	k1.Union(7, 8);
	k1.Union(7, 9);
	k1.Union(5, 7);
	//k1.Union(10,11);/*
	//k1.Union(4, 10);*/
	k1.Union(5, 3);
	int s = 0;
	for (int i = 0; i < 12; i++)
	{
		s++;
		if(s<2)
			cout<<"i="<<i<<" 下标为： "<< k1.Find(i) <<"   ";
		else
		{
			s = s % 2;
			cout << "i=" << i << " 下标为： " << k1.Find(i) << endl;
		}
	}

	system("pause");
	cout << "-------------------*高度优先合并测试*-------------------"<<endl;

	int s2 = 1;
	while (1) {
		cout << "********************************************" << endl;
		cout << "*************  0.退出          *************" << endl;
		cout << "*************  1.合并          *************" << endl;
		cout << "*************  2.查询根结点    *************" << endl;
		cout << "*************  3.查询父结点    *************" << endl;
		cout << "********************************************" << endl;
		cout << endl;
		int choice;
		cout << "请输入你的选择([0],[1],[2],[3])" << endl;
		cin >> choice;
		switch (choice)
		{
		case 0:
			cout << "感谢你的使用，再见~" << endl;
			return 0;
		case 1:
			system("cls");
			int a, b;
			cout << "**请输入想要合并的两个元素a、b：**********" << endl;
			cin >> a >> b;
			k2.HeightPriUnion(a, b);
			system("cls");
			cout << "合并成功" << endl;
			break;
		case 2:
			system("cls");
			for (int i = 0; i < 12; i++)
			{
				cout << std::setw(15) << "i=" << i << " 所在并查集根结点的下标为： " << k2.Find(i) << "   ";
				if (s2 % 2 == 0)
				{
					cout << endl;
					s2 = 0;
				}
				s2++;
			}
			cout << endl;
			system("pause");
			system("cls");
			break;
		case 3:
			system("cls");
			s2 = 1;
			for (int i = 0; i < 12; i++)
			{
				cout << std::setw(20) << "i=" << i << " 的父结点下标为：" << k2.getParent(i) << " ";
				if (s2 % 2 == 0)
				{
					cout << endl;
					s2 = 0;
				}
				s2++;
			}
			system("pause");
			system("cls");
			break;
		}
		/*k2.HeightPriUnion(3, 4);
		k2.HeightPriUnion(5, 6);
		k2.HeightPriUnion(7, 8);
		k2.HeightPriUnion(7, 9);
		k2.HeightPriUnion(5, 7);
		k2.HeightPriUnion(2, 11);
		k2.HeightPriUnion(2, 10);
		k2.HeightPriUnion(4, 10);
		k2.HeightPriUnion(5, 3);*/
	}
	system("pause");
	return 0;
}