#include<stdio.h>
#define dim 1030
#define maxim(a, b) ((a>b)?a:b) // daca a>b return a altfel return b

int a[dim],b[dim],d[dim][dim],sir[dim],bst,m,n;
int main()
{
int i,j;
FILE *f=fopen("cmlsc.in","r"), *g=fopen("cmlsc.out","w");

fscanf(f,"%d%d",&m,&n);
for(i=1;i<=m;i++)
fscanf(f,"%d",&a[i]);
for(i=1;i<=n;i++)
fscanf(f,"%d",&b[i]);	

for(i=1;i<m;i++)
	for(j=1;j<n;j++)
			if(a[i]==b[j])
				d[i][j]=1+d[i-1][j-1];
			else
				d[i][j]=maxim(d[i-1][j],d[i][j-i]);
			
for (i=m,j=n;i;)
	if(a[i]==b[j])
		sir[++bst]=a[i],i--,j--;
	else if(d[i-1][j]<d[i][j-1])
		--j;
	else
		--i;
	fprintf(g,"%d\n",bst);
	for(i=bst;i;--i)
		fprintf(g,"%d ",sir[i]);
	fprintf(g,"\n");
fclose(f);
fclose(g);
return 0;}