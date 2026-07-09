#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int dp[1025][1025];
short n,m,i,j;
short a[1025],b[1025];

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
            if(dp[i][j]>dp[i-1][j] && dp[i][j]>dp[i][j-1])
                v.push_back(a[i]);
        }
    }
    fout<<v.size()<<'\n';
    for(auto it:v)
        fout<<it<<" ";
    return 0;
}
