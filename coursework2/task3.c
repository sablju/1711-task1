#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the struct for the fitness data
typedef struct {
    char date[11];
    char time[6];
    int steps;
} FitnessData;

// Function to tokenize a record
void tokeniseRecord(char *record, char delimiter, char *date, char *time, int *steps) {
    char *ptr = strtok(record, &delimiter);
    if (ptr != NULL) {
        strcpy(date, ptr);
        ptr = strtok(NULL, &delimiter);
        if (ptr != NULL) {
            strcpy(time, ptr);
            ptr = strtok(NULL, &delimiter);
            if (ptr != NULL) {
                *steps = atoi(ptr);
            }
        }
    }
}

// Function to write records to a .tsv file
void writeTSVFile(FitnessData records[], int numRecords, const char *filename) {
    FILE *outputFile = fopen(filename, "w");

    if (outputFile == NULL) {
        perror("无法创建文件");
        exit(EXIT_FAILURE);
    }

    fprintf(outputFile, "Date\tTime\tSteps\n");

    for (int i = 0; i < numRecords; i++) {
        fprintf(outputFile, "%s\t%s\t%d\n", records[i].date, records[i].time, records[i].steps);
    }

    fclose(outputFile);
}

// Function to perform selection sort on fitness data
void selectionSort(FitnessData records[], int numRecords) {
    int i, j, minIndex;
    FitnessData temp;

    for (i = 0; i < numRecords - 1; i++) {
        minIndex = i;

        for (j = i + 1; j < numRecords; j++) {
            if (records[j].steps > records[minIndex].steps) {
                minIndex = j;
            }
        }

        temp = records[minIndex];
        records[minIndex] = records[i];
        records[i] = temp;
    }
}

int main() {
    int numRecords = sizeof(records) / sizeof(records[0]);

    // 排序数据
    selectionSort(records, numRecords);

    // 输出排序后的数据到文件
    writeTSVFile(records, numRecords, "sorted_fitness_data.tsv");

    printf("Data sorted and written to sorted_fitness_data.tsv\n");

    return 0;
}
