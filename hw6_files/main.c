#include "tinytest.h"
#include "bucket_sort.h"
#include <stdio.h>
#include <string.h>


int tinytest_setup(const char *pName)
{
    fprintf( stderr, "RUNNING TEST: %s\n", pName);
    return 0;
}

int tinytest_teardown(const char *pName)
{
    for(int i = 0; i < 60; i++)
        fprintf(stderr, "=");
    fprintf(stderr, "\n");
    return 0;
}

int test_open_data1()
{
    FILE *fp = openFile("data1.txt");
    TINYTEST_ASSERT_MSG(fp != NULL, "File failed to open.\n");
    int N = readSizeFromFile(fp);
    TINYTEST_EQUAL_MSG(6, N, "Invalid size read.");
    int *arr = readArrayFromFile(fp, N);
    fclose(fp);
    TINYTEST_ASSERT_MSG(arr != NULL, "Returned array is NULL\n");
    int testArr[6] = {9, 1, 7, 5, 8, 2};
    for(int i = 0; i < 6; i++)
    {
        TINYTEST_EQUAL_MSG(testArr[i], arr[i], "Array read incorrectly.\n");
    }
    free(arr);
    return 1;
}

int test_open_data2()
{
    FILE *fp = openFile("data2.txt");
    TINYTEST_ASSERT_MSG(fp != NULL, "File failed to open.\n");
    int N = readSizeFromFile(fp);
    TINYTEST_EQUAL_MSG(6, N, "Invalid size read.");
    int *arr = readArrayFromFile(fp, N);
    fclose(fp);
    TINYTEST_ASSERT_MSG(arr != NULL, "Returned array is NULL\n");
    int testArr[6] = {9, 2, 7, 5, 8, 1};
    for(int i = 0; i < 6; i++)
    {
        TINYTEST_EQUAL_MSG(testArr[i], arr[i], "Array read incorrectly.\n");
    }
    free(arr);
    return 1;
}

int test_open_dex1()
{
    FILE *fp = openFile("dex1.txt");
    TINYTEST_ASSERT_MSG(fp != NULL, "File failed to open.\n");
    int N = readSizeFromFile(fp);
    TINYTEST_EQUAL_MSG(4, N, "Invalid size read.");
    int *arr = readArrayFromFile(fp, N);
    fclose(fp);
    TINYTEST_ASSERT_MSG(arr != NULL, "Returned array is NULL\n");
    int testArr[4] = {2147483646, 2147483647, -2147483648, -2147483647};
    for(int i = 0; i < 4; i++)
    {
        TINYTEST_EQUAL_MSG(testArr[i], arr[i], "Array read incorrectly.\n");
    }
    free(arr);
    return 1;
}

int test_min()
{
    int arr1[5] = {-1, 3, -123, 2, 1};
    int min_computed = min_element(arr1, 5);
    TINYTEST_EQUAL(-123, min_computed);
    int arr2[7] = {5128, 34244, 232, 111, 5, 0, 5128};
    min_computed = min_element(arr2, 7);
    TINYTEST_EQUAL(0, min_computed);
    return 1;
}

int test_max()
{
    int arr1[6] = {4, 2, 1, 0, 9, 100};
    int max_computed = max_element(arr1, 6);
    TINYTEST_EQUAL(100, max_computed);
    int arr2[4] = {-2, -3, -4, -5};
    max_computed = max_element(arr2, 4);
    TINYTEST_EQUAL(-2, max_computed);
    return 1;
}

int test_min_max_data1()
{
    FILE *fp = openFile("data1.txt");
    TINYTEST_ASSERT(fp != NULL);
    int N = readSizeFromFile(fp);
    TINYTEST_ASSERT(N);
    int *arr = readArrayFromFile(fp, N);
    TINYTEST_ASSERT(arr);
    fclose(fp);
    int min_computed = min_element(arr, N);
    int max_computed = max_element(arr, N);
    TINYTEST_EQUAL(1, min_computed);
    TINYTEST_EQUAL(9, max_computed);
    free(arr);
    return 1;
}

