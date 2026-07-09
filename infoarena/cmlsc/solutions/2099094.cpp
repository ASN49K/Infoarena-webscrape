#include <bits/stdc++.h>

using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int c[1025][1025],a[1025],b[1025],n,m,k;
bool verif[1025][1025];
string rez;

void backtrack(int c[1025][1025],int a[],int b[],int i,int j)
{
    if (i==0||j==0) return ;
    if (a[i]==b[j]&&!verif[i][j]) {rez+=a[i]; verif[i][j]=1; k++; backtrack(c,a,b,i-1,j-1);}
    if (c[i][j-1]>c[i-1][j]) backtrack(c,a,b,i,j-1);
    backtrack(c,a,b,i-1,j);
}

int main()
{
    int n,m;
    f>>n>>m;
    for (int i=1;i<=n;++i) f>>a[i];
    for (int i=1;i<=m;++i) f>>b[i];
    for (int i=1;i<=n;++i)
    {
        for (int j=1;j<=m;++j)
        {
            if (a[i]==b[j]) {c[i][j]=c[i-1][j-1]+1;}
            else c[i][j]=max(c[i-1][j],c[i][j-1]);
        }
    }
    backtrack(c,a,b,n,m);
    g<<k<<'\n';
    for (int i=k-1;i>=0;--i) g<<(int)(rez[i])<<" ";
    return 0;
}
