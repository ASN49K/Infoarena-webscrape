#include <bits/stdc++.h>

using namespace std;
int n,m,a[10001], b[10001], c[10001][10001], i, j,d[10001],h;
int main()
{
    ifstream f("cmlsc.in");
    ofstream g("cmlsc.out");

    f>>n>>m;
    for(i=1;i<=n;i++)
    f>>a[i];
    for(j=1;j<=m;j++)
    f>>b[j];

    for(i=1;i<=n;i++)
    for(j=1;j<=m;j++) c[i][j]=0;

    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            if(a[i]==b[j]) c[i][j]=1+c[i-1][j-1];
            else c[i][j]=max(max(c[i-1][j],c[i][j-1]),c[i-1][j-1]);
        }
    }
   g<<c[n][m];
   g<<endl;
   while(i>=0 && j>=0)
    {
        if(a[i]==b[j]) d[++h]=a[i], --i, --j;
        else if(c[i-1][j]< c[i][j-1]) --j;
        else --i;
    }

    for(i=h;i>=1;i--)
    if(d[i]!=0)
    g<<d[i]<<" ";


    return 0;
}
