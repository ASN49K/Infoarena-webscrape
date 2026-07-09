#include <iostream>
#include <fstream>
#define MAX 1025
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int v[MAX],x[MAX],a[MAX][MAX];
void afis(int i,int j)
{

    if(i>=1&&j>=1)
    {
        if(v[i]!=x[j])
            {if(a[i-1][j]>a[i][j-1]) afis(i-1,j);
        else afis(i,j-1);}
        else {
            afis(i-1,j-1);
            g<<v[i]<<" ";
        }

    }
}
int main()
{
    int n,m,i,j;
    f>>n>>m;
    for(i=1;i<=n;i++)
        f>>v[i];
    for(j=1;j<=m;j++)
        f>>x[j];
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
    {
        if(v[i]==x[j])a[i][j]=a[i-1][j-1]+1;
        else a[i][j]=max(a[i-1][j],a[i][j-1]);
    }
    g<<a[n][m]<<'\n';
    afis(n,m);
    return 0;
}
