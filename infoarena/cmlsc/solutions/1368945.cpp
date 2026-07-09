#include<fstream>
#include<algorithm>>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int n,nr,m,a[1024],b[1024],c[1024],d[1024][1024];
int main()
{
    int i,j;
    fin>>n>>m;
    for(i=1;i<=n;i++)
        fin>>a[i];
    for(i=1;i<=m;i++)
        fin>>b[i];
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
        if(a[i]==b[j])
        d[i][j]=d[i-1][j-1]+1;
    else d[i][j]=max(d[i-1][j],d[i][j-1]);
    fout<<d[n][m]<<'\n';
    i=n; j=m;
    while(i!=0 && j!=0)
    {
        if(a[i]==b[j])
        {
            nr++;
            c[nr]=a[i];
            i--; j--;
        }
        else if(d[i-1][j]>d[i][j-1])
            i--;
        else j--;
    }
    for(i=nr;i>=1;i--)
        fout<<c[i]<<" ";
    fin.close();
    fout.close();
    return 0;
}
