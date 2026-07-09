#include <fstream>
#define N 1<<10
using namespace std;
ifstream g("cmlsc.in");
ofstream p("cmlsc.out");
short i,j,d[N][N],n,m,a[N],b[N],s[N];
int main()
{
    g>>m>>n;
    for(i=1;i<=m;i++) g>>a[i];
    for(i=1;i<=n;i++) g>>b[i];
    for(int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++) d[i][j]=(a[i]==b[j])?d[i-1][j-1]+1:max(d[i-1][j],d[i][j-1]);
    for(i=m,j=n;i;)
        if(a[i]==b[j]) s[++s[0]]=a[i],i--,j--;
        else (d[i-1][j]<d[i][j-1])?j--:i--;
    p<<s[0]<<"\n";
    for(i=s[0];i;i--) p<<s[i]<<" ";
}
