#include<stdio.h>

#define MAX_N 1025
#define MAX(a,b) (a) > (b) ? (a) : (b)
int n,m;
int A[MAX_N],B[MAX_N],sir[MAX_N];
int C[MAX_N][MAX_N];

void read(),solve();

int main()
{
	freopen("cmlsc.in","r",stdin);
	freopen("cmlsc.out","w",stdout);
	
	read();
	solve();
	
	fclose(stdin); fclose(stdout);
	return 0;
}

void read()
{
	int i;
	scanf("%d%d",&n,&m);
	for(i = 1; i <= n; i++)
		scanf("%d",&A[i]);
	for(i = 1; i <= m; i++)
		scanf("%d",&B[i]);
}

void solve()
{
	int i,j,lg;
	for(i = 1; i <= n; i++)
		for(j = 1; j <= m; j++)
			if(A[i] == B[j])
			{
				C[i][j] += C[i-1][j-1] + 1;
			}
			else
			{
				C[i][j] += MAX(C[i-1][j],C[i][j-1]);
			}
		
	for(i = n,j = m,lg = 0; i;)
	{
		if(A[i] == B[j])
		{
			sir[++lg] = A[i];
			i--;
			j--;
		}
		else if(C[i-1][j] < C[i][j-1])
		{
			j--;
		}
		else
		{
			i--;
		}			
	}
	printf("%d\n",lg);
	for(i = lg; i > 0; i--)
		printf("%d ",sir[i]);	
}
