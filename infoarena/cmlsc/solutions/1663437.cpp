#include <iostream>
#include <fstream>

using namespace std;

int n,m,nr;
int a[1030],b[1030],d[1030][1030],ans[1030];

int main()
{
    ifstream f("cmlsc.in");
    ofstream g("cmlsc.out");
    f>>n>>m;
    for(int i=1;i<=n;i++)
        f>>a[i];
    for(int i=1;i<=m;i++)
        f>>b[i];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            if(a[i]==b[j])
                d[i][j]=d[i-1][j-1]+1;
            else
                d[i][j]=max(d[i-1][j],d[i][j-1]);
        }
    for(int i=n,j=m; i; )
    {
        if(a[i]==b[j])
            ans[++nr]=a[i],i--,j--;
        else if(d[i-1][j]<d[i][j-1])
            j--;
        else
            i--;
    }
    g<<d[n][m]<<'\n';
    for(int i=nr;i;i--)
        g<<ans[i]<<" ";
    g<<'\n';
    f.close();
    g.close();
    return 0;
}
