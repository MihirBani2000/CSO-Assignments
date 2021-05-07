/* C program for Merge Sort */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
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

void merge(int arr[], int l, int m, int r)
{
    register int i, j, k;
    register int n1 = m - l + 1;
    register int n2 = r - m;

    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of L[], if there
    are any */
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there
    are any */
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void iter_mergeSort(int arr[], int n)
{
    register int curr_size;
    register int l;

    for (curr_size = 1; curr_size <= n - 1; curr_size *= 2)
    {
        for (l = 0; l < n - 1; l += 2 * curr_size)
        {
            register int m = min(l + curr_size - 1, n - 1);
            register int r = min(l + 2 * curr_size - 1, n - 1);

            merge(arr, l, m, r);
            // iter_merge(arr, l, m, r);
        }
    }
}

/* UTILITY FUNCTIONS */
/* Function to print an array */
void printArray(int A[], int size)
{
    register int i;
    for (i = 0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}

void printArrayFile(int A[], int size)
{
    register int i;

    FILE *myfile;
    myfile = fopen("out_iter.txt", "w");

    for (i = 0; i < size; i++)
        fprintf(myfile, "%d ", A[i]);
    fprintf(myfile, "\n");
}

void takeInput(int arr[], int size)
// void takeInput(int arr[], int arr1[], int size)
{
    register int i;
    for (i = 0; i < size; i++)
    {
        // scanf("%d",&arr[i]);
        arr[i] = (rand() % 10000000);
    }
}

int rand(void);

/* Driver code */
int main()
{
    // time keeping variables
    time_t t;
    clock_t start, end;
    clock_t start1, end1;
    clock_t start2, end2;
    double cpu_time, cpu_time1, cpu_time2;

    /* Intializes random number generator */
    // srand((unsigned)time(&t));
    srand(3);

    start1 = clock();

    int arr_size;

    // printf("Enter the size of array\n");
    arr_size = N;
    // scanf("%d", &arr_size);
    takeInput(arr, arr_size);

    // Merge sort function call
    start2 = clock();
    iter_mergeSort(arr, arr_size);
    end2 = clock();

    // printf("\nSorted array is in File Out.txt\n");
    printArrayFile(arr, arr_size);

    cpu_time2 = ((double)(end2 - start2)) / CLOCKS_PER_SEC;
    printf("\nExecution time for Iterative MergeSort = %f \n", cpu_time2);
    end1 = clock();
    cpu_time1 = ((double)(end1 - start1)) / CLOCKS_PER_SEC;
    printf("Total Execution time  = %f \n", cpu_time1);

    return 0;
}