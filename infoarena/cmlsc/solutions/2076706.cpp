#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

#define lim 1050
int A[lim],B[lim],dp[lim][lim],sol[lim],n,m,dr,ia,ib;

int main()
{
    fin>>n>>m;
    for (int i=1; i<=n; i++)
        fin>>A[i];
    for (int i=1; i<=m; i++)
        fin>>B[i];

    for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++)
            if (A[i]==B[j])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max (dp[i][j-1], dp[i-1][j]);

    for (ia=n, ib=m; ia; )
        if (A[ia]==B[ib])   sol[++dr]=A[ia], ia--, ib--;
        else if (dp[ia-1][ib] > dp[ia][ib-1])   ia--;
        else    ib--;


    fout<<dr<<'\n';
    for (int i=dr; i; i--)
        fout<<sol[i]<<' ';

    fin.close();
    fout.close();
    return 0;
}
