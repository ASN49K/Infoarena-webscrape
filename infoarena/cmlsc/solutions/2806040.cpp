#include <iostream>
#include <fstream>

using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int i,n,m,x[1025][1025],a[1025],b[1025],sol[1025],j;
void afisare()
{
    int l=x[n][m];
    g<<'\n';
    int i=n,j=m;
    while(l!=0)
        if(a[i]==b[j]){sol[l]=a[i];l--;i--;j--;}
        else if(x[i-1][j]>x[i][j-1])i--;
             else j--;
    for(i=1;i<=x[n][m];i++)g<<sol[i]<<" ";
}
int main()
{
    f>>n>>m;
    for(i=1; i<=n; i++)f>>a[i];
    for(i=1; i<=m; i++)f>>b[i];
    x[0][0]=0;
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
    {
        if(a[i]==b[j])x[i][j]=1+x[i-1][j-1];
        else x[i][j]=max(x[i-1][j],x[i][j-1]);
    }
    g<<x[n][m];
    afisare();
    return 0;
}
