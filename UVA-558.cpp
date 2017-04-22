/*input
9
6 10
5 2 1357
1 3 1256
3 4 262
5 0 1271
2 0 189
1 2 -189
1 4 530
1 0 -470
0 1 -447
4 5 1168
6 10
4 2 749
3 4 567
2 4 1111
0 1 90
5 4 145
4 3 8
5 2 188
0 5 763
2 3 1146
3 5 -180
6 10
3 0 119
1 4 -267
3 1 232
5 0 -87
3 2 466
0 2 -172
0 4 18
1 5 537
3 5 -307
0 3 844
6 10
0 2 -243
3 0 359
1 0 -395
0 1 1412
3 4 1337
1 5 1002
4 0 776
2 4 405
2 3 -433
0 5 1132
6 10
4 1 1458
2 4 290
5 1 1297
4 3 1070
1 2 592
4 0 312
2 3 606
3 2 -393
1 3 -308
0 5 77
6 10
3 1 733
2 5 287
3 4 1477
0 2 -151
2 0 1274
0 4 1130
2 4 811
5 3 -465
3 0 534
4 2 -299
6 10
0 4 -258
1 0 -77
5 4 58
4 3 1263
3 4 -447
4 5 1489
0 1 583
2 4 788
3 2 990
3 0 -467
6 10
3 4 50
0 2 1483
4 1 238
1 2 -125
4 5 -473
1 4 1447
5 3 -496
5 4 -317
0 5 908
0 3 250
6 10
3 5 817
5 0 1091
5 2 664
0 1 -211
4 1 634
3 4 948
4 5 1117
1 5 -114
4 3 1431
2 3 312
*/

#include <iostream>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX 200000

using namespace std;

bool negtiv_cycle(int n, int m)
{
    int d[n];
    int x[m], y[m], t[m];

    for (int hole = 0 ; hole < m; hole++) {
        scanf("%d %d %d", &x[hole], &y[hole], &t[hole]);
    }

    for (int k = 0 ; k < n ; k++) d[k] = MAX;

    d[0] = 0 ;

    for (int i = 0 ; i < n - 1 ; i++) {
        for (int j = 0 ; j < m; j++) {
            d[y[j]] = min(d[y[j]], d[x[j]] + t[j]);
        }
    }

    bool check = false;

    for (int j = 0 ; j < m; j++) {
        if (d[y[j]] > d[x[j]] + t[j])
            return true;
    }
    return false;
}


int main()
{
    int test;
    scanf("%d", &test);
    while (test--) {
        int n, m;
        scanf("%d %d", &n, &m);
        (negtiv_cycle(n, m)) ? printf("possible\n") : printf("not possible\n");
    }
    return 0;
}
