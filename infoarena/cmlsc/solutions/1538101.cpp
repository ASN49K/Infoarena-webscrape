#include <iostream>
#include <fstream>
#define maxim(a,b) ((a>b)?a:b)
using namespace std;
fstream f;
int x[2000],y[2000], t[2000][2000],sol[2000];
int i,j,n,m;
main()
{
    f.open("cmlsc.in",ios::in);
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
    for (i=n,j=m;i;)
    {
        if (x[i]==y[j])
        {sol[k]=x[i];
        i--;
        j--;
        k++;}
        else if (t[i][j-1]<t[i-1][j])
        i--;
        else j--;
    }

    k=t[n][m];
    for (i=0;i<k/2;i++)
    {
        int aux;
        aux=sol[i];
        sol[i]=sol[k-i-1];
        sol[k-i-1]=aux;
    }
    f.close();
    f.open("cmlsc.out",ios::out);
    f<<k<<endl;
    for (i=0;i<k;i++)
    f<<sol[i]<<" ";
}
