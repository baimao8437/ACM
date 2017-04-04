/*input
3dsVd YSFivX4lPGAJjnnaDxDTSA2WIzR5h0 g sni4oZcXN5ETkBQ6 T6FJtWCKWdPSRxIMtAuYFDf7
O19QO
WbJ9ohkcz5B65ddvH8LS4nsfTI kYyj Xj7e
4jcp3xWcTSpd8Fv0IJrteBfnMyi1qOlahol2YU7bOJ9oOwBXWuLjYVTc5218j3VcOU52roU5uBAYjoKEFgrWDBS1Wjlnb0SGtQ
mX RvtR1lmZpn2VfDBtfRowvn1ToBXiLBpzTjP3nsKzIefS3vyzJamXTx
JPM9NTEAA4GG870DYXK9SedurFbw33uExzkKItLU26Bbjs2CAT2KEXzZYzgwre6WdVF1EsmAjIeUtqKfF5SPSYA
l2856q6Efb1GBtWnG6VQ2eVd g5Y3r3Yoqw1LHuabXUU2VqDMKit4Wa6wSdSo391nQH6SWp7ol5VP1J
1eUUt0CI
su5oxkfdoEWm88YAE8oprjyjF4R8DtrrvPUpA
2dUtCNs8LK3BGtVVSEq8Zm9VmruKCBcwoLtvHXWnD0gRMHKfHM1LRFuS2rK77jJQ zGXHIzvjgsSgCDTI2iK6NS
9tVwtPRGoKjlfQWoBldSjy7dmYaHIps
FowJbhex91kUMa18VA2ZSZDFde6N1MD 5fzc8jjy1lJgnkTHV74FVX6vSsb4
btge0TlTsCT8mMg7QH1F qWtx VILvZq4BHRDBs8lqowSOdvzYuSFlENsZfU 9KGb78gmnonG50iythhyqRz
zV2
#
*/

/*ans
Case #1: you can visit at most 3 cities.
Case #2: you can visit at most 2 cities.
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
	int test = 0;
	while (getline(cin, input) && input != "#") {
		b = !b;
		if (b) {
			s1.clear();
			for (int i = 0 ; input[i]; i++)
				s1.push_back(input[i]);
		}
		else {
			test++;
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
			printf("Case #%d: you can visit at most %d cities.\n", test, array[s1.size()][s2.size()]);
		}
	}
	return 0;
}
