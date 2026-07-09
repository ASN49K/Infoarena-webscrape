#include <bits/stdc++.h>
#define FOR(i, a, b) for (i = a; i <= b; ++i)
int n,m,bst=1,ops=0,jk;
int a[10000];
int b[10000];
int c[10000][10000];
int d[10000];
using namespace std;
ifstream f("sir.in");
ofstream g("sir.out");
void citire()
{
    for(int i=1;i<=n;i++)
    f>>a[i];
    for(int i=1;i<=m;i++)
    f>>b[i];
}
void afisare()
{
g<<ops<<'\n';
for(int i=1;i<=ops;i++)
    g<<d[i]<<' ';
g<<'\n';
for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++)
        g<<c[i][j]<<' ';
    g<<'\n';
}
}
int main()
{int i,j;
    f>>n>>m;
citire();

for( i=1;i<=n;i++){
    for( j=1;j<=m;j++)
            if(a[i]==b[j]){
                c[i][j]=ops+1;ops++;
                d[i]=a[i];
            }
            else
                c[i][j]=max(c[i-1][j],c[i][j-1]);

}


for (i = n, j = m; i; ){
        if (a[i] == b[j])
            d[++bst] = a[i], --i, --j;
        else if (c[i-1][j] < c[i][j-1])
            --j;
        else
            --i;
}

afisare();
    return 0;
}
