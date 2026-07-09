#include <iostream>
#include <fstream>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int a[1025][1025],n,m,x[1025],y[1025],sol[1025];
void cmlsc()
{
    int i,j;
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
        if(x[i]==y[j]) a[i][j]=a[i-1][j-1]+1;
    else a[i][j]=max(a[i-1][j],a[i][j-1]);
}
void afis()
{
    int l=a[n][m];

    g <<l<<endl;
    int i=n;
    int j=m;
    while(l)
    if(x[i]==y[j]){sol[l]=x[i];l--;i--;j--;}
    else if(a[i-1][j]<a[i][j-1])j--;
    else i--;
    for(int k=1;k<=a[n][m];k++)g<<sol[k]<<" ";
}
int main()
{ int i;
    f>>n>>m;
    for(i=1;i<=n;i++)
        f>>x[i];
    for(i=1;i<=m;i++)
        f>>y[i];
    cmlsc();
    afis();
    return 0;
}
