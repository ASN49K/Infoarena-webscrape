#include <iostream>
#include <fstream>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int A[1015],B[1025],v[1025],a[1025][1025];
int maxim(int x, int y)
{
    if(x>y) return x;
    return y;
}
int main()
{int n,m,i,j;
f>>n>>m;
for(i=1;i<=n;i++)
f>>A[i];
for(i=1;i<=m;i++)
f>>B[i];
for(i=1;i<=n;i++)
    for(j=1;j<=m;j++)
    if(A[i]==B[j]) a[i][j]=a[i-1][j-1]+1;
    else a[i][j]=maxim(a[i][j-1],a[i-1][j]);
int k=0;
i=n;
j=m;
while(i>0 and j>0)
{
    if(A[i]==B[j]) {v[++k]=A[i]; i--; j--;}
    else if(a[i-1][j]<a[i][j-1]) j--;
    else i--;
}
g<<k<<'\n';
for(i=k;i>=1;i--)
g<<v[i]<<' ';
    return 0;
}
