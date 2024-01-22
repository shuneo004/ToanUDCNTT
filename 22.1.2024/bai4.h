#pragma once
#include <bits/stdc++.h>
#include "bai2.h"
#include "bai3.h"
using namespace std;
class bai4 {
    public:
        static long long phi(int n) {
            int root = sqrt(n);
            long long ans = bai3::power(n, bai2::numFators(n) / 2);
            if (root * root == n) ans *= root;
            return ans;
        }
        static void analysis(int n) {
            long long ans = phi(n);
            cout << "Tich cac uoc so la : " << ans << endl;
        }
};