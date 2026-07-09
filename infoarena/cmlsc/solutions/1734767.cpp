#include <fstream>
#define N 1025
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int x[N],y[N],s[N][N],c[N],i,j,n,m,l;
int main()
{
    f>>n>>m;
    for(i=1;i<=n;i++)
        f>>x[i];
    for(j=1;j<=m;j++)
        f>>y[j];
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            if(x[i]==y[j])
                s[i][j]=s[i-1][j-1]+1;
            else
                s[i][j]=max(s[i-1][j],s[i][j-1]);
    l=s[n][m];
    i=n;j=m;n=l;
    while(s[i][j])
    {
        if(x[i]==y[j])
        {
            c[n]=x[i];
            i--;j--;
            n--;continue;
        }
        if(s[i-1][j]>=s[i][j-1])
            i--;
        else
            j--;
    }
    g<<l<<'\n';
    for(i=1;i<=l;i++)
        g<<c[i]<<" ";
    return 0;
}
