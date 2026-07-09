#include<stdio.h>
int n,m,nr;
int a[1026],b[1026],v[1026][1026];
int sol[1026];

void read()
{
	freopen("cmlsc.in","r",stdin);
	freopen("cmlsc.out","w",stdout);
	scanf("%d%d",&n,&m);
	int i;
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(i=1;i<=m;i++)
		scanf("%d",&b[i]);
}

inline int max(int a, int b)
{
	if(a>b)
		return a;
	return b;
}

void rez()
{
	int i,j;
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			if(a[i]==b[j])
				v[i][j]=v[i-1][j-1]+1;
			else
				v[i][j]=max(v[i-1][j],v[i][j-1]);
	i=n;
	j=m;
	nr=v[n][m];
	while(i)
	{
		if(a[i]==b[j])
		{
			sol[nr--]=a[i];
			i--;
			j--;
		}
		else
			if(v[i-1][j]<v[i][j-1])
				j--;
			else
				i--;
	}
	nr=v[n][m];
	printf("%d\n",nr);
	for(i=1;i<=nr;i++)
		printf("%d ",sol[i]);
}

int main()
{
	read();
	rez();
	return 0;
}
