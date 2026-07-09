#include<fstream>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int x[100],y[100],n,m,a[100][100];
void citire()
{
    int i;
    f>>n>>m;
    for(i=1;i<=n;i++) f>>x[i];
    for(i=1;i<=m;i++) f>>y[i];
}
void dinamica()
{
    int i,j;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            if(x[i]==y[j]) a[i][j]=a[i-1][j-1]+1;
            else
            {
                a[i][j]=max(a[i-1][j],a[i][j-1]);
            }
        }
    }
}
void afis()
{
    int i,j,K=0,v[100];
    i=n; j=m;
    g<<a[n][m]<<"\n";
    while(i!=0&&j!=0)
    {
        if(x[i]==y[j])
        {   v[++K]=x[i];
            i--;
            j--;
        }
        else
        {
            if(a[i][j]==a[i][j-1]) j--;
            else i--;
        }
    }
    for(i=K;i>=1;i--) g<<v[i]<<" ";
}
int main()
{
    citire();
    dinamica();
    afis();
    return 0;
}
