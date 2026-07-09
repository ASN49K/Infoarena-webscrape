#include<stdio.h>
#define max(a,b) ((a>b) ? a : b)
#define Nmax 1100
int nr,n,m,a[Nmax],b[Nmax],sol[Nmax],mat[Nmax][Nmax];

void citire()
{
 freopen("cmlsc.in","r",stdin);
 int i;
 scanf("%d%d",&n,&m);
 for(i=1;i<=n;i++)
	scanf("%d",&a[i]);
 for(i=1;i<=m;i++)
	scanf("%d",&b[i]);
 fclose(stdin);
}

void cautare()
{
 int i,j;
 for(i=1;i<=n;i++)
	for(j=1;j<=m;j++)
	{
	if(a[i]==b[j])
		mat[i][j]=mat[i-1][j-1]+1;
	else
		mat[i][j]=max(mat[i][j-1],mat[i-1][j]);
	}
}

void construire()
{
 int i,j;
	for(j=m,i=n;j && i;)
		if(a[i]==b[j])
			{
			sol[++nr]=a[i];
			i--;
			j--;
			}
		else
			if(mat[i-1][j]>mat[i][j-1])
				i--;
			else
				j--;

}

void afisare()
{
 freopen("cmlsc.out","w",stdout);
 int i;
 printf("%d\n",nr);
 for(i=nr;i>0;i--)
	printf("%d ",sol[i]);
 printf("\n");
 fclose(stdout);
}

int main()
{
 citire();
 cautare();
 construire();
 afisare();
 return 0;
}