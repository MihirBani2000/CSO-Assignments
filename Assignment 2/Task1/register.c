#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 1200

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

int A[3500][3500], B[3500][3500], M[3500][3500];
int rand(void);

void matmul(int A[][3500], int B[][3500], int m, int n, int q, int M[][3500])
{
  register int i = 0;
  register int j = 0;
  register int k = 0;

  for (i = 0; i < m; ++i)
  {
    for (k = 0; k < n; ++k)
    {
      for (j = 0; j < q; ++j)
      {
        M[i][j] += A[i][k] * B[k][j];
      }
    }
  }
}

void takeinput(int arr[][3500], int r, int c)
{
  register int i;
  register int j;

  for (i = 0; i < r; ++i)
  {
    for (j = 0; j < c; ++j)
    {
      arr[i][j] = (rand() % 600);
    }
  }
}

void print_matrix(int m1[][3500], int m, int q)
{
  register int i = 0;
  register int j = 0;

  FILE *myfile;
  myfile = fopen("out.txt", "w");

  for (i = 0; i < m; ++i)
  {
    for (j = 0; j < q; ++j)
      //   printf("%d", M[i][j]);
      fprintf(myfile, "%d\t", M[i][j]);
    // printf("\n");
    fprintf(myfile, "\n");
  }
}

int main()
{
  int m, n, p, q, c, d, k, sum = 0;
  time_t t;

  /* Intializes random number generator */
  srand(3);
  // srand((unsigned)time(&t));

  clock_t start, end;
  clock_t start1, end1;
  double cpu_time_used, cpu_time_used1;

  start1 = clock();
  //Input
  // printf("Enter number of rows and columns of first matrix\n");
  m = N;
  n = N;
  // scanf("%d%d", &m, &n);
  // printf("Enter elements of first matrix\n");

  takeinput(A, m, n);

  // printf("Enter number of rows and columns of second matrix\n");
  p = N;
  q = N;
  //  scanf("%d%d", &p, &q);

  if (n != p)
    printf("The multiplication isn't possible.\n");
  else
  {
    // printf("Enter elements of second matrix\n");
    takeinput(B, p, q);

    start = clock();

    // Matrix Multiplication
    matmul(A, B, m, p, q, M);

    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    // printf("Product of the matrices:\n");
    print_matrix(M, m, q);

    printf("\n Execution time for matmul = %f \n", cpu_time_used);
    end1 = clock();
    cpu_time_used1 = ((double)(end1 - start1)) / CLOCKS_PER_SEC;
    printf("\n total Execution time  = %f \n", cpu_time_used1);
  }

  return 0;
}