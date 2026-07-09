#include <iostream>
#include <fstream>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int x[1050][1050];
int main()
{
    int i,j,a[1050],b[1050],m,n,z[1024],p=0;
    f>>n>>m;
    for(i=1; i<=n; i++)
        f>>a[i];
    for(i=1; i<=m; i++)
        f>>b[i];
    for(i=1; i<=n; i++)
        for(j=1; j<=m; j++)
        {
            if(a[i]==b[j])
                x[i][j]=1+x[i-1][j-1];
            else
                x[i][j]=max(x[i-1][j], x[i][j-1]);
        }
    g<<x[n][m]<<endl;
    for(i=n,j=m; i>=1 && j>=1 ;)
    {
        if(a[i]==b[j])
        {
            p++;
            z[p]=a[i];
            i--;
            j--;
        }
        else
        {
            if(x[i-1][j]>x[i][j-1])
                i--;
            else
                j--;
        }
        if(x[i-1][j]==0 && x[i][j-1]==0)
        {
            p++;
            z[p]=a[i];
            break;
        }
    }
    for(;p>=1;p--)
        g<<z[p]<<" ";

    return 0;
}
