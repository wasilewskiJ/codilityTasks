// you can write to stdout for debugging purposes, e.g.
// printf("this is a debug message\n");
#include <stdlib.h>
#define MAX_SIZE 200000

struct Stack {
    char data[MAX_SIZE];
    int top;
};

void initializeStack(struct Stack* stack) {
    stack->top = 0;
}

void push(struct Stack* stack, char value) {
    if (stack->top >= MAX_SIZE) {
        printf("can't alocate on stack\n");
        return;
    }

    stack->data[stack->top] = value;
    stack->top++;
}

void pop(struct Stack* stack) {
    if (stack->top < 0) {
        printf("cant pop from stack\n");
        return;
    }
    stack->top--;
}

char peek(struct Stack* stack) {
    return stack->data[stack->top-1];
}

int isEmpty(struct Stack* stack) {
    if (stack->top == 0)
        return 1;
    else
        return 0;
}

int solution(char *S) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack*));
    initializeStack(stack);
    int idx = 0;
    char bracket;
    while ((bracket = S[idx]) != '\0') {
        if (bracket == '(' || bracket == '[' || bracket == '{') {
            push(stack, bracket);
        } else if (bracket == ')') {
            if(stack->data[stack->top-1] == '(')
                pop(stack);
            else
                return 0;
            
        } else if (bracket == ']') {
            if(stack->data[stack->top-1] == '[')
                pop(stack);
            else
                return 0;
            
        } else if (bracket == '}') {
            if(stack->data[stack->top-1] == '{')
                pop(stack);
            else
                return 0;
            
        }
    }
    if (isEmpty(stack))
        return 1;
    else
        return 0;
}
