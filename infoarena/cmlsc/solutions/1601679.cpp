#include<fstream>
#include<iostream>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int n,m,i,j,v[2000],a[2000],l,k[2000][2000],st[2000],p;

void citire(){
    f>>n>>m;
for(i=1;i<=n;i++)
   f>>v[i];
for(i=1;i<=m;i++)
    f>>a[i];

}
int maxx(int a,int b){
if(a>b)return a;
else return b;}

int main(){
citire();
for(i=1;i<=n;i++)
    for(j=1;j<=m;j++)
   if(v[i]==a[j]){
       k[i][j]=k[i-1][j-1]+1;}
else k[i][j]=maxx(k[i][j-1],k[i-1][j]);

for(i=n,j=m;i;)
if(a[j]==v[i]){st[++p]=a[j];i--;j--;}
else if(k[i-1][j]<k[i][j-1])
    j--;
else i--;


g<<p<<"\n";
for(i=p;i;i--)
    g<<st[i]<<" ";


f.close();
g.close();
return 0;}
