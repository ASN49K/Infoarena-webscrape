#include <fstream>

using namespace std;

#define Nmax 1024
#define maxim(a,b) ((a>b)?a:b)

int m,n,a[Nmax],b[Nmax],d[Nmax][Nmax],sir[Nmax],lung;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int main(){
int i,j;
f>>m>>n;
for(i=1;i<=m;i++) f>>a[i];
for(j=1;j<=n;j++) f>>b[j];
for (i=1;i<=m;i++)
    for (j=1;j<=n;j++)
    if (a[i]==b[j]) d[i][j]=1+d[i-1][j-1];
    else d[i][j]=maxim(d[i-1][j],d[i][j-1]);

for (i=m,j=n;i;)
    if(a[i]==b[j]){sir[++lung]=a[i]; --i; --j;}
    else if (d[i][j-1]<d[i-1][j]) --i;
    else --j;

g<<lung<<'\n';
for (i=lung;i;i--)
    g<<sir[i]<<" ";

return 0;
}