int test_min_max_data1_rev()
{
    FILE *fp = openFile("data1_rev.txt");
    TINYTEST_ASSERT(fp != NULL);
    int N = readSizeFromFile(fp);
    TINYTEST_EQUAL(6, N);
    int *arr = readArrayFromFile(fp, N);
    TINYTEST_ASSERT(arr);
    fclose(fp);
    int min_computed = min_element(arr, N);
    int max_computed = max_element(arr, N);
    TINYTEST_EQUAL(1, min_computed);
    TINYTEST_EQUAL(9, max_computed);
    free(arr);
    return 1;
}

int test_min_max_dex1()
{
    FILE *fp = openFile("dex1.txt");
    TINYTEST_ASSERT(fp != NULL);
    int N = readSizeFromFile(fp);
    TINYTEST_EQUAL(4, N);
    int *arr = readArrayFromFile(fp, N);
    TINYTEST_ASSERT(arr);
    fclose(fp);
    int min_computed = min_element(arr, N);
    int max_computed = max_element(arr, N);
    TINYTEST_EQUAL(-2147483648, min_computed);
    TINYTEST_EQUAL(2147483647, max_computed);
    free(arr);
    return 1;
}

int test_min_max_data2()
{
    FILE *fp = openFile("data2.txt");
    TINYTEST_ASSERT(fp != NULL);
    int N = readSizeFromFile(fp);
    TINYTEST_EQUAL(6, N);
    int *arr = readArrayFromFile(fp, N);
    TINYTEST_ASSERT(arr);
    fclose(fp);
    int min_computed = min_element(arr, N);
    int max_computed = max_element(arr, N);
    TINYTEST_EQUAL(1, min_computed);
    TINYTEST_EQUAL(9, max_computed);
    free(arr);
    return 1;
}

int test_min_max_neg1()
{
    FILE *fp = openFile("neg1.txt");
    TINYTEST_ASSERT(fp != NULL);
    int N = readSizeFromFile(fp);
    TINYTEST_EQUAL(5, N);
    int *arr = readArrayFromFile(fp, N);
    TINYTEST_ASSERT(arr);
    fclose(fp);
    int min_computed = min_element(arr, N);
    int max_computed = max_element(arr, N);
    TINYTEST_EQUAL(-10, min_computed);
    TINYTEST_EQUAL(90, max_computed);
    free(arr);
    return 1;
}

int test_bucket_index_data1()
{
    FILE *fp = openFile("data1.txt");
    TINYTEST_ASSERT(fp);
    int N = readSizeFromFile(fp);
    int *arr = readArrayFromFile(fp, N);
    TINYTEST_ASSERT(arr);
    fclose(fp);
    int min_computed = min_element(arr, N);
    int max_computed = max_element(arr, N);
    int index_computed[6];
    for(int i = 0; i < 6; i++)
    {
        index_computed[i] = bucket_index(arr[i], min_computed, max_computed, 6);
    }
    int testArr[6] = {5, 0, 4, 2, 4, 0};
    for(int i = 0; i < 6; i++)
    {
        TINYTEST_EQUAL_MSG(testArr[i], index_computed[i], "Bucket index computed incorrectly.\n");
    }
    free(arr);
    return 1;
}

int test_bucket_index_data1_rev()
{
    FILE *fp = openFile("data1_rev.txt");
    TINYTEST_ASSERT(fp);
    int N = readSizeFromFile(fp);
    int *arr = readArrayFromFile(fp, N);
    TINYTEST_ASSERT(arr);
    fclose(fp);
    int min_computed = min_element(arr, N);
    int max_computed = max_element(arr, N);
    int index_computed[6];
    for(int i = 0; i < 6; i++)
    {
        index_computed[i] = bucket_index(arr[i], min_computed, max_computed, 6);
    }
    int testArr[6] = {5, 0, 4, 2, 4, 0};
    for(int i = 0; i < 6; i++)
    {
        TINYTEST_EQUAL_MSG(testArr[5 - i], index_computed[i], "Bucket index computed incorrectly.\n");
    }
    free(arr);
    return 1;
}

