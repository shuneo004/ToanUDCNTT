import java.util.Scanner;

public class test {
    public static void test1() {
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int b = sc.nextInt();
        System.out.println(bai1.gcd(a, b));
        sc.close();
    }
    
    public static void test2() {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        System.out.println(bai2.totient(n));
        sc.close();
    }
    public static void test3() {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        System.out.println(bai3.isPrime(n));
        sc.close();
    }
    public static void test8() {
        Scanner sc = new Scanner(System.in);
        int[] a, m;
        final int n = 3;
        a = new int[n];
        m = new int[n];
        long commonM = 1;
        for (int i = 0; i < n; ++i) {
            a[i] = sc.nextInt();
            m[i] = sc.nextInt();
            commonM *= m[i];
        }
        System.out.println(bai8.remainderChinese(a, m) + " + k*" + commonM);
        sc.close();
    }
    public static void main(String[] args) {
        test8();
    }
}
