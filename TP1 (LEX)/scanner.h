#pragma once
#include <stdbool.h>

typedef enum TokenType TokenType;
typedef struct Token Token;

/* scanner known types */
enum TokenType {
    EndOfFile = 0,
    Number = 1,
    Addition = '+',
    Multiplication = '*',
    Substraction = '-',
    Division = '/',
    Modulus = '%',
    PopResult = '\n',
    LexError
};

/* token data possible type values */
union TokenData {
   double val;
   char* lexeme;
};

/* token structrue */
struct Token {
    TokenType type;
    union TokenData data;
};

/* Returns true if is possible to read another token, the read token is stored in t. */
bool GetNextToken(struct Token *t);
