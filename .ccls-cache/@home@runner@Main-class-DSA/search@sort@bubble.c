#include <stdio.h>

int main() {
    int n, swapped;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n];

    printf("Enter %d elements:\n", n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Advanced Bubble Sort with swapped flag to check if the array is already sorted
    for(int i = 0; i < n-1; i++) {
        swapped = 0; // Reset swapped flag for each iteration
        for(int j = 0; j < n-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                // Swap arr[j] and arr[j+1]
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                swapped = 1; // Set swapped flag if there was a swap
            }
        }
        // If no two elements were swapped by inner loop, then break
        if(swapped == 0) {
            break;
        }
    }

    printf("Sorted array:\n");
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}