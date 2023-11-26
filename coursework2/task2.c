#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FitnessDataStruct.h"

// Struct moved to header file

// Define any additional variables here
// Global variables for filename and FITNESS_DATA array


// This is your helper function. Do not change it in any way.
// Inputs: character array representing a row; the delimiter character
// Ouputs: date character array; time character array; steps character array
void tokeniseRecord(const char *input, const char *delimiter,
                    char *date, char *time, char *steps) {
    // Create a copy of the input string as strtok modifies the string
    char *inputCopy = strdup(input);
    
    // Tokenize the copied string
    char *token = strtok(inputCopy, delimiter);
    if (token != NULL) {        strcpy(date, token);
    }
    
    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(time, token);
    }
    
    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(steps, token);
    }
    
    // Free the duplicated string
    free(inputCopy);

                    }


// Complete the main function
typedef int Record;

int main() {  
    typedef struct {
        time_t start;
        time_t end;
        int steps;
    } TimeSlot; 
    
    char choice;
    char filename[200];
    int count = 0;
    float mean = 0; 
    int total_steps = 0;
    int a;
    int record;
    FILE *file;
    
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
                printf("Input filenmae: ");
                scanf("%s", filename);
                printf("File sucessfully loaded.\n");

                file = fopen(filename, "r");
                if (file == NULL) {
                     perror("");
                    return 1;
                }
                break;
            case 'B':                
                while((a = fscanf(file,"%d",&record)) != EOF) {
                    if (a == '\n') {
                        count++;
                        total_steps += record;
                    }
                }
                printf("Total number of records in the file: %d\n", count); 
                break;
            case 'C':
            
                break;
            case 'D':
                printf("Date and time of the time slot with the most steps\n");
                // Add code to find the date and time of the time slot with the most steps
                break;
            case 'E':
                printf("Average number of steps in all records: %.2f\n", mean);
                break;
            case 'F':
                printf("Longest continuous period with steps over 500\n");
                // Add code to find the longest continuous period with steps over 500
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