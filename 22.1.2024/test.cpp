#include <bits/stdc++.h>
#include "bai1.h"
#include "bai2.h"
#include "bai3.h"
#include "bai4.h"
#include "bai5.h"
#include "bai6.h"
#include "bai7.h"
using namespace std;
const int tests = 5;

void demo(void f(int), int id) {
    string link = string("./demo/bai") + (char(id + 48)) + string(".out");
    ifstream fi("./demo/data.inp");
    freopen(link.c_str(), "w", stdout);
    for (int i = 0; i < tests; ++i) {
        int n;
        fi >> n;
        cout << "lan thu " << i << ": Nhap so N: " << n << endl;
        f(n);
        cout << endl;
    }
    fi.close();
}
void demo7th(void f(int, int), int id) {
    string link = string("./demo/bai") + (char(id + 48)) + string(".out");
    ifstream fi("./demo/data7.inp");
    freopen(link.c_str(), "w", stdout);
    for (int i = 0; i < tests; ++i) {
        int l,r;
        fi >> l >> r;
        cout << "lan thu " << i << ": Nhap so l, r: " << l << " " << r << endl;
        f(l,r);
        cout << endl;
    }
    fi.close();
}
int main(int argc, char const *argv[])
{
    demo(bai1::analysis, 1);
    demo(bai2::analysis, 2);
    demo(bai3::analysis, 3);
    demo(bai4::analysis, 4);
    demo(bai5::analysis, 5);
    demo(bai6::analysis, 6);
    demo7th(bai7::analysis, 7);
    return 0;
}
