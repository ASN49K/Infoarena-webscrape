#include <fstream>  // NICOLI
#include <cstring>
using namespace std;
const int kMaxN = 1024;
int n, m;
int v1[kMaxN + 1], v2[kMaxN + 1], dp[kMaxN + 1][kMaxN + 1];
int lcs[kMaxN + 1];
ifstream fin ("cmlsc.in");
ofstream fout("cmlsc.out");

int main()
{   int i, j;
    fin>>m>>n;
    for (i=1;i<=m;i++) fin>>v1[i];
    for (i=1;i<=n;i++) fin>>v2[i];
    for (i=1;i<=m;i++)
        for (j=1;j<=n;j++)
            if (v1[i] == v2[j]) {
                dp[i][j] = 1 + dp[i-1][j-1];
            } else
                if (dp[i][j-1] > dp[i-1][j])
                    dp[i][j] = dp[i][j-1];
                else
                    dp[i][j] = dp[i-1][j];
        /// afisare cerinte
        int lcs[1025];
        i = m; j = n;
        while (i > 0 && j > 0) {
		if (v1[i] == v2[j]) {
			            lcs[dp[i][j]] = v1[i];
			            i--; j--;
		                  }
               else if (dp[i - 1][j] < dp[i][j - 1]) j--;
		      else i--;
	}
	fout<<dp[m][n]<<'\n';
	for (i = 1; i <= dp[m][n]; i++) fout<<lcs[i]<<' ';
    return 0;
}





