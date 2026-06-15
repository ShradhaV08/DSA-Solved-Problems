bool isMatch(char *s, char *p) {
    int i = 0, j = 0;
    int star = -1, match = 0;

    while (s[i]) {
        // Characters match or '?'
        if (p[j] == s[i] || p[j] == '?') {
            i++;
            j++;
        }
        // Found '*'
        else if (p[j] == '*') {
            star = j;
            match = i;
            j++;
        }
        // Previous '*' exists, backtrack
        else if (star != -1) {
            j = star + 1;
            match++;
            i = match;
        }
        // No match possible
        else {
            return false;
        }
    }

    // Skip remaining '*' in pattern
    while (p[j] == '*')
        j++;

    return p[j] == '\0';
}