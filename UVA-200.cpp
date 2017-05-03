/*input
CA
CAE
CAF
AFFE
AFFB
AFFBC
EF
EB
#
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <vector>

using namespace std;


vector<char> ans;
char input[1000][30];
bool alph[30] = {false};
int totalAlph = 0;
int max_len = 0;


void checkNextCol(int lineS, int lineE, int col)
{
    char oldC = 'a';
    int oldI = 0;
    int firstline = 0 ;
    if (col > max_len - 1) return;
    for (int i = lineS ; i <= lineE; i++) {
        if (!input[i][col])
            firstline++;
        if (input[i][col] && lineS != lineE) {
            // printf("%d %d ", i, col);
            // for (int z = 0 ; z < col; z++) {
            // printf(" ");
            // }
            // printf("%c\n", input[i][col]);
            if (input[i][col] != oldC) {
                ans.push_back(input[i][col]);
                // printf("push %c\n", input[i][col]);
                // if (i == lineE) {
                // printf("line");
                //     return;
                // }
                if (i != firstline) {
                    // ans.pop_back();
                    // printf("pop %c\n", ans.back());
                    // printf("1col:%d from %d to %d\n", col + 1, oldI, i - 1);
                    checkNextCol(oldI, i - 1 , col + 1);
                }

                // oldI = i; //printf("oldI = %d\n", i);
            }
            if (i == lineE) {
                // printf("2col:%d form %d to %d\n", col + 1, oldI, i);
                checkNextCol(oldI, i , col + 1);
            }
            oldC = input[i][col];
        }
    }
    // if (oldI == 0) {
    // printf("pop %c", ans.back());
    //     ans.pop_back();
    // }
}

int main()
{
    int i = 0;
    while (scanf("%s", input[i]) && input[i][0] != '#') {
        max_len = (max_len < strlen(input[i])) ? strlen(input[i]) : max_len;
        for (int j = 0 ; j < strlen(input[i]) ; j++) {
            if (!alph[input[i][j] - 'A']) {
                alph[input[i][j] - 'A'] = true;
                totalAlph++;
            }
        }
        i++;
    }
    i--;
    checkNextCol(0, i, 0);

    // printf("ans:%ld ", ans.size());
    for (int j = 0 ; j < ans.size(); j++) {
        if (alph[ans[j] - 'A']) {
            printf("%c", ans[j]);
            alph[ans[j] - 'A'] = false;
        }
    }

    return 0;
}