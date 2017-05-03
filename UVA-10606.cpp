/*input
1
10
50
90
101
130
0
*/

#include <iostream>
#include <cstdio>
#include <string.h>

using namespace std;


int main()
{
    char doors[100] ;
    int open[100];
    // int sum;
    while (scanf("%s", doors) && doors[0] - '0') {
        cout << atoi(doors);
        memset(open, -1, sizeof(open));
        for (int boy = 1 ; boy <= atoi(doors); boy++) {
            for (int i  = 1 ; i * boy <= atoi(doors); i++) {
                open[i * boy - 1] *= -1; //cout<<i*boy<<"->"<<((open[i*boy-1]>0)?" 1":" -1")<<endl;
            }
            // for(int i = 0 ; i < atoi(doors);i++)
            //  cout<<((open[i]>0)?"+ ":"- ");
            // cout<<endl;
        }
        for (int i = atoi(doors) ; i >= 0; i--)
            if (open[i] > 0) {
                cout << atoi(doors) << " " << i + 1 << endl;
                break;
            }
    }
    return 0;
}