#include <fstream>
using namespace std;
int n, m, a[1024],b[1024], g[1024][1024],i,j,k=0,s[1024];
ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");
int main()
{
    cin>>m>>n;
    for(i=1;i<=m;i++) cin>>a[i];
    for(i=1;i<=n;i++) cin>>b[i];

    for(i=1;i<=m;i++)
        for(j=1;j<=n;j++)
        {
            if(a[i]==b[j]) g[i][j] = g[i-1][j-1]+1;
            else g[i][j] = max(g[i-1][j], g[i][j-1]);
        }
    for(i=m, j=n;i;)
    {
        if(a[i]==b[j])
        {
            s[++k]=a[i];
            i--;
            j--;
        }
        else if(g[i-1][j]<g[i][j-1])
            j--;
        else
            i--;
    }
    cout<<k<<'\n';
    for(i=k;i;i--)
        cout<<s[i]<<' ';
	return 0;
}
