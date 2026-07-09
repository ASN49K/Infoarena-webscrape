#include <iostream>
#include <fstream>

using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int i,n,m,a[1025][1025],x[1025],y[1025],sol[1025],j;
void afisare()
{ int i=n,j=m;
    int l=a[n][m];
    g<<l<<'\n';
    while(l)
        if(x[i]==y[j]){sol[l]=x[i];l--;i--;j--;}
        else if(a[i-1][j]>a[i][j-1])i--;
             else j--;
    for(int k=1;k<=a[n][m];k++)g<<sol[i]<<" ";
}


void cmlsc()
{ int i,j;
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
    {
        if(x[i]==y[j])a[i][j]=1+a[i-1][j-1];
        else a[i][j]=max(a[i-1][j],a[i][j-1]);
    }
}

int main()
{
    f>>n>>m;
    for(i=1; i<=n; i++)f>>x[i];
    for(i=1; i<=m; i++)f>>y[i];
    a[0][0]=0;
    cmlsc();
    g<<a[n][m];
    afisare();
    return 0;
}
