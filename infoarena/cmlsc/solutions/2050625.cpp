#include <iostream>
#include <fstream>
using namespace std;
ofstream fout("cmlsc.out");
ifstream fin("cmlsc.in");
int n,m,s1[1050],s2[1050],dp[1050][1050];
int main()
{
    fin>>n>>m;
    for(int i=1;i<=n;i++)
        fin>>s1[i];
    for(int i=1;i<=m;i++)
        fin>>s2[i];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            if(s1[i]==s2[j])
                dp[i][j]=max(dp[i][j],dp[i-1][j-1]+1);
        }
    int g=1;
//    fout<<dp[n][m]<<"\n";
//    for(int i=1;i<=n;i++)
//        for(int j=1;j<=n;j++)
//            if(dp[i][j]==g)
//            {
//                fout<<s1[i]<<" ";
//                g++;
//            }
    return 0;
}
