#include <stdio.h>
#include "./stack.h"

#define MAX 100

int ai = 0; // actual index
double stack[MAX];

/* Checks if stack is empty */
int isEmpty(void) {
    return ai == 0;
}

/* Checks if stack is full */
int isFull(void) {
    return ai == MAX;
}

/* pop double from stack */
StackItem pop(void) {
    if (!isEmpty()) {
        return stack[--ai];
    }
    printf("There is no more elements in stack");
    return 0.0;
}

/* push double to stack */
void push(StackItem c) {
    if (!isFull()) {
        stack[ai++] = c;
    }
    else {
        printf("%f cant be push, reached stack maximum capacity", c);
    }
}

int height(void){
    return ai;
}
