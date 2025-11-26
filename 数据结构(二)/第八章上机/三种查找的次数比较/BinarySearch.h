#pragma once
#include <iostream>
using namespace std;

void Binarysearch1(int a[],int num,int size)
{
	int countnum = 0;
	int l = 0, r = size - 1, mid;
	bool flag = 0;
	while (l <= r)
	{
		mid = (l + r) / 2;
		if (a[mid] == num)
		{
			countnum++;
			flag = 1;
			break;
		}
		else if (a[mid] < num)
		{
			countnum++;
			l = mid + 1;
		}
		else
		{
			countnum++;
			r = mid - 1;
		}
	}
	if (flag == 1)
	{
		cout << "查找成功！元素 " << num << " 位于原数组下标为 " << mid << " 的地方" << endl;
		cout << "查找次数为：" << countnum << endl;
	}
	else
	{
		cout << "查找失败！元素 " << num << " 位于数组下标为 " << r << " 与下标为 "<<l<<" 的元素的中间"<< endl;
		cout << "即在 " << a[r] << " 与 " << a[l] << "之间" << endl;
		cout << "查找次数为：" << countnum << endl;
	}
	return;
}