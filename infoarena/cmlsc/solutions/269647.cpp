#include<stdio.h>
# define N 1030

int n,m,x;
int s[N],t[N],v[N];
int a[N][N];

void eu_citesc()
{
	int i;
	scanf("%d",&n);
	scanf("%d",&m);
	for(i=1;i<=n;i++)
		scanf("%d",&s[i]);
	for(i=1;i<=m;i++)
		scanf("%d",&t[i]);
}

int eu_aflu_max(int a,int b)
{
	if(a > b)
		return a;
	else
		if(a < b) 
			return b;
	return a;	
}	

void eu_lucrez()
{
	
	int i,j;
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
		{	
			if(s[i] == t[j])
				a[i][j] = a[i-1][j-1] + 1;
			else
				if(s[i] != t[j])
					a[i][j] = eu_aflu_max(a[i-1][j],a[i][j-1]);
		}

}
void eu_afisez()
{
	int i;
	for(i=x;i>=1;--i)
		printf("%d ",v[i]);
}

void eu_reconstruiesc()
{
	int i;
	
	while(n && m)
	{
		if(s[n] == t[m])
		{
			v[++x]=s[n];
			n--;
			m--;
			continue;
		}
		if(eu_aflu_max(a[n-1][m],a[n][m-1]) == a[n-1][m])
			n--;
		else
			m--;
	}
	eu_afisez();
}



int main()
{
	
	freopen("cmlsc.in","r",stdin);
	freopen("cmlsc.out","w",stdout);
	
	eu_citesc();
	eu_lucrez();
	printf("%d\n",a[n][m]);
	eu_reconstruiesc();
	return 0;
}
