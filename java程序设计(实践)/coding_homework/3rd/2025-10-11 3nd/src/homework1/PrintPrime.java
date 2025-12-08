package homework1;

public class PrintPrime {
    public static boolean CheckPrime(int x) {
        if (x <= 1)
            return false;
        if (x == 2)
            return true;
        for (int i = 2; i <= Math.sqrt(x); i++) {
            if (x % i == 0)
                return false;
        }
        return true;
    }

    public static void main(String[] args) {
        for (int i = 100; i <= 200; i++) {
            if (CheckPrime(i) == true)
                System.out.println(i);
        }
    }
}