import java.util.*;

public class MathUtils {

    // Проверка на простоту
    public static boolean isPrime(int n) {
        if (n < 2) return false;
        if (n == 2) return true;
        if (n % 2 == 0) return false;
        for (int d = 3; d * d <= n; d += 2) {
            if (n % d == 0) return false;
        }
        return true;
    }

    // Быстрое возведение в степень по модулю
    public static int powmod(int base, int exp, int mod) {
        int res = 1;
        base = base % mod;
        while (exp > 0) {
            if ((exp & 1) == 1) res = (int)(((long)res * base) % mod);
            base = (int)(((long)base * base) % mod);
            exp >>= 1;
        }
        return res;
    }

    // Обычный gcd
    public static int gcd(int a, int b) {
        while (b != 0) {
            int t = a % b;
            a = b;
            b = t;
        }
        return a;
    }

    // Расширенный алгоритм Евклида (находит u,v)
    public static int extendedEuclid(int a, int b, int[] uv) {
        if (b == 0) {
            uv[0] = 1; uv[1] = 0;
            return a;
        }
        int[] uv1 = new int[2];
        int d = extendedEuclid(b, a % b, uv1);
        uv[0] = uv1[1];
        uv[1] = uv1[0] - (a / b) * uv1[1];
        return d;
    }

    // Обратный по модулю
    public static int modInverse(int a, int m) {
        int[] uv = new int[2];
        int g = extendedEuclid(a, m, uv);
        if (g != 1) throw new ArithmeticException("Обратный не существует!");
        return ((uv[0] % m) + m) % m;
    }

    // Цепная дробь
    public static List<Integer> continuedFraction(int a, int b) {
        List<Integer> res = new ArrayList<>();
        while (b != 0) {
            res.add(a / b);
            int t = a % b;
            a = b;
            b = t;
        }
        return res;
    }

    // Решение диофантова уравнения ax + by = c
    public static boolean solveDiophantine(int a, int b, int c, int[] xy) {
        int g = extendedEuclid(Math.abs(a), Math.abs(b), xy);
        if (c % g != 0) return false;
        xy[0] *= c / g;
        xy[1] *= c / g;
        if (a < 0) xy[0] = -xy[0];
        if (b < 0) xy[1] = -xy[1];
        return true;
    }

    // ---- ЗАДАНИЯ ----

    public static void taskPowMod(Scanner sc) {
        System.out.print("a: "); int a = InputUtils.readInt(sc);
        System.out.print("x: "); int x = InputUtils.readInt(sc);
        System.out.print("p: "); int p = InputUtils.readInt(sc);
        if (!isPrime(p)) {
            System.out.println("p не простое!");
            return;
        }
        System.out.println("a^x mod p = " + powmod(a, x, p));
    }

    public static void taskExtendedEuclid(Scanner sc) {
        System.out.print("a: "); int a = InputUtils.readInt(sc);
        System.out.print("b: "); int b = InputUtils.readInt(sc);
        int[] uv = new int[2];
        int g = extendedEuclid(a, b, uv);
        System.out.println("gcd = " + g + ", u = " + uv[0] + ", v = " + uv[1]);
        System.out.println(a + "*" + uv[0] + " + " + b + "*" + uv[1] + " = " + g);
    }

    public static void taskModularInverse(Scanner sc) {
        System.out.print("a: "); int a = InputUtils.readInt(sc);
        System.out.print("mod: "); int m = InputUtils.readInt(sc);
        try {
            int inv = modInverse(a, m);
            System.out.println("Обратный: " + inv);
        } catch (ArithmeticException e) {
            System.out.println(e.getMessage());
        }
    }

    public static void taskContinuedFractionAndDiophantine() {
        int a = 143, b = 169, c = 5;
        System.out.println("Цепная дробь для " + a + "/" + b + ":");
        List<Integer> frac = continuedFraction(a, b);
        System.out.println(frac);

        int[] xy = new int[2];
        if (solveDiophantine(a, b, c, xy)) {
            System.out.println("Решение уравнения: " + a + "*x + " + b + "*y = " + c);
            System.out.println("x = " + xy[0] + ", y = " + xy[1]);
        } else {
            System.out.println("Нет целых решений!");
        }
    }
}
