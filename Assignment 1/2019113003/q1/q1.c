#include <stdio.h>
typedef long int ll;

extern ll func(ll n);

// ll func(ll n)
// {
//     ll temp = n;
//     ll count = 0;
//     while (n)
//     {
//         if (n & 1)
//             count++;
//         // n /= 2;
//         n = n >> 1;
//     }
//     return (count & 1);
// }

// ll func(ll n)
// {
//     ll size = sizeof(long int) * 8;
//     // printf("%ld\n", size);
//     ll base = 1;
//     ll temp = 1;
//     ll count = 0;
//     for (ll i = 0; i < size - 1; i++)
//     {
//         temp = base << i;
//         if (temp & n)
//         {
//             printf("%ld\n", temp);
//             count++;
//         }
//     }
//     printf("\n%ld\n", count);
//     return (count & 1);
// }

int main()
{
    ll n;
    scanf("%ld", &n);
    int flag = func(n);

    if (flag)
        printf("TRUE\n");
    else
        printf("FALSE\n");

    return 0;
}
