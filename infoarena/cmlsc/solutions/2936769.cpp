#include <bits/stdc++.h>

using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
const int N = 1030;
int n,m,a[N],b[N],d[N][N];
void afiseaza(int lin,int col)
{
    if(d[lin][col]==0)
        return;
    if(a[lin]==b[col])
    {
        afiseaza(lin-1,col-1);
        g<<a[lin]<<' ';
    }
    else
    {
        if(d[lin-1][col]>=d[lin][col-1])
            afiseaza(lin-1,col);
        else
            afiseaza(lin,col-1);
    }
}
int main()
{
    f>>n>>m;
    for(int i=1; i<=n; i++)f>>a[i];
    for(int i=1; i<=m; i++)f>>b[i];
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
        {
            if(a[i]==b[j])
                d[i][j]=d[i-1][j-1]+1;
            else
                d[i][j]=max(d[i][j-1],d[i-1][j]);
        }
    g<<d[n][m]<<'\n';
    afiseaza(n,m);
    return 0;
}

/// d[i][j] = lungimea celui mai mic subsir comun daca luam
/// - primele i elemente din a[]
/// - primele j elemente din b[]
/// 1> a[i]==b[j] d[i][j]=d[i-1][j-1]+1
/// 2> a[i]!=b[j] d[i][j]=max(d[i-1][j],d[i][j-1])
/// lungime maxima (solutie) d[n][m]


//    7 5 8
//  0 0 0 0
//1 0 0 0 0
//7 0 1 1 1
//3 0 1 1 1
//9 0 1 1 1
//8 0 1 1 2
//
//l c
//5 3 8 l-- c--
//4 2   c--
//4 1   l--
//3 1   l--
//2 1 7 l-- c--
