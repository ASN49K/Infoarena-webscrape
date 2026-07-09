#include <fstream>

using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int n,m,i,j,a[1025],b[1025],d[1025][1025],rasp,v[1025];
int main()
{
    f>>n>>m;
    for(i=1;i<=n;i++)
    {
        f>>a[i];
    }
    for(i=1;i<=m;i++)
    {
        f>>b[i];
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            if(a[i]==b[j])
            {
                d[i][j]=d[i-1][j-1]+1;
            }
            else
            {
                d[i][j]=max(d[i-1][j],d[i][j-1]);
            }
            rasp=max(rasp,d[i][j]);
        }
    }
    g<<rasp<<'\n';
    i=n,j=m;
    n=rasp;
    while(i>=1 && j>=1)
    {
        if(a[i]==b[j])
        {
            v[rasp]=b[j];
            rasp--;
            j--;
            i--;
        }
        else
        {
            if(d[i-1][j]<d[i][j-1])
            {
                j--;
            }
            else
            {
                i--;
            }
        }
    }
    for(i=1;i<=n;i++)
    {
        g<<v[i]<<" ";
    }
    return 0;
}
