#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* 
This code takes approximatly 5min to run on device with following config-
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

// #define N 4
#define N 1000
int A[N][N], B[N][N], M[N][N];

int rand(void);

void print_matrix(int m1[][N])
{
  int i = 0;
  for (i = 0; i < N; ++i)
  {
    int j = 0;
    for (j = 0; j < N; ++j)
      printf("%d\t", M[i][j]);
    printf("\n");
  }
}

void matmul(int a[][N], int b[][N], int res[][N])
{
  int i, j, k, sum;
  i = 0;
  j = 0;
  k = 0;
  sum = 0;
  // for (i = 0; i < N; ++i)
  // {
  //   for (k = 0; k < N; ++k)
  //   {
  //     for (j = 0; j < N; ++j)
  //     {
  //       sum = sum + A[i][k] * B[k][j];
  //     }
  //     res[i][j] = sum;
  //     sum = 0;
  //   }
  // }

  for (i = 0; i < N; ++i)
  {
    for (j = 0; j < N; ++j)
    {
      for (k = 0; k < N; ++k)
      {
        sum = sum + A[i][k] * B[k][j];
      }
      res[i][j] = sum;
      sum = 0;
    }
  }

  //   for (i = 0; i < N; ++i)
  //   {
  //     for (k = 0; k < N; ++k)
  //     {
  //       for (j = 0; j < N; ++j)
  //       {
  //         sum = sum + A[i][k] * B[k][j];
  //       }
  //       res[i][j] = sum;
  //       sum = 0;
  //     }
  //   }

}

int main()
{
  int m, n, p, q, c, d, k;
  // int sum = 0;
  time_t t;

  // for measuring time
  clock_t start, end;
  clock_t start1, end1;
  double cpu_time_used, cpu_time_used1;

  /* Intializes random number generator */
  srand((unsigned)time(&t));

  //Input
  start1 = clock();
  // printf("Enter number of rows and columns of first matrix\n");
  // scanf("%d%d", &m, &n);
  m = N;
  n = N;
  // printf("Enter elements of first matrix\n");

  for (c = 0; c < m; ++c)
    for (d = 0; d < n; ++d)
    {
      // scanf("%d", &A[c][d]);
      A[c][d] = (rand() % 600);
    }

  // printf("Enter number of rows and columns of second matrix\n");
  //  scanf("%d%d", &p, &q);
  p = N;
  q = N;

  if (n != p)
    printf("The multiplication isn't possible.\n");
  else
  {
    // printf("Enter elements of second matrix\n");

    for (c = 0; c < p; ++c)
      for (d = 0; d < q; ++d)
      {
        // scanf("%d", &B[c][d]);
        B[c][d] = (rand() % 600);
      }

    // Matrix Multiplication
    start = clock();
    matmul(A, B, M);
    // for (c = 0; c < m; ++c)
    // {
    //   for (d = 0; d < q; ++d)
    //   {
    //     for (k = 0; k < p; ++k)
    //     {
    //       sum = sum + A[c][k] * B[k][d];
    //     }
    //     M[c][d] = sum;
    //     sum = 0;
    //   }
    // }

    end = clock();

    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    // printf("Product of the matrices:\n");
    // print_matrix(M);

    printf("\n Execution time for matmul = %f \n", cpu_time_used);
    end1 = clock();
    cpu_time_used1 = ((double)(end1 - start1)) / CLOCKS_PER_SEC;
    printf("\n total Execution time  = %f \n", cpu_time_used1);
  }

  return 0;
}