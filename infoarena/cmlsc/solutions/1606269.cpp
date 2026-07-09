#include <fstream>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int m,n,x[1030],y[1030],z[1030],v[1030][1030],l,c,k;
int main()
{
    f>>m>>n;
    for(int i=1; i<=m; i++)
        f>>x[i];
    for(int i=1; i<=n; i++)
        f>>y[i];
    for(int i=1; i<=m; i++)
        for(int j=1; j<=n; j++)
        {
            if(x[i]==y[j])
                v[i][j]=1+v[i-1][j-1];
            else v[i][j]=max(v[i][j-1],v[i-1][j]);
        }
    l=m;c=n;
    while(l&&c)
    {
        if(x[l]==y[c])
        {
            z[++k]=x[l];
            l--;
            c--;
        }
        if(v[l][c]==v[l-1][c])
            l--;
        if(v[l][c]==v[l][c-1])
            c--;
    }
    g<<v[m][n]<<endl;
    for(int i=k;i>=1;i--)
        g<<z[i]<<" ";
    return 0;
}
