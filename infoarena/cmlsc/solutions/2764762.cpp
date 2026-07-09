#include <bits/stdc++.h>

using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

//ifstream f("prieteni.in");
//ofstream g("prieteni.out");

int a[1025], b[1025];
int c[1025][1025];
int n, m;

void show_seq(int x, int y)
{
    if(x==0 && y==0)
        return;

    if(c[x][y]==c[x-1][x-1]+1)
    {
        show_seq(x-1, y-1);
        g<<a[x]<<' ';
    }
    else
    {
        if(c[x][y]==c[x-1][y])
            show_seq(x-1, y);
        else
            show_seq(x, y-1);
    }

}

int main(){
    f>>n>>m;

    for(int i=1; i<=n; ++i)
        f>>a[i];

    for(int i=1; i<=m; ++i)
        f>>b[i];

    for(int i=1; i<=n; ++i)
    {
        for(int j=1; j<=m; ++j)
            if(a[i]==b[j])
            {
                c[i][j]=c[i-1][j-1]+1;
            }
            else
                c[i][j]=max(c[i-1][j], c[i][j-1]);
    }

    g<<c[n][m]<<'\n';

    show_seq(n, m);

    return 0;
}
