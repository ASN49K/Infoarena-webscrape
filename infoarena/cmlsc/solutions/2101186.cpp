#include <fstream>

using namespace std;
int i,j,n,m,t;
int v[1050],u[1050],r[1050][1050],w[1050];
int main()
{
    ifstream f("cmlsc.in");
    ofstream g("cmlsc.out");

    f>>n>>m;
    for(i=1;i<=n;i=i+1)
        f>>v[i];
    for(j=1;j<=m;j=j+1)
        f>>u[j];

    for(i=1;i<=n;i=i+1)
        for(j=1;j<=m;j=j+1)
    {
        if(v[i]==u[j])
            r[i][j]=r[i-1][j-1]+1;
        else
            r[i][j]=max(r[i-1][j],r[i][j-1]);
    }
    g<<r[n][m]<<'\n';


    i=n;j=m;
    while(i!=0||j!=0)
    {
        if(v[i]==u[j])
        {
            w[++t]=v[i];
            i--;
            j--;
        }
        else
        {
            if(r[i-1][j]<r[i][j-1])
                j--;
            else
                i--;
        }
    }

    for(i=t;i>=1;i--)
        g<<w[i]<<' ';


    return 0;
}
