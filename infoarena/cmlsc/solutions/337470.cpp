#include<stdio.h>
#define N 1025
int A[N], B[N], C[N][N], S[N], bst;

const char in[]="cmlsc.in";
const char out[]="cmlsc.out";

inline int maxim(int a, int b)
	{
		if(a>b) return a;
		return b;
}

int main()
	{
		int n, m, i, j;
		freopen(in, "r", stdin);
		freopen(out, "w", stdout);
		scanf("%d %d", &n, &m);
			for(i=1;i<=n;++i)
				scanf("%d ", &A[i]);
			for(i=1;i<=m;++i)
				scanf("%d ", &B[i]);
			for(i=1;i<=n;++i)
				for(j=1;j<=m;++j)
					if(A[i] == B[j])C[i][j]=1 + C[i-1][j-1];
				else C[i][j]=maxim(C[i][j-1],C[i-1][j]);
			
			for(i=n, j=m;i;)
				if(A[i]==B[j])S[++bst]=B[j], --i, --j;
			else if(C[i-1][j]<C[i][j-1])--i;
				else --j;
			printf("%d\n",bst);
				for(;bst;)
					printf("%d ",S[bst--]);
				printf("\n");
			return 0;
}			