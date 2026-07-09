#include <stdio.h>
#define NMAX 1040

int C[NMAX][NMAX], b[NMAX][NMAX];
int A[NMAX], B[NMAX];
int n, m;

inline int max(int i, int j)
{
    return (i>j)?i:j;
}

void lcs()
{
    int i, j;
    for (i=1; i<=n; ++i)
	for (j=1; j<=m; ++j) {
	    if (A[i] == B[j]) 
		C[i][j] = C[i-1][j-1] + 1;
	    else
		C[i][j] = max(C[i][j-1], C[i-1][j]);
	}
}

void print(int i, int j)
{
    if (i == 0 || j == 0)
	return;
    if (A[i] == B[j]) {
	print(i-1, j-1);
	printf("%d ", A[i]);
    }
    else if (C[i-1][j] >= C[i][j-1])
	print(i-1, j);
    else
	print(i, j-1);
}
    
int main()
{
    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);
    int i;
    scanf("%d %d", &n, &m);
    for (i=1; i<=n; ++i) 
	scanf("%d", &A[i]);
    for (i=1; i<=m; ++i) 
	scanf("%d", &B[i]);
    lcs();
    printf("%d\n", C[n][m]);
    print(n, m);
    return 0;
}
