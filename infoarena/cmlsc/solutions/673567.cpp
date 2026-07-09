# include <fstream>
using namespace std;
# define NMAX 1025
int main()
{long m,n,i,a[NMAX],b[NMAX],k=1,c[NMAX],ant=0,j;
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
                                             

