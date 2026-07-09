#include <fstream>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int v1[1025],v2[1025],a[1025][1025];

void afis(int i,int j)
{
    if(i==0 || j==0)
        return;
    if(v1[i]==v2[j])
    {
        afis(i-1,j-1);
        fout<<v1[i]<<' ';
    }
     else
     {
    if(a[i-1][j]>a[i][j-1])
        afis(i-1,j);
    else
        afis(i,j-1);
     }
}

int main()
{
    int n,m;
    fin>>n>>m;
    for(int i=1;i<=n;i++)
        fin>>v1[i];
    for(int i=1;i<=m;i++)
        fin>>v2[i];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
    {
        if(v1[i]!=v2[j])
            a[i][j]=max(a[i-1][j],a[i][j-1]);
        else
            a[i][j]=a[i-1][j-1]+1;
    }
    fout<<a[n][m]<<'\n';
    afis(n,m);
    return 0;
}
