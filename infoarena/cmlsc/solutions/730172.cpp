#include <fstream>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

short int n,m,a[1030],b[1030],d[1030][1030];

void afisare(short int p,short int q);

int main()
{
    short int i,j;
    f>>n>>m;
    for(i=1;i<=n;i++)
        f>>a[i];
    for(i=1;i<=m;i++)
        f>>b[i];
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            if(a[i]==b[j])
                d[i][j]=d[i-1][j-1]+1;
            else
                d[i][j]=d[i-1][j]>d[i][j-1]?d[i-1][j]:d[i][j-1];}}
    g<<d[n][m]<<'\n';
    afisare(n,m);
    f.close();
    g.close();
    return 0;
}

void afisare(short int p,short int q){
    if(a[p]==b[q]){
        if(d[p][q]>1)
            afisare(p-1,q-1);
        g<<a[p]<<' ';}
    else{
        if(d[p-1][q]>d[p][q-1])
            afisare(p-1,q);
        else
            afisare(p,q-1);}}
