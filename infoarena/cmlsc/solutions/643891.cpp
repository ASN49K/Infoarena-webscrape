#include <cstdio>

#define file_in "cmlsc.in"
#define file_out "cmlsc.out"

#define nmax (1<<10)+10

int N,M;
int i,j,A[nmax],B[nmax],D[nmax][nmax],nr,sir[nmax];

int max(int a, int b) { return a>b?a:b; }

int main(){
	
	freopen(file_in,"r",stdin);
	freopen(file_out,"w",stdout);
	
	scanf("%d %d", &N, &M);
	for (i=1;i<=N;++i)
		 scanf("%d", &A[i]);
	for (i=1;i<=M;++i)
		 scanf("%d", &B[i]);
	
	for (i=1;i<=N;++i)
		 for (j=1;j<=M;++j)
			  if (A[i]==B[j])
				   D[i][j]=1+D[i-1][j-1];
			  else
				  D[i][j]=max(D[i-1][j],D[i][j-1]);
			  

	for (i=N,j=M;i;){
		if (A[i]==B[j])
			sir[++nr]=A[i],
			i--,
			j--;
			else
			if (D[i-1][j]>D[i][j-1])
 	            i--;
            else
	            j--;
	}
	
	printf("%d\n", nr);
	for (i=nr;i>=1;--i)
		 printf("%d ", sir[i]);
	
	return 0;
	
}
