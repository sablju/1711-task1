#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char date[11];
    char time[9]; // Adjusted to accommodate seconds (HH:mm:ss)
    int steps;
} FitnessData;

void tokeniseRecord(char *record, char delimiter, char *date, char *time, int *steps);
void selectionSort(FitnessData records[], int numRecords);
void writeTSVFile(FitnessData records[], int numRecords, const char *filename);

int main() {
    char inputFilename[520];

    printf("输入文件名： ");
    fgets(inputFilename, sizeof(inputFilename), stdin);
    inputFilename[strcspn(inputFilename, "\n")] = 0; // Remove trailing newline
    getchar();  // Consume the newline character from the buffer

    FILE *inputFile = fopen(inputFilename, "r");
    if (!inputFile) {
        printf("无法打开文件: %s\n", inputFilename);
        return 1;
    }

    FitnessData records[100];
    int numRecords = 0;
    char line[520];

    while (fgets(line, sizeof(line), inputFile)) {
        tokeniseRecord(line, ',', records[numRecords].date, records[numRecords].time, &records[numRecords].steps);
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

void tokeniseRecord(char *record, char delimiter, char *date, char *time, int *steps) {
    char *ptr = strtok(record, &delimiter);
    if (ptr) {
        strcpy(date, ptr);
    } else {
        *date = '\0';
    }
    ptr = strtok(NULL, &delimiter);
    if (ptr) {
        strcpy(time, ptr);
    } else {
        *time = '\0';
    }
    ptr = strtok(NULL, &delimiter);
    if (ptr) {
        *steps = atoi(ptr);
    } else {
        *steps = 0;
    }
}

void selectionSort(FitnessData records[], int numRecords) {
    for (int i = 0; i < numRecords - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < numRecords; j++)
            if (records[j].steps > records[minIndex].steps)
                minIndex = j;

        FitnessData temp = records[minIndex];
        records[minIndex] = records[i];
        records[i] = temp;
    }
}

void writeTSVFile(FitnessData records[], int numRecords, const char *filename) {
    FILE *outputFile = fopen(filename, "w");
    if (!outputFile) {
        perror("无法创建文件");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < numRecords; i++)
        fprintf(outputFile, "%s\t%s\t%d\n", records[i].date, records[i].time, records[i].steps);

    fclose(outputFile);
}
