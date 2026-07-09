#include<fstream>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int m,n, v[1025], w[1025], i, j, a[1025][1025], x[1025], k;
int main()
{
    f>>n>>m;
    for(i=1;i<=n;i++)f>>v[i];
    for(i=1;i<=m;i++)f>>w[i];
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            if(v[i]==w[j])a[i][j]=a[i-1][j-1]+1;
            else
            {
                a[i][j]=max(a[i-1][j],a[i][j-1]);
            }
        }
    }
    i=n;
    j=m;
    while(i&&j)
    {
        if(v[i]==w[j])
        {
            x[++k]=v[i];
            i--;
            j--;
        }
        else
        {
            if(a[i][j]==a[i-1][j])i--;
            else j--;
        }
    }
    g<<k<<'\n';
    for(i=k;i>=1;i--)g<<x[i]<<" ";
    f.close();
    g.close();
    return 0;
}
