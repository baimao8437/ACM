/*input
4 6
17 17
*/

#include <iostream>
#include <cstdio>
using namespace std;

int exGCD(int a, int b , int &X, int &Y)
{
    if (!b) {
        X = 1;
        Y = 0;
        return a;
    } else {
        int gcd = exGCD(b, a % b, X, Y);
        int tmp = X;
        X = Y;
        Y = tmp - (a / b) * Y;
        return gcd;
    }
}

int main()
{
    int a , b, X, Y;
    while (scanf("%d %d", &a, &b) != EOF) {
        a = exGCD(a, b, X, Y);
        printf("%d %d %d\n", X, Y, a);
    }
    return 0;
}