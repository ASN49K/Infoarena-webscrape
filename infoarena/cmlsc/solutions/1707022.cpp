#include<fstream>
#define N 1025
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int x[N][N],t[N];

int main()
{
    int i,j,n,m,v[N],w[N];
    f>>n>>m;
    for(i=1;i<=n;i++)
        f>>v[i];
    for(i=1;i<=m;i++)
        f>>w[i];
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
        {
            if(v[i]==w[j])
                x[i][j] = 1+x[i-1][j-1];
            else
            {
                if(x[i-1][j] > x[i][j-1])
                    x[i][j] = x[i-1][j];
                else
                    x[i][j] = x[i][j-1];
            }
        }
    i=n;
    j=m;
    while(i!=0 && j!=0)
        if(v[i]==w[j])
        {
            t[++t[0]]=v[i];
            --i;
            --j;
        }
        else
            if(x[i-1][j]<x[i][j-1])
                --j;
            else
                --i;
    g<<t[0]<<'\n';
    for(i=t[0];i;i--)
        g<<t[i]<<" ";
    return 0;
}
