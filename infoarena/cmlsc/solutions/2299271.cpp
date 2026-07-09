#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

const int NLIM = 1025;

int n,m;
int a[NLIM],b[NLIM];
int dp[NLIM][NLIM];

void citeste()
{
    fin >> n >> m;
    for (int i = 1; i <= n; i++)
        fin >> a[i];
    for (int i = 1; i <= m; i++)
        fin >> b[i];
}

void CompletareDP()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m;j++)
        {
            if (a[i] == b[j])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    }
   /* for (int i=0;i<=n;i++)
    {
        for (int j=0;j<=m;j++)
            cout << dp[i][j] << " ";
        cout << endl;
    }*/
    fout << dp[n][m] << "\n";
}

void afisare(int i,int j)
{
    if (i!=0 && j!=0)
   {
        if (dp[i][j] == dp[i-1][j])
            afisare(i-1,j);
        else if (dp[i][j] == dp[i][j-1])
            afisare(i,j-1);
        else
        {
            afisare(i-1,j-1);
            fout << a[i] << " ";
        }
   }
}

void cmlsc()
{
    CompletareDP();
    afisare(n,m);
}

int main()
{
    citeste();
    cmlsc();
    return 0;
}
