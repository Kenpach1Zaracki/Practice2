#include <iostream>
#include <string>
#include "math.h"
#include "crypto.h"
#include "validInput.h"

using namespace std;

int main() {
    bool loop = true;
    while (loop) {
        cout << "\nМеню заданий:\n"
             << "1. a^x mod p (свойства, быстрая степень, Ферма)\n"
             << "2. Расширенный алгоритм Евклида (u и v)\n"
             << "3. Обратное по модулю (расширенный Евклид)\n"
             << "4. Диффи-Хеллман (обмен ключами, атака)\n"
             << "5. Цепная дробь и диофантово уравнение\n"
             << "6. MITM-атака на Диффи-Хеллман\n"
             << "0. Выход\n"
             << "Выберите задание: ";

        int choice = getIntInput(0, 6);

        switch (choice) {
            case 1:
                taskFermatPower();
                break;
            case 2:
                taskExtendedEuclidUV();
                break;
            case 3:
                taskModularInverse();
                break;
            case 4:
                taskDiffieHellman();
                break;
            case 5:
                taskContinuedFractionAndDiophantine();
                break;
            case 6:
                taskDiffieHellmanMITM();
                break;
            case 0:
            default:
                loop = false;
                cout << "Завершение работы.\n";
        }
    }
    return 0;
}
