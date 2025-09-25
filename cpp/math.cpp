#include "math.h"
#include <iostream>
#include <cmath>
#include <vector>

// Проверка простоты (обычный перебор)
bool isPrime(int n) {
    if (n < 2) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    for (int d = 3; d * d <= n; d += 2)
        if (n % d == 0) return false;
    return true;
}

// Быстрое возведение в степень по модулю (через двоичное разложение)
int powmod(int base, int exp, int mod) {
    int res = 1;
    base %= mod;
    while (exp > 0) {
        if (exp & 1) res = (1LL * res * base) % mod;
        base = (1LL * base * base) % mod;
        exp >>= 1;
    }
    return res;
}

// Обычный gcd
int gcd(int a, int b) {
    while (b) {
        int t = a % b;
        a = b;
        b = t;
    }
    return a;
}

// Расширенный Евклид
int extendedEuclid(int a, int b, int &x, int &y) {
    if (b == 0) {
        x = 1; y = 0;
        return a;
    }
    int x1, y1;
    int d = extendedEuclid(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return d;
}

// Обратный по модулю
int modInverse(int a, int m) {
    int x, y;
    int g = extendedEuclid(a, m, x, y);
    if (g != 1) throw std::runtime_error("Обратного по модулю не существует");
    return (x % m + m) % m;
}

// Цепная дробь (a/b)
std::vector<int> continuedFraction(int a, int b) {
    std::vector<int> cf;
    while (b != 0) {
        cf.push_back(a / b);
        int t = a % b;
        a = b;
        b = t;
    }
    return cf;
}

// Решение диофантова уравнения (ax + by = c)
bool solveDiophantine(int a, int b, int c, int &x, int &y) {
    int g = extendedEuclid(abs(a), abs(b), x, y);
    if (c % g != 0) return false;
    x *= c / g;
    y *= c / g;
    if (a < 0) x = -x;
    if (b < 0) y = -y;
    return true;
}

// Задание 1: a^x mod p с проверкой Ферма
void taskFermatPower() {
    using namespace std;
    cout << "Вычисление a^x mod p с проверкой условий малой теоремы Ферма\n";
    int a, x, p;
    cout << "Введите основание a: "; cin >> a;
    cout << "Введите степень x: "; cin >> x;
    cout << "Введите модуль p: "; cin >> p;
    if (!isPrime(p)) {
        cout << "p не является простым числом!\n";
        return;
    }
    if (gcd(a, p) != 1) {
        cout << "a и p не взаимно просты!\n";
        return;
    }
    if ((x % (p - 1)) == 0)
        cout << "По малой теореме Ферма: a^x mod p = 1\n";
    else
        cout << "a^x mod p = " << powmod(a, x, p) << endl;
}

// Задание 2: расширенный Евклид (u и v)
void taskExtendedEuclidUV() {
    using namespace std;
    cout << "Введите два числа для расширенного алгоритма Евклида:\n";
    int a, b, x, y;
    cout << "a: "; cin >> a;
    cout << "b: "; cin >> b;
    int g = extendedEuclid(a, b, x, y);
    cout << "gcd = " << g << ", коэффициенты: x = " << x << ", y = " << y << endl;
    cout << a << "*" << x << " + " << b << "*" << y << " = " << g << endl;
}

// Задание 3: модульный обратный
void taskModularInverse() {
    using namespace std;
    cout << "Введите число и модуль: \n";
    int a, m;
    cout << "a: "; cin >> a;
    cout << "modulus m: "; cin >> m;
    try {
        int inv = modInverse(a, m);
        cout << "Обратный элемент: " << inv << endl;
        cout << a << "*" << inv << " mod " << m << " = " << (a * inv) % m << endl;
    } catch (const std::exception &e) {
        cout << "Ошибка: " << e.what() << endl;
    }
}

// Задание 5: цепная дробь и диофантово уравнение
void taskContinuedFractionAndDiophantine() {
    using namespace std;
    cout << "Цепная дробь и диофантово уравнение для 143a + 169b = 5\n";
    int a = 143, b = 169, c = 5;
    cout << "Цепная дробь для (" << a << "/" << b << "): ";
    auto cf = continuedFraction(a, b);
    for (size_t i = 0; i < cf.size(); ++i) {
        cout << cf[i];
        if (i + 1 != cf.size()) cout << ", ";
    }
    cout << endl;
    int x, y;
    if (solveDiophantine(a, b, c, x, y)) {
        cout << "Решение уравнения " << a << "a + " << b << "b = " << c << ":\n";
        cout << "a = " << x << ", b = " << y << endl;
        cout << a << "*" << x << " + " << b << "*" << y << " = " << a * x + b * y << endl;
    } else {
        cout << "Нет целых решений!\n";
    }
}
