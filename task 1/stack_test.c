#include "stack.h"

#include <stdio.h>

int main() {
    stack *stk = create_stack();
    
    if (!stk) {
        printf("Failed to create stack\n");
        return 1;
    }

    // Push items
    push(stk, 1);
    push(stk, 2);
    push(stk, 3);
    push(stk, 4);
    push(stk, 5);

    push(stk, 6);  // This should double the size of array

    printf("Stack items pushed\n");
    print_stack(stk);

    // Pop items
    printf("Popped: %d\n", pop(stk));
    printf("Popped: %d\n", pop(stk));

    printf("Popped two items!\n");
    print_stack(stk);

    // Peek item
    printf("Top of stack: %d\n", peek_top(stk));

    // Clear stack
    clear_stack(stk);
    printf("Stack after clearing: ");
    print_stack(stk);

    // Test popping from an empty stack
    printf("Popped from empty stack: %d\n", pop(stk));

    destroy_stack(stk);
    return 0;
}
