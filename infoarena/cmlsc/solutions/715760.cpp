#include <fstream>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int v[1026][1026],n,m;
int a[1026],b[1026];
int main()
{
    int i,j,x,y,k;
    fin>>n>>m;
    for(i=1;i<=n;i++)
        fin>>a[i];
    for(i=1;i<=m;i++)
        fin>>b[i];
    for(x=n;x>=1;x--)
        for(y=m;y>=1;y--)
            if(a[x]==b[y])
                v[x][y]=1+v[x+1][y+1];
            else if(v[x+1][y]>v[x][y+1])
                v[x][y]=v[x+1][y];
            else v[x][y]=v[x][y+1];
    fout<<v[1][1]<<'\n';
    for(k=v[1][1];k>=1;k--)
        for(i=1;i<=n;i++)
            for(j=1;j<=m;j++)
                if(v[i][j]==k && a[i]==b[j])
                {
                    fout<<a[i]<<' ';
                    i=n+1;
                    j=m+1;
                }
    fin.close();
    fout.close();
    return 0;
}
