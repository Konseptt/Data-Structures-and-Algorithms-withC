#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct Stack {
  int items[MAX];
  int top;
} Stack;

void initStack(Stack *s) { s->top = -1; }

int isFull(Stack *s) { return s->top == MAX - 1; }

int isEmpty(Stack *s) { return s->top == -1; }

void push(Stack *s, int data) {
  if (isFull(s)) {
    printf("Stack is full\n");
    return;
  }
  s->items[++(s->top)] = data;
}

int pop(Stack *s) {
  if (isEmpty(s)) {
    printf("Stack is empty\n");
    return -1;
  }
  return s->items[(s->top)--];
}

int peek(Stack *s) {
  if (isEmpty(s)) {
    printf("Stack is empty\n");
    return -1;
  }
  return s->items[s->top];
}

int main() {
  Stack s;
  initStack(&s);
  int choice, data;

  while (1) {
    printf("1. Push\n");
    printf("2. Pop\n");
    printf("3. Peek\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
      printf("Enter data: ");
      scanf("%d", &data);
      push(&s, data);
      break;
    case 2:
      data = pop(&s);
      if (data != -1) {
        printf("Popped: %d\n", data);
      }
      break;
    case 3:
      data = peek(&s);
      if (data != -1) {
        printf("Top element: %d\n", data);
      }
      break;
    case 4:
      exit(0);
    default:
      printf("Invalid choice\n");
    }
  }

  return 0;
}