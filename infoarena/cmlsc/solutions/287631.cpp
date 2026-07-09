#include<stdio.h>
FILE *f,*g;
int d[1025][1025],n,m,i,a[1025],b[1025],j,nr,v[1025];
int max(int a,int b)
{ if(a>b) return a; return b; }
int main()
{ f=fopen("cmlsc.in","r"); g=fopen("cmlsc.out","w");
  fscanf(f,"%d%d",&n,&m);
  for(i=1;i<=n;i++) fscanf(f,"%d",&a[i]);
  for(i=1;i<=m;i++) fscanf(f,"%d",&b[i]);
  for(i=1;i<=n;i++)
   for(j=1;j<=m;j++)
    { if(a[i]==b[j]) d[i][j]=d[i-1][j-1]+1;
      else d[i][j]=max(d[i][j-1],d[i-1][j]);
    }
  nr=d[n][m];
  fprintf(g,"%d\n",nr);
  i=n; j=m;
  while(nr!=0)
   { if(a[i]==b[j]) { v[nr]=a[i]; nr--; i--; j--;}
     else
      if(d[i][j-1]==max(d[i][j-1],d[i-1][j])&&j>1) j--;
      else i--;
   }
  for(i=1;i<=d[n][m];i++) fprintf(g,"%d ",v[i]);
  fclose(g);
  return 0;
}



