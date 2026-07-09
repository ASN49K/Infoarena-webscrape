#include <fstream>

using namespace std;

ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");

int main()
{
    int n, m, a[1025], b[1025], sol[1025], k=0, s[1025][1025];

    cin>>n>>m;

    for(int i=1; i<=n; i++) cin>>a[i];
    for(int j=1; j<=m; j++) cin>>b[j];

    for(int i=1; i<=n; i++)
    for(int j=1; j<=m; j++)
        if(a[i]==b[j]){ s[i][j]=s[i-1][j-1]+1; k++; sol[k]=a[i];}
    else s[i][j]=max(s[i-1][j], s[i][j-1]);

    cout<<s[n][m]<<"\n";

    for(int i=1; i<=k; i++) if(a[i]!=0) cout<<sol[i]<<" ";

return 0;
}