int test_bucket_index_data2()
{
    FILE *fp = openFile("data2.txt");
    TINYTEST_ASSERT(fp);
    int N = readSizeFromFile(fp);
    int *arr = readArrayFromFile(fp, N);
    TINYTEST_ASSERT(arr);
    fclose(fp);
    int min_computed = min_element(arr, N);
    int max_computed = max_element(arr, N);
    int index_computed[6];
    for(int i = 0; i < 6; i++)
    {
        index_computed[i] = bucket_index(arr[i], min_computed, max_computed, 6);
    }
    int testArr[6] = {5, 0, 4, 2, 4, 0};
    for(int i = 0; i < 6; i++)
    {
        TINYTEST_EQUAL_MSG(testArr[i], index_computed[i], "Bucket index computed incorrectly.\n");
    }
    free(arr);
    return 1;
}

int test_bucket_index_dex1()
{
    FILE *fp = openFile("dex1.txt");
    TINYTEST_ASSERT(fp);
    int N = readSizeFromFile(fp);
    int *arr = readArrayFromFile(fp, N);
    TINYTEST_ASSERT(arr);
    fclose(fp);
    int min_computed = min_element(arr, N);
    int max_computed = max_element(arr, N);
    int index_computed[4];
    for(int i = 0; i < 4; i++)
    {
        index_computed[i] = bucket_index(arr[i], min_computed, max_computed, 4);
    }
    int testArr[4] = {3, 3, 0, 0};
    for(int i = 0; i < 4; i++)
    {
        TINYTEST_EQUAL_MSG(testArr[i], index_computed[i], "Bucket index computed incorrectly.\n");
    }
    free(arr);
    return 1;
}

int test_bucket_index_neg1()
{
    FILE *fp = openFile("neg1.txt");
    TINYTEST_ASSERT(fp);
    int N = readSizeFromFile(fp);
    int *arr = readArrayFromFile(fp, N);
    TINYTEST_ASSERT(arr);
    fclose(fp);
    int min_computed = min_element(arr, N);
    int max_computed = max_element(arr, N);
    int index_computed[5];
    for(int i = 0; i < 5; i++)
    {
        index_computed[i] = bucket_index(arr[i], min_computed, max_computed, 5);
    }
    int testArr[5] = {0, 0, 4, 0, 2};
    for(int i = 0; i < 5; i++)
    {
        TINYTEST_EQUAL_MSG(testArr[i], index_computed[i], "Bucket index computed incorrectly.\n");
    }
    free(arr);
    return 1;
}

int linkedListsEqual(nodePT head1, nodePT head2)
{
    nodePT curr1 = head1;
    nodePT curr2 = head2;
    while(curr1 != NULL && curr2 != NULL)
    {
        if(curr1->data != curr2->data)
        {
            return 0;
        }
        curr1 = curr1->next;
        curr2 = curr2->next;
    }
    if(curr1 != NULL || curr2 != NULL)
    {
        return 0;
    }
    return 1;
}

int test_buckets_data1()
{
    FILE *fp = openFile("data1.txt");
    TINYTEST_ASSERT(fp);
    int N = readSizeFromFile(fp);
    int *arr = readArrayFromFile(fp, N);
    TINYTEST_EQUAL(6, N);
    TINYTEST_ASSERT(arr);
    fclose(fp);
    nodePT *buckets = putIntoBuckets(arr, N);
    TINYTEST_ASSERT(buckets);
    int buckets_arr[][6] = {
        {1, 2},
        {},
        {5},
        {},
        {7, 8},
        {9}
    };
    int sizes[] = {2, 0, 1, 0, 2, 1};
    for(int i = 0; i < N; i++)
    {
        nodePT expected_bucket_list = array_2_list(buckets_arr[i], sizes[i]);
        TINYTEST_ASSERT(linkedListsEqual(expected_bucket_list, buckets[i]));
        destroy_list(expected_bucket_list);
    }
    free(arr);
    for(int i = 0; i < N; i++)
    {
        destroy_list(buckets[i]);
    }
    free(buckets);
    return 1;
}

