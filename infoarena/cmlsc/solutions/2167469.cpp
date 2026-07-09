#include <bits/stdc++.h>
#define N 1030
using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int na,nb;
int a[N],b[N];
int t[N][N];
int sir[N]; int nsir;

int main()
{   int i,j;
    fin>>na>>nb;
    for (i=1;i<=na;i++) fin>>a[i];
    for (i=1;i<=nb;i++) fin>>b[i];
    fin.close();

    for (i=1;i<=na;i++)
        for (j=1;j<=nb;j++)
             if (a[i]==b[j]) { sir[++nsir]=a[i]; t[i][j]=t[i-1][j-1]+1; }
             else t[i][j]=max(t[i-1][j],t[i][j-1]);

    fout<<t[na][nb]<<"\n";
    for (i=1;i<=nsir;i++) fout<<sir[i]<<" ";
    fout<<"\n";
    return 0;
}
