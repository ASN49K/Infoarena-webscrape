#include<stdio.h>
int n,m,y;
int a[1025],b[1025],z[1025];
int x[1025][1025];

void citire()
{
	int i;
	scanf("%d",&n);
	scanf("%d",&m);
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(i=1;i<=m;i++)
		scanf("%d",&b[i]);
}

int max(int p,int q)
{
	if(p > q)
		return p;
	else
		if(p < q) 
			return q;
	return p;	
}	

void subsir()
{
	
	int i,j;
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
		{	
			if(a[i] == b[j])
				x[i][j] = x[i-1][j-1] + 1;
			else
				if(a[i] != b[j])
					x[i][j] = max(x[i-1][j],x[i][j-1]);
		}

}
void afisare()
{
	int i;
	for(i=y;i>=1;--i)
		printf("%d ",z[i]);
}

void construire()
{
	int i;
	
	while(n && m)
	{
		if(a[n] == b[m])
		{
			z[++y]=a[n];
			n--;
			m--;
			continue;
		}
		if(max(x[n-1][m],x[n][m-1]) == x[n-1][m])
			n--;
		else
			m--;
	}
	afisare();
}



int main()
{
	
	freopen("cmlsc.in","r",stdin);
	freopen("cmlsc.out","w",stdout);
	
	citire();
	subsir();
	printf("%d\n",x[n][m]);
	construire();
	return 0;
}
