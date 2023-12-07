#include <stdio.h>   /* for printf() */
#include "stack.h"   /* for push() && pop() */
#include "scanner.h" /* for GetNextToken() */
#include <math.h>    /* for fmod() */
#include <stdlib.h>  /* for EXIT_FAILURE && exit() */

void exitwitherror(const char *error);

int main()
{
    struct Token token;
    StackItem op2;

    while (GetNextToken(&token)) {
        switch (token.type) {
        case LexError:
            printf("Lexic error. Unknown command %s\n", token.data.lexeme);
            exit(EXIT_FAILURE);
            break;
        case Number:
            push(token.data.val);
            break;
        case PopResult:
            if (height() == 1) {
                printf("\t%.8g\n", pop());
            }
            else {
                exitwitherror("Syntax error.");
            }
            break;
        default:
            if (height() > 1) {
                switch (token.type) {
                    case Addition:
                        push(pop() + pop());
                        break;
                    case Multiplication:
                        push(pop() * pop());
                        break;
                    case Substraction:
                        op2 = pop();
                        push(pop() - op2);
                        break;
                    case Division:
                        op2 = pop();
                        if (op2 != 0.0)
                            push(pop() / op2);
                        else
                            exitwitherror("Semantic error. Cant have zero as divisor.\n");
                        break;
                    default: // case Modulus:
                        op2 = pop();
                        if (op2 != 0.0)
                        {
                            // push((int) pop() % (int) op2); // int modulus
                            push(fmod(pop(), op2)); // double modulus
                        }
                        else
                            exitwitherror("Semantic error. Cant have zero as modulus.\n");
                }
            }
            else {
                exitwitherror("Syntax error.");
            }
        }
    }
}

void exitwitherror(const char *error) {
    printf(error);
    exit(EXIT_FAILURE);
}