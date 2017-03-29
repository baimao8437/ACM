/*input
4 6 4 3 2 2 1 1
5 3 2 1 1
12 6 4 4 4 4 3 1
400 12 50 50 50 50 50 50 25 25 25 25 25 25
0 0
*/

#include <iostream>
#include <cstdio>
#include <stdio.h>
#include <string.h>
#include <vector>

using namespace std;

int t, n;
int num[12] = {0};
bool selectNum[12];
vector<int> ans;
vector<vector<int>> prevAns;
int ansCount = 0;

void solution(int sum, int pos)
{
	if (sum == t) {
		bool existAns = false;
		if (!prevAns.empty())
			for (int j  = 0; j < prevAns.size(); j++) {
				if (prevAns[j] == ans) {
					existAns = true;
				}
			}
		if (existAns)
			return;
		prevAns.push_back(ans);
		for (int i = 0 ; i < ans.size() ; i++) {
			if (i != 0)
				printf("+");
			printf("%d", ans[i]);
		}
		printf("\n");
		return;
	}

	for (int i = pos ; i < n ; i++) {
		if (sum + num[i] <= t) {
			ans.push_back(num[i]);
			selectNum[i] = true;
			solution(sum + num[i], i + 1);
			ans.pop_back();
			selectNum[i] = false;
		}
	}
	return;
}


int main()
{
	while (scanf("%d %d", &t, &n) && t) {
		memset(selectNum, false, sizeof(selectNum));
		ans.clear();
		prevAns.clear();
		for (int i = 0 ; i < n ; i++)
			scanf("%d", &num[i]);
		printf("Sums of %d:\n", t, n);
		solution(0, 0);
		if (prevAns.empty()) {
			printf("NONE\n");
		}
	}
	return 0;
}