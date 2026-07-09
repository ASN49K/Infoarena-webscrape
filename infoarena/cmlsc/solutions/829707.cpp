#define max(a,b) (a>b) ? a:b
#include<stdio.h>
int L[1030][1030],v1[1030],v2[1030],sol[1030];

void compute_LCSlenght(int a,int b)
{
	for(int i=1; i<=a ;i++)
	
		for(int j=1; j<=b; j++)

			if(v1[i]==v2[j])
			     L[i][j]=L[i-1][j-1]+1;
			else
				 L[i][j]=max(L[i-1][j],L[i][j-1]);
}
void compute_LCS(int a,int b)
{
	int i=a,j=b,k=0;
	 while( j && i )
			 if(v1[i]==v2[j])
				 sol[++k]=v1[i],--i,--j;
			 else
				 if(L[i-1][j]<L[i][j-1])
					 j--;
				 else 
					 i--;
}
int main()
{
	int n,m;
	FILE *f=fopen("cmlsc.in","r");
	FILE *g=fopen("cmlsc.out","w");
	fscanf(f,"%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		fscanf(f,"%d",&v1[i]);
	for(int j=1;j<=m;j++)
		fscanf(f,"%d",&v2[j]);
	compute_LCSlenght(n,m);
	fprintf(g,"%d\n",L[n][m]);
	compute_LCS(n,m);
	for(int i=L[n][m];i>=1;i--)
		fprintf(g,"%d ",sol[i]);
}