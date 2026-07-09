#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int n,m;
int a[1025],b[1025];
int dp[1025][1025];
int rez[1025];

int main()
{
    int cont=1;
    fin >> n >> m;
    for(int i=1;i<=n;i++) fin >> a[i];
    for(int i=1;i<=m;i++) fin >> b[i];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(a[i]==b[j])
            {
                dp[i][j]=dp[i-1][j-1]+1;
            }
            else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    fout << dp[n][m] << '\n';
    int i=n,j=m;
    while(i*j!=1)
    {
        if(dp[i-1][j]==dp[i][j]) i--;
        else if(dp[i][j-1]==dp[i][j]) j--;
        else
        {
            rez[cont++]=a[i];
            i--;
            j--;
        }
    }
    for(int i=1;i<cont;i++) fout << rez[i] << ' ';
}
