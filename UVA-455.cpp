/*input
6
abcdefghijk
abcdabcd
abababababababbababababab
amanamanamanaman
bbabb
aabaaaba
*/

#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

int period = 0 ;

int fail(char input[], int pi[]) {
	pi[0] = -1;
	int cur_pos = -1;
	for (int i = 1 ; i < strlen(input); ++i)
	{
		while (~cur_pos && input[i] != input[cur_pos + 1]) {
			cur_pos = pi[cur_pos];
		}
		if (input[i] == input[cur_pos + 1]) {
			pi[i] = ++cur_pos;
		} else {
			pi[i] = cur_pos;
		}
	}
	int l = 0;
	for (int i = 0 ; i < strlen(input); i++) {
		if (pi[i] == -1)
			l = i;
	}
	printf(" l=%d", l + 1);
	return l + 1;
}

int main()
{
	int n;
	scanf("%d", &n);
	char input[n][80];
	for (int i = 0 ; i < n; i++)
	{
		scanf("%s", input[i]);
		int pi[strlen(input[i])];

		printf("\n%s", input[i]);

		int l = fail(input[i], pi);
		printf("\npi:\n");

		for (int j = 0 ; j < strlen(input[i]); j++) {
			printf("%3c", input[i][j]);
		}
		printf("\n");
		for (int j = 0 ; j < strlen(input[i]); j++) {
			printf("%2d ", pi[j]);
		}

		period = (pi[strlen(input[i]) - 1] == -1) ? strlen(input[i]) : l;
		printf("\n%d\n", l + pi[strlen(input[i]) - 1] + 1);
		if (l + pi[strlen(input[i]) - 1] + 1 == strlen(input[i]) )
			printf("one:%d\n", period);
		else
			printf("two:%d\n", (pi[strlen(input[i]) - 1] == -1) ? strlen(input[i]) : pi[strlen(input[i]) - 1] + 1);
		period = 0;
	}
	return 0;
}