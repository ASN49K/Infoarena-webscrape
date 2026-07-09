#include <stdio.h>
FILE *f=fopen("cmlsc.in","r");
FILE *g=fopen("cmlsc.out","w");
int c[1025][1025],m,n,a[1025],b[1025],i,j;
void rec(int i, int j) {
	if(i>0&&j>0)
		if(a[i]==b[j])
		{
			rec(i-1,j-1);
			fprintf(g,"%d ",a[i]);
		}
		else
			if(c[i-1][j]==c[i][j])
				rec(i-1,j);
				 else
					  rec(i,j-1);
}
int main() {
	fscanf(f,"%d%d",&m,&n);
	for(i=1;i<=m;i++)
		fscanf(f,"%d",&a[i]);
	for(i=1;i<=n;i++)
		fscanf(f,"%d",&b[i]);
	for(i=1;i<=m;i++)
		for(j=1;j<=n;j++)
			if(a[i]==b[j])
				c[i][j]=1+c[i-1][j-1];
			else
				if(c[i-1][j]>c[i][j-1])
					c[i][j]=c[i-1][j];
				else
					c[i][j]=c[i][j-1];
	fprintf(g,"%d\n",c[m][n]);
	rec(m,n);
	return 0;
}