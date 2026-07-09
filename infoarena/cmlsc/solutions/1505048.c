#include<stdio.h>
float maxim(float a, float b)
{
	if(a>b)
		return a;
	else
		return b;
}
int main()
{
	int i,j,a[1024],b[1024],m,n,k,subsir[1024],mat[1024][1024];
	freopen("cmlsc.in","r",stdin);
	freopen("cmlsc.out","w",stdout);
	scanf("%d",&m);
	scanf("%d",&n);
	for(i=1;i<=m;i++)
		scanf("%d",&a[i]);
	for(j=1;j<=n;j++)
		scanf("%d",&b[j]);
	for(i=1;i<=m;i++)
		for(j=1;j<=n;j++)
			if(a[i]==b[j])
				mat[i][j]=1+mat[i-1][j-1];
		    else
		    	mat[i][j]=maxim(mat[i-1][j],mat[i][j-1]);
	for(i=1;i<=m;i++)
		for(j=1;j<=n;j++)
			if(a[i]==b[j])
				{k++;
				subsir[k]=a[i];
				i--;
				j--;}
			else
			if(mat[i-1][j]<mat[i][j-1])
				j--;
			else
				i--;
	printf("%d \n",k);
	while(k)
	{
		printf("%d",subsir[k]);
		k--;}
	return 0;}