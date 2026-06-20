#include <ctype.h>

bool isNumber(char* s) {
    int i = 0;

    int seenDigit = 0;
    int seenDot = 0;
    int seenExp = 0;
    int digitAfterExp = 1;

    while (s[i]) {

        if (isdigit(s[i])) {
            seenDigit = 1;
            digitAfterExp = 1;
        }

        else if (s[i] == '+' || s[i] == '-') {
            if (i > 0 && s[i - 1] != 'e' && s[i - 1] != 'E')
                return false;
        }

        else if (s[i] == '.') {
            if (seenDot || seenExp)
                return false;

            seenDot = 1;
        }

        else if (s[i] == 'e' || s[i] == 'E') {
            if (seenExp || !seenDigit)
                return false;

            seenExp = 1;
            digitAfterExp = 0;
        }

        else {
            return false;
        }

        i++;
    }

    return seenDigit && digitAfterExp;
}