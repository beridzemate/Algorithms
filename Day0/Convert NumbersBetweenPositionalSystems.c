#include <stdio.h>
#include <string.h>
#include <math.h>

void reverse(char str[], int length) {
    int start = 0;
    int end = length - 1;
    while (start < end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

int toDecimal(char *num, int base) {
    int len = strlen(num);
    int power = 1; 
    int decimal = 0; 
    int i;


    for (i = len - 1; i >= 0; i--) {
        if (num[i] >= '0' && num[i] <= '9') {
            decimal += (num[i] - '0') * power;
        } else if (num[i] >= 'A' && num[i] <= 'F') {
            decimal += (num[i] - 'A' + 10) * power;
        }
        power = power * base;
    }

    return decimal;
}

void fromDecimal(int decimal, int base, char *result) {
    int index = 0; 

    
    while (decimal > 0) {
        int remainder = decimal % base;
        if (remainder >= 0 && remainder <= 9) {
            result[index++] = (remainder + '0');
        } else {
            result[index++] = (remainder - 10 + 'A');
        }
        decimal = decimal / base;
    }
    result[index] = '\0';

    
    reverse(result, index);
}

int main() {
    char num[100];
    int base1, base2;
    char result[100];

    printf("Enter the number: ");
    scanf("%s", num);
    printf("Enter the base of the number: ");
    scanf("%d", &base1);
    printf("Enter the base to convert to: ");
    scanf("%d", &base2);

    int decimal = toDecimal(num, base1);
    fromDecimal(decimal, base2, result);

    printf("The number %s in base %d is %s in base %d\n", num, base1, result, base2);

    return 0;
}