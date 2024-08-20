#include <stdio.h>

int main() {
    int n, i, j, k;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n], left[n / 2], right[n - n / 2];
    printf("Enter the elements: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    // Divide the array into two halves
    for (i = 0; i < n / 2; i++) {
        left[i] = arr[i];
    }
    for (i = n / 2; i < n; i++) {
        right[i - n / 2] = arr[i];
    }
    // Merge sort the left half
    for (i = 0; i < n / 2 - 1; i++) {
        for (j = i + 1; j < n / 2; j++) {
            if (left[i] > left[j]) {
                int temp = left[i];
                left[i] = left[j];
                left[j] = temp;
            }
        }
    }
    // Merge sort the right half
    for (i = 0; i < n - n / 2 - 1; i++) {
        for (j = i + 1; j < n - n / 2; j++) {
            if (right[i] > right[j]) {
                int temp = right[i];
                right[i] = right[j];
                right[j] = temp;
            }
        }
    }
    // Merge the sorted halves
    i = 0;
    j = 0;
    k = 0;
    while (i < n / 2 && j < n - n / 2) {
        if (left[i] < right[j]) {
            arr[k] = left[i];
            i++;
        } else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }
    // Copy remaining elements from left array
    while (i < n / 2) {
        arr[k] = left[i];
        i++;
        k++;
    }
    // Copy remaining elements from right array
    while (j < n - n / 2) {
        arr[k] = right[j];
        j++;
        k++;
    }
    // Print the sorted array
    printf("Sorted array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
}