#include <iostream>
#include <fstream>
#define MAX 1024
using namespace std;
fstream f("cmlsc.in",ios::in);
fstream g("cmlsc.out",ios::out);

int maxim (int a,int b)
{
    if (a>b)
        return a;
    return b;
}

int main()
{
    int n,m,i,j;
    char a[MAX],b[MAX],c[MAX][MAX];
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
            c[i][j]=maxim(c[i-1][j],c[i][j-1])+(a[i]==b[j]);

    for (i=n-1,j=m-1;i>=0&&j>=0;)
        {
        g<<c[i][j]<<" ";
        if (c[i][j-1]>c[i-1][j])
            j--;
        else
            i--;
        }
}
