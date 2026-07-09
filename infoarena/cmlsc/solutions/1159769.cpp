#include <iostream>
#include <cstdio>
using namespace std;
int a[1050][1050],m,n,i,j,b[1050],c[1050],d[1050],nr;
int main()
{
    FILE *fin=fopen("cmlsc.in","r");
    FILE *fout=fopen("cmlsc.out","w");
    fscanf(fin,"%d%d",&n,&m);
    for(i=1;i<=n;i++)
        fscanf(fin,"%d",&b[i]);
    for(i=1;i<=m;i++)
        fscanf(fin,"%d",&c[i]);
    for(i=1;i<=n;i++)
    for(j=1;j<=m;j++)
    {
    if(b[i]==c[j])a[i][j]=a[i-1][j-1]+1;
    else
    {
    if(a[i-1][j]>a[i][j-1])a[i][j]=a[i-1][j];
    else a[i][j]=a[i][j-1];
    }
    }
    nr=a[n][m];
    i=n;
    j=m;
    fprintf(fout,"%d\n",nr);
    while(nr!=0)
    {
     while(a[i-1][j]==nr)i--;
     while(a[i][j-1]==nr)j--;
     d[nr]=b[i];
     nr--;
    }
    for(i=1;i<=a[n][m];i++)fprintf(fout,"%d ",d[i]);
    fclose(fin);
    fclose(fout);
    return 0;
}
