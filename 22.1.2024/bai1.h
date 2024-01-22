#include <iostream>
using namespace std;
class bai1 {
    public:
        static void display(int p, int n, int a) {
            if (n == 1) {
                cout << p;
            } else cout << p << "^" << n;
            if (a > 1) cout << ".";
        }
        static void analysis(int n) {
            if (n == 1) cout << 1;
            for (int p = 2; p*p <= n; ++p) {
                if (n % p == 0) {
                    int cnt = 0;
                    while (n % p == 0) {
                        cnt ++;
                        n /= p;
                    }
                    display(p, cnt, n);
                }
            }
            if (n > 1) display(n, 1, 1);
        }
};