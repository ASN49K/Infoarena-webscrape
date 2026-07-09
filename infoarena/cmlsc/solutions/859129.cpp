#include<fstream>
using namespace std;
#define max(a, b) ((a > b) ? a : b)
unsigned short int a[1030],r[1030][1030];
main(){
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
unsigned short int m,n,i,j,max1=0,max2,poz=1,k;
f>>m>>n;
for(i=1;i<=m;i++) f>>a[i];
for(k=1;k<=n;k++){
f>>j;
for(i=1;i<=m;i++){
if(j==a[i])r[k][i]=1+r[k-1][i-1];
else r[k][i]=max(r[k-1][i],r[k][i-1]);
}} g<<r[n][m]<<"\n"; max1=1;
for(i=1;i<=m;i++) {if(r[n][i]==max1) {g<<a[i]<<" "; max1++;}}
}
