/*input
7
g
f
e
d
c
b
a
7
a b
c b
d b
e f
f d
e g
f g
7
a
b
c
d
e
f
g
7
a b
c b
d b
e d
f d
g e
g f
0
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

bool adj[101][101];
int visit[101];
int low[101];
int t = 0;
int n;
int critical = 0;
string arr_city[101];

map<string, int> city;
vector<string> ans;

void DFS(int p, int i)
{
    visit[i] = low[i] = ++t;

    int child = 0;
    bool ap = false;

    for (int j = 1; j <= n; ++j)
        if (adj[i][j] && j != p)
            if (visit[j]) { // back edge
                // 遍歷時刻較小者，即是較高祖先。
                low[i] = min(low[i], visit[j]);
            } else {        // tree edge
                child++;
                DFS(i, j);

                // 遍歷時刻較小者，即是較高祖先。
                low[i] = min(low[i], low[j]);
                if (low[j] >= visit[i]) ap = true;
            }

    if ((p != -1 || child > 1) && ap) {
        critical++;
        ans.push_back(arr_city[i]);
    }
}

int main()
{

    string line;
    int test = 1;
    while (scanf("%d\n", &n) && n) {
        if (test > 1)
            printf("\n");

        memset(adj, false, sizeof(adj));
        memset(visit, 0, sizeof(visit));
        memset(low, 0, sizeof(low));
        t = 0;
        critical = 0;
        city.clear();
        ans.clear();
        for (int i = 1 ; i <= n; i++) {
            getline(cin, line);
            stringstream s(line);
            string city_name;
            s >> city_name;
            arr_city[i] = city_name;
            city[city_name] = i;
        }

        int road;
        scanf("%d\n", &road);

        for (int i = 0 ; i < road; i++) {
            getline(cin, line);
            stringstream ss(line);
            string tmp;
            int a, b;
            ss >> tmp;
            a = city.find(tmp)->second;
            ss >> tmp;
            b = city.find(tmp)->second;

            adj[a][b] = true;
            adj[b][a] = true;

        }
        for (int i = 1; i <= n; i++)
            if (!visit[i])
                DFS(-1, i);

        printf("City map #%d: %d camera(s) found\n", test++, critical);
        sort(ans.begin(), ans.end());
        for (int i = 0 ; i < ans.size(); i++) {
            cout << ans[i] << endl;
        }

    }
    return 0;
}
