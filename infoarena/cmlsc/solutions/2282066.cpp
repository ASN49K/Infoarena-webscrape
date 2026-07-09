#include <iostream>
#include <fstream>
using namespace std;
ifstream f("sumtri.in");
ofstream g("sumtri.out");
int a[101][101],x[101][101],n,i,j,mx;
int main()
{f>>n;

for(i=1;i<=n;i++)
{
   for(j=1;j<=i;j++)
   {

        f>>a[i][j];

   }
}
for(j=1;j<=n;j++)
    x[n][j]=a[n][j];
for(i=n-1;i>=1;i--)
{
    for(j=1;j<=i;j++)
    {
    if(x[i+1][j]>x[i+1][j+1])
    {
        x[i][j]=a[i][j]+x[i+1][j];
    }
    else
    {
        x[i][j]=a[i][j]+x[i+1][j+1];
    }
    }
}
g<<x[1][1];

    return 0;
}
