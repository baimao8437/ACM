/*input
2 2
100 223
2300 1000
0 0
*/

#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

/*hint
C(n,m)=n!/(n-m)!m!
row_sum=row*C(col,2)*2
=>row*col*(col-1)
 */

long long int arrange(long long int n)
{
	return n * (n - 1) / 2;
}

int main()
{
	long long int row, col;
	long long int sum = 0;
	while (scanf("%lld %lld", &row, &col) && row && col) {
		if (row < col)
		{
			int tmp = row;
			row = col;
			col = tmp;
		}
		sum = (row * arrange(col) + col * arrange(row)) * 2; //row+col total
		sum += (arrange(col) * (row - col + 1)) * 4; //longest dia
		for (int i = 2 ; i < col; i++) //other dia each have 2
			sum += arrange(i) * 8;

		printf("%lld\n", sum);
	}
	return 0;
}