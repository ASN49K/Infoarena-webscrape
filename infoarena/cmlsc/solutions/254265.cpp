#include<stdio.h>
#define max(a,b) a>b?a:b
FILE *f=fopen("cmlsc.in","r"),
     *g=fopen("cmlsc.out","w");
int a[1025],b[1025],i,j,k,n,m,d[1025][1025],sir[1025];
int main()
{ fscanf(f,"%d %d",&n,&m);
  for(i=1;i<=n;++i) fscanf(f,"%d",&a[i]);
  for(i=1;i<=m;++i) fscanf(f,"%d",&b[i]);
  for(i=1;i<=n;++i) for(j=1;j<=m;++j) if(a[i]==b[j]) d[i][j]=1+d[i-1][j-1];
                                      else d[i][j]=max(d[i][j-1],d[i-1][j]);
  for(i=n,j=m;i;) if(a[i]==b[j]) sir[++k]=a[i],--i,--j;
                 else if(d[i-1][j]>d[i][j-1]) --i;
                 else --j;
  fprintf(g,"%d\n",k);
  for(i=k;i;--i) fprintf(g,"%d ",sir[i]);
  fprintf(g,"\n");
  fclose(f);
  fclose(g);
  return 0;
}
