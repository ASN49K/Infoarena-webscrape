#include <stdio.h>

#define NMAX 1024


int A[NMAX],B[NMAX],C[NMAX][NMAX],sir[NMAX],c,n,m;


int max(int a, int b)
{
 if(a > b) return a;
           else return b;
}

int main()
{

 int i,j;

 freopen("cmlsc.in", "r", stdin);
 freopen("cmlsc.out", "w", stdout);

 scanf("%d %d", &n, &m);

 for(i=1; i<=n; ++i)
    scanf("%d", &A[i]);

 for(i=1; i<=m; ++i)
    scanf("%d", &B[i]);

 for(i=1; i<=n; ++i)
    for(j=1; j<=m; ++j)
       if(A[i] == B[j]) C[i][j] = 1 + C[i-1][j-1];
                        else C[i][j] = max(C[i-1][j], C[i][j-1]);

 for(i=n, j=m; i;)
    if(A[i] == B[j]) sir[++c] = A[i] , --i, --j;
                     else if(C[i-1][j] < C[i][j-1]) --j;
                                                    else --i;

 printf("%d\n", c);

 for(; c; --c)
    printf("%d ", sir[c]);



 return 0;
}
