/*input
2
1
1 2
0 0
5
3
1 2
3 5
3 1
2 4
4 5
0 0
5
5
5 1
5 2
5 3
5 4
4 1
4 2
0 0
0
*/

#include <iostream>
#include <stdio.h>

#define MAX 200000

using namespace std;

void negtiv_cycle(int n, int m)
{
    int d[n];
    int x[20000], y[20000];
    int path = 0;

    while (scanf("%d %d", &x[path], &y[path]) && x[path] && y[path++]);

    for (int k = 0 ; k < n ; k++) d[k] = MAX;
    d[m - 1] = 0 ;

    for (int i = 0 ; i < n - 1 ; i++) {
        for (int j = 0 ; j < path; j++) {
            d[y[j] - 1] = min(d[y[j] - 1], d[x[j] - 1] - 1);
        }
    }

    int longest = 0;
    int end = 0;
    for (int i = 0 ; i < n; i++) {
        if (longest > d[i]) {
            longest = d[i];
            end = i;
        }
    }
    printf("The longest path from %d has length %d, finishing at %d.\n", m, 0 - longest, end + 1);
}

int main()
{
    int n, m;
    int test = 1;
    while (scanf("%d", &n) && n != 0 && scanf("%d", &m)) {
        printf("Case %d: ", test++);
        negtiv_cycle(n, m);

        printf("\n");
    }
    return 0;
}
