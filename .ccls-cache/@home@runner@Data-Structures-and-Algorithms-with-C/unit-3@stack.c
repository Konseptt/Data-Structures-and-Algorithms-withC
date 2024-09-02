#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

int stack[MAX_SIZE];
int top = -1;

void push(int data) {
  if (top == MAX_SIZE - 1) {
    printf("Stack Overflow\n");
  } else {
    top++;
    stack[top] = data;
  }
}

int pop() {
  if (top == -1) {
    printf("Stack Underflow\n");
    return -1
  } else {
    int data = stack[top];
    top--;
    return data;
  }
}

int main() {
  int choice, data, n, i;

  printf("Enter the number of elements to push: ");
  scanf("%d", &n);

  printf("Enter %d elements:\n", n);
  for (i = 0; i < n; i++) {
    scanf("%d", &data);
    push(data);
  }

  printf("1. Push\n");
  printf("2. Pop\n");
  printf("3. Print Stack\n");
  printf("4. Exit\n");

  while (1) {
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        printf("Enter data to push: ");
        scanf("%d", &data);
        push(data);
        printf("Stack after push: ");
        for (int i = 0; i <= top; i++) {
          printf("%d ", stack[i]);
        }
        printf("\n");
        break;

      case 2:
        data = pop();
        if (data != -1) {
          printf("Popped element: %d\n", data);
          printf("Stack after pop: ");
          for (int i = 0; i <= top; i++) {
            printf("%d ", stack[i]);
          }
          printf("\n");
        }
        break;

      case 3:
        printf("Stack: ");
        for (int i = 0; i <= top; i++) {
          printf("%d ", stack[i]);
        }
        printf("\n");
        break;

      case 4:
        exit(0);

      default:
        printf("Invalid choice\n");
    }
  }
  return 0;
}