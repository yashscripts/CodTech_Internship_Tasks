#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to check if a word is a keyword
int isKeyword(char word[]) {
    char keywords[10][10] = {
        "int", "float", "if", "else", "while", "return", "for", "char", "double", "void"
    };

    for (int i = 0; i < 10; i++) {
        if (strcmp(word, keywords[i]) == 0) {
            return 1; // It's a keyword
        }
    }
    return 0; // Not a keyword
}

// Function to check if a character is an operator
int isOperator(char ch) {
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '=' || ch == '<' || ch == '>') {
        return 1;
    }
    return 0;
}

int main() {
    FILE *file;
    char ch, word[50];
    int i = 0;

    // Open the input file
    file = fopen("input.c", "r");

    if (file == NULL) {
        printf("File not found!\n");
        return 0;
    }

    printf("Lexical Analyzer Output:\n\n");

    // Read the file character by character
    while ((ch = fgetc(file)) != EOF) {
        // If it's a letter or number, add to the word
        if (isalnum(ch)) {
            word[i++] = ch;
        }
        else {
            // End of word
            word[i] = '\0';
            i = 0;

            // If word is not empty
            if (strlen(word) > 0) {
                if (isKeyword(word)) {
                    printf("%s --> Keyword\n", word);
                }
                else {
                    printf("%s --> Identifier\n", word);
                }
            }

            // Check for operator
            if (isOperator(ch)) {
                printf("%c --> Operator\n", ch);
            }
        }
    }

    fclose(file);
    return 0;
}
