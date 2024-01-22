#include <bits/stdc++.h>
#include "bai3.h"
using namespace std;
class bai5 {
    public:
        static void analysis(int n) {
            cout << "So " << n << "co phai la hoan hao hay khong? \n";
            if (bai3::sumDiv(n) - n == n) {
                cout << "YES\n";
            } else cout << "NO\n";
                    
        }
};