// Name StudentID
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <limits.h>

#include "list.h"

// Opens a new file in read mode with the given file name
FILE *openFile(char *fileName)
{
    FILE *file = fopen(fileName, "r");
    if (file == NULL) {
        printf("Error opening file %s\n", fileName);
        exit(EXIT_FAILURE);
    }
    return file;
}

// Reads a single integer from file.
int readSizeFromFile(FILE *file)
{
    int size;
    fscanf(file, "%d", &size);
    return size;
}

// Dynamically allocates an array of N integers, populates it from the file and returns it
int *readArrayFromFile(FILE *file, int N)
{
    int *array = (int *)malloc(N * sizeof(int));
    if (array == NULL) 
    {
        //NOT SUPPOSED TO HAPPEN
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < N; i++) {
        fscanf(file, "%d", &array[i]);
    }

    return array;
}


// Finds the minimum element
int min_element(int *arr, int N)
{
    int min = INT_MAX;
    for (int i = 0; i < N; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

// Finds the maximum element
int max_element(int *arr, int N)
{
    int max = INT_MIN;
    for (int i = 0; i < N; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

int bucket_index(int element, int min, int max, int N)
{
    return (int)((element - min) / ((max - min) / N));
}



nodePT *putIntoBuckets(int *arr, int N)
{
    // Find the minimum and maximum elements in the array
    int min = min_element(arr, N);
    int max = max_element(arr, N);

    // Dynamically allocate an array of linked lists representing the buckets
    nodePT **buckets = (nodePT **)malloc(N * sizeof(nodePT *));
    if (buckets == NULL) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    // Initialize each bucket to NULL
    for (int i = 0; i < N; i++) {
        buckets[i] = NULL;
    }

    // For each element in the array, find the bucket index and insert the element into the corresponding bucket
    for (int i = 0; i < N; i++) {
        int index = bucket_index(arr[i], min, max, N);
        buckets[index] = insert(buckets[index], arr[i]);
    }

    return buckets;
}

int *run_bucket_sort(char *fileName)
{
    // Open the file
    FILE *fp = openFile(fileName);

    // Read the size of the array from the file
    int N = readSizeFromFile(fp);

    // Read the array from the file
    int *arr = readArrayFromFile(fp, N);

    // Put the elements of the array into buckets
    nodePT *buckets = putIntoBuckets(arr, N);

    // Rewrite the original array with the elements from the buckets to get the sorted array
    int k = 0;
    for (int i = 0; i < N; i++) {
        nodePT current = buckets[i];
        while (current != NULL) {
            arr[k++] = current->data;
            current = current->next;
        }
    }

    // Destroy the buckets and the array containing them
    // Add your code here to free memory allocated for buckets

    // Close the file
    fclose(fp);

    // Return the sorted array
    return arr;
}
