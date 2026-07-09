#include <fstream>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int n,m,a[1025],b[1025],d[1025][1025],sir[1025],dim;
int main()
{
    int i,j;
    f>>m>>n;
    for(i=1;i<=m;i++) f>>a[i];
    for(i=1;i<=n;i++) f>>b[i];
    for(i=1;i<=m;i++)
        for(j=1;j<=n;j++)
            if(a[i]==b[j])
                d[i][j]=1+d[i-1][j-1];
            else
                d[i][j]=max(d[i-1][j],d[i][j-1]);
    i=m;j=n;
    for(;i>=1;)
        if(a[i]==b[j])
            {sir[++dim]=a[i]; i--;j--;}
        else if(d[i][j-1]>d[i-1][j]) j--;
             else i--;
    g<<dim<<'\n';
    for(i=dim;i>=1;i--)
        g<<sir[i]<<' ';
    g<<'\n';
    f.close();
    g.close();
    return 0;
}
