#pragma once
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define ll long long

template <typename T>
class Guibing {
private:
    int maxnum;
    int changesum = 0;
    int cmpsum = 0;
    bool flag = 0;

public:
    void Merge(T num[], int low, int mid, int high)
    {
        T* tmpElem = new T[high + 1];
        int i = low, j = mid + 1, k = low;
        while (i <= mid && j <= high)
        {
            cmpsum += 2;
            if (num[i] <= num[j])
            {
                tmpElem[k++] = num[i++];
                cmpsum++;
                changesum++;
            }
            else
            {
                tmpElem[k++] = num[j++];
                changesum++;
            }
        }
        while (i <= mid)
        {
            cmpsum++;
            tmpElem[k++] = num[i++];
            changesum++;
        }
        while (j <= high)
        {
            cmpsum++;
            tmpElem[k++] = num[j++];
            changesum++;
        }
        for (i = low; i <= high; i++)
            num[i] = tmpElem[i];
        delete[]tmpElem;
    }
    void MergeSort(T num[], int low, int high, int n) {
        if (low < high) {
            int mid = (low + high) / 2;
            MergeSort(num, low, mid, n);
            MergeSort(num, mid + 1, high, n);
            Merge(num, low, mid, high);
        }
        if (flag == 0)
        {
            cout << "经检验，通过该排序方法操作后的数组有序" << endl;
            /*for (int i = 1; i <= n; i++)
                cout << num[i] << " ";
            cout << endl;*/
            flag = 1;
        }
    }
    int getchangesum() {
        return changesum;
    };

    int getcmpsum() {
        return cmpsum;
    };
};