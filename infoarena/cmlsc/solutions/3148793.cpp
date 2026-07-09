#include <iostream>
#include <fstream>
using namespace std;
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");
int a[1024],b[1024],m,n,sir[1024],bs,d[1024][1024];
int maxim(int a,int b){
    return a>b ? a:b;
}
int main(){
in>>n>>m;
for(int i=1;i<=n;i++)
in>>a[i];
for(int i=1;i<=m;i++)
in>>b[i];
for(int i=1;i<=n;i++)
for(int j=1;j<=m;j++)
    if(a[i]==b[j])
    d[i][j]=1+d[i-1][j-1];
    else
    d[i][j]=maxim(d[i-1][j],d[i][j-1]);
int i=n,j=m;
while(i && j){
    if(a[i]==b[j])
    sir[++bs]=a[i],--i,--j;
    else if(d[i-1][j]<d[i][j-1])
    --j;
    else
    --i;
}
out<<bs<<endl;
for(i=bs;i>0;i--)
out<<sir[i]<<" ";
}