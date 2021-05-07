/* C program for Merge Sort */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define N 6000000
// #define N 10000

/*Instructions:
This code takes approximatly 3 secs to run on device with following config-
     *-memory
          description: System memory
          physical id: 0
          size: 8GiB
     *-cpu
          product: Intel(R) Core(TM) i5-7200U CPU @ 2.50GHz
          vendor: Intel Corp.
          physical id: 1
          bus info: cpu@0
          size: 3005MHz
          capacity: 3100MHz
          width: 64 bits

*/

// Merges two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
int arr[N];
// int arr1[N];
int L[N], R[N];

int min(int x, int y) { return (x < y) ? x : y; }

void merge(register int *arr, int l, int m, int r)
{
    register int i, j, k;
    register int n1 = m - l + 1;
    register int n2 = r - m;

    /* Copy data to temp arrays L[] and R[] */
    // for (i = 0; i < n1; ++i)
    //     *(L + i) = *(arr + l + i);
    memcpy(L, &arr[l], sizeof(int) * n1);
    // for (j = 0; j < n2; ++j)
    //     *(R + j) = *(arr + m + 1 + j);
    memcpy(R, &arr[m + 1], sizeof(int) * n2);

    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (*(L + i) <= *(R + j))
        {
            *(arr + k) = *(L + i);
            ++i;
        }
        else
        {
            *(arr + k) = *(R + j);
            ++j;
        }
        ++k;
    }

    /* Copy the remaining elements of L[], if there
    are any */
    while (i < n1 - 15)
    {
        // *(arr + k++) = *(L + i++);
        // *(arr + k++) = *(L + i++);
        // *(arr + k++) = *(L + i++);
        // *(arr + k++) = *(L + i++);
        // *(arr + k++) = *(L + i++);
        // *(arr + k++) = *(L + i++);
        // *(arr + k++) = *(L + i++);
        // *(arr + k++) = *(L + i++);
        // *(arr + k++) = *(L + i++);
        // *(arr + k++) = *(L + i++);
        // *(arr + k++) = *(L + i++);
        // *(arr + k++) = *(L + i++);
        // *(arr + k++) = *(L + i++);
        // *(arr + k++) = *(L + i++);
        // *(arr + k++) = *(L + i++);
        // *(arr + k++) = *(L + i++);

        *(arr + k) = *(L + i);
        *(arr + k + 1) = *(L + i + 1);
        *(arr + k + 2) = *(L + i + 2);
        *(arr + k + 3) = *(L + i + 3);
        *(arr + k + 4) = *(L + i + 4);
        *(arr + k + 5) = *(L + i + 5);
        *(arr + k + 6) = *(L + i + 6);
        *(arr + k + 7) = *(L + i + 7);
        *(arr + k + 8) = *(L + i + 8);
        *(arr + k + 9) = *(L + i + 9);
        *(arr + k + 10) = *(L + i + 10);
        *(arr + k + 11) = *(L + i + 11);
        *(arr + k + 12) = *(L + i + 12);
        *(arr + k + 13) = *(L + i + 13);
        *(arr + k + 14) = *(L + i + 14);
        *(arr + k + 15) = *(L + i + 15);

        i += 16;
        k += 16;
    }
    while (i < n1)
    {
        *(arr + k++) = *(L + i++);
    }

    /* Copy the remaining elements of R[], if there
    are any */
    while (j < n2 - 15)
    {
        // *(arr + k++) = *(R + j++);
        // *(arr + k++) = *(R + j++);
        // *(arr + k++) = *(R + j++);
        // *(arr + k++) = *(R + j++);
        // *(arr + k++) = *(R + j++);
        // *(arr + k++) = *(R + j++);
        // *(arr + k++) = *(R + j++);
        // *(arr + k++) = *(R + j++);
        // *(arr + k++) = *(R + j++);
        // *(arr + k++) = *(R + j++);
        // *(arr + k++) = *(R + j++);
        // *(arr + k++) = *(R + j++);
        // *(arr + k++) = *(R + j++);
        // *(arr + k++) = *(R + j++);
        // *(arr + k++) = *(R + j++);
        // *(arr + k++) = *(R + j++);

        *(arr + k) = *(R + j);
        *(arr + k + 1) = *(R + j + 1);
        *(arr + k + 2) = *(R + j + 2);
        *(arr + k + 3) = *(R + j + 3);
        *(arr + k + 4) = *(R + j + 4);
        *(arr + k + 5) = *(R + j + 5);
        *(arr + k + 6) = *(R + j + 6);
        *(arr + k + 7) = *(R + j + 7);
        *(arr + k + 8) = *(R + j + 8);
        *(arr + k + 9) = *(R + j + 9);
        *(arr + k + 10) = *(R + j + 10);
        *(arr + k + 11) = *(R + j + 11);
        *(arr + k + 12) = *(R + j + 12);
        *(arr + k + 13) = *(R + j + 13);
        *(arr + k + 14) = *(R + j + 14);
        *(arr + k + 15) = *(R + j + 15);

        j += 16;
        k += 16;
    }
    while (j < n2)
    {
        *(arr + k++) = *(R + j++);
    }
}

