#include <iostream>
#include <fstream>
using namespace std;
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");
int n,m,contor;
int a[1030],b[1030],dp[1030][1030],sir[1030];
int main()
{
    in>>n>>m;
    for(int i=1;i<=n;++i)
        in>>a[i];
    for(int i=1;i<=m;++i)
        in>>b[i];
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            if(a[i]==b[j])
                dp[i][j]=1+dp[i-1][j-1];
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    for(int i=n,j=m;i>0;){
        if(a[i]==b[j]){
            contor++;
            sir[contor]=a[i];
            i--;
            j--;
        }
        else if(dp[i-1][j]<dp[i][j-1]) j--;
        else i--;
    }
    out<<dp[n][m]<<'\n';
    for(int i=contor;i>0;--i)
        out<<sir[i]<<" ";
    return 0;
}
