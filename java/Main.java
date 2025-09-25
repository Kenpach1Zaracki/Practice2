import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while (true) {
            System.out.println();
            System.out.println("Меню заданий:");
            System.out.println("1. a^x mod p (свойства, быстрая степень, Ферма)");
            System.out.println("2. Расширенный алгоритм Евклида (u и v)");
            System.out.println("3. Обратное по модулю (расширенный Евклид)");
            System.out.println("4. Диффи-Хеллман (обмен ключами, атака)");
            System.out.println("5. Цепная дробь и диофантово уравнение");
            System.out.println("6. MITM-атака на Диффи-Хеллман");
            System.out.println("0. Выход");
            System.out.print("Выберите задание: ");

            int choice = InputUtils.readInt(sc, 0, 6);

            switch (choice) {
                case 1: MathUtils.taskPowMod(sc); break;
                case 2: MathUtils.taskExtendedEuclid(sc); break;
                case 3: MathUtils.taskModularInverse(sc); break;
                case 4: CryptoUtils.taskDiffieHellman(); break;
                case 5: MathUtils.taskContinuedFractionAndDiophantine(); break;
                case 6: CryptoUtils.taskMITMAttack(); break;
                case 0: 
                    System.out.println("Завершение работы.");
                    return;
            }
        }
    }
}
