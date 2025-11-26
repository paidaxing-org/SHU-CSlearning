#pragma once
#include <iostream>
using namespace std;

void InsertSearch(int a[], int num, int size)
{
	int countnum = 0;
	int l = 0, r = size - 1, pos;
	bool flag = 0;
	while (l <= r && a[l] <= num && a[r] >= num)
	{
		pos = l+((num-a[l])*(r-l))/(a[r]-a[l]);
		if (a[pos] == num)
		{
			countnum++;
			flag = 1;
			break;
		}
		else if (a[pos] < num)
		{
			countnum++;
			l = pos + 1;
		}
		else
		{
			countnum++;
			r = pos - 1;
		}
	}
	if (flag == 1)
	{
		cout << "查找成功！元素 " << num << " 位于原数组下标为 " << pos << " 的地方" << endl;
		cout << "查找次数为：" << countnum << endl;
	}
	else
	{
		//cout << "l=" << l << " pos=" << pos << " r=" << r << endl;
		if (pos + 1 == l)
		{
			cout << "查找失败！元素 " << num << " 位于数组下标为 " << pos << " 与下标为 " << l << " 的元素的中间" << endl;
			cout << "即在 " << a[pos] << " 与 " << a[l] << "之间" << endl;
		}
		else
		{
			cout << "查找失败！元素 " << num << " 位于数组下标为 " << r << " 与下标为 " << pos << " 的元素的中间" << endl;
			cout << "即在 " << a[r] << " 与 " << a[pos] << "之间" << endl;
		}
		cout << "查找次数为：" << countnum << endl;
	}
	return;
}