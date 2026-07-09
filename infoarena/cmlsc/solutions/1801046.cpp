#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int a[1025],b[1025],c[1025][1025],z[1025];
int main()
{
    int n,m,i,j,maxx;
    fin>>n>>m;
    for(i=1;i<=n;i++)
        fin>>a[i];
    for(j=1;j<=m;j++)
        fin>>b[j];
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
        {
            if(a[i]==b[j])c[i][j]=c[i-1][j-1]+1;
            else c[i][j]=max(c[i-1][j],c[i][j-1]);
        }
    maxx=c[n][m];
    i=n;
    j=m;
    while(maxx>0)
    {
        if(a[i]==b[j] && c[i][j]==maxx)
        {
            z[0]++;
            z[z[0]]=a[i];
            maxx--;
            i--;
            j--;
        }
        else
        {
            if(c[i-1][j]==maxx)
                i--;
            else j--;
        }
    }
    fout<<z[0]<<'\n';
    for(i=z[0];i>=1;i--)
        fout<<z[i]<<" ";
    return 0;
}
