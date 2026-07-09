#include <fstream>
using namespace std;
ifstream fin ("cmlsc.in");
ofstream fout ("cmlsc.out");
int n,m,i,j,a[1025],b[1025],d[1025][1025];
void f (int n,int m,int k)
{
    if (k!=0)
    {
        if (a[n]==b[m])
        {
            f (n-1,m-1,k-1);
            fout<<a[n]<<" ";
        }
        else
        {
            if (d[n-1][m]>d[n][m-1])
                f (n-1,m,k);
            else
                f (n,m-1,k);
        }
    }
}
int main()
{
    fin>>n>>m;
    for (i=1; i<=n; i++)
        fin>>a[i];
    for (i=1; i<=m; i++)
        fin>>b[i];
    for (i=1; i<=n; i++)
    {
        for (j=1; j<=m; j++)
        {
            if (a[i]==b[j])
                d[i][j]=1+d[i-1][j-1];
            else
                d[i][j]=max (d[i-1][j],d[i][j-1]);
        }
    }
    fout<<d[n][m]<<"\n";
    f (n,m,d[n][m]);
    return 0;
}
