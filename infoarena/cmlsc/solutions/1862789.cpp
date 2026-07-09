#include <fstream>
using namespace std;
ifstream f("scmax.in");
ofstream g("scmax.out");
int v[1001],a[1001],m,n,lg[1001][1001],p,urm[1001];
void cit()
{
    f>>n>>m;
    for(int i=1;i<=n;i++)
        f>>v[i];
    for(int i=1;i<=m;i++)
        f>>a[i];
}
int best(int a,int b)
{
    if(a>b)
        return a;
    return b;
}
void dinam()
{
    int i,j;

    for(i=1;i<=n;i++)
    {
        lg[i][0]=0;
        for(j=1;j<=m;j++)
        {
            lg[0][j]=0;
            if(v[i]==a[j])
                lg[i][j]=1+lg[i-1][j-1];
            else
                lg[i][j]=best(lg[i][j-1],lg[i-1][j]);
        }
    }

}

void af()
{
    int q=0,j;
    for(j=1;j<=m;j++)
    {
        if(lg[n][j]>q)
        {
            q=lg[n][j];
            g<<a[j]<<' ';
        }
    }
}
int main()
{
    int i,j;
    cit();
    dinam();
    g<<lg[n][m]<<'\n';
    af();
    return 0;
}
