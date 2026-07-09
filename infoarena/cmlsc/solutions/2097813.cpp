#include <bits/stdc++.h>
using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int a[2001];
int k=0,sir[2001];

void lsc( int *X, int *Y, int m, int n)
{
    int L[m+1][n+1];
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
             if (X[i] == Y[j])
                L[i][j]=L[i-1][j-1]+1;
            else
                L[i][j] = max(L[i-1][j], L[i][j-1]);
    }
    int i=m,j=n;
    while(i)
        if(X[i]==Y[j])
            sir[++k]=X[i],--i,--j;
        else if(L[i-1][j]<L[i][j-1])
            --j;
        else
            --i;
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
    lsc(X,Y,m,n);
    fout<<k<<endl;
    for(int i=k;i>0;--i)
        fout<<sir[i]<<" ";
    return 0;

}


