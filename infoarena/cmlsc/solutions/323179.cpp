#include<stdio.h>
#define NMax 1024

FILE *in=fopen("cmlsc.in","r"),*out=fopen("cmlsc.out","w");

int m,n,A[NMax],B[NMax],D[NMax][NMax],sir[NMax],bst;

int main()
{
	int i,j;
	
	fscanf(in,"%d %d",&m,&n);
	for(i=1;i<=m;i++)
		fscanf(in,"%d",&A[i]);
	for(i=1;i<=n;i++)
		fscanf(in,"%d",&B[i]);
	
	for(i=1;i<=m;i++)
		for(j=1;j<=n;j++)
			if(A[i]==B[j])
				D[i][j]=1+D[i-1][j-1];
			else
				D[i][j]=(D[i-1][j]>D[i][j-1]) ? D[i-1][j] : D[i][j-1];
	for(i=m,j=n; i;)
		if(A[i]==B[j])
			sir[++bst] = A[i], --i, --j;
		else if (D[i-1][j] < D[i][j-1])
			--j;
		else
			--i;

	fprintf(out,"%d\n",bst);
	for(i=bst; i; --i)
		fprintf(out,"%d ",sir[i]);
	
	fclose(out);
	return 0;
}
