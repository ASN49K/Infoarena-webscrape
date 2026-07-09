#include<fstream>
#include<algorithm>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int m, n, v[1025], w[1025], a[1025][1025], aux[1025],k;
void citire()
{
    int i;
    f>>n>>m;
    for(i=1;i<=n;i++)f>>v[i];
    for(i=1;i<=m;i++)f>>w[i];
}
void cmlsc()
{
    int i, j;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            if(v[i]==w[j])
            {
                a[i][j]=a[i-1][j-1]+1;
            }
            else
            {
                a[i][j]=max(a[i-1][j],a[i][j-1]);
            }
        }
    }
    g<<a[n][m]<<'\n';
    i=n;
    j=m;
    while(i&&j)
    {
        if(v[i]==w[j])
        {
            aux[++k]=v[i];
            i--;
            j--;
        }
        else
        {
            if(a[i-1][j]>a[i][j-1])i--;
            else j--;
        }
    }
    for(i=k;i>=1;i--)g<<aux[i]<<" ";
}
int main()
{
    citire();
    cmlsc();
    f.close();
    g.close();
    return 0;
}
