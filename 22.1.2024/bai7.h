#include <bits/stdc++.h>
using namespace std;
class bai7 {
    public:
        static vector<int> rangeSivePrime(int L, int R) {
            const int N = R - L + 1;
            bool isPrime[N];
            vector<int> prime;
            for (int i = 0; i < N; ++i) isPrime[i] = true;
            for (int i = 2; i * i <= R; ++i) {
                for (int j = max(i * i, (L + i - 1)  / i * i); j <= R; j += i) {
                    isPrime[j-L] = false;
                }
            }
            if (1 >= L) {  // Xét riêng trường hợp số 1
                isPrime[1 - L] = false;
            }
            for (int x = L; x <= R; ++x) {
                if (isPrime[x-L] == true) {
                    prime.push_back(x);
                }
            }
            return prime;
        }
        static void analysis(int l, int r) {
            vector<int> prime = bai7::rangeSivePrime(l, r);
            for (int i = 0; i < prime.size(); ++i) {
                cout << prime[i] << " ";
            }
            cout << endl;
        }
};