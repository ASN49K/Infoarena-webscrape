#include <fstream>

using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int n,m,i,j,a[1024],b[1024],c[1024],z;
int main()
{f>>n>>m;z=1;
for(i=1;i<=n;i++)f>>a[i];
for(i=1;i<=m;i++)f>>b[i];
for(i=1;i<=n;i++)
for(j=1;j<=m;j++)
if(a[i]==b[j]){
c[z]=a[i];
z++;
}
g<<z-1<<'\n';
for(i=1;i<=z-1;i++)g<<c[i]<<" ";

    return 0;
}
