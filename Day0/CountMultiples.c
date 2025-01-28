

#include <stdio.h>
#include <stdlib.h>

int count_multiples(int a, int b, int c) {
    if (c == 0) {
        printf("Error: c cannot be zero.\n");
        return -1;
    }

    int start = (a < b) ? a : b;
    int end = (a > b) ? a : b;
    int m_start = (start + abs(c) - 1) / abs(c) * abs(c);

    int m_end = (end / abs(c)) * abs(c);

    if (m_start > m_end) {
        return 0; 
    }

    return (m_end - m_start) / abs(c) + 1;
}

int main() {
    int a = 3, b = 15, c = 3;
    int result = count_multiples(a, b, c);
    if (result != -1) {
        printf("Count of multiples of %d between %d and %d: %d\n", c, a, b, result);
    }
    return 0;
}
