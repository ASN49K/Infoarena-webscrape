#include <iostream>
#include <fstream>
#define maxim(a,b) ((a>b)?a:b)
using namespace std;
ifstream f ("cmlsc.in");
ofstream g ("cmlsc.out");

int x[2000],y[2000], t[2000][2000],sol[2000];
int i,j,n,m;
main()
{

    f>>n>>m;
    for (i=1;i<=n;i++)
        f>>x[i];
    for (i=1;i<=m;i++)
        f>>y[i];

    for (i=1;i<=n;i++)
    for (j=1;j<=m;j++)
    {
        if (x[i]==y[j]) t[i][j]=t[i-1][j-1]+1;
        if (x[i]!=y[j])
        t[i][j]=maxim(t[i-1][j],t[i][j-1]);
    }
    int k=0;
    i=n;j=m;
    while (i>0)
    {
        if (x[i]==y[j])
        {sol[++k]=x[i];
        i--;
        j--;
        }
        else if (t[i-1][j]>t[i][j-1])
        i--;
        else j--;
    }


    g<<k<<endl;
    for (i=k;i>=1;i--)
   g<<sol[i]<<" ";

   return 0;
}
