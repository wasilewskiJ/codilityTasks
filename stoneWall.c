// you can write to stdout for debugging purposes, e.g.
// printf("this is a debug message\n");

// wkladam na stack H[0]
// petla od i=1 do N-1:
//    while(H[i] < peek(Stack) || !stackIsEmpty(stack))
//         pop(stack)
//    jezeli H[i] == peek(Stack) -> continue
//    push(stack, H[i])

typedef struct Stack Stack;
struct Stack
{
    int *data;
    int top;
    int capacity;
};

Stack *createStack(int capacity)
{
    Stack *stack = malloc(sizeof(Stack));
    stack->data = malloc(capacity * sizeof(int));
    stack->capacity = capacity;
    stack->top = 0;
    return stack;
}

int isEmpty(Stack *stack)
{
    if (stack->top <= 0)
        return 1;
    else
        return 0;
}

int isFull(Stack *stack)
{
    if (stack->top >= stack->capacity)
        return 1;
    else
        return 0;
}

int push(Stack *stack, int value)
{
    if (isFull(stack))
        return 0;
    stack->data[stack->top++] = value;
    return 1;
}

int pop(Stack *stack)
{
    if (isEmpty(stack))
        return 0;
    else
        stack->top--;
    return 1;
}

int peek(Stack *stack, int *value)
{
    if (isEmpty(stack))
    {
        return 0;
    }
    *value = stack->data[stack->top - 1];
    return 1;
}

void destroyStack(Stack *stack)
{
    free(stack->data);
    free(stack);
}

int solution(int H[], int N)
{
    Stack *stack = createStack(N);
    push(stack, H[0]);
    int counter = 1;
    for (int i = 1; i < N; i++)
    {
        int value;
        while (!isEmpty(stack))
        {
            peek(stack, &value);
            if (H[i] < value)
            {
                pop(stack);
            }
            else
            {
                break;
            }
        }

        if (isEmpty(stack) || H[i] != value)
        {
            push(stack, H[i]);
            counter++; // Only increment if we push a new height
        }
    }
        destroyStack(stack);
        return counter;
}
    // wkladam na stack H[0]
    // petla od i=1 do N-1:
    //    while(H[i] < peek(Stack) || !stackIsEmpty(stack))
    //         pop(stack)
    //    jezeli H[i] == peek(Stack) -> continue
    //    push(stack, H[i])
