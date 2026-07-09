#include <fstream>

#define NMAX 1028

using namespace std;
ifstream fin ("cmlsc.in");
ofstream fout ("cmlsc.out");

int n, m;
int a[NMAX];
int b[NMAX];
int dp[NMAX][NMAX];

int main()
{
    int i, j;
    fin>>n>>m;
    for(i = 1; i <= n; i++) fin>>a[i];
    for(i = 1; i <= m; i++) fin>>b[i];
    for(i = 1; i <= n; i++) //vectorul a, pe linii
        for(j = 1; j <= m; j++) //vectorul b, pe coloane
           if(a[i] == b[j])
             dp[i][j] = dp[i-1][j-1] + 1;
             else
             dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
    fout<<dp[n][m]<<'\n';
    int crt = 1;
    for(i = 1; i <= n; i++) //vectorul a, pe linii
        {
         for(j = 1; j <= m; j++) //vectorul b, pe coloane
            if(crt == dp[i][j])
              {crt++; fout<<a[i]<<' ';}
        }
    return 0;
}
