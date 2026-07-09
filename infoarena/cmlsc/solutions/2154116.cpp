#include <fstream>

using namespace std;

ifstream fin ("cmlsc.in");
ofstream fout ("cmlsc.out");

int a[1030],b[1030],ans[1030];
int m,n,v[1030][1030],i,j,val,x,y;

int main ()
{
    fin>>n>>m;
    for(i=1;i<=n;i++)
        fin>>a[i];
    for(i=1;i<=m;i++)
        fin>>b[i];
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            if(a[i]==b[j])
                v[i][j]=v[i-1][j-1]+1;
            else
                v[i][j]=max(v[i-1][j],v[i][j-1]);
    fout<<v[n][m]<<'\n';
    val=v[n][m];
    x=n; y=m;
    while(val>0)
    {
        while(v[x-1][y]==val)
            x--;
        while(v[x][y-1]==val)
            y--;
        ans[val]=a[x];
        x--; y--;
        val--;
    }
    for(i=1;i<=v[n][m];i++)
        fout<<ans[i]<<' ';
    fout<<'\n';

}
