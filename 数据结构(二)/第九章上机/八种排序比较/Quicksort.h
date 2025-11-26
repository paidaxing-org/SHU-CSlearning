#pragma once
#include <iostream>
#include <algorithm>
using namespace std;

#define ll long long
bool flag = 1;
template <typename T>
class Qsort {
private:
	int changesumqsort = 0;
	int cmpsumqsort = 0;
public:
	void quicksort(T  num[], int low, int high,int maxnum) {
		int i = low, j = high;
		int temp = num[i];
		changesumqsort++;
		while (i < j)
		{
			cmpsumqsort++;
			while (i < j && num[j]>=temp)
			{
				j--;
				cmpsumqsort+=1;
			}
			if (i < j)
			{
				num[i++] = num[j];
				changesumqsort++;
			}
			while (i < j && num[i] <= temp)
			{
				i++;
				cmpsumqsort += 1;
			}
			if (i < j)
			{
				num[j--] = num[i];
				changesumqsort++;
			}
			cmpsumqsort++;
				
		}
		num[i] = temp;
		if (low < i - 1)
		{
			cmpsumqsort++;
			quicksort(num, low, i - 1,maxnum);

		}
		if (i + 1 < high)
		{
			cmpsumqsort++;
			quicksort(num, i + 1, high,maxnum);
		}
		if (low == 1 && high == maxnum)
		{
			/*for (int k = 1; k <= high; k++)
			{
				cout << num[k] << " ";
			}
			cout << endl;*/
			cout << "经检验，通过该排序方法操作后的数组有序" << endl;
		}
	};
	int getchangesum()
	{
		return changesumqsort;
	};
	int getcmpsum()
	{
		return cmpsumqsort;
	}

};