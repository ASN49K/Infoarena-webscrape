#include<stdio.h>

#define maxim(a,b) ((a>b)? a:b)
int M,N,a[1025],b[1025],mat[1025][1025],sir[1025],bst=0;

int main()
{
	FILE* f1,*f2;
	f1=fopen("cmlsc.in","r");
	f2=fopen("cmlsc.out","w");
	fscanf(f1,"%d %d",&M,&N);
	int i,j;
	for(i=1;i<=M;i++)
		fscanf(f1,"%d",&a[i]);
	for(i=1;i<=N;i++)
		fscanf(f1,"%d",&b[i]);

	for(i=1;i<=M;i++)
		for(j=1;j<=N;j++)
			if(a[i]==b[j])
				mat[i][j]=1+mat[i-1][j-1];
			else mat[i][j]=maxim(mat[i-1][j],mat[i][j-1]);

	for(i=M,j=N;i;)
		if(a[i]==b[j])
		{
			sir[++bst]=a[i];
			i--;
			j--;
		}
		else if(mat[i-1][j]<mat[i][j-1])
			j--;
		else i--;
	fprintf(f2,"%d\n",bst);
	for(i=bst;i>0;i--)
		fprintf(f2,"%d ",sir[i]);
	fcloseall();
	return 0;
}