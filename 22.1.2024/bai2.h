#pragma once
#include <bits/stdc++.h>
using namespace std;
class bai2 {
    public:
        static int numFators(int n) {
            int res = 1;
            for (int p = 2; p < n; ++p) {
                if (n % p == 0) {
                    int cnt = 0;
                    while (n % p == 0) {
                        ++cnt;
                        n /= p;
                    }
                    res *= (cnt + 1);
                }
            }
            if (n > 1) res *= 2;
            return res;
        }
        static void analysis(int n) {
            cout << "Tong so uoc la: " << numFators(n) << endl;
            vector <int> saves1, saves2;
            for (int i = 1; i*i <= n; ++i) {
                if (n % i == 0) {
                    saves1.push_back(i);
                    if (i*i != n) saves2.push_back(n/i);
                }
            }
            cout << "Liet ke cac uoc: " << endl;
            for (auto x : saves1) {
                cout << x << " ";
            }
            reverse(saves2.begin(), saves2.end());
            for (auto x : saves2) {
                cout << x << " ";
            }
        }
};