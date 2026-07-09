#include <stdio.h>
int a[1024][1024];
int main ()
{int n,m,i,j,x[1024],y[1024],v[2100],k;
FILE *f=fopen("cmlsc.in","r");
FILE *g=fopen("cmlsc.out","w");
fscanf(f,"%d %d",&n,&m);
for(i=1; i<=n; i++)
   fscanf(f,"%d",&x[i]);
for(i=1; i<=m; i++)
   fscanf(f,"%d",&y[i]);
for(i=1; i<=n; i++)
   for(j=1; j<=m; j++)
      if(x[i]==y[j]) a[i][j]=a[i-1][j-1]+1;
      else if(a[i][j-1]>a[i-1][j]) a[i][j]=a[i][j-1];
	   else a[i][j]=a[i-1][j];
i=n;
j=m;
k=0;
while(i && j)
  { if(x[i]==y[j]) { v[++k]=x[i--];
		    j--;}
    else if(a[i][j]==a[i-1][j]) i--;
	 else if(a[i][j]==a[i][j-1]) j--;
	 }
fprintf(g,"%d\n",k);
for(i=k; i>=1; i--) fprintf(g,"%d ",v[i]);
fclose(f);
fclose(g);
return 0;
}
