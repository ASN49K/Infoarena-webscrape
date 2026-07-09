#include <fstream>

using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int v1[1025],v2[1025],d[1025][1025],n,m,i,j,k,sol[1025];

int main()
{
    f>>n>>m;
    for(i=1;i<=n;i++)
        f>>v1[i];
    for(i=1;i<=m;i++)
        f>>v2[i];
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            if(v1[i]==v2[j])
            {
                d[i][j]=d[i-1][j-1]+1;
            }
            else
            {
                d[i][j]=max(d[i-1][j],d[i][j-1]);
            }
        }
    }

    i=n;
    j=m;

    while(i!=1||j!=1)
    {
        if(v1[i]==v2[j])
        {
            sol[++k]=v1[i];
            if(i!=1)
                i--;
            if(j!=1)
                j--;
        }
        else
        {
            if((d[i-1][j]>d[i][j-1]||j==1)&&i!=1) i--;
            else j--;
        }
    }

    g<<k<<'\n';
    for(i=k;i>=1;i--)
        g<<sol[i]<<" ";

    return 0;
}
