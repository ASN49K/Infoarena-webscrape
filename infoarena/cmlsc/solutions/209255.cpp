#include<stdio.h>

#define max 1025

int a[max],b[max],c[max],d[max][max],m,n,i,j,x;
FILE *g=fopen("cmlsc.out","w");

void printsir(int,int);

int main()
{
	FILE *f=fopen("cmlsc.in","r");
	fscanf(f,"%i %i",&m,&n);
	for(i=1;i<=m;i++)
		fscanf(f,"%i",&a[i]);
	for(i=1;i<=n;++i)
		fscanf(f,"%i",&b[i]);
	for(i=1;i<=m;++i)
		for(j=1;j<=n;++j)
			if (a[i]==b[j]) d[i][j]=d[i-1][j-1]+1;
			else if (d[i-1][j]>d[i][j-1]) d[i][j]=d[i-1][j];
				else d[i][j]=d[i][j-1];
	fprintf(g,"%i\n",d[m][n]);
	printsir(m,n);
        return 0;
}


void printsir(int i1,int i2)
{
int y=0;
while((i1!=0)&&(i2!=0))
	{
	if (a[i1]==b[i2])
		{
		c[y]=a[i1];
		y++;
		i1--;
		i2--;
		}
	else
		if (d[i1-1][i2]<d[i1][i2-1])
			i2--;
		else
			i1--;
	}
while (y!=0)
{
      y--;
      fprintf(g,"%i ",c[y]);
}
}