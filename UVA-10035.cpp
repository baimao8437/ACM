/*input
123 456
555 555
123 594
0 0
*/

/*trap
1.digits 10 => long int
2.sum = 0, 1 => "carry operation[]"
  sum > 1    => "carry operation[s]"
*/

#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    long int a , b, carry, sum;
    while (scanf("%ld %ld", &a, &b) && (a || b)) {
        sum = 0;
        carry = 0;
        while (a > 0 || b > 0) {
            if (a % 10 + b % 10 + carry >= 10) {
                sum++;
                a /= 10;
                b /= 10;
                carry = 1;
            } else {
                a /= 10;
                b /= 10;
                carry = 0;
            }
        }
        if (sum == 1)
            printf("1 carry operation.\n");
        else if (sum == 0)
            printf("No carry operation.\n");
        else
            printf("%ld carry operations.\n", sum);
    }
    return 0;
}