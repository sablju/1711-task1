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
    int count = 0;
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
        
        switch(choice) {
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

                // Reset count to 0 before reading the file
                count = 0;

                // Rewind the file to the beginning
                rewind(file);

                while (fgets(line, sizeof(line), file) != NULL && count < MAX_TIME_SLOTS) {
                    char date[20];
                    int steps;
                    tokeniseRecord(line, ",", date, &steps);
                    snprintf(FITNESSDATA[count].datetime, sizeof(FITNESSDATA[count].datetime), "%s", date);
                    FITNESSDATA[count].steps = steps;
                    count++;
                }

                printf("Total number of records in the file: %d\n", count);
                break;
            case 'C':
                if (count > 0) {
                    int minSteps = INT_MAX;
                    char minTimeSlot[20] = "";

                    for (int i = 0; i < count; i++) {
                        if (FITNESSDATA[i].steps < minSteps) {
                            minSteps = FITNESSDATA[i].steps;
                            strcpy(minTimeSlot, FITNESSDATA[i].datetime);
                        }
                    }

                    if (minSteps != INT_MAX) {
                        printf("Fewest steps: %s with %d steps\n", minTimeSlot, minSteps);
                    } else {
                        printf("No data available.\n");
                    }
                } else {
                    printf("No data available.\n");
                }
                break;

            // Add other cases as needed

            case 'Q':
                if (file != NULL) {
                    fclose(file);
                }
                return 0;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}

