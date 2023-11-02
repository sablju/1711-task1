#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define an appropriate struct
typedef struct {
	char date[11];
	char time[6];
	int steps;
} FITNESS_DATA;

// Define any additional variables here



// This is your helper function. Do not change it in any way.
// Inputs: character array representing a row; the delimiter character
// Ouputs: date character array; time character array; steps character array
void tokeniseRecord(const char *input, const char *delimiter,
                    char *date, char *time, int *steps) {
    // Create a copy of the input string as strtok modifies the string
    char *inputCopy = strdup(input);
    
    // Tokenize the copied string
    char *token = strtok(inputCopy, delimiter);
    if (token != NULL) {        
        strcpy(date, token);
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
    char record[21] = "2023-09-01,07:30,300";
    char date[11];
    char time[6];
    int steps[10];  // Large enough to hold a typical step count as a string

int stepsint;
    char filename[] = "FitnessData_2023.csv";
    FILE*file = fopen(filename,"r");
    if (file == NULL)  {
        perror("");
        return 1;
    }
    
    int buffer_size = 1024;
    char line_buffer[buffer_size];
     int line_count = 0;
while (fgets(line_buffer, buffer_size, file) != NULL) {
    if (line_count >= 3) {
        break;
    }
    tokeniseRecord(line_buffer, ",", date, time, steps);
    printf("%s/%s/%s", date, time, steps);
    line_count++;
}
    fclose(file);
    return 0;

    FILE *fp = fopen("output.txt", "w");
    if (file == NULL) {
        perror("");
        return 1;
    }

    int number, num_lines = 3;
    printf("Type %d numbers: ", num_lines);
    for (int i = 0; i < num_lines; i++) {
        scanf("%d", &number);
        fprintf(file, "%d\n", number);
    }

    fclose(file);
    return 0;
}

