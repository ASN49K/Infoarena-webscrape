#include <fstream>
using namespace std;
ifstream cin("cmlsc.in"); ofstream cout("cmlsc.out");
int n,m,a[1000],b[1000],i,j,rez[1000],rezl,nr,c[1000][1000];
int main()
{ cin>>n>>m; 
	for(i=1;i<=n;i++) cin>>a[i];
    for(i=1;i<=m; i++) cin >> b[i];
    for(i=1;i<=n;i++) { for(j=1; j<=m;j++) if(a[i]==b[j]) c[i][j] = c[i-1][j-1]+1;else c[i][j]=max(c[i-1][j],c[i][j-1]);}
    i=n;j=m;
    while(i&&j) { if(a[i]==b[j]){ rezl++;rez[rezl]=a[i];i--;j--;}
        else
        {if(c[i-1][j]>c[i][j-1])i--;else j--;} }
    cout<<c[n][m]<<'\n';
    for(i=rezl;i>=1;i--)cout<<rez[i]<<' ';return 0;
}
