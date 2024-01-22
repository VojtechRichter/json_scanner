#include "token.h"

int scan_character(char c)
{
    switch (c)
    {
        case '{':
            {
                return TOKEN_LBRACE;
            } break;
        case '}':
            {
                return TOKEN_RBRACE;
            } break;
        case '"':
            {
                return TOKEN_DOUBLE_QUOTE;
            } break;
        case ':':
            {
                return TOKEN_COLON;
            } break;
        case ',':
            {
                return TOKEN_COMMA;
            } break;
        case '[':
            {
                return TOKEN_LBRACKET;
            } break;
        case ']':
            {
                return TOKEN_RBRACKET;
            } break;
        default:
        {
            return TOKEN_EMPTY;
        }
    }
}

const char *get_token_name(char c)
{
    switch (c)
    {
        case '{':
            {
                return "TOKEN_LBRACE";
            } break;
        case '}':
            {
                return "TOKEN_RBRACE";
            } break;
        case '"':
            {
                return "TOKEN_DOUBLE_QUOTE";
            } break;
        case ':':
            {
                return "TOKEN_COLON";
            } break;
        case ',':
            {
                return "TOKEN_COMMA";
            } break;
        case '[':
            {
                return "TOKEN_LBRACKET";
            } break;
        case ']':
            {
                return "TOKEN_RBRACKET";
            } break;
        default:
        {
            return "TOKEN_EMTPY";
        }
    }
}



