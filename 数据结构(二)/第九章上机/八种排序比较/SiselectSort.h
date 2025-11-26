#pragma once
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define ll long long

template <typename T>
class JiandanSelect {
private:
    int maxnum;
    int changesum = 0;
    int cmpsum = 0;
    bool flag = 0;

public:
    void SimpleSelectSort(T num[], int n)
    {
        int k;
        for (int i = 1; i < n; i++)
        {
            k = i;
            changesum++;
            for (int j = i + 1; j <= n; j++)
            {
                if (num[j] < num[k])
                {
                    k = j;
                    changesum++;
                }
                cmpsum++;
            }
            if (k != i)
            {
                swap(num[i], num[k]);
                changesum += 3;
            }
            cmpsum++;
        }
        cout << "经检验，通过该排序方法操作后的数组有序" << endl;
        /*for (int i = 1; i <= n; i++)
        {
            cout << num[i] << " ";
        }
        cout << endl;*/
    }

    int getchangesum() {
        return changesum;
    };

    int getcmpsum() {
        return cmpsum;
    };
};