/*input
2
5 4
1 2
1 3
3 4
5 3

4 4
1 2
1 3
4 2
4 3
*/

#include <iostream>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <vector>
using namespace std;

vector<int> edge[100001];
int visit[100001], low[100001], t = 0;
int stack[100001], top = 0;  // 堆疊
bool instack[100001];        // 記錄DFS forest目前尚存哪些點
int contract[100001];        // 每個點收縮到的點
int indegree[100001];
int C;
int n, m;

void DFS(int i)
{
    visit[i] = low[i] = ++t;
    stack[top++] = i;
    instack[i] = true;

    for (int j = 0; j < edge[i].size(); j++)
    {
        int v = edge[i][j];

        // tree edge
        if (!visit[v]) {
            DFS(v);
            low[i] = min(low[i], low[v]);
        }

        // tree/back/forward/cross edge
        // 已經遍歷過、但是尚未形成SCC的點
        else if (instack[v])
            low[i] = min(low[i], visit[v]);

    }

    // 形成SCC，從目前的DFS forest移除它。
    // i點會是SCC裡面，最早拜訪的點。
    if (visit[i] == low[i])
    {
        int j;
        C++;
        indegree[C] = 0;
        do
        {
            j = stack[--top];
            instack[j] = false;
            contract[j] = C;
        } while (j != i);
    }
}

void tarjan()
{
    memset(visit, 0, sizeof(visit));
    t = 0;

    for (int i = 1; i <= n; ++i)
        if (!visit[i])
            DFS(i);
}

int main()
{
    int Case;
    scanf("%d", &Case);
    for (int i = 0; i < Case; i++) {
        scanf("%d %d", &n, &m);
        int a, b;

        memset(instack, false, sizeof(instack));
        memset(stack, 0, sizeof(stack));
        top = 0;
        C = 0;

        for (int j = 1; j <= n; j++) {
            edge[j].clear();
        }

        for (int j = 0 ; j < m; j++) {
            scanf("%d %d", &a, &b);
            edge[a].push_back(b);
        }

        tarjan();

        for (int u = 1; u <= n; u ++)
        {
            for (int k = 0; k < edge[u].size(); k++)
            {
                int v = edge[u][k];
                if (contract[u] != contract[v])
                    indegree[contract[v]] ++;
            }
        }

        int count = 0;
        for (int c = 1; c <= C; c ++)
        {
            if (indegree[c] == 0)
                count ++;
        }

        printf("Case %d: %d\n", i + 1, count);
    }
    return 0;
}
