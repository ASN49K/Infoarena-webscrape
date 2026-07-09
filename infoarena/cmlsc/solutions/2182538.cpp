#include <bits/stdc++.h>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int n, m;
int x[1025], y[1025];
int D[1025][1025];
int sol[1025];

int main()
{
    fin>>n>>m;
    for(int i=1; i<=n; ++i) fin>>x[i];
    for(int j=1; j<=m; ++j) fin>>y[j];
    for(int i=1; i<=n; ++i)
    {
        for(int j=1; j<=m; ++j)
        {
            if(x[i]==y[j]) D[i][j]=D[i-1][j-1]+1;
            else D[i][j]=max(D[i-1][j], D[i][j-1]);
        }
    }
    int k=0;
    int i=n, j=m;
    while(i)
    {
        if(x[i]==y[j])
        {
            sol[++k]=x[i];
            --i; --j;
        }
        else if(D[i-1][j]<D[i][j-1]) --j;
        else --i;
    }
    fout<<D[n][m]<<"\n";
    for(int i=k; i>=1; --i) fout<<sol[i]<<" ";
    fout<<"\n";
    return 0;
}
