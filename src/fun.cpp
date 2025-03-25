// Copyright 2022 UNN-IASR
#include "fun.h"
#include <cctype>
#include <cmath>

unsigned int faStr1(const char *str) {
    unsigned int count = 0;
    bool inWord = false;
    bool hasDigits = false;
    
    for (; *str; ++str) {
        if (isspace(*str)) {
            count += inWord && !hasDigits;
            inWord = hasDigits = false;
        } else {
            if (!inWord) {
                inWord = true;
                hasDigits = false;
            }
            hasDigits |= isdigit(*str);
        }
    }
    return count + (inWord && !hasDigits);
}

unsigned int faStr2(const char* str) {
    unsigned int count = 0;
    bool inWord = false, valid = false;

    for (; *str; ++str) {
        if (isspace(*str)) {
            count += inWord && valid;
            inWord = valid = false;
        } else if (!inWord) {
            inWord = true;
            valid = isupper(*str);
        } else if (!islower(*str)) {
            valid = false;
        }
    }
    return count + (inWord && valid);
}

unsigned int faStr3(const char *str) {
    int totalLetters = 0;
    int wordCount = 0;
    bool inWord = false;
    for (; *str != '\0'; ++str) {
        if (isspace(*str)) {
            inWord = false;
        } else {
            if (!inWord) {
                ++wordCount;
                inWord = true;
            }
            ++totalLetters;
        }
    }
    if (wordCount == 0) {
        return 0;
    }
    double average = static_cast<double>(totalLetters) / wordCount;
    return static_cast<unsigned int>(round(average));
}
