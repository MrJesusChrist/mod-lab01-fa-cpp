// Copyright 2022 UNN-IASR
#include "fun.h"
#include <cctype>

// КА: считает слова без цифр
// Состояния: 0 — между словами, 1 — в слове (цифр нет), 2 — в слове (есть цифра)
unsigned int faStr1(const char *str) {
    unsigned int count = 0;
    int state = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        char c = str[i];
        bool sp = isspace(static_cast<unsigned char>(c));
        bool dg = isdigit(static_cast<unsigned char>(c));

        switch (state) {
        case 0:
            if (!sp) state = dg ? 2 : 1;
            break;
        case 1:
            if (sp)      { count++; state = 0; }
            else if (dg) { state = 2; }
            break;
        case 2:
            if (sp) state = 0;
            break;
        }
    }

    if (state == 1) count++;
    return count;
}

// КА: считает слова, начинающиеся с заглавной латинской буквы,
//     а среди остальных символов только строчные латинские буквы
// Состояния: 0 — между словами, 1 — первый символ заглавный,
//            2 — слово валидно, 3 — слово невалидно
unsigned int faStr2(const char *str) {
    unsigned int count = 0;
    int state = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        char c = str[i];
        bool sp    = isspace(static_cast<unsigned char>(c));
        bool upper = (c >= 'A' && c <= 'Z');
        bool lower = (c >= 'a' && c <= 'z');

        switch (state) {
        case 0:
            if (!sp) state = upper ? 1 : 3;
            break;
        case 1:
            if (sp)        { count++; state = 0; }
            else if (lower) { state = 2; }
            else            { state = 3; }
            break;
        case 2:
            if (sp)        { count++; state = 0; }
            else if (!lower) { state = 3; }
            break;
        case 3:
            if (sp) state = 0;
            break;
        }
    }

    if (state == 1 || state == 2) count++;
    return count;
}

// КА: находит среднюю длину слова, округлённую по правилам арифметического округления
// Состояния: 0 — между словами, 1 — в слове
unsigned int faStr3(const char *str) {
    unsigned int totalLen  = 0;
    unsigned int wordCount = 0;
    unsigned int curLen    = 0;
    int state = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        char c = str[i];
        bool sp = isspace(static_cast<unsigned char>(c));

        switch (state) {
        case 0:
            if (!sp) { state = 1; curLen = 1; }
            break;
        case 1:
            if (sp) { totalLen += curLen; wordCount++; state = 0; }
            else    { curLen++; }
            break;
        }
    }

    if (state == 1) { totalLen += curLen; wordCount++; }
    if (wordCount == 0) return 0;

    // Арифметическое округление: (2*total + count) / (2*count)
    return (2 * totalLen + wordCount) / (2 * wordCount);
}
