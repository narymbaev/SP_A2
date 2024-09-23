#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"  // Make sure this is your linked-list stack implementation

int main() {
    struct timeval tv1, tv2;
    stack *stk = create_stack();

    gettimeofday(&tv1, NULL);  // Start timer

    int iteration = 75000000;

    for (int i = 0; i < iteration; ++i) {
        push(stk, i);
    }

    gettimeofday(&tv2, NULL);  // End timer

    printf("Total time for linked list-based stack = %f seconds\n",
           (double)(tv2.tv_usec - tv1.tv_usec) / 1000000 +
           (double)(tv2.tv_sec - tv1.tv_sec));

    destroy_stack(stk);
    return 0;
}
