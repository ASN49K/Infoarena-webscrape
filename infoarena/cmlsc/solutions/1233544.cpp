#include <fstream>
#define N 1025

using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int n,m,k,i,j,a[N],b[N],c[N],x[N][N];
int main()
{
    fin>>n>>m;
    for(i=1;i<=n;i++)fin>>a[i];
    for(i=1;i<=m;i++)fin>>b[i];
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
        {
            x[i][j]=max(x[i-1][j],x[i][j-1]);
            if(a[i]==b[j])x[i][j]=x[i-1][j-1]+1;
        }
    fout<<x[n][m]<<'\n';
    for(i=n,j=m;x[i][j];)
    {
        if(a[i]==b[j])
        {
            c[++k]=a[i];
            i--;
            j--;

        }
        else
            if(x[i][j]==x[i][j-1])
                j--;
                else
                    i--;

    }
    for(;k;k--)
        fout<<c[k]<<' ';
    return 0;
}
