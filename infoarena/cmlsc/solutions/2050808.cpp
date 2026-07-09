#include <bits/stdc++.h>

using namespace std;
ifstream fin ("cmlsc.in");
ofstream fout ("cmlsc.out");
int n,m,v1[1025],v2[1025],dp[1025][1025];
int main()
{
    fin>>n>>m;
    for(int i=1;i<=n;i++)
        fin>>v1[i];
    for(int i=1;i<=m;i++)
        fin>>v2[i];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
    {
        if(v1[i]==v2[j])
            dp[i][j]=dp[i-1][j-1]+1;
        else
            dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
    }
    fout<<dp[n][m]<<endl;
    /* for(int i=1;i<=n;i++)
     {
         fout<<endl;
         for(int j=1;j<=m;j++)
    fout<<dp[i][j]<<" ";
     }*/
     int i=n,j=m,x[1025],q=0;
     while(i>0 && j>0 && dp[i][j]>0)
     {
         if(v1[i]==v2[j])
         {  x[q]=v1[i];
             i--;
             j--;
             q++;
         }
         else
         {
             if(dp[i-1][j]>dp[i][j-1])
                i--;
             else
                j--;
         }
     }
     for(int i=q-1;i>=0;i--)
        fout<<x[i]<<" ";

    return 0;
}
