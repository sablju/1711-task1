#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MAX_TIME_SLOTS 100
#define buffer_size 256

// Define an appropriate struct
struct TimeSlot {
    char datetime[20];
    int steps;
};

// Helper function prototype
void tokeniseRecord(const char *input, const char *delimiter, char *date, int *steps);

int main() {
    // Declare an array of struct TimeSlot
    struct TimeSlot FITNESSDATA[MAX_TIME_SLOTS];
    char choice;
    char filename[buffer_size];
    FILE *file = NULL;
    char line[buffer_size];

    while (1) {
        printf("Menu:\n");
        printf("A: Specify the filename to import\n");
        printf("B: Display the total number of records in the file\n");
        printf("C: Find the date and time of the time slot with the least steps\n");
        printf("D: Find the date and time of the time slot with the most steps\n");
        printf("E: Find the average number of steps in all records\n");
        printf("F: Find the longest continuous period with steps over 500\n");
        printf("Q: Quit\n");

        printf("Please enter your choice: ");
        scanf(" %c", &choice);

        switch (choice) {
            case 'A':
                printf("Input filename: ");
                scanf("%s", filename);
                printf("File successfully loaded.\n");

                file = fopen(filename, "r");
                if (file == NULL) {
                    perror("Error opening file");
                    return 1;
                }
                break;

            case 'B':
                if (file == NULL) {
                    printf("Please specify a filename first.\n");
                    break;
                }

                int count = 0;  // Initialize count
                while (fgets(line, buffer_size, file) != NULL) {
                    count++;
                }

                printf("Total number of records in the file: %d\n", count);
                break;

            case 'C':
               if (file == NULL) {
                    printf("Please specify a filename first.\n");
                    break;
                }

                rewind(file);  // Rewind the file to the beginning
                int min_steps = 9999;
                char min_steps_time[100];

                // Initialize count to 0
                int count = 0;

                while (fgets(line, 100, file)) {
                    char date[50], time[50];
                    int steps;
                    sscanf(line, "%s %s %d", date, time, &steps);

                    for (int a = 0; a < count; a++) {
                        if (steps < min_steps) {
                            min_steps = steps;
                            sprintf(min_steps_time, "%s %s", date, time);
                        }
                    }

                    count++;  // Increment count for each line
                }
                printf("Fewest steps:%s\n", min_steps_time);
                break;
