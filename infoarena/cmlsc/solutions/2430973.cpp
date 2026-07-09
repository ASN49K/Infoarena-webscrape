#include <fstream>
#define N 1<<10
using namespace std;
ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");
short i,j,d[N][N],n,m,a[N],b[N],s[N],r;
main()
{
    cin>>m>>n;
    for(i=1; i<=m; i++)cin>>a[i];
    for(i=1; i<=n; i++)cin>>b[i];
    for(i=1; i<=m; i++)
        for(j=1; j<=n; j++)
            if(a[i]==b[j])
                d[i][j]=d[i-1][j-1]+1;
            else d[i][j]=max(d[i-1][j],d[i][j-1]);
    for(i=m,j=n; i;)
        if(a[i]==b[j])
            s[++r]=a[i],i--,j--;
        else
            (d[i-1][j]<d[i][j-1])?j--:i--;
    cout<<r<<"\n";
    for(i=r; i; i--) cout<<s[i]<<" ";
}
