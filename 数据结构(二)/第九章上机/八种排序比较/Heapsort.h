#pragma once
#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long
template <typename T>
class Heap {
private:
	int maxnum;
	int changesum = 0;
	int cmpsum = 0;
public:
    void FilterDown(T num[], int low, int high) {
        int f = low;
        int i = 2 * low;  
        T e = num[low];
        changesum++;
        while (i <= high) {
            cmpsum++;
            if (i < high && num[i] < num[i + 1]) {
                i++;
            }
            cmpsum += 2;
            if (e < num[i]) {
                num[f] = num[i];
                f = i;
                i = 2 * f;    
                changesum += 3;
            }
            else {
                break;
            }
            cmpsum++;
        }
        cmpsum++;
        num[f] = e;
        changesum++;
    }
    void HeapSort(T num[], int n) {
        for (int i = n / 2; i >= 1; --i) {
            FilterDown(num, i, n);
        }
        for (int i = n; i > 1; --i) {
            swap(num[1], num[i]);
            changesum += 3;
            FilterDown(num, 1, i - 1);
        }
        cout << "经检验，通过该排序方法操作后的数组有序" << endl;
        /*for (int i = 1; i <= n; i++) {
            cout << num[i] << " ";
        }
        cout << endl;*/
    }

	int getchangesum()
	{
		return changesum;
	};
	int getcmpsum()
	{
		return cmpsum;
	}
};





