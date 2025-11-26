#pragma once
#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long
template <typename T>
class maopao {
private:
	int maxnum;
	int changesum = 0;
	int cmpsum = 0;
public:
	void maopaosort(T num[],int n) {
		bool flag = 1;
		int i = 1;
		while (i <= n && flag != 0)
		{
			flag = 0;
			for (int j = 1; j < n; j++)
			{
				if (num[j] > num[j + 1])
				{
					swap(num[j], num[j + 1]);
					changesum += 3;
					flag = 1;
				}
				cmpsum++;
			}
		}
		cout << "经检验，通过该排序方法操作后的数组有序" << endl;
		/*for (int i = 1; i <= n; i++)
			cout << num[i] << " ";
		cout << endl;*/
		/*cout << "比较次数为:" << cmpsum << " 赋值次数为:" << changesum << endl; */
	};
	int getchangesum()
	{
		return changesum;
	};
	int getcmpsum()
	{
		return cmpsum;
	}
};