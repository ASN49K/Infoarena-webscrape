#include<stdio.h>
#define max(x,y) ((x)>(y)?(x):(y))
int mat[2][1025],vec[1025],m,n,a[1025],b[1025];
void citire()
{scanf("%d%d",&n,&m);
for(int i=1;i<=n;i++)
	scanf("%d",&a[i]);
for(int j=1;j<=m;j++)
	scanf("%d",&b[j]);
}
void cmlsc()
{int lung=0;int k=0;
for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
		if(a[i]==b[j])
		{	mat[i%2][j]=mat[(i-1)%2][j-1]+1;
			if(mat[i%2][j]>lung)
			{	vec[++k]=a[i];
				lung=mat[i%2][j];
			}
			if(mat[i%2][j]==lung)
				vec[k]=a[i];
		}
		else
			mat[i%2][j]=max(mat[(i-1)%2][j],mat[i%2][j-1]);
printf("%d\n",mat[n%2][m]);
for(int i=1;i<=k;i++)
	printf("%d ",vec[i]);
}
int main()
{freopen("cmlsc.in","r",stdin);
freopen("cmlsc.out","w",stdout);
citire();
cmlsc();
return 0;
}
