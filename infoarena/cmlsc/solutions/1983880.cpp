#include <iostream>
#include <fstream>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int n,m,a[1025],b[1025],d[1025][1025];

int main()
{
    f>>n>>m;
    for(int i=1;i<=n;i++)
        f>>a[i];
    for(int i=1;i<=m;i++)
        f>>b[i];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            if(a[i]==b[j])
                d[i][j]=1+d[i-1][j-1];
            else
                d[i][j]=max(d[i-1][j],d[i][j-1]);
        }
    g<<d[n][m]<<endl;
    int i=n,j=m,k=d[n][m],t[1025];
    while(i>0 && j>0)
    {
        if(a[i]==b[j])
        {
            t[k--]=a[i];
            i--;
            j--;
        }
        else
        if(d[i][j-1] > d[i-1][j])
            j--;
        else
            i--;
    }
    for(int i=1;i<=d[n][m];i++)
        g<<t[i]<<" ";
    return 0;
}
