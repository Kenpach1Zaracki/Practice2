#include "crypto.h"
#include "math.h"
#include "validInput.h"
#include <iostream>
#include <random>

static int genPrime(int min, int max) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distrib(min | 1, max);
    int p;
    do {
        p = distrib(gen);
    } while (!isPrime(p));
    return p;
}

static int genSecret(int p) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distrib(2, p - 2);
    return distrib(gen);
}

// Диффи-Хеллман простой (без файла)
void taskDiffieHellman() {
    using namespace std;
    cout << "--- Протокол Диффи-Хеллмана ---\n";
    int p = genPrime(10000, 50000);
    cout << "Генерируем простое p: " << p << endl;
    int g = genPrime(2, p - 1);
    cout << "Генерируем первообразный корень g: " << g << endl;
    int a = genSecret(p), b = genSecret(p);
    cout << "Секрет Алисы a: " << a << endl;
    cout << "Секрет Боба b: " << b << endl;
    int A = powmod(g, a, p); // публичный Алисы
    int B = powmod(g, b, p); // публичный Боба
    cout << "Открытый Алисы (A): " << A << endl;
    cout << "Открытый Боба (B): " << B << endl;
    int kA = powmod(B, a, p); // общий ключ у Алисы
    int kB = powmod(A, b, p); // общий ключ у Боба
    cout << "Общий ключ у Алисы: " << kA << endl;
    cout << "Общий ключ у Боба: " << kB << endl;
    cout << (kA == kB ? "Ключи совпали!\n" : "Ошибка: ключи различны!\n");
}

// MITM-атака на Диффи-Хеллман (эмуляция)
void taskDiffieHellmanMITM() {
    using namespace std;
    cout << "--- MITM атака на Диффи-Хеллман ---\n";
    int p = genPrime(10000, 50000);
    int g = genPrime(2, p - 1);
    cout << "p: " << p << "\ng: " << g << endl;

    // Алиса
    int alice_secret = genSecret(p);
    int alice_pub = powmod(g, alice_secret, p);

    // Боб
    int bob_secret = genSecret(p);
    int bob_pub = powmod(g, bob_secret, p);

    // Мэллори (злоумышленник)
    int mallory_secret = genSecret(p);
    int mallory_pub = powmod(g, mallory_secret, p);

    cout << "Алиса отправляет A (на самом деле Бобу передает Mallory): " << alice_pub << endl;
    cout << "Боб отправляет B (на самом деле Алисе передает Mallory): " << bob_pub << endl;

    // Mallory подменяет публичные ключи
    int fakeA = mallory_pub;
    int fakeB = mallory_pub;

    // Алиса вычисляет "общий" ключ с Mallory
    int alice_shared = powmod(fakeB, alice_secret, p);
    // Боб вычисляет "общий" ключ с Mallory
    int bob_shared = powmod(fakeA, bob_secret, p);
    // Mallory знает оба секрета
    int mallory_alice = powmod(alice_pub, mallory_secret, p);
    int mallory_bob = powmod(bob_pub, mallory_secret, p);

    cout << "Общий ключ (Алиса): " << alice_shared << "\n";
    cout << "Общий ключ (Боб):   " << bob_shared << "\n";
    cout << "Mallory может вычислить оба: с Алисой " << mallory_alice << ", с Бобом " << mallory_bob << endl;
    cout << "Все сообщения Mallory сможет расшифровать!\n";
}
