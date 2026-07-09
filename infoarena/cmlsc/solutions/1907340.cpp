#include <fstream>
using namespace std;
int n,m,maxx,sol[1024],i,k,j,DP[1024][1024];
int a[1024],b[1024];
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int main()
{
    f>>n>>m;
    for(i=1;i<=n;i++)
        f>>a[i];
    for(i=1;i<=m;i++)
        f>>b[i];
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            if (a[i]==b[j]) DP[i][j] = DP[i-1][j-1] + 1;
                else DP[i][j] = max(DP[i][j-1], DP[i-1][j]);
    g<< DP[n][m]<< "\n";
    i=n, j=m; k=0;
    while(i>0 && j>0){
        if (a[i]==b[j]) {
            sol[++k] = a[i];
            i--;j--;
        }
        else if (DP[i][j-1]>DP[i-1][j]) j--;
                    else i--;
    }
    for(i=k;i>=1;i--)
      g<<sol[i]<<" ";
    return 0;
}
