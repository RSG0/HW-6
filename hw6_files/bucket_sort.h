#ifndef BUCKET_SORT_H
#define	BUCKET_SORT_H

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <limits.h>

#include "list.h"

FILE *openFile(char *fileName);
int readSizeFromFile(FILE *fp);
int *readArrayFromFile(FILE *fp, int N);
int min_element(int *arr, int N);
int max_element(int *arr, int N);
int bucket_index(int element, int min, int max, int N);
int *run_bucket_sort(char *fileName);
nodePT *putIntoBuckets(int *arr, int N);

#endif    /* BUCKET_SORT_H */