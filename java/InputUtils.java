import java.util.Scanner;

public class InputUtils {
    public static int readInt(Scanner sc) {
        while (true) {
            try {
                return Integer.parseInt(sc.nextLine().trim());
            } catch (Exception e) {
                System.out.print("Ошибка! Введите целое число: ");
            }
        }
    }

    public static int readInt(Scanner sc, int min, int max) {
        while (true) {
            int val = readInt(sc);
            if (val < min || val > max) {
                System.out.print("Введите число от " + min + " до " + max + ": ");
            } else {
                return val;
            }
        }
    }
}
