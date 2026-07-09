#include <fstream>

using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int a[1025],b[1025],v[1025];
int d[1025][1025];
int main()
{
    int n,m,k=0;
    f >> m >> n;
    for(int i=1;i<=m;i++)
        f >> a[i];
    for(int i=1;i<=n;i++)
        f >> b[i];
    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++){
            if(a[i]==b[j])
                d[i][j]=1+d[i-1][j-1],v[++k]=a[i];
            else
                d[i][j]=max(d[i-1][j],d[i][j-1]);
    }
    g << d[m][n] << '\n';
    for(int i=1;i<=k;i++)
        g << v[i] << ' ';
    return 0;
}
