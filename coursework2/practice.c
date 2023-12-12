#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MAX_TIME_SLOTS 100
#define BUFFER_SIZE 256

struct TimeSlot {
    char datetime[20];
    int steps;
};

void tokeniseRecord(const char *input, const char *delimiter, char *date, int *steps);

int main() {
    struct TimeSlot FITNESSDATA[MAX_TIME_SLOTS];
    char filename[BUFFER_SIZE];
    FILE *file = NULL;
    int count =0;
    while (1) {
        printf("Menu:\n");
        printf("A: Specify the filename to import\n");
        printf("B: Display the total number of records in the file\n");
        printf("C: Find the date and time of the time slot with the least steps\n");
        printf("Q: Quit\n");

        printf("Please enter your choice: ");
        char choice;
        scanf(" %c", &choice);

        switch (choice) {
            case 'A':
                printf("Input filename: ");
                scanf("%s", filename);
                file = fopen(filename, "r");
                if (file == NULL) {
                    perror("Error opening file");
                    return 1;
                }
                printf("File successfully loaded.\n");
                break;

            case 'B':
                if (file == NULL) {
                    printf("Please specify a filename first.\n");
                    break;
                }

                rewind(file);
                char line[BUFFER_SIZE];
                while (fgets(line, BUFFER_SIZE, file) != NULL) {
                    count++;
                }

                printf("Total number of records in the file: %d\n", count);
                break;

            case 'C':
                if (file == NULL) {
                    printf("Please specify a filename first.\n");
                    break;
                }

                rewind(file);
                int min_steps = INT_MAX;
                char min_steps_time[BUFFER_SIZE];
               
                while (fgets(min_steps_time, sizeof(min_steps_time), file)) {
                    char date[50], time[50];
                    int steps;
                    sscanf(min_steps_time, "%s %s %d", date, time, &steps);

                    if (steps < min_steps) {
                        min_steps = steps;
                        strcpy(min_steps_time, min_steps_time);  // Copy the entire line
                        count++;
                    }
                }

                if (count > 0) {
                    printf("Fewest steps: %d at %s\n", min_steps, min_steps_time);
                } else {
                    printf("No data found in the file.\n");
                }
                break;

            case 'Q':
                printf("Exiting program...\n");
                if (file != NULL) {
                    fclose(file);
                }
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}
