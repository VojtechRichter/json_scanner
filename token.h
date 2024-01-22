#ifndef JSON_SCANNER_TOKEN
#define JSON_SCANNER_TOKEN

int scan_character(char c);

typedef enum {
    TOKEN_LBRACE, // single
    TOKEN_RBRACE, // single
    TOKEN_DOUBLE_QUOTE, // single
    TOKEN_COLON, // single
    TOKEN_COMMA, // single
    TOKEN_VALUE_STRING, // multiple
    TOKEN_VALUE_ARRAY, // multiple
    TOKEN_VALUE_NUMBER, // multiple
    TOKEN_LBRACKET, // single
    TOKEN_RBRACKET, // sigle
    TOKEN_EMPTY
} Token;

#endif // JSON_SCANNER_TOKEN
