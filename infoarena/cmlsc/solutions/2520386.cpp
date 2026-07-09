#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int dp[1025][1025];
short n,m,i,j;
short a[1025],b[1025];
int p;

vector <short> v;

int main()
{
    fin>>n>>m;
    for(i=1;i<=n;i++)
        fin>>a[i];
    for(j=1;j<=m;j++)
        fin>>b[j];
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            dp[i][j]=max(dp[i-1][j],max(dp[i][j-1],dp[i-1][j-1]+(a[i]==b[j])));
        }
    }
    fout<<dp[n][m]<<'\n';
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            if(dp[i][j]>p)
                v.push_back(a[i]);
            p=dp[i][j];
        }
    }
    for(auto it:v)
        fout<<it<<' ';
    return 0;
}
