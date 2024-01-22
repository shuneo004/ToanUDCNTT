#include <bits/stdc++.h>
using namespace std;
class bai6 {
    public:
        static const int N = 1e7;
        static int density(int n) {
            return n / log(n);
        }
        static vector <int> sievePrime(int dest) {
            dest += 10;
            vector <int> primes;
            bool isPrime[dest];
            for (int i = 0; i < dest; ++i) isPrime[i] = true;
            isPrime[0] = false;
            isPrime[1] = false;
            for (int i = 2; i*i < dest; ++i) {
                if (isPrime[i] == true) {
                    for (int j = i*i; j < dest; j += i) {
                        isPrime[j] = false;
                    }
                }
            }
            for (int i = 2; i < dest; ++i) {
                if (isPrime[i] == true) {
                    primes.push_back(i);
                }
            }
            return primes;
        }
        static void analysis(int n) {
            int dest = N;
            while (density(dest) > density(n)) dest --;
            vector<int> prime = sievePrime(dest);
            auto lower = lower_bound(prime.begin(), prime.end(), n);
            auto higher = upper_bound(prime.begin(), prime.end(), n);
            cout << "So nguyen to gan nhat cua " << n << " la" << endl;
            if (lower == prime.begin()) {
                cout << *lower << endl;
            } else {
                --lower;
                if (n - *lower == *higher - n) cout << *lower << " " << *higher << endl;
                else if (n - *lower < *higher - n) cout << *lower << endl;
                else cout << *higher << endl;
            }
        }
};