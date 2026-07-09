#include<stdio.h>
FILE *f,*g;
int a[1025],b[1025],c[1025],d[1025],o,n,m,i,j,max,nr,t;
int main()
{
f=fopen ("cmlsc.in","rt");
g=fopen ("cmlsc.out","wt");
fscanf(f,"%d %d\n",&n,&m);
for (i=1;i<=n;i++)
	fscanf(f,"%d",&a[i]);
for (i=1;i<=m;i++)
	fscanf(f,"%d",&b[i]);
o=1;
for (i=1;i<=m;i++)
	{
	t=o;
	nr=1;
	for (j=t;j<=n;j++)
		if (b[i]==a[j]) {c[nr++]=b[i];o=t+1;i++;}
	if (nr>max) {max=nr;d[0]=nr;for(j=1;j<=nr;j++)d[j]=c[j]; }
	for (j=1;j<=nr;j++)
		c[j]=0;
	}
fprintf(g,"%d\n",d[0]);
for (j=1;j<=d[0];j++)
	fprintf(g,"%d ",d[j]);
fprintf(g,"\n");
fclose(f);
fclose(g);
return 0;
}