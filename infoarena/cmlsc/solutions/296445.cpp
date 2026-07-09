#include <stdio.h>

#define NMax 1024
#define maxim(a,b) ( (a>b) ? a :b )

int m,n,D[NMax][NMax],A[NMax],B[NMax],sir[NMax];

int main()
{
	freopen("cmlsc.in","r",stdin);
	freopen("cmlsc.out","w",stdout);
	scanf("%d",&m); scanf("%d",&n);
	for(int i=1;i<=m;i++) scanf("%d",&A[i]);
	for(int i=1;i<=n;i++) scanf("%d",&B[i]);
	
	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++)
			if(A[i]==B[j])
				D[i][j]=D[i-1][j-1]+1;
			else
				D[i][j]=maxim(D[i-1][j],D[i][j-1]);
	int bst=0,i=m,j=n;
	while (i && j)
		if (A[i]==B[j]) {bst++; sir[bst]=A[i]; i--; j--; }
		else
			if (D[i-1][j]<D[i][j-1]) j--;
			else i--;
	printf("%d\n",bst);
	for(i=bst;i;i--) printf("%d ",sir[i]);	
	
	
}