int test_buckets_data1_rev()
{
    FILE *fp = openFile("data1_rev.txt");
    TINYTEST_ASSERT(fp);
    int N = readSizeFromFile(fp);
    int *arr = readArrayFromFile(fp, N);
    TINYTEST_EQUAL(6, N);
    TINYTEST_ASSERT(arr);
    fclose(fp);
    nodePT *buckets = putIntoBuckets(arr, N);
    TINYTEST_ASSERT(buckets);
    int buckets_arr[][6] = {
        {1, 2},
        {},
        {5},
        {},
        {7, 8},
        {9}
    };
    int sizes[] = {2, 0, 1, 0, 2, 1};
    for(int i = 0; i < N; i++)
    {
        nodePT expected_bucket_list = array_2_list(buckets_arr[i], sizes[i]);
        TINYTEST_ASSERT(linkedListsEqual(expected_bucket_list, buckets[i]));
        destroy_list(expected_bucket_list);
    }
    free(arr);
    for(int i = 0; i < N; i++)
    {
        destroy_list(buckets[i]);
    }
    free(buckets);
    return 1;
}

int test_buckets_neg1()
{
    FILE *fp = openFile("neg1.txt");
    TINYTEST_ASSERT(fp);
    int N = readSizeFromFile(fp);
    int *arr = readArrayFromFile(fp, N);
    TINYTEST_EQUAL(5, N);
    TINYTEST_ASSERT(arr);
    fclose(fp);
    nodePT *buckets = putIntoBuckets(arr, N);
    TINYTEST_ASSERT(buckets);
    int buckets_arr[][5] = {
        {-10, -4, 7},
        {},
        {50},
        {},
        {90}
    };

    int sizes[] = {3, 0, 1, 0, 1};
    for(int i = 0; i < N; i++)
    {
        nodePT expected_bucket_list = array_2_list(buckets_arr[i], sizes[i]);
        TINYTEST_ASSERT(linkedListsEqual(expected_bucket_list, buckets[i]));
        destroy_list(expected_bucket_list);
    }
    free(arr);
    for(int i = 0; i < N; i++)
    {
        destroy_list(buckets[i]);
    }
    free(buckets);
    return 1;
}

int compare_int(const void *a, const void *b)
{
    int arg1 = *(const int*)a;
    int arg2 = *(const int*)b;
 
    if (arg1 < arg2)
        return -1;
    else if (arg1 > arg2)
        return 1;
    else
        return 0;
}

// Compare against glibc qsort
int test_sorting_data1()
{
    FILE *fp = openFile("data1.txt");
    TINYTEST_ASSERT(fp);
    int N = readSizeFromFile(fp);
    TINYTEST_EQUAL(6, N);
    int *arr = readArrayFromFile(fp, N);
    TINYTEST_ASSERT(arr);
    fclose(fp);
    qsort(arr, N, sizeof(int), compare_int);
    int *test_sorted = run_bucket_sort("data1.txt");
    TINYTEST_ASSERT(test_sorted);
    for(int i = 0; i < N; i++)
    {
        TINYTEST_EQUAL(arr[i], test_sorted[i]);
    }
    free(arr);
    free(test_sorted);
    return 1;
}

int test_sorting_data1_rev()
{
    FILE *fp = openFile("data1_rev.txt");
    TINYTEST_ASSERT(fp);
    int N = readSizeFromFile(fp);
    TINYTEST_EQUAL(6, N);
    int *arr = readArrayFromFile(fp, N);
    TINYTEST_ASSERT(arr);
    fclose(fp);
    qsort(arr, N, sizeof(int), compare_int);
    int *test_sorted = run_bucket_sort("data1_rev.txt");
    TINYTEST_ASSERT(test_sorted);
    for(int i = 0; i < N; i++)
    {
        TINYTEST_EQUAL(arr[i], test_sorted[i]);
    }
    free(arr);
    free(test_sorted);
    return 1;
}

int test_sorting_dex1()
{
    FILE *fp = openFile("dex1.txt");
    TINYTEST_ASSERT(fp);
    int N = readSizeFromFile(fp);
    TINYTEST_EQUAL(4, N);
    int *arr = readArrayFromFile(fp, N);
    TINYTEST_ASSERT(arr);
    fclose(fp);
    qsort(arr, N, sizeof(int), compare_int);
    int *test_sorted = run_bucket_sort("dex1.txt");
    TINYTEST_ASSERT(test_sorted);
    for(int i = 0; i < N; i++)
    {
        //printf("Compare %d with %d\n", arr[i], test_sorted[i]);
        TINYTEST_EQUAL(arr[i], test_sorted[i]);
    }
    free(arr);
    free(test_sorted);
    return 1;
}

