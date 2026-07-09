#include<fstream>
#define max(a, b) ((a > b) ? a : b)

using namespace std;

int main(){
int m,n,i,j,lungime;
ifstream f("cmlsc.in");
f>>m;
f>>n;
int a[m],b[n],sir[1024];
int c[m][n];
for(i=1;i<m;i++)
f>>a[i];
for(i=1;i<n;i++)
f>>b[i];
f.close();

for(i=1;i<m;i++)
for(j=1;j<n;j++)
if(a[i]==b[j])
c[i][j]=c[i-1][j-1]+1;
else
c[i][j]=max(c[i][j-1],c[i-1][j]);

for(i=m;j=n;i)
if(a[i]==b[j])
sir[++lungime]=a[i], --i,--j;
else if(c[i-1][j]<c[i][j-1])
--j;
else
--i;
ofstream g("cmlscout");
g<<lungime;
for(i=lungime;i;i--)
g<<sir[i];
return 0;
}


