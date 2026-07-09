#include<fstream>
#define N 1025
using namespace std;
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

int n,m,i,j,p,ok,v[N],w[N],t[N],x[N][N];

int main(){
    in>>n>>m;
    for(i=1;i<=n;++i) in>>v[i];
    for(j=1;j<=m;++j) in>>w[j];
    for(i=1;i<=n;++i)
        for(j=1;j<=m;++j)
            if(v[i]==w[j])
                x[i][j]=x[i-1][j-1]+1;
            else
                x[i][j]=max(x[i-1][j],x[i][j-1]);
    out<<x[n][m]<<'\n';
    i=n;j=m;
    if(x[n][m])
        while(!ok){
            while(x[i][j-1]==x[i][j]) --j;
            while(x[i-1][j]==x[i][j]) --i;
            if(x[i-1][j-1]>0)
                t[++p]=v[i],--i,--j;
            else t[++p]=v[i],ok=1;
    }
    for(i=p;i;--i)
        out<<t[i]<<' ';
    return 0;
}
