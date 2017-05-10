#include <iostream>
#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <stdbool.h>

using namespace std;

struct E {
	int s;
	int d;
	double w;
} edge[10001];

int set[101];

int getSet(int x) {
	return (set[x] == x) ? x : (set[x] = getSet(set[x]));
}
void Union(int a, int b) {
	a = getSet(a);
	b = getSet(b);
	if (a != b)
		set[a] = b;
}
bool cmp(E a, E b) {
	return a.w > b.w;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	int N, n, m, a, b, c, tmpN;
	scanf("%d", &N);
	tmpN = N;
	while (N--) {
		//input
		scanf("%d %d", &n, &m);
		for (int i = 0; i < m; i++) {
			scanf("%d %d %d", &a, &b, &c);
			edge[i].s = a;
			edge[i].d = b;
			edge[i].w = c;
		}
		//large->small
		sort(edge, edge + m, cmp);

		for (int i = 0 ; i < n; i++) {
			set[i] = i;
		}
		//build MST from shortest edge
		int ans = 1001;
		for (int i = 0, e = 0 ; i < m && e < n - 1; i++) {
			while (getSet(edge[i].s) == getSet(edge[i].d))
				i++;

			Union(edge[i].s, edge[i].d);
			e++;
			if (ans > edge[i].w)
				ans = edge[i].w;
		}
		printf("Case #%d: %d\n", tmpN - N, ans);
	}
	return 0;
}
