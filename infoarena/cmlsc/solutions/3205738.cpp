#include<bits/stdc++.h>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
#define maxmn 1025
int M, N, A[maxmn], B[maxmn], D[maxmn][maxmn], P[maxmn], i, j, k;
int main()
{
    fin>>M>>N;
    for(i=1;i<=M;i++)
    {
        fin>>A[i];
    }
    for(i=1;i<=N;i++)
    {
        fin>>B[i];
    }
    for(i=1;i<=M;i++)
    {
        for(j=1;j<=N;j++)
        {
            if(A[i]==B[j])
            {
                D[i][j]=1+D[i-1][j-1];
            }
            else
            {
                D[i][j]=max(D[i][j-1], D[i-1][j]);
            }
        }
    }
    i=M; j=N;
    while(i&&j)
    {
        if(A[i]==B[j])
        {
            P[++k]=A[i];
            i--;j--;
        }
        else
        {
            if(D[i-1][j]<D[i][j-1])
            {
                j--;
            }
            else
            {
                i--;
            }
        }
    }
    fout<<k<<'\n';
    for(i=k;i>=1;i--)
    {
        fout<<P[i]<<' ';
    }
    return 0;
}