#include<stdio.h>
int n,m,a[1027],b[1027],x[10027][1027];

int max(int i,int j)
{
	if(i>j)return i;
	else return j;
}

int main()
{
	freopen("cmlsc.in","r",stdin);
	freopen("cmlsc.out","w",stdout);
	scanf("%d", &n);
	scanf("%d", &m);
	for(int i=n;i>=1;i--)
		scanf("%d",&a[i]);	
	for(int j=m;j>=1;j--)
		scanf("%d",&b[j]);

	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(a[i]==b[j])
				x[i][j]=x[i-1][j-1]+1;
			else
				x[i][j]=max(x[i-1][j],x[i][j-1]);
	
	printf("%d\n", x[n][m]);

	int i=n; int j=m;
	while(x[n][m]){
		if (a[i]==b[j]){
			printf("%d ",a[i]);--i;--j;--x[n][m];
		}
		else 
			if (x[i-1][j] < x[i][j-1])
				--j;
			else
				--i;
	}		

	
return 0;
}
