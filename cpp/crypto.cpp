#include "crypto.h"
#include "math.h"
#include "validInput.h"
#include "uint128.h"
#include <iostream>
#include <random>

// Проверка простоты для __uint128_t 
static bool isPrime128(__uint128_t n) {
    if (n < 2) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    for (uint64_t d = 3; d * d <= n; d += 2)
        if (n % d == 0) return false;
    return true;
}

// Генерация большого простого 
static __uint128_t genPrime128(__uint128_t min, __uint128_t max) {
    std::random_device rd;
    std::mt19937_64 gen(rd());
    std::uniform_int_distribution<uint64_t> distrib((uint64_t)min | 1, (uint64_t)max);
    __uint128_t p;
    do {
        p = distrib(gen);
    } while (!isPrime128(p));
    return p;
}

static __uint128_t genSecret128(__uint128_t p) {
    std::random_device rd;
    std::mt19937_64 gen(rd());
    std::uniform_int_distribution<uint64_t> distrib(2, (uint64_t)p - 2);
    return distrib(gen);
}

// Быстрое возведение в степень по модулю для __uint128_t
__uint128_t powmod128(__uint128_t base, __uint128_t exp, __uint128_t mod) {
    __uint128_t res = 1;
    base %= mod;
    while (exp > 0) {
        if (exp & 1) res = (res * base) % mod;
        base = (base * base) % mod;
        exp >>= 1;
    }
    return res;
}

// Диффи-Хеллман
void taskDiffieHellman() {
    using namespace std;
    cout << "--- Протокол Диффи-Хеллмана (uint128) ---\n";
    __uint128_t p = genPrime128(1000000000000000ULL, 1000000000001000ULL); // пример диапазона
    __uint128_t g = genPrime128(2, p - 1);
    cout << "Генерируем первообразный корень g: " << g << endl;
    __uint128_t a = genSecret128(p), b = genSecret128(p);
    cout << "Секрет Алисы a: " << a << endl;
    cout << "Секрет Боба b: " << b << endl;
    __uint128_t A = powmod128(g, a, p); // публичный Алисы
    __uint128_t B = powmod128(g, b, p); // публичный Боба
    cout << "Открытый Алисы (A): " << A << endl;
    cout << "Открытый Боба (B): " << B << endl;
    __uint128_t kA = powmod128(B, a, p); // общий ключ у Алисы
    __uint128_t kB = powmod128(A, b, p); // общий ключ у Боба
    cout << "Общий ключ у Алисы: " << kA << endl;
    cout << "Общий ключ у Боба: " << kB << endl;
    cout << (kA == kB ? "Ключи совпали!\n" : "Ошибка: ключи различны!\n");
}

// MITM-атака на Диффи-Хеллман 
void taskDiffieHellmanMITM() {
    using namespace std;
    cout << "--- MITM атака на Диффи-Хеллман (uint128) ---\n";
    __uint128_t p = genPrime128(1000000000000000ULL, 1000000000001000ULL);
    __uint128_t g = genPrime128(2, p - 1);
    cout << "p: " << p << "\ng: " << g << endl;

    // Алиса
    __uint128_t alice_secret = genSecret128(p);
    __uint128_t alice_pub = powmod128(g, alice_secret, p);

    // Боб
    __uint128_t bob_secret = genSecret128(p);
    __uint128_t bob_pub = powmod128(g, bob_secret, p);

    // Мэллори (злоумышленник)
    __uint128_t mallory_secret = genSecret128(p);
    __uint128_t mallory_pub = powmod128(g, mallory_secret, p);

    cout << "Алиса отправляет A (на самом деле Mallory): " << alice_pub << endl;
    cout << "Боб отправляет B (на самом деле Mallory): " << bob_pub << endl;

    // Mallory подменяет публичные ключи
    __uint128_t fakeA = mallory_pub;
    __uint128_t fakeB = mallory_pub;

    // Алиса вычисляет "общий" ключ с Mallory
    __uint128_t alice_shared = powmod128(fakeB, alice_secret, p);
    // Боб вычисляет "общий" ключ с Mallory
    __uint128_t bob_shared = powmod128(fakeA, bob_secret, p);
    // Mallory знает оба секрета
    __uint128_t mallory_alice = powmod128(alice_pub, mallory_secret, p);
    __uint128_t mallory_bob = powmod128(bob_pub, mallory_secret, p);

    cout << "Общий ключ (Алиса): " << alice_shared << "\n";
    cout << "Общий ключ (Боб):   " << bob_shared << "\n";
    cout << "Mallory может вычислить оба: с Алисой " << mallory_alice << ", с Бобом " << mallory_bob << endl;
    cout << "Все сообщения Mallory сможет расшифровать!\n";
}
