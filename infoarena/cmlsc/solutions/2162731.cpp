#include<fstream>
using namespace std;
ifstream f ("cmlsc.in");
ofstream g ("cmlsc.out");
int n,m,a[2010],b[2010],d[2010][2010],sol[2010];
int main()
{
    f>>n>>m;
    for(int i=1;i<=n;++i)f>>a[i];
    for(int i=1;i<=m;++i)f>>b[i];
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            if(a[i]==b[j]) d[i][j]=d[i-1][j-1]+1;
            else d[i][j]=max(d[i-1][j],d[i][j-1]);
        }
    }
    g<<d[n][m]<<'\n';
    int i=n,j=m,k=0;
    while(i&&j){
        if(a[i]==b[j])
            sol[++k]=a[i],--i,--j;
        else if(d[i-1][j]<d[i][j-1])--j;
        else --i;
    }
    for(int i=k;i>=1;--i){
        g<<sol[i]<<" ";
    }

}
