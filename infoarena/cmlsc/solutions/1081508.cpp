#include <fstream>
#define M 1025
#define maxim(a, b) ((a > b) ? a : b)

using namespace std;

int d[M][M],sub[M];

int main(){
    int n,m,a[M],b[M],x=0,i,j;

    ifstream f("cmlsc.in");
    ofstream g("cmlsc.out");
    f>>n>>m;
    for(int i=1;i<=n;++i)
        f>>a[i];
    for(int i=1;i<=m;++i)
        f>>b[i];
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            if(a[i]==b[j])
                d[i][j] = d[i-1][j-1] + 1;
            else
                d[i][j] = maxim(d[i-1][j], d[i][j-1]);
        }
    }
    i=n;
    j=m;
    while(i>0){
        if(a[i] == b[j]){
            sub[++x] = a[i];
            --i;
            --j;
        }
        else{
            if(d[i-1][j] >= d[i][j-1])
                --i;
            else
                --j;
        }
    }
    g<<d[n][m]<<"\n";
    for(int i=x;i>0;--i)
        g<<sub[i]<<" ";
    f.close();
    g.close();
    return 0;
}
