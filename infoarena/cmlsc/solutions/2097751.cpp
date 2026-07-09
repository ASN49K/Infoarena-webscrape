#include <bits/stdc++.h>
using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int a[2001],k=0;

void lsc( int *X, int *Y, int m, int n)
{
    int L[m+1][n+1];
    for(int i=0;i<=m;i++)
    {
        for(int j=0;j<=n;j++)
            if (i==0 or j==0)
                L[i][j]=0;
            else if (X[i-1] == Y[j-1])
                L[i][j]=L[i-1][j-1]+1,a[++k]=X[i-1];
            else
                L[i][j] = max(L[i-1][j], L[i][j-1]);

    }
    fout<<L[m][n];

}


int main()
{
    int X[2001], Y[2001];
    int n,m;
    fin>>m>>n;
    for(int i=0;i<m;i++)
        fin>>X[i];
    for(int i=0;i<n;i++)
        fin>>Y[i];
    lsc( X, Y, m , n);
    fout<<endl;
    for(int i=1;i<=k;i++)
        fout<<a[i]<<" ";
    return 0;

}
