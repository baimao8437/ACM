/*input
die einkommen der landwirte
sind fuer die abgeordneten ein buch mit sieben siegeln
um dem abzuhelfen
muessen dringend alle subventionsgesetze verbessert werden
#
die steuern auf vermoegen und einkommen
sollten nach meinung der abgeordneten
nachdruecklich erhoben werden
dazu muessen die kontrollbefugnisse der finanzbehoerden
dringend verbessert werden
#
*/

/*ans
die einkommen der abgeordneten muessen dringend verbessert werden
*/

#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <stdbool.h>
using namespace std;

int main()
{
	while (1) {
		vector<string> s1;
		vector<string> s2;

		char word[30];
		bool in = true;

		while (scanf("%s", word) != EOF) {
			if (word[0] == '#') {
				in = !in;
				if (in)
					goto result;
				else
					continue;

			} else {
				string tmp = word;
				if (in)
					s1.push_back(tmp);
				else
					s2.push_back(tmp);
			}
		}
		break;
result:
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

		int r = s1.size(), c = s2.size();
		vector<string> ans;
		while (r && c) {
			if (prev[r][c] == 0) {
				ans.insert(ans.begin(), s1[r - 1]);
				r--;
				c--;
			}
			else if (prev[r][c] == 1) {c--;}
			else if (prev[r][c] == 2) {r--;}
		}
		for (int i = 0; i < ans.size(); i++) {
			cout << ans[i];
			if (i != ans.size() - 1)
				cout << " ";
		}
		cout << endl;
	}
	return 0;
}