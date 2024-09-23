#include "stack.h"

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

stack* create_stack() {
    stack *stk = (stack*)malloc(sizeof(stack));
    if (stk) {
        stk->stack_size = 0;
        stk->top = NULL;
    }
    return stk;
}

void destroy_stack(stack *stk) {
    if (stk) {
        clear_stack(stk);
        free(stk);
    }
}

void push(stack *stk, int val) {
    node *new_node = (node*)malloc(sizeof(node));
    new_node->value = val;
    new_node->link = stk->top;
    stk->top = new_node;
    stk->stack_size++;
}

int pop(stack *stk) {
    if (stk->stack_size == 0) {
        printf("Stack is empty! you cannot pop item.\n");
        return INT_MIN;
    }
    
    node *temp = stk->top;
    int removed_value = temp->value;
    stk->top = temp->link;

    // Free allocated memory
    free(temp);

    stk->stack_size--;
    return removed_value;
}

int peek_top(stack *stk) {
    if (stk->stack_size == 0) {
        printf("Stack is empty! Nothing to peek.\n");
        return INT_MIN;
    }
    return stk->top->value;
}

size_t stack_size(stack *stk) {
    return stk->stack_size;
}

void clear_stack(stack *stk) {
    while (stk->stack_size > 0) {
        pop(stk);
    }
}

void print_stack(stack *stk) {
    if (stk->stack_size == 0) {
        printf("Stack is empty!\n");
        return;
    }
    
    node *current = stk->top;
    printf("Stack items: ");
    while (current) {
        printf("%d ", current->value);
        current = current->link;
    }
    printf("\n");
}
