#include <fstream>

using namespace std;

int a[10000][10000];
int main()
{

    ifstream f("cmlsc.in");
    ofstream g("cmlsc.out");
    int n,m,v1[10000],v2[100000],i,j,v3[100000],k=0;
    f>>n>>m;
    for(i=1;i<=n;i++)
        f>>v1[i];
    for(i=1;i<=m;i++)
        f>>v2[i];
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            if(v1[i]==v2[j])
                a[i][j]=a[i-1][j-1]+1;
            else
                if(a[i-1][j]>a[i][j-1])
                    a[i][j]=a[i-1][j];
                else
                    a[i][j]=a[i][j-1];

    g<<a[n][m]<<'\n';
    i=n;j=m;
    while(a[i][j]!=0)
    {
        if(a[i][j]>a[i-1][j] && a[i][j]> a[i][j-1])
        {
            v3[++k]=v1[i];
            i--;
            j--;
        }
        else
        {
            if(a[i][j-1]>a[i-1][j])
                j--;
            else
                i--;
        }
    }
    for(i=k;i>=1;i--)
        g<<v3[i]<<" ";
    f.close();
    g.close();
    return 0;
}
