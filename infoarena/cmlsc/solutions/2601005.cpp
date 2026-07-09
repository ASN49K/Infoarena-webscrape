#include <fstream>
#define NMAX 1030
using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int n,m,a[NMAX],b[NMAX],dp[NMAX][NMAX],sol[2*NMAX],cont;

int main()
{
    int i,j;
    fin>>m>>n;
    for(i=1; i<=m; i++)
        fin>>a[i];
    for(i=1; i<=n; i++)
        fin>>b[i];

    for(i=1; i<=m; i++)
        for(j=1; j<=n; j++)
            if(a[i]==b[j])
                dp[i][j]=dp[i-1][j-1]+1;
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);

    for(i=m,j=n; i>0; )
        if(a[i]==b[j])
            sol[++cont]=a[i],i--,j--;
        else if(dp[i-1][j] < dp[i][j-1])
            j--;
        else
            i--;

    fout<<cont<<'\n';
    for(i=cont; i>=1; i--)
        fout<<sol[i]<<' ';

    return 0;
}
