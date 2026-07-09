#include <fstream>

using namespace std;
typedef short var;
var x[1026],y[1026];
var a[1026][1026];
var sir[1026];
var maxim(int a,int b)
{
    if(a>b)
        return a;
    return b;
}
int main()
{
    ifstream f("cmlsc.in");
    ofstream g("cmlsc.out");
    var n,m,i,j,e,best;
    f>>n;
    f>>m;
    for(i=1;i<=n;i++)
        f>>x[i];
    for(i=1;i<=m;i++)
        f>>y[i];
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            if(x[i]==y[j])
                a[i][j]=a[i-1][j-1]+1;
            else
                a[i][j]=maxim(a[i-1][j],a[i][j-1]);
        }
    }
    best=a[n][m];
    i=n;
    j=m;
    for(e=best;e;)
    {
        if(x[i]==y[j])
        {
            sir[e]=x[i];
            i-=1;
            j-=1;
            e-=1;
        }
        else
        {
            if(a[i-1][j]>a[i][j-1])
            {
                i-=1;
            }
            else
                j-=1;
        }
    }
    g<<best<<'\n';
    for(i=1;i<=best;i++)
        g<<sir[i]<<" ";
    f.close();
    g.close();
    return 0;
}
