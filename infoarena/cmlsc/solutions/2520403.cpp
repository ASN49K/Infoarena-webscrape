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
    fin>>m>>n;
    for(i=1;i<=m;i++)
        fin>>a[i];
    for(j=1;j<=n;j++)
        fin>>b[j];
    for(i=1;i<=m;i++){
        for(j=1;j<=n;j++){
            dp[i][j]=max(dp[i-1][j],max(dp[i][j-1],dp[i-1][j-1]+(a[i]==b[j])));
        }
    }
    fout<<dp[m][n]<<'\n';
    i=m;j=n;
    while(i>0&&j>0&&dp[i][j]!=0){
        while(dp[i][j]==dp[i-1][j])
            i--;
        while(dp[i][j]==dp[i][j-1])
            j--;
        v.push_back(a[i]);
        i--;
    }
    for(i=v.size()-1;i>=0;i--)
        fout<<v[i]<<" ";
    return 0;
}
