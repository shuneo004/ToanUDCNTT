#include <bits/stdc++.h>
using namespace std;
const int N = 25000;
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
int density(int n) {
    return n / log2(n);
}
int main() {
    cout << "Cac So nguyen to nho hon " << N << " la: \n";
    vector<int> prime = sieve(N);
    for (int x : prime) cout << x << ' ';
    int dest = N;
    int n = N;
    while (density(dest) == density(n)) dest ++;
    prime = sieve(dest);
    auto lower = lower_bound(prime.begin(), prime.end(), n);
    auto higher = upper_bound(prime.begin(), prime.end(), n);
    cout << endl << "So nguyen to gan nhat cua " << n << " la" << endl;
    if (lower == prime.begin()) {
        cout << "lower\n";
        cout << *lower << endl;
    } else if (higher == prime.end()) {
        --lower;
        cout << *lower << endl;
    } else {
        --lower;
        if (n - *lower == *higher - n) cout << *lower << " " << *higher << endl;
        else if (n - *lower < *higher - n) cout << *lower << endl;
        else cout << *higher << endl;
    }
        
    
    return 0;
}