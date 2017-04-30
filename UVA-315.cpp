/*input
5
1 2
2 3
3 4
4 5
5 1
0
5
1 2
2 3
3 4
4 5
0
0
*/

#include <iostream>
#include <stdio.h>
#include <stdbool.h>
#include <sstream>
#include <string.h>

using namespace std;

bool adj[101][101];
int visit[101];
int low[101]; // 記錄自身與子孫們
// 用back edge連到的最高祖先（的遍歷時刻）。
// 由於遍歷時刻要盡量小，故大家習慣取名為low。
int t = 0;
int n;
int critical = 0;
void DFS(int p, int i)
{
	visit[i] = low[i] = ++t;

	int child = 0;
	bool ap = false;

	for (int j = 1; j <= n; ++j)
		if (adj[i][j] && j != p)
			if (visit[j])   // back edge
			{
				// 遍歷時刻較小者，即是較高祖先。
				low[i] = min(low[i], visit[j]);
			}
			else            // tree edge
			{
				child++;
				DFS(i, j);

				// 遍歷時刻較小者，即是較高祖先。
				low[i] = min(low[i], low[j]);
				if (low[j] >= visit[i]) ap = true;
			}

	if ((i == p && child > 1) || (i != p && ap))
		critical++;
}

int main()
{

	string line;

	while (scanf("%d", &n) && n) {
		memset(adj, false, sizeof(adj));
		memset(visit, 0, sizeof(visit));
		memset(low, 0, sizeof(low));
		t = 0;
		critical = 0;
		while (getline(cin, line) && line != "0") {
			stringstream ss(line);
			int a, b;
			ss >> a;
			while (ss >> b) {
				adj[a][b] = true;
				adj[b][a] = true;
			}
		}
		DFS(1, 1);
		printf("%d\n", critical);
	}
	return 0;
}