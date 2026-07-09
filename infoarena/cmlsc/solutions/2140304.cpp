#include <fstream>

using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int v[1030][1030],x[1030],y[1030];
void af(int i,int j)
{
    if(v[i][j]!=0)
    {
        if(x[i]==y[j])
        {
            af(i-1,j-1);
            g<<x[i]<<" ";
        }
        else
        {
            if(v[i-1][j]>v[i][j-1])
                af(i-1,j);
            else
                af(i,j-1);
        }
    }
}
int main()
{
    int n,m,i,j;
    f>>n>>m;
    for(i=1;i<=n;i++)
        f>>x[i];
    for(i=1;i<=m;i++)
        f>>y[i];
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            if(x[i]==y[j])
            {
                v[i][j]=v[i-1][j-1]+1;
            }
            else
            {
                v[i][j]=max(v[i-1][j],v[i][j-1]);
            }
        }
    }
    g<<v[n][m]<<endl;
    af(n,m);
    return 0;
}
