/*input
1

3
1.0 1.0
2.0 2.0
2.0 4.0
*/

#include <cmath>
#include <iostream>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

using namespace std;

float adj[101][101];
float d[101];
bool visit[101];

int main()
{
	int Case;
	scanf("%d\n", &Case);
	string blank;
	getline(cin, blank);
	int n;
	float x[101], y[101];

	while (Case--) {
		scanf("%d", &n);

		for (int i = 0 ; i < n; i++)
			d[i] = 9999.9;
		memset(adj, 0.0, sizeof(adj));
		memset(visit, false, sizeof(visit));
		d[0] = 0;

		for (int i = 0; i < n; i++) {
			scanf("%f %f\n", &x[i], &y[i]);
		}

		for (int i = 0; i < n  ; i++) {
			for (int j = i; j < n; j++) {
				float dx = x[i] - x[j];
				float dy = y[i] - y[j];
				adj[i][j] = sqrt(dx * dx + dy * dy);
				adj[j][i] = adj[i][j];
			}
		}

		float sum = 0.0;
		for (int i = 0 ; i < n; i++) {
			int a = -1, b = -1;
			float min = 9999.9;
			for (int j = 0; j < n; j++)
				if (!visit[j] && d[j] < min ) {
					a = j;
					min = d[j];
				}
			if (a == -1) break;
			sum += min;
			visit[a] = true;
			for (b = 0; b < n; b++)
				if (!visit[b] && adj[a][b] < d[b]) {
					d[b] = adj[a][b];
				}

		}
		getline(cin, blank);
		printf("%.2f\n", sum);
		if (Case != 0)
			printf("\n");
	}
	return 0;
}
