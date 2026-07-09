#include <iostream>
#include <fstream>

using namespace std;

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

int a[1025][1025],i,m,n,x[1025],y[1025],sol[1025];

void cmlsc()
{
    int i,j;
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            if(x[i]==y[j]) a[i][j]=1+a[i-1][j-1];
            else a[i][j]=max(a[i-1][j],a[i][j-1]);
}

void afis()
{
    int l=a[n][m];
    out<<a[n][m]<<'\n';
    int i=n,j=m;
    while(l)
    {
        if(x[i]==y[j])
        {
            sol[l]=x[i];
            l--;
            i--;
            j--;
        }
        else
        {
            if(a[i-1][j]<a[i][j-1]) j--;
            else i--;
        }
    }
    for(int k=1;k<=a[n][m];k++)
        out<<sol[k]<<" ";
}

int main()
{
    in>>n>>m;
    for(i=1;i<=n;i++) in>>x[i];
    for(i=1;i<=m;i++) in>>y[i];
    a[0][0]=0;
    cmlsc();
    afis();
    return 0;
}
