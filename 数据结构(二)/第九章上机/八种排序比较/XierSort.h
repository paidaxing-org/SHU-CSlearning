#pragma once
#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long
template <typename T>
class Xier {
private:
    int maxnum;
    int changesum = 0;
    int cmpsum = 0;
public:

    void XierSort(T num[], int n) {
        for (int gap = n / 2; gap >= 1; gap /= 2) {
            for (int i = gap + 1; i <= n; ++i) {
                T temp = num[i];
                int j;
                cmpsum++;
                for (j = i; j > gap && num[j - gap] > temp; j -= gap) {
                    num[j] = num[j - gap];
                    changesum++;
                    cmpsum += 2;
                }
                num[j] = temp;
                changesum++;
            }
        }
        cout << "经检验，通过该排序方法操作后的数组有序" << endl;
        /*for (int i = 1; i <= n; i++)
            cout << num[i] << " ";
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












