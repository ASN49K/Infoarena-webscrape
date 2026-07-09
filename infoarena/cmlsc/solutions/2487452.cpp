#include <iostream>
#include <fstream>
#define N 1025
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int n,m,a[N],b[N];
int dp[N][N],v[N],k;
void Read()
{
    int i,j;
    fin>>n>>m;
    for(i=1; i<=n; i++)
        fin>>a[i];
    for(i=1; i<=m; i++)
        fin>>b[i];
}

void Solve()
{
    int i,j;
    for(i=1; i<=n; i++)
        for(j=1; j<=m; j++)
            if(a[i]==b[j])
                dp[i][j]=dp[i-1][j-1]+1;

            else
            dp[i][j]=max(dp[i-1][j],dp[i][j-1]);

    //lungime
    fout<<dp[n][m]<<"\n";

    //elemente comune
    i=n;
    j=m;
    while(i != 0 && j != 0)
    {
        if(a[i]==b[j])
            {v[++k]=a[i]; i--; j--; }
        else
           if(dp[i-1][j]<=dp[i][j-1])
              j--;
           else
             if(dp[i-1][j]>dp[i][j-1])
                i--;
    }
    for(i=k; i>=1; i--)
      fout<<v[i]<<" ";

}

int main()
{
    Read();
    Solve();

    return 0;
}

/*5 3
s:7 5 8
t:1 7 3 9 8

dp  1 7 3 9 8

7   0 1 1 1 1
5   0 1 2 1 1
8   0 1 1 1 2

i=n, j=m
dp[i][j] - cel mai lung subsir comun considerand primele i cifre ale primului cuvant,
                    si primele j cifre ale celui de-al doilea

*/
