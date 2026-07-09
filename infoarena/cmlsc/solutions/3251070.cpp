#include <bits/stdc++.h>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int v1[1030], v2[1030], dp[1030][1030], sol[1030];

int main()
{
    int n, m, len;
    fin >> n >> m;
    for(int i=1; i<=n; i++) {
        fin >> v1[i];
    }
    for(int i=1; i<=m; i++) {
        fin >> v2[i];
    }
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            if(v1[i]==v2[j]) {
                dp[i][j]=dp[i-1][j-1]+1;
            } else {
                dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    len=dp[n][m];
    int i=n, j=m, id=0;
    while(i>0 || j>0) {
        if(v1[i]==v2[j]) {
            sol[id]=v1[i];
            id++;
            i--;
            j--;
        } else {
            if(dp[i-1][j]>=dp[i][j-1] && i>1) {
                i--;
            } else if(dp[i][j-1]>=dp[i-1][j] && j>1) {
                j--;
            } else {
                if(i>1) {
                    i--;
                } else if(j>1) {
                    j--;
                } else {
                    break;
                }
            }
        }
    }
    fout << len << "\n";
    for(i=len-1; i>=0; i--) {
        fout << sol[i] << " ";
    }
    return 0;
}
