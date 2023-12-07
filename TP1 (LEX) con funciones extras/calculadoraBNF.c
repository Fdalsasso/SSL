#include <stdio.h>   /* for printf() */
#include "stack.h"   /* for push() && pop() */
#include "scanner.h" /* for GetNextToken() */
#include <math.h>    /* for fmod() */
#include <stdlib.h>  /* for EXIT_FAILURE && exit() */

static void match(TokenType);
static double expr(void);
static void exprlist(void);

static Token CurrentToken;

/*
    program -> exprlist EOF
    exprlist -> expr \n | exprlist expr \n
    expr -> number | expr expr operator
*/

int main()
{
    exprlist();
}

static void exprlist()
{
    for (; GetNextToken(&CurrentToken);)
    {
        double value = expr();
        if (CurrentToken.type == PopResult)
        {
            printf("\t%.8g\n", value);
        }
        else
        {
            printf("Syntax error.\n");
            exit(EXIT_FAILURE);
        }
    }
}

static double expr()
{
    double value = CurrentToken.data.val;
    match(Number);
    if(CurrentToken.type == Number)
    {
        double op2 = expr();
        switch (CurrentToken.type)
        {
        case Addition:
            match(Addition);
            value += op2;
            break;
        case Multiplication:
            match(Multiplication);
            value *= op2;
            break;
        case Substraction:
            match(Substraction);
            value = value - op2;
            break;
        case Division:
            match(Division);
            value = value / op2;
            break;
        case Modulus:
            match(Modulus);
            value = fmod(value, op2);
            break;
        case PopResult:
            printf("Syntax error.\n");
            exit(EXIT_FAILURE);
        case Number:
            printf("Syntax error.\n");
            exit(EXIT_FAILURE);
        default:
            printf("Unknown command %s\n", CurrentToken.data.lexeme);
            exit(EXIT_FAILURE);
        }
    }
    return value;
};

static void match(TokenType expected)
{
    if (CurrentToken.type == expected)
    {
        GetNextToken(&CurrentToken);
    }
    else
    {
        printf("Syntax error.\n");
        exit(EXIT_FAILURE);
    }
}