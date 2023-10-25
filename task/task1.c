#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define an appropriate struct
typedef struct {
	char date[11];
	char time[6];
	int steps;
} FITNESS_DATA;
 char *inputCopy = strdup(input);
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
    FILE*file = fopen(FitnessData_2023.csv, "w");
    if (file == NULL) {
        perror("")
        return 1;
    }
    int buffer_size = 1000;
    char line_buffer[buffer_size];
    wile (fgete(line_buffer, buffer_size, file) ! = NULL) {
        printf("%s",line_buffer);
    }
    fclose(file);
    return0
}