/* Dynamic Programming implementation of LCS problem */
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <fstream>
using namespace std;

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

int n,m;
int v1[1100];
int v2[1100];
int lcss[1100][1100];
int rez[1100];
int k;

void lcs() {

    for(int i = 0; i <= m; i++) {

        for(int j = 0; j <= n; j++) {

            if(i == 0 || j == 0) {
                lcss[i][j] = 0;
                continue;
            }

            if(v1[i] == v2[j]) {
                lcss[i][j] = lcss[i-1][j-1]+1;
            } else {
                lcss[i][j] = max(lcss[i-1][j], lcss[i][j-1]);
            }

        }

    }

    int i = m;
    int j = n;

    while(i > 0 && j > 0) {

        if(lcss[i][j] == lcss[i-1][j-1]+1) {

            rez[k++] = v1[i];
            i--;
            j--;

        } else {

            int mx = max(lcss[i-1][j], lcss[i][j-1]);

            if(lcss[i-1][j] == mx) {
                i--;
            } else {
                j--;
            }

        }

    }

}

int main() {
    in >> m >> n;
    for(int i = 1; i <= m; i++)
        in >> v1[i];
    for(int i = 1; i <= n; i++)
        in >> v2[i];
    lcs();

    out << lcss[m][n] << '\n';

    for(int i = k-1; i >= 0; i--)
        out << rez[i] << " ";

    return 0;
}
