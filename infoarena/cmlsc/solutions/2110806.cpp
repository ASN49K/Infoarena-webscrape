#include <fstream>
#define nmax 1030
using namespace std;
int n, m, a[nmax], b[nmax], dp[nmax][nmax], rez[nmax];
fstream f1("cmlsc.in", ios::in);
fstream f2("cmlsc.out", ios::out);
int main()
{
    int i, j, k;
    f1>>n>>m;
    for(i=1; i<=n; i++)
        f1>>a[i];
    for(i=1; i<=m; i++)
        f1>>b[i];
    for(i=1; i<=n; i++)
        for(j=1; j<=m; j++)
           if(a[i]==b[j]) dp[i][j]=dp[i-1][j-1]+1;
           else dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
    f2<<dp[n][m]<<"\n";

    i=n; j=m;
    k=0;

    while((i>=1)&&(j>=1))
    {
        if(a[i]==b[j]) {k++;rez[k]=a[i]; i--; j--;}
        else
        {
            if(i==1) j--;
            else if(j==1) i--;
                 else if(dp[i-1][j]> dp[i][j-1]) i--;
                          else j--;
        }
    }

    for(i=k; i>=1; i--)
        f2<<rez[i]<<' ';
    return 0;
}
