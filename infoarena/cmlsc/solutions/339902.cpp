#include <stdio.h>

#define nmax 1024

int m, n, i, j, a[nmax], b[nmax], mat[nmax][nmax], k, drum[nmax];

int maxim (int a, int b) {
	if (a > b) return a;
	else return b;
} 


int main() {
 		freopen ("cmlsc.in", "r", stdin);
		freopen ("cmlsc.out", "w", stdout);   
 		scanf("%d %d", &m, &n);
 		for (i=1; i<=m; ++i)
 			scanf("%d", &a[i]);
 		for (i=1; i<=n; ++i)
		 	scanf("%d", &b[i]);
		 	
	 	for (i=0; i<=m; ++i) {
			mat[0][i]=0;	
			mat[n][i]=0;
		}
		for (i=0; i<=n; ++i) {
			mat[i][0]=0;	
			mat[m][0]=0;
		}		
		
		for (i=1; i<=m; ++i)
			for (j=1; j<=n; ++j)
				if (a[i] == b[j])
				   mat[i][j] = mat[i-1][j-1] + 1;
	   			else
				   mat[i][j] = maxim(mat[i][j-1], mat[i-1][j]);
			
	 	i = m;
	 	j = n;
	 	k = 0;
	 	
	 	while (i > 0 && j > 0) {
			  if (a[i] == b[j]) {
			  	 			  drum[++k] = a[i];
			  	 			  i--;
 			  	 			  j--;
			  }
			  else
			  if (mat[i][j-1] > mat[i-1][j]) 
	 			 j--;
 			  else i--;
	  }
	  
	  printf ("%d\n", k);
	  for (i=k; i>0; --i)
	  	  printf ("%d ", drum[i]);		
 	
	  return 0;	 
}
