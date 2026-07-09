#include <iostream>
#include <fstream>

using namespace std;

int a[1024], b[1024], c[1024], l[1024][1024], i, j, m, n, k;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int main()
{
    f>>n>>m;
    for(i=1; i<=n; i++)
        f>>a[i];
    for(j=1; j<=m; j++)
        f>>b[j];
    for(i=1; i<=n; i++)
        for(j=1; j<=m; j++)
        if(a[i]==b[j])
        l[i][j]=l[i][j-1]+1;
    else
        l[i][j]=max(l[i-1][j], l[i][j-1]);
   k=0;
   i=n;
   j=m;
   while(i>0)
   {

    if(a[i]==b[j])
   {
       c[k++]=a[i];
       i--;
        j--;
   }
   else
    if(l[i][j-1]>l[i-1][j])
    j--;
   else
    i--;
}
g<<l[n][m]<<"\n";
for(i=k-1; i>=0; i--)
    g<<c[i]<<" ";
    f.close();
    g.close();
    return 0;
}
