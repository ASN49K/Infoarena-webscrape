#include<stdio.h>
int n,m,z;
int x[1030],y[1030],pred[1030];
int a[1030][1030];


 void citire()
{
	int i;
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;i++)
		scanf("%d",&x[i]);
	for(i=1;i<=m;i++)
		scanf("%hd",&y[i]);
}

 int max(int a,int b)
 {
	if(a > b)
		return a;
	else
		if(a < b) 
			return b;
	return a;
 }	 
 void prel()
{


	int i,j;
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
		{	
			if(x[i] == y[j])
				a[i][j] = a[i-1][j-1] + 1;
			else
				if(x[i] != y[j])
					a[i][j] = max(a[i-1][j],a[i][j-1]);
		}
}

 void afisare()
{
	int i;
	for(i=z;i>=1;--i)
		printf("%d ",pred[i]);
}

 void predictie()
{
	int i;
	
	while(n!=0 && m!=0)
	{
		if(x[n] == y[m])
		{
			pred[++z]=x[n];
			n--;
			m--;
			continue;
		}
		if(max(a[n-1][m],a[n][m-1]) == a[n-1][m])
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
	prel();
	printf("%d\n",a[n][m]);
	predictie();
	return 0;
}