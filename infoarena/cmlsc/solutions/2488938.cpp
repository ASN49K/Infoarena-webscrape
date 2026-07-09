#include <iostream>
#include <fstream>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int n,m,a[1025],b[1025],ap[1026][1026],c[1025];
int main()
{
    f>>n>>m;
    for(int i=1;i<=n;i++)
        f>>a[i];
    for(int j=1;j<=m;j++)
        f>>b[j];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        if(a[i]==b[j])
            ap[i][j]=ap[i-1][j-1]+1;
        else
            ap[i][j]=max(ap[i-1][j],ap[i][j-1]);
    g<<ap[n][m]<<'\n';
    int i=n,j=m,k=0;
    while(i>0 && j>0)
    {
        if(a[i]==b[j])
        {
            c[++k]=a[i];
            i--;
            j--;
        }
        else if (ap[i-1][j]>ap[i][j-1])
            i--;
        else j--;
    }
    for(int i=k;i>0;i--)
        g<<c[i]<<' ';
}
