#include<stdio.h>
# define N 1100

int n,m,p;
int x[N],y[N],v[N];
int a[N][N];

void citire()
{
	int i;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
		scanf("%d",&x[i]);
	for(i=1;i<=m;i++)
		scanf("%d",&y[i]);
}

int max(int a,int b)
{
	if(a>b)
		return a;
	else
		if(a<b) 
			return b;
	return a;	
}	

void subsir  ()
{
	
	int i,j;
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
		{	
			if(x[i]==y[j])
				a[i][j]=a[i-1][j-1] + 1;
			else
				if(x[i]!=y[j])
					a[i][j]=max(a[i-1][j],a[i][j-1]);
		}

}
void afisare()
{
	int i;
	for(i=p;i>=1;--i)
		printf("%d ",v[i]);
}

void construire()
{
	
	
	while(n&&m)
	{
		if(x[n]==y[m])
		{
			v[++p]=x[n];
			n--;
			m--;
			continue;
		}
		if(max(a[n-1][m],a[n][m-1])==a[n-1][m])
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
	printf("%d\n",a[n][m]);
	construire();
	return 0;
}
