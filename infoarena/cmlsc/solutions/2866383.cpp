#include <iostream>
#include <fstream>
using namespace std;
ifstream fin ("cmlsc.in");
ofstream fout ("cmlsc.out");
int n,i,j,m,a[1030],b[1030],dp[1030][1030],st1,st2,depus,afis[1030];
int main()
{
    fin>>n>>m;
    for(i=1;i<=n;i++) fin>>a[i];
    for(i=1;i<=m;i++) fin>>b[i];
    for(i=n;i>=1;i--)
    {
        for(j=m;j>=1;j--)
        {
            if(a[i]==b[j]) dp[i][j]=dp[i+1][j+1]+1;
            else dp[i][j]=max(dp[i+1][j],dp[i][j+1]);

        }
    }
    fout<<dp[1][1]<<'\n';
    st1=n;st2=m;
    while(st1>=1 and st2>=1)
    {
        if(a[st1]==b[st2])
        {
            depus++;
            afis[depus]=a[st1];
            st1--;st2--;
        }
        else
        {
            if(dp[st1][st2-1]>=dp[st1-1][st2]) st2--;
            else st1--;
        }
    }
    for(i=depus;i>=1;i--) fout<<afis[i]<<' ';
    return 0;
}
