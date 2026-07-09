#include <iostream>
#include<fstream>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int a[1025],b[1025],c[1025][1025],m,n,i,l,j,k,sir[1025];
void afisare() {
for(i=1;i<=n;i++) {
    for(j=1;j<=m;j++) cout<<c[i][j]<<" ";
cout<<"\n";
}
}
int maxim(int a,int b) {
if(a>b) return a;
else return b;
}
int main()
{ f>>n>>m;
for(i=1;i<=n;i++) f>>a[i];
for(i=1;i<=m;i++) f>>b[i];
for(i=1;i<=n;i++)
    for(j=1;j<=m;j++)
    if(a[i]==b[j]) c[i][j]=c[i-1][j-1]+1;
else c[i][j]=maxim(c[i-1][j],c[i][j-1]);
g<<c[n][m]<<"\n";
i=n;
j=m;
while(i>0) {
    if(a[i]==b[j]) {
    sir[++k]=a[i];
    i--;
    j--;
}
else if(c[i-1][j] < c[i][j-1]) j--;
else i--;
}
for(i=k;i>=1;i--) g<<sir[i]<<" ";
}
