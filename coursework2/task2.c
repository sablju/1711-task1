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
int main() {
   printf("Menu:\n");
    printf("A: Specify the filename to import\n");
    printf("B: Display the total number of records in the file\n");
    printf("C: Find the date and time of the time slot with the least steps\n");
    printf("D: Find the date and time of the time slot with the most steps\n");
    printf("E: Find the average number of steps in all records\n");
    printf("F: Find the longest continuous period with steps over 500\n");
    printf("Q: Quit\n");
  
  int letter;
  printf("Enter the letter:\n");
  scanf("%d",&letter);
  switch (letter)
  {
    case A: printf ()
  }
}