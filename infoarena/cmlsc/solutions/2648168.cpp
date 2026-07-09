#include <fstream>

using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int m,n,v[1025],v2[1025],d[1025][1025],rasp[1025];
int main()
{
    f>>n>>m;
    for(int i=1; i<=n; ++i)
    {
        f>>v[i];
    }
    for(int i=1; i<=m; ++i)
    {
        f>>v2[i];
    }
    for(int i=1; i<=n; ++i)
    {
        for(int j=1; j<=m; ++j)
        {
            if(v[i]==v2[j])
            {
                d[i][j]=d[i-1][j-1]+1;
            }
            else
            {
                d[i][j]=max(d[i][j-1],d[i-1][j]);
            }
        }
    }
    g<<d[n][m]<<'\n';
int i=n,j=m,nr=d[n][m];
while(i>0 && j>0)
{
    if(v[i]==v2[j])
    {
        rasp[nr]=v[i];
        nr--;
        i--;
        j--;
    }
    else
    {
        if(d[i-1][j]>d[i][j-1])
        {
            i--;
        }
        else
        {
            j--;
        }
    }
}
for(int k=1; k<=d[n][m]; ++k)
{
    g<<rasp[k]<<" ";
}
                return 0;
}
