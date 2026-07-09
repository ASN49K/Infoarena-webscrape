#include<stdio.h>
int m16[1030], ak47[1030], v[1030], nr=0, a[1030][1030],m,n;

void citiritiune()
{
	freopen("cmlsc.in","r",stdin);
	scanf("%d%d\n",&m,&n);
	for(int i=1;i<=m;++i)
		scanf("%d", &m16[i]);
	for(int j=1;j<=n;++j)
		scanf("%d", &ak47[j]);
}

void maxiune(int i,int j)
{
	if(a[i][j-1]>a[i-1][j])
		a[i][j]=a[i][j-1];
	else
		a[i][j]=a[i-1][j];
}

void matriciune()
{
	for(int i=1;i<=m;++i)
		for(int j=1;j<=n;++j)
			if(m16[i]==ak47[j])
			{
				a[i][j]=a[i-1][j-1]+1;
			}
			else
				maxiune(i,j);

}

void afisiune()
{
	int i=m,j=n;
	freopen("cmlsc.out","w",stdout);
	printf("%d\n", a[m][n]);
	do
	{
		if(a[i][j]==a[i-1][j-1]+1)
		{
			v[++nr]=ak47[j];
			i--;j--;
		}
		else
		{	
			if(a[i][j]==a[i][j-1])
				j--;
			if(a[i][j]==a[i-1][j])
				i--;
		}
	}while(a[i][j]);
	while(nr)
		printf("%d ", v[nr--]);
}
	
int main()
{	
	citiritiune();
	matriciune();
	afisiune();
	return 0;
}