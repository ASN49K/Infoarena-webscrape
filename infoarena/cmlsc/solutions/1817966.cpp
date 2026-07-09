#include <fstream>
#define N 1<<10
using namespace std;
ifstream g("cmlsc.in");
ofstream p("cmlsc.out");
short i,j,d[N][N],n,m,a[N],b[N],s[N],r;
int main(){
    g>>m>>n;
    for(i=1;i<=m;i++) g>>a[i];
    for(i=1;i<=n;i++) g>>b[i];
    for(i=1;i<=m;i++)
        for (j=1;j<=n;j++) d[i][j]=(a[i]==b[j])?d[i-1][j-1]+1:max(d[i-1][j],d[i][j-1]);
    for(i=m,j=n;i;)
        if(a[i]==b[j]) s[++r]=a[i],i--,j--;
        else (d[i-1][j]<d[i][j-1])?j--:i--;
    p<<r<<"\n";
    for(i=r;i;i--) p<<s[i]<<" ";
}
