#include <stdio.h>

int main() {
    int n, target;
    printf("Enter number of elements in the sorted array: ");
    scanf("%d", &n);
    int arr[n];

    printf("Enter %d sorted elements:\n", n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the target number to search: ");
    scanf("%d", &target);

    int low = 0, high = n - 1, mid, found = 0;
    while(low <= high) {
        mid = low + (high - low) / 2; 
        if(arr[mid] == target) {
            printf("Element found at position: %d\n", mid + 1);
            found = 1;
            break;
        } else if(arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    if(!found) {
        printf("Element not found in the array.\n");
    }
}