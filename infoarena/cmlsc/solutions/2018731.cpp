#include<stdio.h>

#define NMAX 1024
#define max(a, b) ((a > b) ? a : b)

int n, m, A[NMAX], B[NMAX], D[NMAX][NMAX], sequence[NMAX], current_common_element;

int main() {
	freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);

	scanf("%d %d", &m, &n);
    for (int i = 1; i <= m; i++)
    {
        scanf("%d", &A[i]);
    } 
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &B[i]);
    } 

 
    for(int i = 1; i <= m; i++)
    	for(int j = 1; j <= n; j++) 
    		if (A[i] == B[j])
    			D[i][j] = 1 + D[i-1][j-1];
    		else 
    			D[i][j] = max(D[i-1][j], D[i][j-1]);

    for (int i = m, j = n; i; )
    	if (A[i] == B[j]) {
    		sequence[++current_common_element] = A[i];
    		--i;
    		--j;
    	} else if (D[i-1][j] < D[i][j-1]) {
    		--j;
    	} else {
    		--i;
    	}	
    		
    printf("%d\n", current_common_element);	
    for(int i = current_common_element; i; --i)
    	printf("%d ", sequence[i]); 
	
	return 0;
}