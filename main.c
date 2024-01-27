#include "token.h"

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <assert.h>

static FILE *load_input_file(int argc, char **argv)
{
    if (argc > 1)
    {
        FILE *f = fopen(argv[1], "r");     
        if (f == NULL)
        {
            fprintf(stderr, "Error: could not load the input file\n");
            exit(1);
        }

        return f;
    }

    fprintf(stderr, "Error: not enough arguments provided\n");
    exit(1);
}

static void traverse(FILE *f)
{
    int current_char = fgetc(f);
    int token_type = 0;
    while (!feof(f))
    {
        if (!isspace(current_char))
        {
            token_type = scan_character(current_char);
            if (token_type == TOKEN_DOUBLE_QUOTE)
            {
                char *string_value = (char *)malloc(sizeof(char));
                assert(string_value);

                int next_char = fgetc(f);
                int size = 0;

                for (; next_char != '"'; size += 1)
                {
                    string_value[size] = next_char;
                    next_char = fgetc(f);
                }

                string_value[size] = '\0';
                printf("TOKEN_VALUE_STRING: %s\n", string_value);
                free(string_value);
            }
            else if (token_type == TOKEN_LBRACKET)
            {
                char *array_value = (char *)malloc(sizeof(char));                
                assert(array_value);

                int next_char = fgetc(f);
                int size = 0;
                
                for (; next_char != ']'; size += 1)
                {
                    array_value[size] = next_char;
                    next_char = fgetc(f);
                } 

                array_value[size] = '\0';
                printf("TOKEN_VALUE_ARRAY: [%s]\n", array_value);
                free(array_value);
            }
            else if (isdigit(current_char))
            {
                char *string_value = (char *)malloc(sizeof(char));
                assert(string_value);

                string_value[0] = current_char;

                int next_char = fgetc(f);
                int size = 1;

                for (; isdigit(next_char); size += 1)
                {
                    string_value[size] = next_char;
                    next_char = fgetc(f);
                }
                ungetc(next_char, f);

                string_value[size] = '\0';
                printf("TOKEN_VALUE_NUMBER: %s\n", string_value);
                free(string_value);
            }
            else
            {
                printf("%s\n", (const char *)get_token_name(current_char));
            }
        }
        current_char = fgetc(f);
    }
}

int main(int argc, char **argv)
{
    FILE *f = load_input_file(argc, argv); 

    traverse(f);

    return 0;
}
