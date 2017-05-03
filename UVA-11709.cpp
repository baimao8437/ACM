/*input
12 26
fK, Ze
gg, I
X, Q
uHI, ADlq
l, dR
Vk, DD
da, qG
A, i
K, t
b, L
FYfLBNa, aWWjZnAGQP
a, S
b, L
FYfLBNa, aWWjZnAGQP
X, Q
a, S
A, i
da, qG
K, t
fK, Ze
A, i
uHI, ADlq
uHI, ADlq
b, L
X, Q
gg, I
b, L
a, S
l, dR
FYfLBNa, aWWjZnAGQP
Vk, DD
l, dR
fK, Ze
K, t
gg, I
b, L
Vk, DD
gg, I
gg, I
a, S
gg, I
da, qG
Vk, DD
b, L
FYfLBNa, aWWjZnAGQP
b, L
fK, Ze
b, L
a, S
FYfLBNa, aWWjZnAGQP
X, Q
A, i
X, Q
l, dR
Vk, DD
A, i
da, qG
Vk, DD
K, t
X, Q
b, L
gg, I
fK, Ze
A, i
0 0
*/


#include <iostream>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <vector>
#include <map>

using namespace std;

vector<int> edge[100001];
map<string, int>M;
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
    C = 0;

    for (int i = 0; i < n; ++i)
        if (!visit[i])
            DFS(i);

}

int main()
{
    // freopen("in.txt", "r", stdin);
    int Case = 1;;
    while (scanf("%d %d\n", &n, &m) && n) {
        // cout << "case: " << Case++ << endl;
        memset(instack, false, sizeof(instack));
        memset(stack, 0, sizeof(stack));
        top = 0;
        C = 0;

        for (int i = 1; i <= n; i++) {
            edge[i].clear();
        }

        string name;
        for (int i = 0 ; i < n; i++) {
            getline(cin, name);
            // cout << name << endl;
            M[name] = i;
        }
        int a, b;
        for (int i = 0 ; i < m; i++) {
            getline(cin, name);
            a = M[name];
            // cout << name << " ";
            getline(cin, name);
            b = M[name];
            // cout << name << endl;
            edge[a].push_back(b);
        }

        tarjan();

        printf("%d\n", C);
    }
    return 0;
}
