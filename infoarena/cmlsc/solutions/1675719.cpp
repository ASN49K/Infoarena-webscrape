#include <fstream>

using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int n,m,a[1025],b[1025],c[1025][1025],st[1025],lvl;
int main()
{
   f>>n>>m;
   for(int i=1;i<=n;i++)
        f>>a[i];
   for(int i=1;i<=m;i++)
        f>>b[i];
   for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(a[i]==b[j])
                c[i][j]=c[i-1][j-1]+1;
            else c[i][j]=max(c[i-1][j],c[i][j-1]);
    g<<c[n][m]<<'\n';
    for(int i=n,j=m;i>=1;)
    {
        if(a[i]==b[j])
        {
           st[++lvl]=a[i];
            i--;
            j--;
        }else if(c[i-1][j]>c[i][j-1])
            i--;
        else j--;
    }
    for(int i=lvl;i>=1;i--)
        g<<st[i]<<" ";
    return 0;
}
