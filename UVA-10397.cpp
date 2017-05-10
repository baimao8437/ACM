#include <iostream>
#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <stdbool.h>

using namespace std;

struct T {
	double x;
	double y;
	int set;
} town[751];

struct E {
	int s;
	int d;
	double len;
} edge[751 * 751];

int getSet(int x) {
	return (town[x].set == x) ? x : (town[x].set = getSet(town[x].set));
}
void Union(int a, int b) {
	a = getSet(a);
	b = getSet(b);
	if (a != b)
		town[a].set = b;
}
bool cmp(E a, E b) {
	return a.len < b.len;
}

int main()
{
	int N, M, a, b;
	while (scanf("%d", &N) != EOF) {
		//input
		for (int i = 1; i <= N; i++) {
			scanf("%lf %lf", &town[i].x, &town[i].y);
			town[i].set = i;
		}

		scanf("%d", &M);
		for (int i = 0; i < M; i++) {
			scanf("%d %d", &a, &b);
			Union(a, b);
		}

		//set edge
		int idx = 0;
		for (int i = 1 ; i <= N; i++) {
			for (int j = i + 1; j <= N; j++, idx++) {
				edge[idx].s = i;
				edge[idx].d = j;
				edge[idx].len = sqrt(pow((town[i].x - town[j].x), 2) + pow((town[i].y - town[j].y), 2));
			}
		}
		sort(edge, edge + idx, cmp);

		//build MST from shortest edge
		double newWay = 0;
		for (int i = 0 ; i < idx; i++) {
			if (getSet(edge[i].s) != getSet(edge[i].d)) {
				Union(edge[i].s, edge[i].d);
				newWay += edge[i].len;
			}
		}
		printf("%.2lf\n", newWay);
	}
	return 0;
}
