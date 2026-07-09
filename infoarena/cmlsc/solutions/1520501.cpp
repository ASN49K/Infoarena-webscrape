#include <iostream>
#include <fstream>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int a[1025],b[1025],i,j,n,m,lcs[1025][1025],k,d[1025];
int main()
{
    f>>n>>m;
    for(i=1;i<=n;i++)
        f>>a[i];
    for(j=1;j<=m;j++)
        f>>b[j];
    for(i=0;i<=n;i++)
        lcs[i][0]=0;;
    for(i=0;i<=m;i++)
        lcs[0][i]=0;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            if(a[i]==b[j]) lcs[i][j]=1+lcs[i-1][j-1];
            else if(lcs[i-1][j]>lcs[i][j-1]) lcs[i][j]=lcs[i-1][j];
            else lcs[i][j]=lcs[i][j-1];
        }
    }
    for(k=0,i=n,j=m;lcs[i][j];)
    {
        if(a[i]==b[j])
        {
            d[k++]=a[i]; i--; j--;
        }
        else if(lcs[i][j]==lcs[i-1][j]) i--;
        else j--;
    }
    g<<lcs[n][m]<<'\n';
    for(i=k-1;i>=0;i--)
        g<<d[i]<<" ";
    return 0;
}
