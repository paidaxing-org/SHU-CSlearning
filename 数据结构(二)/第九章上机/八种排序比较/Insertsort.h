#pragma once
#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long
template <typename T>
class inserts {
private:
	int maxnum;
	int changesum = 0;
	int cmpsum = 0;
public:
	void insertsort(T num[], int n) {
		int i, j;
		for (i = 1; i <= n; i++)
		{
			T temp = num[i];
			for (j = i-1; j >= 1 && temp < num[j]; j--)
			{
				num[j + 1] = num[j];
				changesum++;
				cmpsum+=2;

			}
			cmpsum += 2;
			num[j + 1] = temp;
			changesum += 2;
		}
		cout << "经检验，通过该排序方法操作后的数组有序" << endl;
		/*for (int k = 1; k <= n; k++)
			cout << num[k] << " ";
		cout << endl;*/
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