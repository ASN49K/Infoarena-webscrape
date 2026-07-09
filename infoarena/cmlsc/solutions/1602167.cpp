#include <iostream>
#include <fstream>
using namespace std;
int v[1025];
int main()
{
    ifstream f("cmlsc.in");
    ofstream g("cmlsc.out");int i,n,m,x,j=0,nr=0;
f>>n>>m;
for(i=1;i<=n;i++){
f>>x;
v[x]=1;
j=max(j ,x);
}
for(i=1;i<=m;i++){
f>>x;
if(v[x]==1) v[x]=2;
j=max(j ,x);
if(v[x]==2) nr++;
}
g<<nr<<'\n';
for(i=1;i<=j;i++)
if(v[i]==2)g<<i<<' ';
return 0;
}
