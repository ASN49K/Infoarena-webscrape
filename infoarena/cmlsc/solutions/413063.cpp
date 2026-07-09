#include<stdio.h>
#define max(a,b) a>b ? a : b
int k,v1[1030],v2[1030],v[1030][1030],m,n,s[1030];
void matrix_margins()
{
	for (int i=1;i<=n;i++)
		v[0][i+1]=v1[i];
	for (int i=1;i<=m;i++)
		v[i+1][0]=v2[i];
}
void build_matrix()
{
	for(int i=2;i<=m+1;i++)
		for(int j=2;j<=n+1;j++)
			if(v[i][0]==v[0][j])
				v[i][j]=v[i-1][j-1]+1;
			else v[i][j]=max(v[i-1][j],v[i][j-1]);
}
void build_sequence()
{
	int l=m+1,c=n+1;
	while(v[l][c])
	{
		if(v[l][c]==v[l-1][c-1]+1&&v[l][c]==v[l-1][c]+1&&v[l][c]==v[l][c-1]+1)
		{
			s[++k]=v[0][c];
			l--;
			c--;
		}
		else if(v[l-1][c]<v[l][c])
				c--;
		else if(v[c-1][l]<v[l][c])
				l--;
		else
		{
			l--;
			c--;
		}
	}
}
void program()
{
	matrix_margins();
	build_matrix();
	build_sequence();
}
int main()
{
	freopen("cmlsc.in","r",stdin);
	freopen("cmlsc.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&v1[i]);
	for(int i=1;i<=m;i++)
		scanf("%d",&v2[i]);
	program();
	printf("%d\n",k);
	for(int i=k;i>=1;i--)
		printf("%d ",s[i]);
	return 0;
}