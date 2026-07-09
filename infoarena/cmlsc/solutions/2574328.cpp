#include <iostream>
#include <fstream>
using namespace std;
const int NMAX=1030;
ifstream in ("cmlsc.in");
ofstream out ("cmlsc.out");
int a[NMAX],b[NMAX];
int dp[NMAX][NMAX],c[2*NMAX];
int main()
{
    int n,m,i,j;
    in>>n>>m;
    for(i=1;i<=n;i++)
        in>>a[i];
    for(j=1;j<=m;j++)
        in>>b[j];
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++)
            if(a[i]==b[j])
                dp[i][j]=dp[i-1][j-1]+1;
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
    }
    int cnt=0;
    for(i=n,j=m;i;){
        if(a[i]==b[j]){
            c[++cnt]=a[i];
            i--,j--;
        }
        else{
            if(dp[i-1][j]<dp[i][j-1])
                j--;
            else i--;
        }
    }
    out<<cnt<<'\n';
    for(i=cnt;i>=1;i--)
        out<<c[i]<<" ";
    return 0;
}
