/*input
12
12
2
222222222222222222222222
*/

/*warn
10^250 * 10^250 = 10^500-> c[500]
*/

#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;


int main()
{
    char a[250], b[250];

    while (scanf("%s%s", a, b) != EOF) {
        //reverse string
        for (int i = 0; i < strlen(a) / 2; i++)
            swap(a[i], a[strlen(a) - i - 1]);
        for (int i = 0; i < strlen(b) / 2; i++)
            swap(b[i], b[strlen(b) - i - 1]);

        int i , j;
        int c[501] = {0};

        //digit compute
        i = 0;
        while (a[i]) {
            j = 0;
            while (b[j]) {
                c[i + j] += ((a[i] - '0') * (b[j] - '0'));
                j++;
            }
            i++;
        }

        string result = "";
        bool zero = true;
        for (int z = 0; z < i + j ; z++) {
            //all carry compute
            if (c[z] >= 10) {
                c[z + 1] += (c[z] / 10);
                c[z] %= 10;
            }
            if (c[z] != 0)
                zero = false;
            if ((z != i + j - 1) || c[z] != 0)
                result = to_string(c[z]) + result;
        }
        if (zero)
            cout << "0" << endl;
        else
            cout << result << endl;
    }
    return 0;
}