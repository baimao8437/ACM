#include <iostream>
#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <stdbool.h>

using namespace std;

struct E {
	int s;
	int d;
	int w;
} edge[1000001];

int set[1000001];

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
	return a.w < b.w;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	int N, K, M, a, b, c, ans1, ans2, Case = 0;

	while (scanf("%d", &N) != EOF) {
		if (Case++)
			printf("\n");
		ans1 = 0;
		ans2 = 0;
		//input
		for (int i = 1; i < N; i++) {
			scanf("%d %d %d", &a, &b, &c);
			ans1 += c;
		}
		int idx = 0;
		scanf("%d", &K);
		for (int i = 1; i <= K; i++, idx++) {
			scanf("%d %d %d", &a, &b, &c);
			edge[idx].s = a;
			edge[idx].d = b;
			edge[idx].w = c;
		}
		scanf("%d", &M);
		for (int i = 1; i <= M; i++, idx++) {
			scanf("%d %d %d", &a, &b, &c);
			edge[idx].s = a;
			edge[idx].d = b;
			edge[idx].w = c;
		}
		sort(edge, edge + idx, cmp);

		for (int i = 1 ; i <= N; i++) {
			set[i] = i;
		}
		//build MST from shortest edge
		for (int i = 0, e = 0 ; i < idx && e < N - 1; i++) {
			while (getSet(edge[i].s) == getSet(edge[i].d))
				i++;

			Union(edge[i].s, edge[i].d);
			e++;
			ans2 += edge[i].w;
		}
		printf("%d\n%d\n", ans1, ans2);
		getchar();
	}
	return 0;
}
