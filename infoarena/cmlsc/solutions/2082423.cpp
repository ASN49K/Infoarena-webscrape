#include <iostream>
#include <fstream>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int n, m, v1[1029], v2[1029], a[1029][1029], i, j, b[1024], k;
int main()
{
    f>>n>>m;
    for(i=1;i<=n;i++)
        f>>v1[i];
    for(j=1;j<=m;j++)
        f>>v2[j];
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            if(v1[i]==v2[j])
                a[i][j]=a[i-1][j-1]+1;
            else
                if(a[i-1][j]>a[i][j-1])
                    a[i][j]=a[i-1][j];
                else
                    a[i][j]=a[i][j-1];
        }
    }
    g<<a[n][m]<<'\n';
    i=n;
    j=m;
    while(i!=0)
    {
        if(v1[i]==v2[j])
        {
            k++;
            b[k]=v1[i];
            i--;
            j--;
        }
        else
            if(a[i-1][j]>a[i][j-1])
                i--;
            else
                j--;
    }
    for(i=k;i>=1;i--)
        g<<b[i]<<" ";
    return 0;
}
