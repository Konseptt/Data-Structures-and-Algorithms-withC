#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to reverse a string using a stack
void reverseString(char *str) {
  int n = strlen(str);
  char *stack = (char *)malloc(n * sizeof(char));
  int top = -1;

  // Push all characters of the string to the stack
  for (int i = 0; i < n; i++) {
    stack[++top] = str[i];
  }

  // Pop all characters from the stack and put them back to the string
  for (int i = 0; i < n; i++) {
    str[i] = stack[top--];
  }

  free(stack);
}

int main() {
  char str[100];

  printf("Enter a string: ");
  fgets(str, sizeof(str), stdin);

  // Remove newline character if present
  str[strcspn(str, "\n")] = '\0';

  reverseString(str);

  printf("Reversed string: %s\n", str);

  return 0;
}