#include <iostream>
#include<stdio.h>
using namespace std;
FILE *f,*g;
int a[1025][1025],v[1025],x[1025];
void afis (int i,int j)
{
    if(a[i][j]!=0)
    {
        if(v[i]==x[j])
        {
            afis(i-1,j-1);
            fprintf(g,"%d ",v[i]);
        }
        else
        {
            if(a[i-1][j]>a[i][j-1]) afis(i-1,j);
            else afis(i,j-1);
        }
    }
}
int main()
{
    int i,j,m,n;
    f=fopen("cmlsc.in","r");
    g=fopen("cmlsc.out","w");
    fscanf(f,"%d %d",&n,&m);
    for(i=1;i<=n;i++) fscanf(f,"%d",&v[i]);
    for(i=1;i<=m;i++) fscanf(f,"%d",&x[i]);
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            if(v[i]==x[j])
            {
                a[i][j]=a[i-1][j-1]+1;
            }
            else
            {
                if(a[i-1][j]>a[i][j-1]) a[i][j]=a[i-1][j]; else a[i][j]=a[i][j-1];
            }
        }
    }
    fprintf(g,"%d\n",a[n][m]);
    afis(n,m);
    fclose(f);
    fclose(g);
    return 0;
}
