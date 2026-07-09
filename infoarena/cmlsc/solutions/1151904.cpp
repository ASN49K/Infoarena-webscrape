#include <iostream>
#include<fstream>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int a[1025],b[1025],c[1025][1025],m,n,i,l,j;
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
l=1;
for(i=1;i<=n;i++)
    for(j=1;j<=n;j++)
if(c[i][j]==l) {g<<a[i]<<" "; l++;}
}
