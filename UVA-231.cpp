/*input
389
207
155
300
299
170
158
65
-1
23
34
21
-1
-1
*/

#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
	int h[100];
	int test = 0;
	while (1) {
		int i = 0;
		scanf("%d", &h[i++]);
		if (h[0] == -1)
			return 0;
		if (test)
			printf("\n");
		printf("Test #%d:\n", ++test);
		while (scanf("%d", &h[i]) && h[i++] != -1);

		int lds[i - 1];
		for (int m = 0 ; m < i - 1; m++) {
			lds[m] = 1;
			for (int n = 0 ; n < m; n++) {
				if (lds[n] + 1 > lds[m] && h[m] <= h[n])
					lds[m] = lds[n] + 1;
			}
		}
		int max = 0;
		for (int k = 0 ; k < i - 1; k++) {
			max = (lds[k] < max) ? max : lds[k];
		}
		printf("  maximum possible interceptions: %d\n", max);
	}
	return 0;
}
