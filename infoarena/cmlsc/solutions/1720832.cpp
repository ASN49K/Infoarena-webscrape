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
void afis (int i, int j, int k) {
    if (k>0) {
        if (i>=1)
            if (j>=1) {
                if (x[i]==y[j]) {
                    gg<<x[i]<<" ";
                    afis (i, j-1, k-1);
                }
                else afis (i,j-1,k);
            }
        else afis (i-1,m,k);
    }
}
int main()
{
    citire();
    dinamic();
    afis(n,m,a[n][m]);
    return 0;
}
