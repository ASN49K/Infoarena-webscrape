#include<stdio.h>
int A[1025],B[1025],mat[1025][1025];
int  generate_mat(int n,int m)
{
	int i,j;
	for(i=1;i<=n;++i)
		for(j=1;j<=m;++j)
		{
			if(A[i]==B[j])
			{
				//printf("\n egalitate %d %d %d %d\n",A[i],i,B[j],j);
				mat[i][j]=1+mat[i-1][j-1];
			}
			else
				mat[i][j]=(mat[i-1][j]>mat[i][j-1])?mat[i-1][j]:mat[i][j-1];
		}
	printf("%d ",mat[n][m]);
	return mat[n][m];
}
void reconstruct_path(int n,int m,int nt)
{
	int result[1025],nr=0,cop;
	cop=nt;
	//result[--nt]=A[n];	
	//printf("\n%d\n%d\n",result[nt],nt);
	while(n && m)
	{
		printf("(%d,%d)\n",n,m);
		if(A[n]==B[m])
		{
			result[--nt]=A[n];
			--n;
			--m;
			//if(nt)
				//printf("\nramur %d %d\n",result[nt],nt);
		}
		else
		{
			if(((mat[n-1][m]>mat[n][m-1]) ? mat[n-1][m] : mat[n][m-1])==mat[n-1][m])
				--n;
			else
				--m;
		}
	}
	printf("\n");
	for(int i=0;i<cop;++i)
		printf("%d ",result[i]);
	printf("\n");
}
int main()
{
	int n,m,i;
	freopen("cmlsc.in","r",stdin);
	freopen("cmlsc.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;++i)
		scanf("%d",A+i);
	for(i=1;i<=m;++i)
		scanf("%d",B+i);
	//printf("%d\n",generate_mat(n,m));
	reconstruct_path(n,m,generate_mat(n,m));
	/*
	for(i=1;i<=n;++i)
	{
		for(int j=1;j<=m;++j)
			printf("%d ",mat[i][j]);
		printf("\n");
	}
	*/
}
