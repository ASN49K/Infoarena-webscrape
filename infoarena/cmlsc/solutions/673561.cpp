# include <fstream>
# include <iostream>
using namespace std;
int main()
{int m,n,i,a[256],b[256],k=1,c[256],ant=0,j;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
f>>n>>m;
for(i=1;i<=n;i++) f>>a[i];
for(i=1;i<=m;i++) f>>b[i];
for(i=1;i<=n;i++)
{for(j=1;j<=m;j++) if(a[i]==b[j] && ant<j) {c[k++]=a[i];
                                             ant=j;} }
g<<(k-1)<<endl;
for(i=1;i<=k-1;i++) g<<c[i]<<" ";
f.close();
g.close();
}
                                             

