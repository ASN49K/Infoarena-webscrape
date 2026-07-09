//BC
#include <stdio.h>
#define maxN 1200

char  s1[maxN],s2[maxN];
char  mat[maxN][maxN];
int n,m;

void citire()
{
	freopen ("cmlsc.in","r",stdin);
	freopen ("cmlsc.out","w",stdout);
	scanf ("%d %d",&n,&m);
	int x;
	for (int i=1;i<=n;i++)
	{
		scanf ("%d ",&x);
		s1[i]=x;
	}

	for (int j=1;j<=m;j++)
	{
		scanf ("%d ",&x);
		s2[j]=x;
	}
}

inline int max(int a,int b)
{
	return a>b?a:b;
}

void dinamik()
{
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			if(s1[i]==s2[j])
				mat[i][j]=mat[i-1][j-1]+1;
			else
				mat[i][j]=max(mat[i-1][j],mat[i][j-1]);

}


void afisare()
{
	int rez[1024],num=0;
	printf("%d\n",mat[n][m]);
	int i=n,j=m;
	while (mat[i][j])
	{
		if (s1[i]==s2[j])
		{
			rez[num++]=s1[i];
			i--;
			j--;
		}
		else
			if (mat[i][j]==mat[i][j-1])
				j--;
			else
				i--;
	}

	for (i=num-1;i>=0;i--)
	     printf("%d ",rez[i]);
}

int main ()
{
	citire();
	dinamik();
	afisare();
	return 0;
}