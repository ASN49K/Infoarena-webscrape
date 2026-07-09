#include<cstdio>
#define N 1026
using namespace std;
int m[N],n[N],mm,nn,k,sol[N];
int mat[N][N];
int maxim(int a, int b)
{
	if(a>b)
		return a;
	return b;
}

void citire()
{
	freopen("cmlsc.in","r",stdin);
	freopen("cmlsc.out","w",stdout);
	scanf("%d%d",&mm,&nn);
	for (int i=1;i<=mm;i++)
		scanf("%d",&m[i]);	
	for (int i=1;i<=nn;i++)
		scanf("%d",&n[i]);	
}
void calcul()
{
	
	for(int i=1;i<=mm;i++)
		for(int j=1;j<=nn;j++)
			if(m[i]==n[j])
				mat[i][j]=mat[i-1][j-1]+1;
			else
				mat[i][j]=maxim(mat[i-1][j],mat[i][j-1]);
	int	i=mm,j=nn; 
	do{
		if (m[i] == n[j])
		{
			k++;
			sol[k] = m[i];
			i--;
			j--;
		}
		else 
			if (mat[i-1][j] < mat[i][j-1])
						j--;
					else
						i--;
	}while(i>0 && j>0);				
	
	printf("%d\n", k);
	for (i = k; i>0; i--)
		printf("%d ",sol[i]);
	printf("\n");

	
}
int main()
{
	citire();
	calcul();
	return 0;
}