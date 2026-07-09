#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int A[1027],B[1027],dp[1027][1027],sol[1027];
int M,N,k,i,j;
int main()
{
    fin>>N>>M;
    for( i=1;i<=N;i++)
    {
        int x;
        fin>>x;
        A[i]=x;
    }
    for( i=1;i<=M;i++)
    {
        int x;
        fin>>x;
        B[i]=x;
    }
    for( i=1;i<=N;i++)
    {
        for( j=1;j<=M;j++)
        {
            if(A[i]==B[j])
                dp[i][j]=dp[i-1][j-1]+1;
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    for( i=N, j=M;i;)
    {
        if(A[i]==B[j])
        {
            sol[++k]=A[i];
            i--;
            j--;
        }
        else
            if(dp[i-1][j]<dp[i][j-1])
                j--;
            else
                i--;
    }
    fout<<k<<"\n";
    for( i=k;i>=1;i--)
        fout<<sol[i]<<" ";
    return 0;
}
