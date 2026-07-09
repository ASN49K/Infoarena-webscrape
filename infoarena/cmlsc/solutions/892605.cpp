#include <iostream>
#include <stdio.h>

using namespace std;

FILE *f=fopen("cmlsc.in","r");
FILE *g=fopen("cmlsc.out","w");

int mx,c[1025],a[1025],b[1025],w[1025][1025],m,n,i,j;


int main()
{
    fscanf(f,"%d%d",&n,&m);
    for(i=1;i<=n;i++)
    fscanf(f,"%d",&a[i]);
    for(i=1;i<=m;i++)
    fscanf(f,"%d",&b[i]);
    for(i=1;i<=n;i++)
    for(j=1;j<=m;j++)
    if(a[i]==b[j])w[i][j]=w[i-1][j-1]+1; else w[i][j]=max(w[i-1][j],w[i][j-1]);
    mx=w[n][m];
    fprintf(g,"%d\n",w[n][m]);
    for(i=n;i>=1;i--)
    for(j=m;j>=1;j--)
    if(mx && w[i][j]==mx && a[i]==b[j])
    {
        mx--;
        c[++c[0]]=a[i];
    }
    for(i=c[0];i>=1;i--)
    fprintf(g,"%d ",c[i]);
    fclose(g);
    return 0;
}
