#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fitness_data_struct.h"  // Include your header file

void selectionSort(FITNESS_DATA records[], int numRecords);
void writeTSVFile(FITNESS_DATA records[], int numRecords, const char *filename);

int main() {
    char inputFilename[520];

    printf("输入文件名： ");
    fgets(inputFilename, sizeof(inputFilename), stdin);
    inputFilename[strcspn(inputFilename, "\n")] = 0; // Remove trailing newline

    FILE *inputFile = fopen(inputFilename, "r");
    if (!inputFile) {
        printf("无法打开文件: %s\n", inputFilename);
        return 1;
    }

    FITNESS_DATA records[100];
    int numRecords = 0;
    char line[520];

    while (fgets(line, sizeof(line), inputFile)) {
        tokeniseRecord(line, ",", records[numRecords].date, records[numRecords].time, &records[numRecords].steps);
        if(strlen(records[numRecords].date) > 0) numRecords++;
    }

    fclose(inputFile);

    selectionSort(records, numRecords);

    char outputFilename[520];
    snprintf(outputFilename, sizeof(outputFilename), "%s.tsv", inputFilename);
    writeTSVFile(records, numRecords, outputFilename);

    printf("Data sorted and written to %s\n", outputFilename);

    return 0;
}

void selectionSort(FITNESS_DATA records[], int numRecords) {
    for (int i = 0; i < numRecords - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < numRecords; j++)
            if (records[j].steps > records[minIndex].steps)
                minIndex = j;

        FITNESS_DATA temp = records[minIndex];
        records[minIndex] = records[i];
        records[i] = temp;
    }
}

void writeTSVFile(FITNESS_DATA records[], int numRecords, const char *filename) {
    FILE *outputFile = fopen(filename, "w");
    if (!outputFile) {
        perror("无法创建文件");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < numRecords; i++)
        fprintf(outputFile, "%s\t%s\t%d\n", records[i].date, records[i].time, records[i].steps);

    fclose(outputFile);
}
