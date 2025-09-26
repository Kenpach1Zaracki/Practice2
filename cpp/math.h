#pragma once
#include <vector>

// Проверка простоты числа
bool isPrime(int n);

// Быстрое возведение в степень по модулю
int powmod(int base, int exp, int mod);

// Наибольший общий делитель (gcd)
int gcd(int a, int b);

// Расширенный алгоритм Евклида
int extendedEuclid(int a, int b, int &x, int &y);

// Модульный обратный элемент
int modInverse(int a, int m);

// Цепная дробь
std::vector<int> continuedFraction(int a, int b);

// Диофантово уравнение для 143a + 169b = 5 (твой вариант)
bool solveDiophantine(int a, int b, int c, int &x, int &y);

void taskFermatPower();
void taskExtendedEuclidUV();
void taskModularInverse();
void taskContinuedFractionAndDiophantine();
