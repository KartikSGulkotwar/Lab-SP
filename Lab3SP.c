
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void insertionSort_(char** arr, int n) {
    int i, j;
    char* key;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && strcmp(arr[j], key) > 0) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void printArray_(char** arr, int n) {
    int i;
    for (i = 0; i < n; i++)
        printf("%s\n", arr[i]);
}

void readStrings_(char** arr, int n) {
    char bufferr[101];
    int i;
    
    for ( i = 0; i < n; i++) {
        printf("PLease enter string %d: ", i + 1);
        scanf("%100s", bufferr);
        arr[i] = (char*)malloc(strlen(bufferr) + 1);
        strcpy(arr[i], bufferr);
    }
}

int main() {
    int n, i;
    printf("Please enter the number of strings: ");
    scanf("%d", &n);

    char** arr = (char**)malloc(n * sizeof(char*));

    readStrings_(arr, n);

    printf("\nUnsorted Array:\n");
    printArray_(arr, n);

    insertionSort_(arr, n);

    printf("\nSorted Array:\n");
    printArray_(arr, n);

    // To free the allocated memory
    for (i = 0; i < n; i++)
        free(arr[i]);
    free(arr);

    return 0;
}
