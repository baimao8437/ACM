/*input
4 5
1 2 1
1 3 2
2 4 1
3 4 1
4 1 2
3 2
1 2 2
1 3 2
3 2
1 2 2
1 3 1
4 2
1 2 2
3 4 2
0 0
*/

#include <iostream>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <vector>
using namespace std;

vector<int> edge[2001];
int visit[2001], low[2001], t = 0;
int stack[2001], top = 0;  // 堆疊
bool instack[2001];        // 記錄DFS forest目前尚存哪些點
int contract[2001];        // 每個點收縮到的點
int indegree[2001];
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
        // indegree[C] = 0;
        do
        {
            j = stack[--top];
            instack[j] = false;
            // contract[j] = C;
        } while (j != i);
    }
}

void tarjan()
{
    memset(visit, 0, sizeof(visit));
    t = 0;

    for (int i = 1; i <= n; ++i)
        if (!visit[i] && C <= 1 )
            DFS(i);
}

int main()
{
    while (scanf("%d %d", &n, &m) && n) {

        memset(instack, false, sizeof(instack));
        memset(stack, 0, sizeof(stack));
        top = 0;
        C = 0;

        for (int j = 1; j <= n; j++) {
            edge[j].clear();
        }

        int v, w, p;
        for (int j = 0 ; j < m; j++) {
            scanf("%d %d %d", &v, &w, &p);
            edge[v].push_back(w);
            if (p != 1)
                edge[w].push_back(v);
        }

        tarjan();

        printf("%d\n", (C == 1) ? 1 : 0);
    }
    return 0;
}
