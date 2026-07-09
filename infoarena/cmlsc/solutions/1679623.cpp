#include <iostream>
#include <fstream>

using namespace std;
ifstream in ("cmlsc.in");
ofstream out ("cmlsc.out");
int n,m,d[1030][1030],a[1030],b[1030];

void afis (int i,int j)
{
    if(i==0 or j==0)
        return;
    if(a[i]==b[j])
    {
        afis(i-1,j-1);
        out<<a[i]<<" ";
        return;
    }
    if(d[i-1][j]>d[i][j-1])
        afis(i-1,j);
    else
        afis(i,j-1);
}

int max(int a,int b)
{
    if(a>=b)
        return a;
    else
        return b;
}

int main()
{
    in>>n>>m;
    int i,j;
    for(i=1; i<=n; i++)
        in>>a[i];
    for(i=1; i<=m; i++)
        in>>b[i];
    for(i=1; i<=n; i++)
        for(j=1; j<=m; j++)
        {
            if(a[i]==b[j])
                d[i][j]=1+d[i-1][j-1];
            else
                d[i][j]=max(d[i-1][j],d[i][j-1]);
        }
    out<<d[n][m]<<'\n';
    afis(n,m);
    return 0;
}
