#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int dp[1030][1030],N,M,A[1030],B[1030],sol[1030],k;
void read()
{
    fin>>N>>M;
    for(int i=1;i<=N;i++)
        fin>>A[i];
    for(int i=1;i<=M;i++)
        fin>>B[i];
}
void afis()
{
    fout<<k<<"\n";
    for(int i=k;i>=1;i--)
        fout<<sol[i]<<" ";
    fout<<"\n";
}
void solve()
{
    if(A[1]==B[1])
        dp[1][1]=1;
    else
        dp[1][1]=0;
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=M;j++)
        {
            if(A[i]==B[j])
                dp[i][j]=1+dp[i-1][j-1];
            else
                dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
        }
    }
    int i=N,j=M;
    while(i>0 && j>0)
    {
        if(A[i]==B[j])
           {
               sol[++k]=A[i];
               i--;
               j--;
           }
        else
            if(dp[i][j-1]>dp[i-1][j])
            j--;
        else
            i--;
    }
    afis();
}
int main()
{
    read();
    solve();
    fin.close();
    fout.close();
    return 0;
}
