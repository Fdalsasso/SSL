#pragma once

typedef double StackItem;
StackItem pop(void);
void push(StackItem c);
int isEmpty(void);
int isFull(void);
int height(void);
void dup();
void swap();
void top();
void clear();