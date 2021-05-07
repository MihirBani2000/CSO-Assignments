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
int L[N], R[N];

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    /* create temp arrays */
    // int L[n1], R[n2];

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

/* l is for left index and r is right index of the
sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l + (r - l) / 2;

        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

/* UTILITY FUNCTIONS */
/* Function to print an array */
void printArray(int A[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}

void printArrayFile(int A[], int size)
{
    int i;

    FILE *myfile;
    myfile = fopen("out.txt", "w");

    for (i = 0; i < size; i++)
        fprintf(myfile, "%d ", A[i]);
    fprintf(myfile, "\n");
}

void takeInput(int arr[], int size)
{
    int i;
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
    double cpu_time_used, cpu_time_used1;

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
    start = clock();
    mergeSort(arr, 0, arr_size - 1);
    end = clock();

    // printf("\nSorted array is in File Out.txt\n");
    printArrayFile(arr, arr_size);
    // printArray(arr, arr_size);

    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("\nExecution time for MergeSort = %f \n", cpu_time_used);
    end1 = clock();
    cpu_time_used1 = ((double)(end1 - start1)) / CLOCKS_PER_SEC;
    printf("Total Execution time  = %f \n", cpu_time_used1);

    return 0;
}