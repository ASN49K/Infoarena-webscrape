#include <fstream>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int n,m,i,j,v1[1025],v2[1025],a[1025][1025],x[100001],b;
int main()
{
    fin>>n>>m;
    for(i=1;i<=n;i++)
        fin>>v1[i];
    for(i=1;i<=m;i++)
        fin>>v2[i];
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
        {
            if(v1[i]==v2[j])
                a[i][j]=1+a[i-1][j-1];
            else
                a[i][j]=max(a[i-1][j],a[i][j-1]);
        }
    for (i=n,j=m;i>0;)
        if(v1[i]==v2[j])
        {
            x[++b]=v1[i];
            i--;
            j--;
        }
        else
            if (a[i-1][j]<a[i][j-1])
                j--;
            else
                i--;
    fout<<a[n][m]<<'\n';
    for(i=b;i>0;i--)
        fout<<x[i]<<' ';
    fout.close();
    return 0;
}
