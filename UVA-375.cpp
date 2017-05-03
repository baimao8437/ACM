/*input
1

0.263451 0.263451
*/

#include <iostream>
#include <cstdio>
#include <string>

using namespace std;


int main()
{
	int line;
	double a, b;
	scanf("%d", &line);
	scanf("\n");
	for (int i = 0 ; i < line; i++) {
		scanf("%lf%lf", &a, &b);
		printf("%lf %lf", a, b);
	}
	return 0;
}