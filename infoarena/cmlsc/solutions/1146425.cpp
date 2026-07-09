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
    int nr=0,sir[1250];
    out<<v[n][m]<<'\n';
    i=n; j=m;
    while(i!=0)
        if (a[i] == b[j])
            sir[++nr] = a[i], --i, --j;
        else if (v[i-1][j] < v[i][j-1])
            --j;
        else
            --i;
    for(i=nr;i>=1;i--)
        out<<sir[i]<<' ';
    return 0;
}
