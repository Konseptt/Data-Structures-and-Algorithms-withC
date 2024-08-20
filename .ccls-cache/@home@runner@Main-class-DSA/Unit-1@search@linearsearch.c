#include <stdio.h>

int main() {
  int n, search, count = 0;
  printf("Enter the number of elements in array: ");
  scanf("%d", &n);
  int array[n];
  printf("Enter the number in array: ");
  for (int i = 0; i < n; i++) {
    scanf("%d", &array[i]);
  }
  printf("Enter the search number: ");
  scanf("%d", &search);

  for (int i = 0; i < n; i++) {
    if (array[i] == search) {
      printf("\n%d is present in the array at %d.", search, i + 1);
      count++;
    }
  }
  if (count == 0)
    printf("%d is not present in the array.", search);
}