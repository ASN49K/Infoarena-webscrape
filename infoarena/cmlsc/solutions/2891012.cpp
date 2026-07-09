#include <fstream>

using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int n,m,i,j,k;
int a[1025],b[1025],rez[1025],d[1025][1025];

int main()
{
    f>>n>>m;

    for(i=1;i<=n;i++)
        f>>a[i];
    for(i=1;i<=m;i++)
        f>>b[i];

    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
        {
            if(a[i]==b[j])
                d[i][j]=d[i-1][j-1]+1;
            else
                d[i][j]=max(d[i-1][j], d[i][j-1]);
        }
    i=n; j=m;
    while(i>0 && j>0)
    {
        if(a[i]==b[j])
        {
            rez[++k]=a[i];
            i--;j--;
        }
        else
            if(d[i-1][j]>d[i][j-1])
                i--;
        else j--;
    }
    g<<k<<endl;
    for(i=k;i>=1;i--)
        g<<rez[i]<<" ";

    return 0;
}
