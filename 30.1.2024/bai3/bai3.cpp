#include <bits/stdc++.h>
using namespace std;
int x, y, d;
const int NOTEXIST = -1;
void ExtEuler(int a, int b) {
    if (b == 0) {
        x = 1;
        y = 0;
        d = a;
    } else {
        ExtEuler(b, a  % b);
        int tmp = x;
        x = y;
        y = tmp - (a / b) * y;
    }
}
int invModular(int a, int m) {
    ExtEuler(a, m);
    if (d != 1) return NOTEXIST;
    int res = (x % m + m) % m;
    return res;
}
int a1[] = {2, 4, 6, 9, 11};
int m1[] = {3, 5, 7, 11, 13};
int a2[] = {2, 3, 4, 6, 7};
int m2[] = {3, 5, 7, 11, 13};
int remainderChinese(int a[], int m[]) {
    long long commonM = 1;
    int len = 5;
    for (int i = 0; i < len; ++i) {
        commonM *= m[i];
    }
    long long res = 0;
    for (int i = 0; i < len; ++i) {
        long long x = commonM / m[i];
        res += ((a[i] * x % commonM) * invModular((int)(x), m[i])) % commonM;
        res %= commonM;
    }
    res %= commonM;
    return res;
}
int main() {
    cout << "A) \n";
    cout << remainderChinese(a1, m1) << endl;
    cout << "B) \n";
    cout << remainderChinese(a2, m2) << endl;
    return 0;
}