public class bai3 {
    public static boolean isPrime(int n) {
        if (bai2.totient(n) == n-1) return true;
        return false;
    }
}
