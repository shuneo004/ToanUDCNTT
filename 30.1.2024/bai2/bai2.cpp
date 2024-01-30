#include <bits/stdc++.h>
using namespace std;
const int N = 82300;
vector <int> sieve(const int N) {
    bool isPrime[N];
    isPrime[0] = false;
    isPrime[1] = false;
    for (int i = 2; i < N; ++i) {
        isPrime[i] = true;
    }
    for (int i = 2; i * i < N; ++i) {
        if (isPrime[i]) {
            for (int j = i * i; j < N; j += i) {
                isPrime[j] = false;
            }
        }
    }
    vector <int> prime;
    for (int i = 2; i < N; ++i) {
        if (isPrime[i]) prime.push_back(i);
    }
    return prime;
}
int numFators(int n, vector<int> &PrimeDiv) {
    int res = 1;
    for (int p = 2; p < n; ++p) {
        if (n % p == 0) {
            PrimeDiv.push_back(p);
            int cnt = 0;
            while (n % p == 0) {
                ++cnt;
                n /= p;
            }
            res *= (cnt + 1);
        }
    }
    if (n > 1) res *= 2;
    if (n > 1) PrimeDiv.push_back(n);
    return res;
}
long long power(long long x, int y) {
    long long res = 1;
    while (y > 0) {
        if (y % 2 == 1) res = res * x;
        x = x * x;
        y = y / 2;
    }
    return res;
}
int sumDiv(int n) {
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
int main() {
    cout << "a) \n";
    vector<int> prime;
    cout << "So luong cac uoc so nguyen duong cua " << N << " la " << endl;
    cout << numFators(N, prime) << endl;
    cout << "So luong cac uoc so nguyen to cua " << N << " la " << endl;
    cout << prime.size() << endl;
    cout << "Liet ke ne\n";
    int sum = 0;
    for (int x : prime) {
        cout << x << ' ' ;
        sum += x;
    }
    cout << endl;
    cout << "Tong ne\n";
    cout << sum << endl;
    cout << "b) \n";
    for (int i = 6; i <= N; ++i) {
        if (sumDiv(i) == i * 2) cout << i << ' ';
    }
    return 0;
}