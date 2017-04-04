/*input
4
1 4 5 7
4
4 6 8 10
*/

/*ans
1 5
5 7
7 X
7 X
*/

#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

int main()
{
	int lady_n;
	scanf("%d", &lady_n);
	int lady[lady_n];
	for (int i = 0 ; i < lady_n ; i++) {
		scanf("%d", &lady[i]);
	}
	int test;
	int man;
	int prev;
	scanf("%d", &test);
	for (int i = 0 ; i < test ; i++) {
		prev = 0;
		scanf("%d", &man);
		for (int j = 0 ; j < lady_n; j++) {
			if (j == 0 && man < lady[j]) {
				printf("X %d\n", lady[j]);
				break;
			} else if (man == lady[j])
			{
				if (lady[j - 1])
					printf("%d ", lady[j - 1]);
				else
					printf("X ");
				while (lady[j] == man)
					j++;
				if (j < lady_n)
					printf("%d\n", lady[j]);
				else
					printf("X\n");
				break;
			} else if (prev != 0 && man > prev && man < lady[j]) {
				printf("%d %d\n", prev, lady[j]);
				break;
			} else if (j == lady_n - 1 && man > lady[j]) {
				printf("%d X\n", lady[j]);
				break;
			}
			prev = lady[j];
		}
	}
	return 0;
}
