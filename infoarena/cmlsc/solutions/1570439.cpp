#include <fstream>

using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");


int m, n, a[1001], b[1001], dp[1001][1001], sol[1001],k,i,j;

int main()
{
    int i, j;

    fin>>m>>n;

    for(i=1; i<=m; i++)
        fin>>a[i];

    for(i=1; i<=n; i++)
        fin>>b[i];



    for(i=1; i<=m; i++)
        for(j=1; j<=n; j++)

            if (a[i] == b[j])
                dp[i][j] = 1 + dp[i-1][j-1];

            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);


   i=m;
   j=n;

    while(i>0 && j>0 )
    {
        if(dp[i][j]== max(dp[i-1][j], dp[i][j-1]) )
            if(dp[i-1][j]>dp[i][j-1]) --i;
                else --j;

        else {sol[++k]=a[i]; --i; --j; }
    }

    fout<<dp [m][n]<<'\n';
    for(i=k;i>=1;i--) fout<<sol[i]<<" ";
    return 0;
}
