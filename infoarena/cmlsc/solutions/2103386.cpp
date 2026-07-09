#include <bits/stdc++.h>
using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int a[1025];
int k=0,sir[1025];
int L[1025][1025];
void lsc( int X[], int Y[], int m, int n)
{

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
    int X[1025], Y[1025];
    int n,m;
    fin>>m>>n;
    for(int i=1;i<=m;i++)
        fin>>X[i];
    for(int i=1;i<=n;i++)
        fin>>Y[i];
    lsc(X,Y,m,n);
    fout<<k<<'\n';
    for(int i=k;i>0;--i)
        fout<<sir[i]<<" ";
    return 0;

}


