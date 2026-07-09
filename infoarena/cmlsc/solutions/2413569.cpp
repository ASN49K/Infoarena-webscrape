#include <bits/stdc++.h>
#define Dim 1030
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int N,M,A[Dim],B[Dim],C[Dim][Dim],cnt,S[Dim];

void Write(int a,int b)
{
    if(a>=1&&b>=1)
    {
        if(A[a]==B[b])
        {
            S[++cnt]=A[a];
            Write(a-1,b-1);
        }
        else
        if(C[a][b-1]>=C[a-1][b])
        Write(a,b-1);
        else
        Write(a-1,b);
    }
}

int main()
{
    f>>N>>M;
    for(int i=1;i<=N;i++)
    {
        f>>A[i];
        C[i][0]=0;
    }
    for(int i=1;i<=M;i++)
    {
        f>>B[i];
        C[i][0]=0;
    }
    for(int i=1;i<=N;i++)
    for(int j=1;j<=M;j++)
    if(A[i]==B[j])
    C[i][j]=C[i-1][j-1]+1;
    else
    C[i][j]=max(C[i-1][j],C[i][j-1]);

    g<<C[N][M]<<'\n';
    Write(N,M);
    for(int i=cnt;i>=1;i--) g<<S[i]<<" ";
    return 0;
}
