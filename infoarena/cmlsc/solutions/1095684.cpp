#include<fstream>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int sol[1024],p,act,i,j,m,n,a[1025],b[1025],l[1025][1025];
int main()
{
    f>>n>>m;
    for(i=1;i<=n;++i)
    f>>a[i];
    for(j=1;j<=m;++j)
    f>>b[j];
    for(i=1;i<=n;++i)
    for(j=1;j<=m;++j)
    if(a[i]==b[j])
    l[i][j]=l[i-1][j-1]+1;
    else
    l[i][j]=max(l[i-1][j],l[i][j-1]);
    g<<l[n][m]<<'\n';
    act=l[n][m];
    i=n; j=m;
    while(act)
    {
        if(a[i]==b[j])
        ++p, sol[p]=a[i], --i, --j, --act;
        else
        {
            if(l[i-1][j]>l[i][j-1])
            --i;
            else
            --j;
        }
    }
    for(i=p;i>=1;--i)
    g<<sol[i]<<" ";
    g<<'\n';
    return 0;
}
