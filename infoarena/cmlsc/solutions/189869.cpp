#include <stdio.h>   
  
#define maxim(a, b) ((a > b) ? a : b)   
#define FOR(i, a, b) for (i = a; i <= b; ++i)   

  
int M, N, x[1024], y[1024], z[1024][1024], sir[1024], bst;   
  
int main(void)   
{   
    int i, j;   
       
    freopen("cmlsc.in", "r", stdin);   
    freopen("cmlsc.out", "w", stdout);   
  
    scanf("%d %d", &M, &N);   
    FOr (i, 1, M)   
        scanf("%d", &x[i]);   
    FOR (i, 1, N)   
        scanf("%d", &y[i]);   
  
    FOR (i, 1, M)   
        FOR (j, 1, N)   
            if (x[i] == y[j])   
                z[i][j] = 1 + z[i-1][j-1];   
            else  
                z[i][j] = maxim(z[i-1][j], z[i][j-1]);   
  
    for (i = M, j = N; i; )   
        if (x[i] == y[j])   
            sir[++bst] = x[i], --i, --j;   
        else if (z[i-1][j] < z[i][j-1])   
            --j;   
        else  
            --i;   
  
    printf("%d\n", bst);   
    for (i = bst; i; --i)   
        printf("%d ", sir[i]);   
  
    return 0;   
}  