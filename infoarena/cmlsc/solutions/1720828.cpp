#include <fstream>
using namespace std;
ifstream g("cmlsc.in");
ofstream gg("cmlsc.out");
int x[1024],y[1024],c[1024],a[1024][1024],n,m,k=0;
void citire(){
    g>>n>>m;
    for(int i=1;i<=n;i++)
        g>>x[i];

    for(int i=1;i<=m;i++)
        g>>y[i];
    g.close();
}
int maxim(int x, int y){
    if(x>y) return x;
    else return y;
}
void dinamic(){
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++){
            if(x[i]==y[j]) a[i][j]=a[i-1][j-1]+1;
            else a[i][j]=maxim(a[i-1][j],a[i][j-1]);
        }
    }
    gg<<a[n][m]<<"\n";
}
void afisaredr () {
    int i,j;
    k=a[n][m];
    for (j=1;j<=m && k>0; j++) {
        for (i=1;i<=n && k>0; i++) {
            if (y[j]==x[i]){k--; gg<<y[j]<<" ";}
        }
    }
}
int main()
{
    citire();
    dinamic();
    afisaredr();
    return 0;
}
