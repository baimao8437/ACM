/*input
4
4 2 3 1
1 3 2 4
3 2 1 4
2 3 4 1
10
3 1 2 4 9 5 10 6 8 7
1 2 3 4 5 6 7 8 9 10
4 7 2 3 10 6 9 1 5 8
3 1 2 4 9 5 10 6 8 7
2 10 1 3 8 4 9 5 7 6
*/


#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

int main()
{
	int n;
	char str[100];
	char *ptr;

	// get first n
	cin.getline(str, 100);
	ptr = strtok(str, " ");
	n = atoi(ptr);
	while (1) {
next:
		int ans[n];
		int trans[n];
		int idx = 0 ;
		int z = 0;
		// get answer and convert "twice"
		cin.getline(str, 100);
		for (ptr = strtok(str, " "); ptr; ptr = strtok(NULL, " ")) {
			idx = atoi(ptr);
			ans[idx - 1] = z;
			z++;
		}
		for (int i = 0 ; i < n ; i++) {
			trans[ans[i]] = i;
		}

		// read student answer or next n
		while (cin.getline(str, 100))
		{

			int input[20];
			int count = 0;
			z = 0;
			for (ptr = strtok(str, " "); ptr; ptr = strtok(NULL, " ")) {
				count++;
				input[z] = atoi(ptr);
				z++;
			}
			// this line is next n
			if (count == 1) {
				n = atoi(strtok(str, " "));
				goto next;
			}

			// convert student answer "twice"
			int seq[n];
			for (int i = 0 ; i < n ; i++)
				seq[input[i] - 1] = i;
			for (int i = 0 ; i < n ; i++) {
				input[i] = trans[seq[i]];
			}

			// build lis
			int lis[n];
			for (int i = 0 ; i < n ; i++) {
				lis[i] = 1;
				for (int j = 0 ; j < i ; j++) {
					if (lis[j] + 1 > lis[i] && input[i] > input[j]) {
						lis[i] = lis[j] + 1;
					}
				}
			}

			// find longest
			int scores = 0;
			for (int i = 0 ; i < n ; i++) {
				scores = (lis[i] > scores) ? lis[i] : scores;
			}
			printf("%d\n", scores);
		}
		break;
	}
	return 0;
}
