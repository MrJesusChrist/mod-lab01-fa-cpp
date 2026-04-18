// Copyright 2022 UNN-IASR
#include "fun.h"
#include <cctype>

unsigned int faStr1(const char *str) {
    unsigned int count = 0;
    int state = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        char c = str[i];
        bool sp = isspace(static_cast<unsigned char>(c));
        bool dg = isdigit(static_cast<unsigned char>(c));

        switch (state) {
        case 0:
            if (!sp)
                state = dg ? 2 : 1;
            break;
        case 1:
            if (sp) {
                count++;
                state = 0;
            } else if (dg) {
                state = 2;
            }
            break;
        case 2:
            if (sp)
                state = 0;
            break;
        }
    }

    if (state == 1)
        count++;
    return count;
}

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
            if (!sp)
                state = upper ? 1 : 3;
            break;
        case 1:
            if (sp) {
                count++;
                state = 0;
            } else if (lower) {
                state = 2;
            } else {
                state = 3;
            }
            break;
        case 2:
            if (sp) {
                count++;
                state = 0;
            } else if (!lower) {
                state = 3;
            }
            break;
        case 3:
            if (sp)
                state = 0;
            break;
        }
    }

    if (state == 1 || state == 2)
        count++;
    return count;
}

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
            if (!sp) {
                state = 1;
                curLen = 1;
            }
            break;
        case 1:
            if (sp) {
                totalLen += curLen;
                wordCount++;
                state = 0;
            } else {
                curLen++;
            }
            break;
        }
    }

    if (state == 1) {
        totalLen += curLen;
        wordCount++;
    }
    if (wordCount == 0)
        return 0;

    return (2 * totalLen + wordCount) / (2 * wordCount);
}
