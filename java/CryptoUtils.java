import java.util.*;

public class CryptoUtils {
    private static Random rand = new Random();

    // Случайное простое число
    public static int genPrime(int min, int max) {
        int p;
        do {
            p = min + rand.nextInt(max - min + 1);
            if (p % 2 == 0) p++;
        } while (!MathUtils.isPrime(p));
        return p;
    }

    // Случайный секрет
    public static int genSecret(int p) {
        return 2 + rand.nextInt(p - 3);
    }

    // Диффи-Хеллман (без MITM)
    public static void taskDiffieHellman() {
        System.out.println("--- Диффи-Хеллман ---");
        int p = genPrime(10000, 50000);
        int g = genPrime(2, p-1);
        System.out.println("p (prime): " + p);
        System.out.println("g (generator): " + g);

        int a = genSecret(p), b = genSecret(p);
        System.out.println("Секрет Алисы (a): " + a);
        System.out.println("Секрет Боба (b): " + b);

        int A = MathUtils.powmod(g, a, p);
        int B = MathUtils.powmod(g, b, p);
        System.out.println("A (Алисы): " + A);
        System.out.println("B (Боба): " + B);

        int keyA = MathUtils.powmod(B, a, p);
        int keyB = MathUtils.powmod(A, b, p);
        System.out.println("Общий ключ Алисы: " + keyA);
        System.out.println("Общий ключ Боба: " + keyB);

        if (keyA == keyB)
            System.out.println("Ключи совпадают!");
        else
            System.out.println("Ключи НЕ совпадают!");
    }

    // MITM-атака на Диффи-Хеллман
    public static void taskMITMAttack() {
        System.out.println("--- MITM-атака на Диффи-Хеллман ---");
        int p = genPrime(10000, 50000);
        int g = genPrime(2, p-1);
        System.out.println("p: " + p + ", g: " + g);

        int aliceSecret = genSecret(p);
        int bobSecret = genSecret(p);
        int mallorySecret = genSecret(p);

        int alicePub = MathUtils.powmod(g, aliceSecret, p);
        int bobPub = MathUtils.powmod(g, bobSecret, p);
        int malloryPub = MathUtils.powmod(g, mallorySecret, p);

        System.out.println("Алиса публикует A: " + alicePub);
        System.out.println("Боб публикует B: " + bobPub);
        System.out.println("Mallory публикует свой ключ: " + malloryPub);

        // Mallory подменяет публичные ключи
        int fakeA = malloryPub, fakeB = malloryPub;

        int aliceShared = MathUtils.powmod(fakeB, aliceSecret, p);
        int bobShared = MathUtils.powmod(fakeA, bobSecret, p);
        int malloryAlice = MathUtils.powmod(alicePub, mallorySecret, p);
        int malloryBob = MathUtils.powmod(bobPub, mallorySecret, p);

        System.out.println("Общий ключ Алисы (с Mallory): " + aliceShared);
        System.out.println("Общий ключ Боба (с Mallory): " + bobShared);
        System.out.println("Mallory получил ключ с Алисой: " + malloryAlice);
        System.out.println("Mallory получил ключ с Бобом: " + malloryBob);
        System.out.println("Mallory может читать все сообщения!");
    }
}
