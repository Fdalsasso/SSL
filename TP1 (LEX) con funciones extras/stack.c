#include <stdio.h>
#include "./stack.h"
#include <stdlib.h>  /* for EXIT_FAILURE && exit() */

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
    printf("Syntax error. There is no element in stack\n");
    exit(EXIT_FAILURE);
}

/* push double to stack */
void push(StackItem c) {
    if (!isFull()) {
        stack[ai++] = c;
    }
    else {
        printf("%f cant be push, reached stack maximum capacity\n", c);
        exit(EXIT_FAILURE);
    }
}

int height(void){
    return ai;
}

void dup(){
    StackItem aux = pop();
    push(aux);
    push(aux);
}

void swap(){
    StackItem aux1 = pop();
    StackItem aux2 = pop();
    push(aux1);
    push(aux2);
}

void top(){
    printf("\tTop of the stack is: %.8g\n", stack[ai-1]);
}

void clear(){
    ai = 0;
}