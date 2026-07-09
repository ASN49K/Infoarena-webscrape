#include <fstream>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int v1[1030], v2[1030], dp[1030][1030], solutie[1030], i, j, aux, n, m, lung;

int main()
{
    fin>>n>>m;
    for(i=1 ; i<n+1 ; i++) {
        fin >> v1[i];
    }
    for(i=1 ; i<m+1 ; i++) {
        fin>>v2[i];
    }
    for(i=1; i<=n; i++) {
        for(j=1; j<=m; j++) {
            if(v1[i]==v2[j]) dp[i][j]=dp[i-1][j-1]+1;
            else dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
        }
    }
    lung=dp[n][m];
    fout<<lung<< '\n';
    i=n, j=m, aux=0;
    while(i>0 || j>0) {
        if(v1[i]==v2[j]) {
            solutie[aux]=v1[i];
            aux++;
            i--;
            j--;
        } else {
            if(dp[i-1][j]>=dp[i][j-1] && i>1) i--;
            else if(dp[i][j-1]>=dp[i-1][j] && j>1) j--;
            else {
                if(i>1) i--;
                else if(j>1) j--;
                else break;
            }
        }
    }
    for(i=lung-1 ; i>-1 ; i--) {
        fout<<solutie[i]<<" ";
    }
    return 0;
}
