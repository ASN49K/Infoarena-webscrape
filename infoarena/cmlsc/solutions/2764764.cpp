#include <bits/stdc++.h>

using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

//ifstream f("prieteni.in");
//ofstream g("prieteni.out");

int a[1025], b[1025], sir[1025];
int c[1025][1025];
int n, m;

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
    int q=0, i, j;
    g<<c[n][m]<<'\n';
    i=n;
    j=m;
    while(i>0){
        if(a[i]==b[j])
            sir[++q]=a[i], --i, --j;
        else
        {
            if(c[i-1][j]<c[i][j-1])
                --j;
            else
                --i;
        }
    }

    for(int i=c[n][m]; i>=1; --i)
        g<<sir[i]<<' ';

    return 0;
}
