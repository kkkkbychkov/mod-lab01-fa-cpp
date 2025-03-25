// Copyright 2022 UNN-IASR
#include "fun.h"
#include <cctype>
#include <cmath>

unsigned int faStr1(const char *str) {
    unsigned int count = 0;
    bool inWord = false;
    bool hasDigits = false;

    for (int i = 0; str[i] != '\0'; ++i) {
        if (isspace(str[i])) {
            if (inWord && !hasDigits) {
                ++count;
            }
            inWord = false;
            hasDigits = false;
        } else {
            if (!inWord) {
                inWord = true;
                hasDigits = false;
            }
            if (isdigit(str[i])) {
                hasDigits = true;
            }
        }
    }

    if (inWord && !hasDigits) {
        ++count;
    }

    return count;
}

unsigned int faStr2(const char *str) {
    unsigned int count = 0;
    bool inWord = false;
    bool isValidWord = false;

    for (; *str != '\0'; ++str) {
        if (!inWord) {
            if (isupper(*str)) {
                inWord = true;
                isValidWord = true;
            } else if (isalpha(*str)) {
                inWord = true;
                isValidWord = false;
            }
        } else {
            if (isspace(*str)) {
                inWord = false;
                if (isValidWord) {
                    ++count;
                }
            } else if (!islower(*str)) {
                isValidWord = false;
            }
        }
    }

    if (inWord && isValidWord) {
        ++count;
    }

    return count;
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
