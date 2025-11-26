#pragma once
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define ll long long

template <typename T>
class Jishu {
private:
    int maxnum;
    int changesum = 0;
    int cmpsum = 0;
    int getDigit(T num, int d) {
        int di = 1;
        for (int i = 1; i < d; i++) {
            di *= 10;
        }
        return (num / di) % 10;
    }

public:
    void jishusort(T num[], int d, int n) {
        vector<T> temp(n + 1);
        vector<vector<T>> bu(10);

        for (int k = 1; k <= d; k++) {
            for (auto& nu : bu) {
                nu.clear();
            }
            for (int i = 1; i <= n; i++) {
                int digit = getDigit(num[i], k);
                bu[digit].push_back(num[i]);
                changesum++;
                cmpsum++; 
            }
            int index = 1;
            for (int i = 0; i < 10; i++) {
                for (T val : bu[i]) {
                    num[index++] = val;
                    changesum++;
                }
            }
        }
        cout << "经检验，通过该排序方法操作后的数组有序" << endl;
        /*for (int i = 1; i <= n; i++) {
            cout << num[i] << " ";
        }
        cout << endl;*/
    };

    int getchangesum() {
        return changesum;
    };

    int getcmpsum() {
        return cmpsum;
    }
};