#include <stdio.h>
#include <ctype.h>

#define MAX_SIZE 100

int stack[MAX_SIZE];
int top = -1;

void push(int x) {
    stack[++top] = x;
}

int pop() {
    return stack[top--];
}

int evaluatePostfix(char *postfix) {
    int i, result = 0, operand1, operand2;
    for (i = 0; postfix[i] != '\0'; ++i) {
        if (isdigit(postfix[i])) {
            push(postfix[i] - '0');
        } else {
            operand2 = pop();
            operand1 = pop();
            switch (postfix[i]) {
                case '+':
                    result = operand1 + operand2;
                    break;
                case '-':
                    result = operand1 - operand2;
                    break;
                case '*':
                    result = operand1 * operand2;
                    break;
                case '/':
                    result = operand1 / operand2;
                    break;
            }
            push(result);
        }
    }
    result = pop();
    return result;
}

int main() {
    char postfix[MAX_SIZE];
    printf("Enter a postfix expression: ");
    scanf("%s", postfix);
    int result = evaluatePostfix(postfix);
    printf("The result of the postfix expression is: %d\n", result);
    return 0;
}