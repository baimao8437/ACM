/*input
110 / 100
99 % 10
2147483647 / 2147483647
2147483646 % 2147483647
*/
#include <iostream>
#include <cstdio>
#include <string.h>
#define MAX 100000
using namespace std;

char a[MAX];
char b[2];
int c;
int q[MAX];
long long int r;

int main()
{
	while (scanf("%s%s%d", a, b, &c) != EOF) {
		r = 0;
		memset(q, 0, sizeof(q));
		//do division while read digit
		for (int i = 0 ; i < strlen(a); i++) {
			r = r * 10 + (a[i] - '0');
			if (r >= c) {
				q[strlen(a) - i - 1] = (r / c);
				r %= c;
			}
		}
		if (strcmp(b, "/"))
			printf("%d\n",  r);
		else {
			bool zero = true;
			for (int i = strlen(a) - 1 ; i >= 0; i--) {
				if (q[i] != 0 || i == 0)
					zero = false;
				if (!zero)
					printf("%d", q[i]);
			}
			printf("\n");
		}
	}
	return 0;
}