typedef struct {
    long long *data;
    int top;
} Stack;

int calculate(char* s) {
    Stack st;
    st.data = (long long*)malloc(sizeof(long long) * (strlen(s) + 1));
    st.top = -1;

    long long result = 0;
    long long number = 0;
    int sign = 1;

    for (int i = 0; s[i] != '\0'; i++) {
        char c = s[i];

        if (isdigit(c)) {
            number = number * 10 + (c - '0');
        }
        else if (c == '+') {
            result += sign * number;
            number = 0;
            sign = 1;
        }
        else if (c == '-') {
            result += sign * number;
            number = 0;
            sign = -1;
        }
        else if (c == '(') {
            st.data[++st.top] = result;
            st.data[++st.top] = sign;

            result = 0;
            sign = 1;
        }
        else if (c == ')') {
            result += sign * number;
            number = 0;

            long long prevSign = st.data[st.top--];
            long long prevResult = st.data[st.top--];

            result = prevResult + prevSign * result;
        }
    }

    result += sign * number;

    free(st.data);
    return (int)result;
}