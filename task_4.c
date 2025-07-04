// Task 4: Run-Length Encoding in C
// Name: Yash
// Internship: CodTech

#include <stdio.h>

int main() {
    FILE *inputFile, *outputFile;
    char currentChar, previousChar;
    int count = 1;

    inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("❌ Error: input.txt not found!\n");
        return 1;
    }

    outputFile = fopen("compressed.txt", "w");
    if (outputFile == NULL) {
        printf("❌ Error: Cannot create compressed.txt!\n");
        fclose(inputFile);
        return 1;
    }

    // Read the first character and check for empty file
    previousChar = fgetc(inputFile);
    if (previousChar == EOF) {
        printf("⚠️ input.txt is empty. Nothing to compress.\n");
        fprintf(outputFile, ""); // leave file empty
        fclose(inputFile);
        fclose(outputFile);
        return 0;
    }

    // Loop through the file
    while ((currentChar = fgetc(inputFile)) != EOF) {
        if (currentChar == previousChar) {
            count++;
        } else {
            fprintf(outputFile, "%c%d", previousChar, count);
            previousChar = currentChar;
            count = 1;
        }
    }

    // Write the last character
    fprintf(outputFile, "%c%d", previousChar, count);

    printf("✅ Compression complete. Check compressed.txt\n");

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}
