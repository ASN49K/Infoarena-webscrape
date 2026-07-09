#include <fstream>
using namespace std;
ifstream g("cmlsc.in");
ofstream gg("cmlsc.out");
int i,j;
int n,m,x[1024],y[1024],z[1024],a[1024][1024],aux;
void citire(){
    g>>m>>n;
    for(int i=1;i<=m;i++)
        g>>x[i];

    for(int i=1;i<=n;i++)
        g>>y[i];
    g.close();
}
int maxim(int x, int y){
    if(x>y) return x;
    else return y;
}
void dinamic(){
    for(int i=1; i<=m; ++i){
        for(int j=1; j<=n; ++j){
            if(x[i]==y[j]) a[i][j] = 1 + a[i-1][j-1];
            else a[i][j] = maxim(a[i-1][j], a[i][j-1]);
        }
    }
    gg<<a[m][n]<<"\n";
}
void afisare(){
    for (i=m, j=n; i; ){
        if(x[i] == y[j]) z[++aux] = x[i], --i, --j;
        else if(a[i-1][j]<a[i][j-1]) j--;
        else i--;
    }
    for (i = aux; i>=1; --i)
        gg<<z[i]<<" ";
}
int main(void)
{
    citire();
    dinamic();
    afisare();
    return 0;
}
