public class bai8 {
    public static int x;
    public static int y;
    public final static int NOTEXIST = -1;
    public static int gcdExtended(int a, int b)
    {
        
        // Base Case
        if (a == 0) {
            x = 0;
            y = 1;
            return b;
        }
 
        // To store results of recursive call
        int gcd = gcdExtended(b % a, a);
        int x1 = x;
        int y1 = y;
 
        // Update x and y using results of recursive
        // call
        int tmp = b / a;
        x = y1 - tmp * x1;
        y = x1;
 
        return gcd;
    }
    public static int invModular(int A, int M) {
        int g = gcdExtended(A, M);
        if (g != 1) {
            return NOTEXIST;
        }
        else {
            // m is added to handle negative x
            int res = (x % M + M) % M;
            return res;
        }
    }
    public static long remainderChinese(int[] a, int[] m) {
        long commonM = 1;
        int len = a.length;
        for (int i = 0; i < len; ++i) {
            commonM *= m[i];
        }
        long res = 0;
        for (int i = 0; i < len; ++i) {
            long x = commonM / m[i];
            res += a[i] * x * invModular((int)(x), m[i]);
        }
        res %= commonM;
        return res;
    }
}
