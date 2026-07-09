#include <fstream>
using namespace std;
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");
int v1[1025],v2[1025],d[1025][1025],afis[1025];
int main()
{
    int n,m,i,j,cnt,cnt1=0;
    in>>n>>m;
    for(i=1; i<=n; i++)
        in>>v1[i];
    for(i=1; i<=m; i++)
        in>>v2[i];
    for(i=1; i<=n; i++)
        for(j=1; j<=m; j++)
            d[i][j]=max(max(d[i-1][j],d[i][j-1]),d[i-1][j-1]+(v1[i]==v2[j]));
    out<<d[n][m]<<'\n';
    cnt=d[n][m];
    for(i=n,j=m; i;)
        if(v1[i]==v2[j])
        {
            afis[++cnt1]=v1[i];
            --i;
            --j;
        }
        else if(d[i][j-1]<d[i-1][j])
            --i;
        else
            --j;
    for(i=cnt1; i>=1; i--)
        out<<afis[i]<<" ";
    return 0;
}
