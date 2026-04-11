// Copyright 2022 UNN-IASR
#include <cstdio>
#include "fun.h"

int main() {
    const char *str1 = "qwe4  gftt e 555gr rrgr  grhh ";
    printf("faStr1(\"%s\") = %u\n", str1, faStr1(str1));

    const char *str2 = "Hello world!";
    printf("faStr2(\"%s\") = %u\n", str2, faStr2(str2));

    const char *str3 = " six monkeys";
    printf("faStr3(\"%s\") = %u\n", str3, faStr3(str3));

    return 0;
}
