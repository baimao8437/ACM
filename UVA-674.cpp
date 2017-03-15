/*input
11
26
*/

#include <iostream>
#include <cstdio>

using namespace std;


int main()
{
	int a = 0;
	int v[5] = {1, 5, 10, 25, 50};
	int dp[7489] = {0};
	dp[0] = 1;
	for (int k = 0; k < 5; k++) {
		for (int i = 1 ; i < 7489; i++)
		{
			if (dp[i - v[k]] >= 1 && (i - v[k]) >= 0) {
				dp[i] += dp[i - v[k]];
			}
		}
	}
	while (scanf("%d", &a) != EOF) {
		cout << a << " " << dp[a] << endl;
	}
	return 0;
}