#include <stdio.h>
#include <math.h>
typedef long int ll;

extern ll four_tower_of_hanoi(ll n);

// ll tower_of_hanoi(ll n)
// {
//     if (n == 1)
//     {
//         return 1;
//     }
//     ll count = 1;
//     count += 2 * tower_of_hanoi(n - 1);
//     return count;
// }

// ll four_tower_of_hanoi(ll n)
// {
//     if (n == 1)
//     {
//         return 1;
//     }

//     // double temp = 8 * n + 1;
//     // ll k = (sqrt(temp) - 1) / 2;

//     ll k = 0;
//     for (ll i = 0; (i * (i + 1)) <= (2 * n); i++)
//     {
//         k = i;
//     }

//     ll count = 0;
//     count += 2 * (four_tower_of_hanoi(n - k));
//     count += tower_of_hanoi(k);

//     return count;
// }

int main()
{
    ll n;
    scanf("%ld", &n);
    ll ans = four_tower_of_hanoi(n);
    printf("%ld\n", ans);
    return 0;
}