#include <stdio.h>
typedef long int ll;

extern ll find_ans(ll n, ll m);

// ll find_ans(ll n, ll m)
// {
//     ll sum = 0;
//     for (ll i = 2; i < n; i++)
//     {
//         ll prime_flag = 1;
//         for (ll j = 2; j * j <= i; j++)
//         {
//             if (i % j == 0)
//             {
//                 prime_flag = 0;
//                 break;
//             }
//         }
//         if (prime_flag)
//         {
//             // printf("try %ld\n", i);
//             sum = (sum + i) % m;
//         }
//     }
//     return sum;
// }

int main()
{
    ll n, m;
    scanf("%ld %ld", &n, &m);

    ll ans = find_ans(n, m);

    printf("%ld\n", ans);
    return 0;
}
