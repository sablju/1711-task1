#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MAX_TIME_SLOTS 1000
#define BUFFER_SIZE 256

struct TimeSlot {
    char date[11]; // YYYY-MM-DD
    char time[6];  // HH:MM
    int steps;
};

int main() {
    struct TimeSlot FITNESSDATA[MAX_TIME_SLOTS];
    char filename[BUFFER_SIZE];
    FILE *file = NULL;
    int count = 0;
    char line[BUFFER_SIZE];

    while (1) {
        printf("Menu:\n");
        printf("A: Specify the filename to import\n");
        printf("B: Display the total number of records in the file\n");
        printf("C: Find the date and time of the time slot with the least steps\n");
        printf("D: Find the date and time of the time slot with the most steps\n");
        printf("E: Display the average number of steps\n");
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
                count = 0;
                while (fgets(line, BUFFER_SIZE, file) != NULL) {
                    sscanf(line, "%[^,],%[^,],%d", FITNESSDATA[count].date, FITNESSDATA[count].time, &FITNESSDATA[count].steps);
                    count++;
                    if (count >= MAX_TIME_SLOTS) {
                        break;
                    }
                }
                fclose(file);
                printf("File successfully loaded.\n");
                break;

            case 'B':
                printf("Total number of records in the file: %d\n", count);
                break;

            case 'C':
                if (count == 0) {
                    printf("No data available. Please load a file first.\n");
                    break;
                }
                int min_steps = INT_MAX;
                int min_index = -1;
                for (int i = 0; i < count; i++) {
                    if (FITNESSDATA[i].steps < min_steps) {
                        min_steps = FITNESSDATA[i].steps;
                        min_index = i;
                    }
                }
                if (min_index != -1) {
                    printf("%s,%s，%d\n", FITNESSDATA[min_index].date, FITNESSDATA[min_index].time, min_steps);
                } else {
                    printf("No data found.\n");
                }
                break;

            case 'D':
                if (count == 0) {
                    printf("No data available. Please load a file first.\n");
                    break;
                }
                int max_steps = INT_MIN;
                int max_index = -1;
                for (int i = 0; i < count; i++) {
                    if (FITNESSDATA[i].steps > max_steps) {
                        max_steps = FITNESSDATA[i].steps;
                        max_index = i;
                    }
                } 
                if (max_index != -1) {
                    printf("%s,%s，%d\n", FITNESSDATA[max_index].date, FITNESSDATA[max_index].time, max_steps);
                } else {
                    printf("No data found.\n");
                }
                break;

            case 'E':
                if (count == 0) {
                    printf("No data available. Please load a file first.\n");
                    break;
                }
                int total_steps = 0;
                for (int i = 0; i < count; i++) {
                    total_steps += FITNESSDATA[i].steps;
                }
                double average_steps = (double)total_steps / count;
                printf("Average steps: %.2f\n", average_steps);
                break;

            case 'Q':
                printf("Exiting program...\n");
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }
    return 0;
}
