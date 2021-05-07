#include <stdio.h>
typedef long int ll;

extern ll nqueen1(ll *board, ll col, ll n);

// ll isSafe(ll *board, ll row, ll col, ll n)
// {
//     ll flag = 1;

//     // upper left diagonal check
//     for (ll i = row, j = col; i >= 0 && j >= 0; i--, j--)
//     {
//         if (*((board + i * n) + j) == 1)
//             flag = 0;
//     }

//     // check in the same row
//     for (ll i = 0; i < col; i++)
//     {
//         if (*((board + row * n) + i) == 1)
//             flag = 0;
//     }

//     // lower left diagonal check
//     for (ll i = row, j = col; i < n && j >= 0; i++, j--)
//     {
//         if (*((board + i * n) + j) == 1)
//             flag = 0;
//     }
//     return flag;
// }

// ll nqueen(ll *board, ll col, ll n)
// {
//     // If all queens are placed then return 1
//     if (col >= n)
//         return 1;

//     // for the current column, put on every row and check
//     for (ll i = 0; i < n; i++)
//     {
//         // Check if the queen can be placed on board[i][col]
//         if (isSafe(board, i, col, n))
//         {
//             //Place this queen in board[i][col]
//             *((board + i * n) + col) = 1;

//             // try the same function recursively for further columns
//             if (nqueen(board, col + 1, n))
//                 return 1;

//             // backtrack, if the position was not satisfactory
//             *((board + i * n) + col) = 0;
//         }
//     }
//     return 0;
// }

int main()
{
    ll n;
    scanf("%ld", &n);
    ll a[n][n];
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < n; j++)
        {
            a[i][j] = 0;
        }
    }

    ll flag = nqueen1(&a[0][0], 0, n);

    if (flag == 1)
    {
        for (ll i = 0; i < n; i++)
        {
            for (ll j = 0; j < n; j++)
            {
                printf("%ld ", a[i][j]);
            }
            printf("\n");
        }
    }
    else
        printf("not possible\n");

    return 0;
}
