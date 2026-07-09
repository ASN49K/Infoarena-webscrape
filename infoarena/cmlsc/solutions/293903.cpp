#include <stdio.h>   
  
#define maxim(a, b) ((a > b) ? a : b)   
#define NMax 1024

int M, N, v[NMax], w[NMax], D[NMax][NMax], sir[NMax], bst;

int main(void)
{
    int i, j;

    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);
    scanf("%d %d", &M, &N);
    for (i=1; i<=M; i++)
	scanf("%d", &v[i]);
    for (j=1; j<=N; j++)
	scanf("%d", &w[j]);
    for (i=1; i<=M; i++)
	 for (int j=1; j<=N; j++)
	     if (v[i]==w[j])
		D[i][j]=D[i-1][j-1]+1;
	     else D[i][j]=maxim(D[i-1][j], D[i][j-1]);
     int jj, ii;
     for (ii=M, jj=N; ii;)
     {     if (v[ii]==w[jj])
	   {  sir[++bst]=v[ii];
	      ii--;
	      jj--;
	   }
	   else if (D[ii][jj-1]>D[ii-1][jj])
		   jj--;
		else ii--;
     }
    printf("%d\n", bst);
    for (i = bst; i; --i)
        printf("%d ", sir[i]);   
  
    return 0;   
}  
