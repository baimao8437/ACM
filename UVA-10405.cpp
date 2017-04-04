/*input
a1b2c3d4e
zz1yy2xx3ww4vv
abcdgh
aedfhr
abcdefghijklmnopqrstuvwxyz
a0b0c0d0e0f0g0h0i0j0k0l0m0n0o0p0q0r0s0t0u0v0w0x0y0z0
abcdefghijklmnzyxwvutsrqpo
opqrstuvwxyzabcdefghijklmn
*/

/*ans
4
3
26
14
*/

#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <stdbool.h>
using namespace std;

int main()
{
	vector<char> s1;
	vector<char> s2;

	string input;
	bool b = false;
	while (getline(cin, input)) {
		b = !b;
		if (b) {
			s1.clear();
			for (int i = 0 ; input[i]; i++)
				s1.push_back(input[i]);
		}
		else {
			s2.clear();
			for (int i = 0 ; input[i]; i++)
				s2.push_back(input[i]);

			int array[s1.size() + 1][s2.size() + 1];
			int prev[s1.size() + 1][s2.size() + 1];
			for (int i = 0; i <= s1.size(); i++) array[i][0] = 0;
			for (int j = 0; j <= s2.size(); j++) array[0][j] = 0;

			for (int i = 1; i <= s1.size(); i++)
				for (int j = 1; j <= s2.size(); j++)
					if (s1[i - 1] == s2[j - 1])
					{
						array[i][j] = array[i - 1][j - 1] + 1;
						prev[i][j] = 0; // 左上方
					}
					else
					{
						if (array[i - 1][j] < array[i][j - 1])
						{
							array[i][j] = array[i][j - 1];
							prev[i][j] = 1; // 左方
						}
						else
						{
							array[i][j] = array[i - 1][j];
							prev[i][j] = 2; // 上方
						}
					}
			printf("%d\n", array[s1.size()][s2.size()]);
		}
	}
	return 0;
}
