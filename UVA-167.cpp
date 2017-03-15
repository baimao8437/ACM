/*input
1
1 2 3 4 5 6 7 8
9 10 11 12 13 14 15 16
17 18 19 20 21 22 23 24
25 26 27 28 29 30 31 32
33 34 35 36 37 38 39 40
41 42 43 44 45 46 47 48
48 50 51 52 53 54 55 56
57 58 59 60 61 62 63 64
*/

#include <iostream>
#include <cstdio>

using namespace std;
int a[8][8];
int sum = 0;
int total = 0;
bool col[8], row[8], ls[15], rs[15];//left,right screw
void solution(int c)
{
	if (c == 8) {
		if (sum > total)
			total = sum;
		else
			return;
	}
	for (int j = 0; j < 8; j++) {
		int indexls = j + c;
		int indexrs = j - c + 7;
		if (!row[c] && !col[j] && !ls[indexls] && !rs[indexrs]) {
			row[c] = true;
			col[j] = true;
			ls[indexls] = true;
			rs[indexrs] = true;
			sum += a[c][j];
			solution(c + 1 );
			sum -= a[c][j];
			row[c] = false;
			col[j] = false;
			ls[indexls] = false;
			rs[indexrs] = false;
		}
	}
}

int main()
{
	int n;
	scanf("%d", &n);
	for (int k = 0; k < n; k++) {
		total = 0;
		sum = 0;
		for (int i = 0; i < 8; i++)
			for (int j = 0; j < 8; j++)
				scanf("%d", &a[i][j]);
		solution(0);
		printf("%5d\n", total);
	}
	return 0;
}
