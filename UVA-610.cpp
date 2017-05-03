/*input
7 10
1 2
1 3
2 4
3 4
4 5
4 6
5 7
6 7
2 5
3 6
0 0
*/

#include <iostream>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <vector>
using namespace std;

vector<int> edge[1001];
int visit[1001], low[1001], t = 0;
int n, m;

int DFS(int p, int i)
{
    visit[i] = 1;
    low[i] = ++t;
    int mn = low[i];

    for (int j = 0; j < edge[i].size(); ++j) {
        int v = edge[i][j];
        if (visit[v]) {
            if (v != p) {
                if (low[i] >= low[v])
                    printf("%d %d\n", i, v);
                mn = min(mn, low[v]);
            }
        } else
        {
            int tmp = DFS(i, v);
            if (tmp > low[i]) {
                printf("%d %d\n", i, v);
                printf("%d %d\n", v, i);
            } else
                printf("%d %d\n", i, v);
            mn = min(mn, tmp);
        }
    }
    return mn;
}

int main()
{
    int Case = 0;
    while (scanf("%d %d", &n, &m) && n) {
        memset(low, 0, sizeof(low));
        memset(visit, 0, sizeof(visit));
        for (int j = 1; j <= n; j++) {
            edge[j].clear();
        }
        int a, b;
        for (int j = 0 ; j < m; j++) {
            scanf("%d %d", &a, &b);
            edge[a].push_back(b);
            edge[b].push_back(a);
        }
        printf("%d\n\n", ++Case);
        for (int i = 1; i <= n; i++) {
            if (!visit[i]) {
                t = 0;
                DFS(-1, i);
            }
        }
        printf("#\n");
    }
    return 0;
}
