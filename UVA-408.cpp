/*input
3 5
15 20
63923 99999
*/
#include <iostream>
#include <cstdio>
using namespace std;
int step, mod;
int seed(int x)
{
	return (x + step) % mod;
}
int main()
{
	while (scanf("%d", &step) != EOF)
	{
		scanf("%d", &mod);
		bool check[mod] = {false};
		int prev = 0;
		check[0] = true;
		bool all_true = true;

		for (int i = 1; i < mod; i++) {
			prev = seed(prev);
			if (check[prev]) {
				all_true = false;
				break;
			}
			check[prev] = true;
		}
		printf("%10d%10d    %-s\n\n", step, mod, (all_true) ? "Good Choice" : "Bad Choice");
	}
	return 0;
}
