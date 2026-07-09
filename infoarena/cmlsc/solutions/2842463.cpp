#include <fstream>
using namespace std;
ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");
const int NMAX=1026;
int d[NMAX][NMAX];
int a[NMAX];
int v[NMAX];
int ans[NMAX];
int n,m;
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=m;i++)cin>>v[i];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(a[i]==v[j])d[i][j]=d[i-1][j-1]+1;
            else d[i][j]=max(d[i-1][j],d[i][j-1]);
    cout<<d[n][m]<<'\n';
    int nr=d[n][m];
    int c=1;
    for(int i=n;i>=1;i--)
    {
        for(int j=m;j>=1;j--)
        {
            if(d[i][j]==nr && a[i]==v[j]){
                ans[c++]=a[i];
                nr--;
            }
        }
    }
    for(int i=c-1;i>=1;i--)
        cout<<ans[i]<<" ";
    return 0;
}
