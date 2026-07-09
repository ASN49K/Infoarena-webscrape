#include <fstream>
#include <iostream>
using namespace std;
fstream f("clmsc.in",ios::in);
fstream g("clmsc.out",ios::out);

int max (int a,int b)
{
    if (a>b)
        return a;
    return b;
}

int main()
{
    int n,m,a[1025],b[1025],i,c[1025][1025]={0},j;
    f>>n>>m;
    for (i=0;i<n;i++)
        f>>a[i];
    for (i=0;i<m;i++)
        f>>b[i];

    if (a[0]==b[0])
        c[0][0]=1;
    for (i=1;i<n;i++)
        c[i][0]=c[i-1][0]+(a[i]==b[0]);
    for (i=1;i<m;i++)
        c[0][i]=c[0][i-1]+(b[i]==a[0]);

    for (i=1;i<n;i++)
        for (j=1;j<m;j++)
            c[i][j]=max(c[i-1][j],c[i][j-1])+(a[i]==b[j]);

    for (i=n-1,j=m-1;;i>=0,j>=0)
        {
        g<<c[i][j]<<" ";
        if (c[i][j-1]>c[i-1][j])
            j--;
        else
            i--;
        }
}
