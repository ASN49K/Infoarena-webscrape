#include <fstream>

using namespace std;
int n,m,k,i,j,x,y,v[1035],w[1035],d[1035][1035];
struct vec{int a,b;}p[1035][1035];
int main()
{
    ifstream f("cmlsc.in");
    ofstream g("cmlsc.out");
    f>>n>>m;
    for(i=1; i<=n; i++) f>>v[i];
    for(i=1; i<=m; i++) f>>w[i];
    for(i=1; i<=n; i++)
    for(j=1; j<=m; j++)
    {
        if(v[i]==w[j])
        {
            d[i][j]=d[i-1][j-1]+1;
            p[i][j].a=i;
            p[i][j].b=j;
        }
        if(d[i][j]<d[i][j-1])
        {
            d[i][j]=d[i][j-1];
            p[i][j]=p[i][j-1];
        }
        if(d[i][j]<d[i-1][j])
        {
            d[i][j]=d[i-1][j];
            p[i][j]=p[i-1][j];
        }
    }
    g<<d[n][m]<<'\n';
    i=p[n][m].a;
    j=p[n][m].b;
    k=0;
    while(i&&j)
    {
        k++;
        w[k]=v[i];
        x=p[i-1][j-1].a;
        y=p[i-1][j-1].b;
        i=x;
        j=y;
    }
    while(k)
    {
        g<<w[k]<<" ";
        k--;
    }
    f.close(); g.close();
    return 0;
}
