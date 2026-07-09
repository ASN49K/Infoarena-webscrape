#include <fstream>
#define DIM 1034
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int n,m;
int a[DIM],b[DIM],D[DIM][DIM];

void afisare(int i,int j){
    if(i==0 || j==0) return;
    if(a[i]==b[j]){
        afisare(i-1,j-1);
        g<<a[i]<<" ";
    }
    else{
        if(D[i-1][j]>D[i][j-1]) afisare(i-1,j);
        else afisare(i,j-1);
    }
}

int main(void){
    register int i,j;

    f>>n>>m;
    for(i=1;i<=n;i++) f>>a[i];
    for(j=1;j<=m;j++) f>>b[j];

    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            if(a[i]==b[j])
                D[i][j]=1+D[i-1][j-1];
            else
                D[i][j]=max(D[i-1][j],D[i][j-1]);
        }
    }

    g<<D[n][m]<<"\n";
    afisare(n,m);
    f.close();
    g.close();
    return 0;
}
