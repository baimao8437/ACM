//           4
//        /     \
//     5-----------3
//     |    \ /    |
//     |    / \    |
//     1-----------2

#include <iostream>
#include <cstdio>
#include <stdio.h>
#include <stdbool.h>
#include <vector>

using namespace std;

int a[5] = {1, 2, 3, 4, 5};
vector<int> s;
int appear[5] = { -1, -2, -2, -1, -2};
bool link[5][5] = {false};

#define SET_LINK(a,b,bl) link[a][b]=bl;link[b][a]=bl

void solution(int len, int pos)
{
	if (appear[pos] == 1) {
		return;
	}
	if (len == 9) {
		for (int i = 0; i < 9; i++)
			printf("%d", s[i]);
		printf("\n");
		return;
	}
	for (int i = 0; i < 5; i++) {
		switch (s.back()) {
		case 1:
			if (i == 0 || i == 3)
				continue;
			break;
		case 2:
			if (i == 1 || i == 3)
				continue;
			break;
		case 3:
			if (i == 2)
				continue;
			break;
		case 4:
			if (i == 3 || i == 0 || i == 1)
				continue;
			break;
		case 5:
			if (i == 4 )
				continue;
			break;
		}
		if (link[pos][i])
			continue;
		s.push_back(a[i]);
		SET_LINK(pos, i, true);
		appear[i]++;
		solution(len + 1, i);
		SET_LINK(pos, i, false);
		s.pop_back();
		appear[i]--;
	}

}

int main()
{
	s.push_back(a[0]);
	solution(1, 0);
	return 0;
}