void iter_mergeSort(register int *arr, int n)
{
    register int curr_size, l;
    register int iter1, temp, j;
    register int insertion_lim = 30;

    for (iter1 = 0; iter1 < n; iter1 += insertion_lim)
    {
        // register int left = iter1;
        register int right = min(iter1 + insertion_lim - 1, n - 1);
        register int iter2;

        for (iter2 = iter1 + 1; iter2 <= right; ++iter2)
        {
            temp = *(arr + iter2);
            j = iter2 - 1;
            while (*(arr + j) > temp && j >= iter1)
            {
                *(arr + j + 1) = *(arr + j);
                --j;
            }
            *(arr + j + 1) = temp;
        }
    }

    for (curr_size = insertion_lim; curr_size <= n - 1; curr_size *= 2)
    {
        for (l = 0; l < n - 1; l += 2 * curr_size)
        {
            register int m = min(l + curr_size - 1, n - 1);
            register int r = min(l + 2 * curr_size - 1, n - 1);

            merge(arr, l, m, r);
        }
    }
}

/* UTILITY FUNCTIONS */
/* Function to print an array */
void printArray(register int *A, register int size)
{
    register int i;
    for (i = 0; i < size; ++i)
        printf("%d ", *(A + i));
    printf("\n");
}

void printArrayFile(register int *A, register int size)
{
    register int i;

    FILE *myfile;
    myfile = fopen("out_iter.txt", "w");

    for (i = 0; i < size; ++i)
        fprintf(myfile, "%d ", *(A + i));
    fprintf(myfile, "\n");
}

void takeInput(register int *arr, int size)
{
    register int i;
    for (i = 0; i < size; ++i)
    {
        // scanf("%d",&arr[i]);
        *(arr + i) = (rand() % 10000000);
    }
}

int rand(void);

/* Driver code */
int main()
{
    // time keeping variables
    // time_t t;
    register clock_t start, end;
    register clock_t start1, end1;
    register clock_t start2, end2;
    register double cpu_time, cpu_time1, cpu_time2;

    /* Intializes random number generator */
    // srand((unsigned)time(&t));
    srand(3);

    start1 = clock();

    register int arr_size;

    // printf("Enter the size of array\n");
    arr_size = N;
    // scanf("%d", &arr_size);
    takeInput(arr, arr_size);

    // Merge sort function call
    start2 = clock();
    iter_mergeSort(arr, arr_size);
    end2 = clock();

    // printf("\nSorted array is in File Out.txt\n");
    // printArray(arr, arr_size);
    printArrayFile(arr, arr_size);

    cpu_time2 = ((double)(end2 - start2)) / CLOCKS_PER_SEC;
    printf("\nExecution time for Iterative MergeSort = %f \n", cpu_time2);
    end1 = clock();
    cpu_time1 = ((double)(end1 - start1)) / CLOCKS_PER_SEC;
    printf("Total Execution time  = %f \n", cpu_time1);

    return 0;
}