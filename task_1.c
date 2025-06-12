#include <stdio.h>

int main() {
    FILE *fp;
    char text1[100], text2[100];

    // 1. Write to file
    fp = fopen("codtech.txt", "w");
    if (fp == NULL) {
        printf("Error creating file.\n");
        return 1;
    }

    printf("Enter a word to write into the file:\n> ");
    scanf("%s", text1);  // Takes one word input
    fprintf(fp, "%s\n", text1);
    fclose(fp);
    printf("Text written to file.\n\n");

    // 2. Append to file
    fp = fopen("codtech.txt", "a");
    if (fp == NULL) {
        printf("Error opening file to append.\n");
        return 1;
    }

    printf("Enter a word to append:\n> ");
    scanf("%s", text2); // Takes one word input
    fprintf(fp, "%s\n", text2);
    fclose(fp);
    printf("Text appended to file.\n\n");

    // 3. Read from file
    fp = fopen("codtech.txt", "r");
    if (fp == NULL) {
        printf("Error reading file.\n");
        return 1;
    }

    char ch;
    printf("File content:\n");
    while ((ch = fgetc(fp)) != EOF) {
        putchar(ch);
    }
    fclose(fp);
    printf("File read complete.\n");

    return 0;
}
