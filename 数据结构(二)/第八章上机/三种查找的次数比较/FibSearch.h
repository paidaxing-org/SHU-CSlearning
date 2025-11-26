#pragma once
#include <iostream>
using namespace std;
#define maxn 1000
int fibn[maxn] = { 0 };
int temp[maxn] = { 0 };
void getFib(int size)
{
	fibn[1] = 1;
	fibn[0] = 1;
	for (int i = 2; i < size; i++)
	{
		fibn[i] = fibn[i - 2] + fibn[i - 1];
	}
	
	return;
}

void Fibsearch1(int a[],int num,int size)
{
	int countnum = 0;
	int ans;
	int l = 0, r = size - 1, mid, k = 0;
	bool flag = 0;
	while (r > fibn[k] - 1)
	{
		k++;
	}
	for (int i = 0; i < size; i++)
	{
		temp[i] = a[i];
	}
	for (int i = r + 1; i < fibn[k]; i++)
	{
		temp[i] = a[r];
	}
	while (l <= r)
	{
		mid = l + fibn[k - 1] - 1;
		if (temp[mid] == num)
		{
			countnum++;
			flag = 1;
			if (mid <= r)
				ans = mid;
			else
				ans = r;
			break;

		}
		else if (temp[mid] < num)
		{
			countnum++;
			l = mid + 1;
			k -= 2;
		}
		else
		{
			countnum++;
			r = mid - 1;
			k--;
		}
	}
	if (flag == 1)
	{
		cout << "查找成功！元素 " << num << " 位于原数组下标为 " << ans << " 的地方" << endl;
		cout << "查找次数为：" << countnum << endl;
	}
	else
	{
		cout << "查找失败！元素 " << num << " 位于数组下标为 " << r << " 与下标为 " << l << " 的元素的中间" << endl;
		cout << "即在 " << a[r] << " 与 " << a[l] << "之间" << endl;
		cout << "查找次数为：" << countnum << endl;
	}
	return;

}
