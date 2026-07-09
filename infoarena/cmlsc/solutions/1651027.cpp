#include <fstream>

using namespace std;
ifstream fin ("cmlsc.in");
ofstream fout ("cmlsc.out");
int m,n,a[1025],b[1025],d[1025][1025],sol[1025],k;
void afis(int i,int j)
{
    for(int i=m,j=n;i&&j;)
    {
        if(a[i]==b[j]) sol[++k]=a[i],i--,j--;
        else
        if(d[i-1][j]>d[i][j-1]) i--; else j--;
    }
    for(int i=k;i>=1;i--) fout<<sol[i]<<' ';
}

int main()
{
    fin>>m>>n;
    for(int i=1;i<=m;i++) fin>>a[i];
    for(int i=1;i<=n;i++) fin>>b[i];
    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++)
        if(a[i]==b[j]) d[i][j]=d[i-1][j-1]+1;
    else d[i][j]=max(d[i-1][j],d[i][j-1]);
    fout<<d[m][n]<<'\n';
    afis(m,n);

    return 0;
}
