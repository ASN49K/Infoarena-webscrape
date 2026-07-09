#include <stdio.h>
#define max(a,b) (a>b?a:b)

int m,n,a[1030],b[1030],mat[1030][1030],rez[1030],rezL,i,j;

int main()
{
	FILE *f=fopen("cmlsc.in","r");
	fscanf(f,"%i%i",&m,&n);
	for(i=0;i<m;i++)
		fscanf(f,"%i",&a[i]);
	for(i=0;i<n;i++)
		fscanf(f,"%i",&b[i]);
	for(i=1;i<=m;i++)
		for(j=1;j<=n;j++)
			if(a[i-1]==b[j-1])
				mat[i][j]=mat[i-1][j-1]+1;
			else 
				mat[i][j]=max(mat[i-1][j],mat[i][j-1]);
	for(i=m,j=n;i;)
		if(a[i-1]==b[j-1])
			rez[rezL++]=a[i-1],i--,j--;
		else
			if(mat[i-1][j]<mat[i][j-1])
				j--;
			else
				i--;
	f=fopen("cmlsc.out","w");
	fprintf(f,"%i\n",rezL);
	for(;rezL;)
		fprintf(f,"%i ",rez[--rezL]);
	return 0;
}
