/*input
5 6
Ben Alexander
Alexander Dolly
Dolly Ben
Dolly Benedict
Benedict Dolly
Alexander Aaron
14 34
John Aaron
Aaron Benedict
Betsy John
Betsy Ringo
Ringo Dolly
Benedict Paul
John Betsy
John Aaron
Benedict George
Dolly Ringo
Paul Martha
George Ben
Alexander George
Betsy Ringo
Alexander Stephen
Martha Stephen
Benedict Alexander
Stephen Paul
Betsy Ringo
Quincy Martha
Ben Patrick
Betsy Ringo
Patrick Stephen
Paul Alexander
Patrick Ben
Stephen Quincy
Ringo Betsy
Betsy Benedict
Betsy Benedict
Betsy Benedict
Betsy Benedict
Betsy Benedict
Betsy Benedict
Quincy Martha
0 0
*/

#include <iostream>
#include <stdio.h>
#include <stdbool.h>
#include <sstream>
#include <string.h>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

// bool adj[101][101];
// int visit[101];
// int low[101];
// int t = 0;
// int n, m;
int critical = 0;
string arr_city[101];

map<string, int> city;
vector<string> ans;

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
        ans.push_back(arr_city[i]);
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

    string line;
    int test = 1;

    while (scanf("%d %d\n", &n, &m) && n) {
        if (test > 1)
            printf("\n");

        // memset(adj, false, sizeof(adj));
        memset(visit, 0, sizeof(visit));
        memset(low, 0, sizeof(low));
        t = 0;
        critical = 0;
        city.clear();
        ans.clear();
        int idx = 0;
        // for (int i = 1 ; i <= n; i++) {
        //     getline(cin, line);
        //     stringstream s(line);
        //     string city_name;
        //     s >> city_name;
        //     arr_city[i] = city_name;
        //     city[city_name] = i;
        // }

        for (int i = 0 ; i < m; i++) {
            getline(cin, line);
            stringstream ss(line);
            string tmp;
            int a, b;
            ss >> tmp;
            // cout << tmp << " ";
            if (city.find(tmp) == city.end()) {
                // cout << "not find";
                arr_city[idx] = tmp;
                city[tmp] = idx++;
            }
            a = city[tmp];
            ss >> tmp;
            // cout << tmp << " ";
            if (city.find(tmp) == city.end()) {
                arr_city[idx] = tmp;
                city[tmp] = idx++;
            }
            b = city[tmp];
            edge[a].push_back(b);
            edge[b].push_back(a);

        }
        for (int i = 1; i <= n; i++)
            if (!visit[i])
                DFS(i);

        printf("City map #%d: %d camera(s) found\n", test++, critical);
        // sort(ans.begin(), ans.end());
        for (int i = 0; i < C; i++) {
            for (int j = 0; j < ans[i].size() - 1; j++)
                cout << arr_city[ans[i][j]] << ", ";
            cout << arr_city[ans[i].back()] << endl;
        }

    }
    return 0;
}

//TODO: tarjan SCC