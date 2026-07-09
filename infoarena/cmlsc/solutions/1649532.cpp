#include <iostream>
#include <fstream>
using namespace std;

ifstream fin ("cmlsc.in");
ofstream fout ("cmlsc.out");

const int nmax = 1030;
int dp[nmax][nmax], a[nmax], b[nmax], sol[nmax], lg;

int main()
{
    ios_base::sync_with_stdio(false);
    int i, j, n, m;
    fin >> n >> m;
    for(i=1; i<=n; i++)
        fin >> a[i];
    for(i=1; i<=m; i++)
        fin >> b[i];
    for(i=1; i<=n; i++)
        for(j=1; j<=m; j++)
        {
            if(a[i]==b[j]) dp[i][j]=dp[i-1][j-1]+1;
            else dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
        }
    i=n, j=m;
    while(i && j)
    {
        if(a[i]==b[j])
        {
            sol[++lg]=a[i];
            i--, j--;
        }
        else if(dp[i-1][j] > dp[i][j-1]) i--;
        else j--;
    }
    fout << lg << "\n";
    for(i=lg; i; i--)
        fout << sol[i] << " ";
    fin.close();
    fout.close();
    return 0;
}
