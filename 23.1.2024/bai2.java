public class bai2 {
    public static long power(long a, int b) {
        long res = 1;
        while (b > 0) {
            if (b % 2 == 1) res *= a;
            a *= a;
            b /= 2;
        }
        return res;
    }
    public static int totient(int n) {
        int res = 1;
        for (int p = 2; p*p <= n; ++p) {
            if (n % p == 0) {
                int cnt = 0;
                while (n % p == 0) {
                    cnt ++;
                    n /= p;
                }
                res *= power(p, cnt - 1) * (p - 1);
            }
        }
        if (n > 1) {
            res *= n - 1;
        }
        return res;
    }
}
