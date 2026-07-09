#include<fstream>
using namespace std;
int n,m,a[1025],b[1025],c[1025][1025],k,d[1025];
int main()
{
    ifstream f("cmlsc.in");
    ofstream g("cmlsc.out");
    int i,j;
    f>>n>>m;
    for(i=1;i<=n;i++)
        f>>a[i];
    for(j=1;j<=m;j++)
        f>>b[j];
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            if(a[i]==b[j])
                c[i][j]=c[i-1][j-1]+1;
            else if(c[i-1][j]>c[i][j-1])
                c[i][j]=c[i-1][j];
            else c[i][j]=c[i][j-1];
    i--;j--;
    g<<c[i][j]<<"\n";
    while(k!=c[n][m])
    {
        if(a[i]==b[j])
        {
            d[++k]=a[i];
            i--;
            j--;
        }
        else if(c[i-1][j]>c[i][j-1])
            i--;
        else j--;
    }
    for(;k>0;k--)
        g<<d[k]<<" ";
    f.close();
    g.close();
    return 0;
}
