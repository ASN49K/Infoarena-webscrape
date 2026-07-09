#include<fstream>
#include<algorithm>
using namespace std;
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");
int v[1025][1025]={{0}},n,m,a[1025],b[1025];

int main ()
{
    int i,j;
    in>>n>>m;
    for(i=1;i<=n;i++)
        in>>a[i];
    for(i=1;i<=m;i++)
        in>>b[i];
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
            if(a[i]==b[j])
                v[i][j]=v[i-1][j-1]+1;
            else
                v[i][j]=max(v[i-1][j],v[i][j-1]);
    }
    out<<v[n][m]<<'\n';
    for(i=0;i<=n-1;i++)
    {
        if(v[i][m]!=v[i+1][m])
            out<<a[i+1]<<' ';
    }
    return 0;
}
