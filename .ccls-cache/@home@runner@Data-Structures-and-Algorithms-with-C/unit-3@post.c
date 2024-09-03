#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

// Function to evaluate postfix expression
int evaluatePostfix(char* exp) {
    int stack[MAX];
    int top = -1;

    for (int i = 0; exp[i]; ++i) {
        if (isdigit(exp[i])) {
            stack[++top] = exp[i] - '0';
        } else {
            int val1 = stack[top--];
            int val2 = stack[top--];
            switch (exp[i]) {
                case '+': stack[++top] = val2 + val1; break;
                case '-': stack[++top] = val2 - val1; break;
                case '*': stack[++top] = val2 * val1; break;
                case '/': stack[++top] = val2 / val1; break;
            }
        }
    }
    return stack[top];
}

int main() {
    char exp[MAX];
    printf("Enter postfix expression: ");
    scanf("%s", exp);
    printf("Result of postfix evaluation: %d\n", evaluatePostfix(exp));
    return 0;
}