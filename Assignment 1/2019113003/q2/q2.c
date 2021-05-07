
#include <stdio.h>
typedef long int ll;

extern void find_transpose(ll *a, ll *transpose, ll row, ll col);

// void find_transpose(ll *a, ll *transpose, ll row, ll col)
// {
//     for (ll i = 0; i < row; i++)
//     {
//         for (ll j = 0; j < col; j++)
//         {
//             *((transpose + j * row) + i) = *((a + i * col) + j);
//         }
//     }
// }

int main()
{
    // printf("%ld", sizeof(long long int));
    ll n, m;
    scanf("%ld %ld", &n, &m);
    ll a[n][m], transposed[m][n];

    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            scanf("%ld", &a[i][j]);
        }
    }

    find_transpose(&a[0][0], &transposed[0][0], n, m);

    // printf("%ld", *(*(a + 0) + 1));

    for (ll i = 0; i < m; i++)
    {
        for (ll j = 0; j < n; j++)
        {
            printf("%ld ", transposed[i][j]);
        }
        printf("\n");
    }
    return 0;
}
