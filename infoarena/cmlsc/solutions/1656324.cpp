#include <stdio.h>
#include<algorithm>
using namespace std;

FILE*f=fopen("cmlsc.in","r");
FILE*g=fopen("cmlsc.out","w");

int a[1025][1025];
int n,m,i,j,x[1025],y[1025];

void afis(int i,int j)
{
    while (x[i]!=y[j])
    {
        if (a[i-1][j]>a[i][j-1]) i--;
        else j--;
    }
    if (a[i-1][j-1]>0) afis(i-1,j-1);
    fprintf(g,"%d ",x[i]);
}

int main()
{


    //citire
    fscanf(f,"%d%d",&n,&m);
    for (i=1;i<=n;i++) fscanf(f,"%d",&x[i]);
    for (i=1;i<=m;i++) fscanf(f,"%d",&y[i]);

    //dinamica
    for (i=1;i<=n;i++)
        for (j=1;j<=m;j++)
            if (x[i]==y[j]) a[i][j]=1+a[i-1][j-1];
            else a[i][j]=max(a[i-1][j],a[i][j-1]);

    //afisare
    fprintf(g,"%d\n",a[n][m]);
    afis(n,m);
    fclose(g);
    fclose(f);
    return 0;
}
