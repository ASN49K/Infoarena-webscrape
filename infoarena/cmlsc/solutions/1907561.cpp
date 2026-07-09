#include <fstream>
#include <algorithm>
using namespace std;
ifstream in ("cmlsc.in");
ofstream out ("cmlsc.out");

int n,m,v[1025][1025],a[1050],b[1050],k;

void afs(int i,int j)
{
    if(i*j)
        if(a[i]==b[j])
            {
                afs(i-1,j-1);
                out<<a[i]<<" ";
            }
        else
            if(v[i][j]==v[i-1][j])
                afs(i-1,j);
            else
                afs(i,j-1);
}

int main()
{
    int i,j;
    in>>n>>m;
    for(i=1;i<=n;i++)
        in>>a[i];
    for(i=1;i<=m;i++)
        in>>b[i];
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            if(a[i]==b[j])
                v[i][j]=v[i-1][j-1]+1;
            else
                v[i][j]=max(v[i][j-1],v[i-1][j]);
    out<<v[n][m]<<"\n";
    afs(n,m);
    return 0;
}
