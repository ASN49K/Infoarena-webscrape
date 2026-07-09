#include <iostream>
#include <fstream>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int n, m, i, j, lmx, mx, x[1024], y[1024], a[1024][1024], sol[1024];
void afis()
{
    int l=a[n][m];
    g<<l<<endl;
    int i=n, j=m;
    while(l)
    {
        if(x[i]==y[j]) {sol[l]=x[i]; l--; i--; j--;}
        else
        {
            if(a[i-1][j]>a[i][j-1]) i--;
            else j--;
        }
    }
    for(i=1;i<=a[n][m];i++) g<<sol[i]<<" ";
}
int main()
{
    f>>n>>m;
    for(i=1;i<=n;i++) f>>x[i];
    for(i=1;i<=m;i++) f>>y[i];
    a[0][0]=0;
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
        {
            if(x[i]==y[j]) a[i][j]=1+a[i-1][j-1];
            else
            {
                if(a[i-1][j]>a[i][j-1]) a[i][j]=a[i-1][j];
                else a[i][j]=a[i][j-1];
            }
        }
    afis();
    return 0;
}
