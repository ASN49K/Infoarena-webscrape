#include <bits/stdc++.h>
#define N 1025
using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int n, m;
int a[N], b[N];
int D[N][N];
int sol[N], nsol;

void Read()
{
    fin>>n>>m;
    for(int i=1; i<=n; i++) fin>>a[i];
    for(int i=1; i<=m; i++) fin>>b[i];
}

void Precalculare()
{
    int i, j;
    for(i=1; i<=n; i++)
        for(j=1; j<=m; j++)
        {
            if(a[i]==b[j]) D[i][j]=D[i-1][j-1]+1;
            else
                D[i][j]=max(D[i-1][j], D[i][j-1]);
        }
    fout<<D[n][m]<<"\n";
}

void Do()
{
    int i=n, j=m;
    while(i>0 && j>0)
    {
        if(a[i]==b[j]) {sol[++nsol]=a[i]; i--; j--;}
        else
            if(D[i-1][j]>D[i][j-1]) i--;
            else j--;
    }
    for(int k=nsol; k>=1; k--) fout<<sol[k]<<" ";
    fout<<"\n";
}

int main()
{
    Read();
    Precalculare();

    /*for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++) cout<<D[i][j]<<" ";
        cout<<"\n";
    }*/

    Do();
    return 0;
}
