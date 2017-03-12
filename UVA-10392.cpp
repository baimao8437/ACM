/*input
90
1234567891
18991325453139
12745267386521023
-1
*/

#include <cstdio>
#include <cmath>
#include <string.h>
#include <iostream>

#define MAX 10000000
using namespace std;

bool isprime[MAX];

void eratosthenes()
{
    memset(isprime, 1, sizeof(isprime));
    isprime[0] = isprime[1] = false;
    for (int i = 2; i <= sqrt(MAX); i++)
        if (isprime[i])
            for (int j = i * i; j < MAX; j += i)
                isprime[j] = false;
}

int main()
{
    long long int a ;
    eratosthenes();
    while (scanf("%lld", &a) && (a != -1)) {
        int i = 0;
        while (i <= MAX && a != 1) {
            if (isprime[i] && a % i == 0)
            {
                printf("    %d\n", i);
                a /= i;
                i--;
            }
            i++;
        }
        if (a != 1)
            printf("    %lld\n", a);
        printf("\n");
    }
    return 0;
}
