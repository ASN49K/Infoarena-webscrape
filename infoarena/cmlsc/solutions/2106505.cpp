#include <iostream>
#include <fstream>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int v1[1025],v2[1025],a[2050][2050],v3[1025],l,c;
int n,i,m,j,k;
int Max(int a ,int b)
{
    if(a>=b)return a;
    else return b;
}

int main ()
{
    f>>n>>m;
    for(i=1;i<=n;i++)
        f>>v1[i];
    for(i=1;i<=m;i++)
        f>>v2[i];
        for(i=2;i<=n+1;i++)
           {
               for(j=2;j<=m+1;j++)
               {
                   if(v1[i-1]==v2[j-1]) a[i][j]=a[i-1][j-1]+1;
                   else a[i][j]=Max(a[i][j-1],a[i-1][j]);
               }}
k=0;
l=n+1;
c=m+1;
while(a[l][c]>=1)
{
    if(a[l][c]!=Max(a[l-1][c],a[l][c-1])){k++;v3[k]=v1[l-1];l=l-1;c=c-1;}
    if(a[l][c]==Max(a[l-1][c],a[l][c-1]) && a[l-1][c]==a[l][c-1]) l=l-1;
    else if(a[l-1][c]>a[l][c-1])l=l-1;
    else if(a[l-1][c]<a[l][c-1])c=c-1;



}
g<<k<<endl;
for(i=k;i>=1;i--)
    g<<v3[i]<<" ";

}
