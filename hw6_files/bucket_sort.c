// Name StudentID
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <limits.h>

#include "list.h"

// Opens a new file in read mode with the given file name
FILE *openFile(char *fileName)
{
	return NULL;
}

// Reads a single integer from file.
int readSizeFromFile(FILE *fp)
{
    return 0;
}

// Dynamically allocates an array of N integers, populates it from the file and returns it
int *readArrayFromFile(FILE *fp, int N)
{
    return NULL;
}

// Finds the minimum element
int min_element(int *arr, int N)
{
    return 0;
}

// Finds the maximum element
int max_element(int *arr, int N)
{
    return 0;
}

int bucket_index(int element, int min, int max, int N)
{
    return 0;
}



nodePT *putIntoBuckets(int *arr, int N)
{
    // Find the minimum and maximum elements in the array using the functions implemented


    // Dynamically allocate an array of linked lists representing the buckets

    // Initialize each bucket to NULL

    // For each element in the array, find the bucket index using the function implemented
    // and insert the element into the corresponding bucket


    // return the buckets array

    return NULL;
}

int *run_bucket_sort(char *fileName)
{
    // Call openFile to open a new file.

    // Call readSizeFromFile to read the size of the array.

    // Call readArrayFromFile to read the array from the file.

    // Call putIntoBuckets to put the elements of the array into buckets

    // Rewrite the original array with the elements from the buckets to get the sorted array

    // Destroy the buckets and the array containing them

    // Return the sorted array

    return NULL;
}
