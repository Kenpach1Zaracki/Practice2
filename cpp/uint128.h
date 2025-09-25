#pragma once
#include <iostream>
#include <string>

// Вывод __uint128_t в поток
inline std::ostream& operator<<(std::ostream& os, __uint128_t value) {
    if (value == 0) {
        os << "0";
        return os;
    }
    std::string out;
    while (value > 0) {
        out.insert(out.begin(), '0' + (value % 10));
        value /= 10;
    }
    os << out;
    return os;
}

// Ввод __uint128_t из потока
inline std::istream& operator>>(std::istream& is, __uint128_t& value) {
    std::string s;
    is >> s;
    value = 0;
    for (char c : s) {
        if (c >= '0' && c <= '9') {
            value = value * 10 + (c - '0');
        }
    }
    return is;
}
