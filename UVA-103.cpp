/*input
5 2
3 7
8 10
5 2
9 11
21 18
8 6
23 15 7 9 11 3
5 4 20 3 30 10
40 50 34 24 14 4
9 10 11 12 13 14
31 4 18 8 27 17
44 32 13 19 41 19
1 2 3 4 5 6
80 37 47 18 21 9
*/

/*
5
3 1 2 4 5
4
7 1 5 6
 */

/*todo:
7258->7256
can order by input sequent
backtracking
 */
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <vector>
#include <stdbool.h>

using namespace std;

int k, n;

typedef struct _box {
	int idx;
	vector<int> length;
} box;

bool boxcmp(box a, box b) {
	for (int i = 0 ; i < n ; i++) {
		if (a.length[i] < b.length[i])
			return true;
		else if (a.length[i] > b.length[i])
			return false;
	}
}

void build_lis(box allbox[]) {
	int lis[n][k];
	// for (int i = 0 ; i < n ; i++)
	// 	for (int j = 0 ; j < k; j++) {
	// 		num[i][j] = allbox[j].length[i];
	// 	}
	for (int x = 0 ; x < n ; x++) {
		for (int i = 0 ; i < k; i++) {
			lis[x][i] = 1;
			for (int j = 0 ; j < i ; j++) {
				if (allbox[i].length[x] > allbox[j].length[x] && lis[x][j] + 1 > lis[x][i])
					lis[x][i] = lis[x][j] + 1;
			}
		}
	}
	for (int i = 0 ; i < k ; i++)
		printf("%4d ", allbox[i].idx);
	printf("\n");
	for (int x = 0 ; x < n ; x++) {
		for (int i = 0 ;  i < k; i++)
			printf("%2d:%d ", allbox[i].length[x], lis[x][i]);
		printf("\n");
	}

	int merge_lis[k];
	for (int i = 0 ; i < k ; i++) {
		int min = lis[0][i];
		int max = min;
		for (int j = 0 ; j < n ; j++) {
			if (lis[j][i] < min)
				min = lis[j][i];
			if (lis[j][i] > max)
				max = lis[j][i];
		}
		merge_lis[i] = min;
		// printf("%4d ", min);
	}
	int max = 0;
	vector<int> ans;
	// printf("\n");
	for (int i = 0 ; i < k ; i++) {
		// printf("%4d ", max);
		// if (merge_lis[i] < max)
		// continue;
		for (int j = 0 ; j < n ; j++) {
			if (lis[j][i] <= max)
				goto next;
		}
		ans.push_back(allbox[i].idx);
		max++;
next:;
	}
	printf("ans: ");
	for (int i = 0 ; i < ans.size() ; i++)
		printf("%d ", ans[i]);
	printf("\n");

}


int main()
{

	while (scanf("%d %d", &k, &n) != EOF) {
		box allbox[k];
		for (int box_i = 0 ; box_i < k ; box_i++) {
			allbox[box_i].idx = box_i + 1;
			allbox[box_i].length.resize(n);
			for (int box_dim = 0; box_dim < n ; box_dim++) {
				scanf("%d", &(allbox[box_i].length[box_dim]));
			}
			sort(allbox[box_i].length.begin(), allbox[box_i].length.end());
		}
		sort(allbox, allbox + k, boxcmp);
		// for (int i = 0 ; i < k; i++) {
		// 	for (int j = 0 ; j < n; j++)
		// 		printf("%2d ", allbox[i].length[j]);
		// 	printf("\n");
		// }
		build_lis(allbox);
	}
	return 0;
}