int test_sorting_neg1()
{
    FILE *fp = openFile("neg1.txt");
    TINYTEST_ASSERT(fp);
    int N = readSizeFromFile(fp);
    TINYTEST_EQUAL(5, N);
    int *arr = readArrayFromFile(fp, N);
    TINYTEST_ASSERT(arr);
    fclose(fp);
    qsort(arr, N, sizeof(int), compare_int);
    int *test_sorted = run_bucket_sort("neg1.txt");
    TINYTEST_ASSERT(test_sorted);
    for(int i = 0; i < N; i++)
    {
        TINYTEST_EQUAL(arr[i], test_sorted[i]);
    }
    free(arr);
    free(test_sorted);
    return 1;
}

int test_sorting_data2()
{
    FILE *fp = openFile("data2.txt");
    TINYTEST_ASSERT(fp);
    int N = readSizeFromFile(fp);
    TINYTEST_EQUAL(6, N);
    int *arr = readArrayFromFile(fp, N);
    TINYTEST_ASSERT(arr);
    fclose(fp);
    qsort(arr, N, sizeof(int), compare_int);
    int *test_sorted = run_bucket_sort("data2.txt");
    TINYTEST_ASSERT(test_sorted);
    for(int i = 0; i < N; i++)
    {
        TINYTEST_EQUAL(arr[i], test_sorted[i]);
    }
    free(arr);
    free(test_sorted);
    return 1;
}

TINYTEST_START_SUITE(BucketSortTestSuite);
    TINYTEST_ADD_TEST(test_sorting_data2, tinytest_setup, tinytest_teardown);
    TINYTEST_ADD_TEST(test_sorting_neg1, tinytest_setup, tinytest_teardown);
    TINYTEST_ADD_TEST(test_sorting_dex1, tinytest_setup, tinytest_teardown);
    TINYTEST_ADD_TEST(test_sorting_data1_rev, tinytest_setup, tinytest_teardown);
    TINYTEST_ADD_TEST(test_sorting_data1, tinytest_setup, tinytest_teardown);
    TINYTEST_ADD_TEST(test_buckets_neg1, tinytest_setup, tinytest_teardown);
    TINYTEST_ADD_TEST(test_buckets_data1_rev, tinytest_setup, tinytest_teardown);
    TINYTEST_ADD_TEST(test_buckets_data1, tinytest_setup, tinytest_teardown);
    TINYTEST_ADD_TEST(test_bucket_index_neg1, tinytest_setup, tinytest_teardown);
    TINYTEST_ADD_TEST(test_bucket_index_dex1, tinytest_setup, tinytest_teardown);
    TINYTEST_ADD_TEST(test_bucket_index_data2, tinytest_setup, tinytest_teardown);
    TINYTEST_ADD_TEST(test_bucket_index_data1_rev, tinytest_setup, tinytest_teardown);
    TINYTEST_ADD_TEST(test_bucket_index_data1, tinytest_setup, tinytest_teardown);
    TINYTEST_ADD_TEST(test_min_max_neg1, tinytest_setup, tinytest_teardown);
    TINYTEST_ADD_TEST(test_min_max_data2, tinytest_setup, tinytest_teardown);
    TINYTEST_ADD_TEST(test_min_max_dex1, tinytest_setup, tinytest_teardown);
    TINYTEST_ADD_TEST(test_min_max_data1_rev, tinytest_setup, tinytest_teardown);
    TINYTEST_ADD_TEST(test_min_max_data1, tinytest_setup, tinytest_teardown);
    TINYTEST_ADD_TEST(test_max, tinytest_setup, tinytest_teardown);
    TINYTEST_ADD_TEST(test_min, tinytest_setup, tinytest_teardown);
    TINYTEST_ADD_TEST(test_open_dex1, tinytest_setup, tinytest_teardown);
    TINYTEST_ADD_TEST(test_open_data2, tinytest_setup, tinytest_teardown);
    TINYTEST_ADD_TEST(test_open_data1, tinytest_setup, tinytest_teardown);
TINYTEST_END_SUITE();

TINYTEST_MAIN_SINGLE_SUITE(BucketSortTestSuite);