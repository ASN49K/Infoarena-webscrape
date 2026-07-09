#include <fstream>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int n,m,i,j;
int lungime;
int a[1024];
int b[1024];
int r[1024];
int d[1024][1024];

int main()
{
    fin>>n>>m;
    for(i=1; i<=n; i++)
        fin>>a[i];
    for(j=1; j<=m; j++)
        fin>>b[j];
    for(i=1; i<=n; i++)
        for(j=1; j<=m; j++)
        {
            d[i][j]=max(d[i-1][j],d[i][j-1]);
            if(a[i]==b[j] && d[i-1][j-1]+1>d[i][j])
                d[i][j]=d[i-1][j-1]+1, r[++lungime]=a[i];
        }
    fout<<d[n][m]<<'\n';
    for(i=1; i<=lungime; i++)
        fout<<r[i]<<' ';
    fout<<'\n';
    return 0;
}
