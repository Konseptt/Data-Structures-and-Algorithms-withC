#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

// Function to check precedence of operators
int precedence(char op) {
  if (op == '+' || op == '-')
    return 1;
  if (op == '*' || op == '/')
    return 2;
  return 0;
}

// Function to convert infix to postfix
void infixToPostfix(char *infix, char *postfix) {
  char stack[MAX];
  int top = -1;
  int k = 0;

  for (int i = 0; infix[i]; i++) {
    if (isdigit(infix[i]) || isalpha(infix[i])) {
      postfix[k++] = infix[i];
    } else if (infix[i] == '(') {
      stack[++top] = infix[i];
    } else if (infix[i] == ')') {
      while (top != -1 && stack[top] != '(') {
        postfix[k++] = stack[top--];
      }
      top--; // pop '('
    } else {
      while (top != -1 && precedence(stack[top]) >= precedence(infix[i])) {
        postfix[k++] = stack[top--];
      }
      stack[++top] = infix[i];
    }
  }

  while (top != -1) {
    postfix[k++] = stack[top--];
  }

  postfix[k] = '\0';
}

int main() {
  char infix[MAX], postfix[MAX];

  printf("Enter an infix expression: ");
  scanf("%s", infix);

  infixToPostfix(infix, postfix);

  printf("Postfix expression: %s\n", postfix);

  return 0;
}