#include<iostream>
#include<stdio.h>
using namespace std;
int max(int a, int b)
{if (a>b)
	return a;
return b;
}
int i,j,bst,sol[1025],a[1025],b[1025],x[1025][1025],n,m;
int main()
{freopen("cmlsc.in","r",stdin);
freopen("cmlsc.out","w",stdout);
scanf("%d%d",&n,&m);
for(i=1;i<=n;i++)
	scanf("%d",&a[i]);
for(i=1;i<=m;i++)
	scanf("%d",&b[i]);
for(i=1;i<=n;i++)
	for(j=1;j<=m;j++)
		if(a[i]==b[j])
			x[i][j]=x[i-1][j-1]+1;
		else
			x[i][j]=max(x[i][j-1],x[i-1][j]);
i=n;j=m;
		for(bst=1;bst<=x[n][m];bst++)
			if(a[i]==b[j])
				{sol[bst]=a[i];i--;j--;}
				else
					{bst--;
						if(x[i-1][j]>x[i][j-1])
						i--;
					else
						j--;}
					printf("%d\n",bst-1);
for(i=x[n][m];i>=1;i--)
	{
		printf("%d ",sol[i]);
	}
}
