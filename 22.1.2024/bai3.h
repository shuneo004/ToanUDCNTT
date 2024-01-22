#pragma once
#include <bits/stdc++.h>
using namespace std;
class bai3 {
    public:
        static long long power(long long x, int y) {
            long long res = 1;
            while (y > 0) {
                if (y % 2 == 1) res = res * x;
                x = x * x;
                y = y / 2;
            }
            return res;
        }
        static int sumDiv(int n) {
            long long sum = 1;
            for (int p = 2; p*p <= n; ++p) {
                if (n % p == 0) {
                    int cnt = 0;
                    while (n % p == 0) {
                        ++cnt;
                        n /= p;
                    }
                    sum *= (power(p, cnt+1) - 1) / (p-1);
                }
            }
            if (n > 1) sum *= (power(n, 2) - 1) / (n-1);
            return sum;
        }
        static void analysis(int n) {
            long long sum = sumDiv(n);
            cout << "Tong cac uoc la: " << sum << endl;
        }
};