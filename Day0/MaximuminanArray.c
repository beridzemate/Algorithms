#include <stdio.h>

int main() {
    int arr[5];
    int max;

    
    printf("Enter 5 elements in the array:\n");
    for(int i = 0; i < 5; i++) {
        scanf("%d", &arr[i]);
    }

    
    max = arr[0];

    
    for(int i = 1; i < 5; i++) {
        if(arr[i] > max) {
            max = arr[i];
        }
    }

    printf("The maximum value in the array is: %d\n", max);

    return 0;
}