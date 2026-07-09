#include <bits/stdc++.h>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int i,j,bst,N,M;
int A[1025],B[1025],cmlsc[1025];
int Dp[1024][1024];
int main()
{
    f>>N>>M;
    for(i=1; i<=N; i++)
        f>>A[i];

    for(j=1; j<=M; j++)
        f>>B[j];

    for(i=1; i<=N; i++)
        for(j=1; j<=M; j++)
        {
            if(A[i]==B[j])
                Dp[i][j]=1+Dp[i-1][j-1];

            else
                Dp[i][j]=max(Dp[i-1][j],Dp[i][j-1]);
        }
    i=N;
    j=M;
    while(i>0 && j>0)
    {
        if(A[i]==B[j])
        {
            cmlsc[bst++]=A[i];
            i--;
            j--;
        }
        else
        {
            if(Dp[i-1][j]<Dp[i][j-1])
                j--;
            else
                i--;
        }


    }
    g<<bst<<"\n";

    for(i=bst-1; i>=0; i--)
        g<<cmlsc[i]<<" ";

    return 0;
}
