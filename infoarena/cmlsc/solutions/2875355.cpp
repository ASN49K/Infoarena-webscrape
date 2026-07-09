#include <fstream>

using namespace std;
ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");
int v[1024][1024];
int a[1024];
int b[1024];
int c[1024];
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
    }
    for(int i=1; i<=m; i++)
    {
        cin>>b[i];
    }
    int poz=1;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if(j!=0)
            {
                v[i][j]=max(v[i][j-1],max(v[i-1][j],v[i-1][j-1]));
            }
            if(a[i]==b[j])
                c[poz++]=b[j], v[i][j]++;
        }
    }
    cout<<v[n][m]<<"\n";
    for(int i=1;i<poz;i++)
        cout<<c[i]<<" ";
}
