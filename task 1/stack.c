#include "stack.h"

#include <stdio.h>
#include <limits.h>

#define DEFAULT_ARRAY_SIZE 5

stack* create_stack() {
    stack *stk = (stack*)malloc(sizeof(stack));
    if (!stk) {
        return NULL;
    }
    stk->values = (int*)malloc(DEFAULT_ARRAY_SIZE * sizeof(int));
    if (!stk->values) {
        free(stk);
        return NULL;
    }
    stk->array_size = DEFAULT_ARRAY_SIZE;
    stk->stack_size = 0;
    return stk;
}

void destroy_stack(stack *stk) {
    if (stk) {
        free(stk->values);
        free(stk);
    }
}

void push(stack *stk, int val) {
    if (stk->array_size == stk->stack_size) {
        stk->array_size *= 2;
        stk->values = (int*)realloc(stk->values, stk->array_size * sizeof(int));
    }
    stk->values[stk->stack_size] = val;
    stk->stack_size++;
}

int pop(stack *stk) {
    if (stk->stack_size == 0) {
        printf("Stack is empty! you cannot pop item.\n");
        return INT_MIN;
    }
    int removed_value = stk->values[stk->stack_size-1];
    stk->stack_size--;
    return removed_value;

}

int peek_top(stack *stk) {
    if (stk->stack_size == 0) {
        printf("Stack is empty! Nothing to peek.\n");
        return INT_MIN;
    }
    return stk->values[stk->stack_size-1];
}

size_t stack_size(stack *stk) {
    return stk->stack_size;
}

void clear_stack(stack *stk) {
    stk->stack_size = 0;
}

void print_stack(stack *stk) {
    if (stk->stack_size == 0) {
        printf("Stack is empty!\n");
        return;
    }
    
    printf("Stack items: ");
    for (size_t i = 0; i < stk->stack_size; i++) {
        printf("%d ", stk->values[i]);
    }
    printf("\n");
}
