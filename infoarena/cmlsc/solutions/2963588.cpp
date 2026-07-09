#include<fstream>
#include<iostream>
using namespace std;

const int N=1024;
int a[N+1], b[N+1], dp[N+1][N+1], m, n;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");


void refac_subsir(int l, int c)
{
    if(l==0 && c==0)
    {
        return;
    }
    if(a[l]==b[c])
    {
        refac_subsir(l-1, c-1);
        fout << a[l] << " ";
    }
    else
    {
            if(dp[l-1][c] > dp[l][c-1])
            {
                refac_subsir(l-1, c);
            }
            else
            {
                    refac_subsir(l, c-1);
            }
    }

}

int main()
{
    fin >> m >> n;
    for(int i=1; i<=m; i++)
    {
        fin >> a[i];
    }
    for(int j=1; j<=n; j++)
    {
        fin >> b[j];
    }
    for(int i=1; i<=m; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(a[i]==b[j])
                dp[i][j]= 1+ dp[i-1][j-1];
            else
            {
                dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    fout << dp[m][n] << "\n";
    refac_subsir(m, n);
    fin.close();
    fout.close();
    return 0;
}
