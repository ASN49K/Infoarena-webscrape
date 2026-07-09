#include <fstream>
#include <climits>
using namespace std;
ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");
int n,m,a[1025],b[1025],d[1024][1024];
void f(int x,int y,int l)
{
    if(l==0)
        return;
    if(a[x]==b[y])
    {
        f(x-1,y-1,l-1);
        cout<<a[x]<<" ";
    }
    else
        if(d[x-1][y]>d[x][y-1])
        f(x-1,y,l);
    else
        f(x,y-1,l);
}
int main()
{
    cin>>n>>m;
    for(int i=1; i<=n; i++)
        cin>>a[i];
    for(int i=1; i<=m; i++)
        cin>>b[i];
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
        {
            if(a[i]==b[j])
                d[i][j]=d[i-1][j-1]+1;
            else
                d[i][j]=max(d[i-1][j],d[i][j-1]);
        }
    cout<<d[n][m]<<'\n';
    f(n,m,d[n][m]);
    return 0;
}
