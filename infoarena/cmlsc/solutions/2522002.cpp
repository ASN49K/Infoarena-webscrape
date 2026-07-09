#include <fstream>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int n,m,i,j;
int lungime;
int a[1030];
int b[1030];
int r[1030];
int d[1030][1030];
int main()
{
    fin>>n>>m;
    for(i=1; i<=n; i++)
        fin>>a[i];
    for(j=1; j<=m; j++)
        fin>>b[j];
    d[0][0]=d[0][1]=d[1][0]=0;
    for(i=1; i<=n; i++)
        for(j=1; j<=m; j++)
        {
            d[i][j]=max(d[i-1][j],d[i][j-1]);
            if(a[i]==b[j] && d[i-1][j-1]+1>=d[i][j])
                d[i][j]=d[i-1][j-1]+1, r[d[i][j]]=a[i];
        }
    fout<<d[n][m]<<'\n';
    for (i=n,j=m;i&&j;){
        if (a[i]==b[j]){
            r[++r[0]]=a[i],i--,j--;
        }
        else if (d[i-1][j]>d[i][j-1]) i--;
            else j--;
    }
    for (i=r[0];i>0;i--){
        fout<<r[i] << ' ';
    }
    fout<<'\n';
    return 0;
}
