#include<fstream>
#define N 1025
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int i,j,n,m,v[N],w[N],t[N],x[N][N];
int main(){
    f>>n>>m;
    for(i=1;i<=n;++i) f>>v[i];
    for(i=1;i<=m;++i) f>>w[i];
    for(i=1;i<=n;++i)
        for(j=1;j<=m;++j) x[i][j]=(v[i]==w[j]?1+x[i-1][j-1]:max(x[i-1][j],x[i][j-1]));
    for(i=n,j=m;i;)
        if(v[i]==w[j]) t[++t[0]]=v[i],--i,--j;
        else x[i-1][j]<x[i][j-1]?--j:--i;
    g<<t[0]<<'\n';
    for(i=t[0];i;--i) g<<t[i]<<" ";
    return 0;
}
