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
int readSizeFromFile(FILE *fp)
{
    int size;
    fscanf(fp, "%d", &size);
    return size;
}

// Dynamically allocates an array of N integers, populates it from the file and returns it
int *readArrayFromFile(FILE *fp, int N)
{
    int *array = (int *)malloc(N * sizeof(int));
    if (array == NULL) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < N; i++) {
        fscanf(fp, "%d", &array[i]);
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

int bucket_index(int x, int min, int max, int num_buckets)
{
    // Handle special case where max and min are equal
    if (max == min) {
        return 0;
    }

    // Calculate the range of each bucket
    double range = (double)(max - min + 1) / num_buckets;

    // Calculate the index of the bucket that x belongs to
    int index = (int)((x - min) / range);

    // Make sure index is within the range [0, num_buckets - 1]
    if (index < 0) {
        index = 0;
    } else if (index >= num_buckets) {
        index = num_buckets - 1;
    }

    return index;
}


nodePT *putIntoBuckets(int *arr, int N)
{
    // Find the minimum and maximum elements in the array
    int min = min_element(arr, N);
    int max = max_element(arr, N);

    // Dynamically allocate an array of linked lists representing the buckets
    nodePT *buckets = (nodePT *)malloc(N * sizeof(nodePT));
    if (buckets == NULL) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    // Initialize each bucket to NULL
    for (int i = 0; i < N; i++) {
        buckets[i] = NULL;
    }

    // For each element in the array, find the bucket index using the function implemented
    // and insert the element into the corresponding bucket
    for (int i = 0; i < N; i++) {
        int index = bucket_index(arr[i], min, max, N); // Fixed the use of N here
        struct node *new_node = (struct node *)malloc(sizeof(struct node));
        new_node->data = arr[i];
        new_node->next = buckets[index];
        buckets[index] = new_node;
    }

    return buckets;
}

int *run_bucket_sort(char *fileName)
{
    // Call openFile to open a new file.
    FILE *fp = openFile(fileName);

    // Call readSizeFromFile to read the size of the array.
    int N = readSizeFromFile(fp);

    // Call readArrayFromFile to read the array from the file.
    int *arr = readArrayFromFile(fp, N);

    // Put the elements of the array into buckets
    nodePT *buckets = putIntoBuckets(arr, N); // Fixed the use of N here

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
    for (int i = 0; i < N; i++) {
        destroy_list(buckets[i]);
    }
    free(buckets);

    // Close the file
    fclose(fp);

    // Return the sorted array
    return arr;
}

/*
RUNNING TEST: test_bucket_index_dex1
ERROR: main.c:272 expected testArr[i], actual: index_computed[i]
.............Bucket index computed incorrectly.
============================================================
RUNNING TEST: test_bucket_index_neg1
============================================================
RUNNING TEST: test_buckets_data1
ERROR: main.c:345 assertion failed: "linkedListsEqual(expected_bucket_list, buckets[i])"
============================================================
RUNNING TEST: test_buckets_data1_rev
============================================================
RUNNING TEST: test_buckets_neg1
ERROR: main.c:415 assertion failed: "linkedListsEqual(expected_bucket_list, buckets[i])"
============================================================
RUNNING TEST: test_sorting_data1
ERROR: main.c:455 expected arr[i], actual: test_sorted[i]
============================================================
RUNNING TEST: test_sorting_data1_rev
============================================================
RUNNING TEST: test_sorting_dex1
ERROR: main.c:498 expected arr[i], actual: test_sorted[i]
============================================================
RUNNING TEST: test_sorting_neg1
ERROR: main.c:519 expected arr[i], actual: test_sorted[i]
============================================================
RUNNING TEST: test_sorting_data2
ERROR: main.c:540 expected arr[i], actual: test_sorted[i]
============================================================
x.x.xx.xxx
OK: 16 FAILED: 7



*/