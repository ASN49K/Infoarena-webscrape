#include <bits/stdc++.h>
using namespace std;

int n,a[1025][1025],x[1025],y[1025],k=1,sol[1025],m;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

void afisare()
{
    int l=a[n][m];
    g<<l<<endl;
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
        else if(a[i-1][j]<a[i][j-1]) j--;
        else i--;
    }
    for(int i=1;i<=a[n][m];i++)
        g<<sol[i]<<" ";
}

int main()
{
    f>>n>>m;
    for(int i=1;i<=n;i++)
        f>>x[i];
    for(int i=1;i<=m;i++)
        f>>y[i];
    a[0][0]=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(x[i]==y[j]) a[i][j]=1+a[i-1][j-1];
            else a[i][j]=max(a[i-1][j],a[i][j-1]);
    afisare();
    return 0;
}
