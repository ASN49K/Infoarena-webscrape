#include<fstream.h>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int a[1025][1025],b[1025],c[1025],i,j,x,sub[1025],n,m;
int main(){
    f>>n>>m;
    for(i=1;i<=n;i++)
        f>>b[i];
    for(i=1;i<=m;i++)
        f>>c[i];
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++) {
            if(b[i]==c[j])
                a[i][j]=a[i-1][j-1]+1;
            else
                a[i][j]=max(a[i][j-1],a[i-1][j]);
        }
    i=n;
    j=m;
    while(a[i][j]) {
        while(a[i][j]==a[i-1][j])
            i--;
            while(a[i][j]==a[i][j-1])
                j--;
        x++;
        sub[x]=b[i];
        i--;
        j--;
        }
        g<<a[n][m]<<"\n";
        for(i=x;i>=1;i--)
        g<<sub[i]<<" ";
        return 0;}