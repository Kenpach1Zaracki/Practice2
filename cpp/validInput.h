#pragma once
#include <string>

// Безопасный ввод числа (с диапазоном)
int getIntInput(int min, int max);

// Безопасный ввод строки
std::string getStringInput(const std::string& prompt);
