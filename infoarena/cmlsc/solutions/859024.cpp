#include<fstream>
using namespace std;
unsigned short int a[1030],r[1030];
main(){
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
unsigned short int m,n,i,j,max1=0,max2,poz=1,k;
f>>m>>n;
for(i=1;i<=m;i++) f>>a[i];
for(k=1;k<=n;k++){
f>>j;
max2=r[1];
for(i=1;i<=m;i++){
if(max2<r[i]) max2=r[i];
if(j==a[i] && !r[i]){max2++; if(max2>=max1) {max1=max2; r[i]=max2;}}
}} g<<max1<<"\n"; max1=1;
for(i=1;i<=m;i++) {if(r[i]==max1) {g<<a[i]<<" "; max1++;}}
}
