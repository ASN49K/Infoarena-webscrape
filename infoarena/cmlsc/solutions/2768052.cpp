#include <iostream>
#include <fstream>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int N,M,A[1030],B[1030],Dp[1030][1030];
int sir[1030],bst;
int main()
{
    f>>N>>M;
    for(int i=1; i<=N; i++)
        f>>A[i];

    for(int i=1; i<=M; i++)
        f>>B[i];


    for(int i=1; i<=N; i++)
        for(int j=1; j<=M; j++)
        {
            if(A[i]==B[j])
                Dp[i][j]=Dp[i-1][j-1]+1;
            else Dp[i][j]=max(Dp[i-1][j],Dp[i][j-1]);
        }

    int i=N,j=M;
    while(i>0 && j>0)
    {
        if(A[i]==B[j])
        {
            sir[bst++]=A[i];
            i--;
            j--;
        }
        else
        {
            if(Dp[i-1][j]>Dp[i][j-1])
                i--;
            else j--;
        }
    }

    g<<bst<<'\n';
    for(int i=bst-1; i>=0; i--)
        g<<sir[i]<<" ";
    return 0;
}
