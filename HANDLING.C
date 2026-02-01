#include <stdio.h>
#include <stdlib.h>

#define FILENAME "example_file.txt"

// Function Prototypes
void writeFile();
void appendFile();
void readFile();

int main() {
    int choice;

    while(1) {
        printf("\n--- FILE OPERATION MENU ---\n");
        printf("1. Create/Write to File (Overwrites existing)\n");
        printf("2. Append to File (Adds to end)\n");
        printf("3. Read File Content\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Clear input buffer to prevent fgets skipping input later
        while ((getchar()) != '\n');

        switch(choice) {
            case 1:
                writeFile();
                break;
            case 2:
                appendFile();
                break;
            case 3:
                readFile();
                break;
            case 4:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

// 1. CREATE / WRITE (Mode "w")
void writeFile() {
    FILE *fptr;
    char content[100];

    // "w" mode creates a new file or clears the existing one
    fptr = fopen(FILENAME, "w");

    if (fptr == NULL) {
        printf("Error opening file!\n");
        return;
    }

    printf("Enter text to write to the file: ");
    fgets(content, sizeof(content), stdin); // Reads a full line including spaces

    fprintf(fptr, "%s", content); // Writes the string to the file
    printf("Data written successfully.\n");

    fclose(fptr);
}

// 2. APPEND (Mode "a")
void appendFile() {
    FILE *fptr;
    char content[100];

    // "a" mode opens file to add data at the end. Creates file if missing.
    fptr = fopen(FILENAME, "a");

    if (fptr == NULL) {
        printf("Error opening file!\n");
        return;
    }

    printf("Enter text to append to the file: ");
    fgets(content, sizeof(content), stdin);

    fprintf(fptr, "%s", content);
    printf("Data appended successfully.\n");

    fclose(fptr);
}

// 3. READ (Mode "r")
void readFile() {
    FILE *fptr;
    char content[100];

    // "r" mode opens the file for reading only
    fptr = fopen(FILENAME, "r");

    if (fptr == NULL) {
        printf("Error: File does not exist yet. Try option 1 first.\n");
        return;
    }

    printf("\n--- File Contents ---\n");
    // Loop through the file line by line until the end
    while (fgets(content, sizeof(content), fptr) != NULL) {
        printf("%s", content);
    }
    printf("\n---------------------\n");

    fclose(fptr);
}