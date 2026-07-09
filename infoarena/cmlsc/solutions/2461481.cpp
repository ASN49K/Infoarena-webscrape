#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int n,m,a[1200],b[1200],dp[1200][1200];
void citire()
{
    fin>>n>>m;
    for(int i=1; i<=n; i++)
        fin>>a[i];
    for(int i=1; i<=m; i++)
        fin>>b[i];
}
void cmlsc()
{
    for(int i=1; i<=n; i++)
        if(a[i]==b[1]||dp[i-1][1]) dp[i][1]=1;
    for(int i=1; i<=m; i++)
        if(b[i]==a[1]||dp[1][i-1]) dp[1][i]=1;
    for(int i=2; i<=n; i++)
        for(int j=2; j<=m; j++)
        {
            if(a[i]==b[j]) dp[i][j]=dp[i-1][j-1]+1;
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }

}
void creare_solutie(int i,int j)
{
    if(i==0||j==0)return;
    if(dp[i][j]==dp[i-1][j]) {creare_solutie(i-1,j); return;}
    if(dp[i][j]==dp[i][j-1]) {creare_solutie(i,j-1); return;}
    if(dp[i][j]==dp[i-1][j-1]+1) {creare_solutie(i-1,j-1); fout<<a[i]<<" "; return;}
}
int main()
{
    citire();
    cmlsc();
    fout<<dp[n][m]<<"\n";
    creare_solutie(n,m);
    return 0;
}
