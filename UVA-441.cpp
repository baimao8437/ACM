/*input
12 2 4 14 17 18 23 25 31 32 34 39 42
10 13 15 17 21 27 39 41 43 47 48
0
*/

#include <iostream>
#include <cstdio>

using namespace std;

int k;
int a[100], s[100];
bool selected[100];

void solution(int len, int pos)
{

	if (len == 6) {
		for (int i = 0; i < 5; i++)
			printf("%d ", s[i]);
		printf("%d\n", s[5]);
		return;
	}
	for (int i = pos; i < k; i++) {
		s[len] = a[i];
		selected[i] = true;
		solution(len + 1, i + 1);
		selected[i] = false;
	}

}

int main()
{
	// blank line at start except case 0
	int n = 0;
	while (scanf("%d", &k) && k) {
		if (n++)
			printf("\n");
		for (int i = 0; i < k; i++) {
			scanf("%d", &a[i]);
		}
		solution(0, 0);
	}
	return 0;
}
