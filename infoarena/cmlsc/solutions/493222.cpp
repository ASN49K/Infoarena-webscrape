#include <cstdio>
#include <cstring>

using namespace std;

#define MAX_N 1030

int n, m;
int d[MAX_N][MAX_N], A[MAX_N], B[MAX_N], R[MAX_N];

inline int MAX (int a, int b) {
       return (a > b) ? a : b;
}

int main () {
    freopen ("cmlsc.in", "r", stdin);
    freopen ("cmlsc.out", "w", stdout);
    
    scanf ("%d %d", &n, &m);
    
    for (int i = 1; i <= n; ++i) scanf ("%d", A + i);
    for (int i = 1; i <= n; ++i) scanf ("%d", B + i);
    
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            if (A[i] == B[j])
               d[i][j] = d[i - 1][j - 1] + 1;
            else
               d[i][j] = MAX (d[i - 1][j], d[i][j - 1]);
               
    printf ("%d\n", d[n][m]);
    
    int pi = n, pj = m, k;
    
    for (k = 0; pi * pj > 0;)
        if (A[pi] == B[pj])
           R[++k] = A[pi], --pi, --pj;
        else
            if (d[pi - 1][pj] > d[pi][pj - 1]) --pi;
                                          else --pj;
                                          
    for (int i = k; i; --i) printf ("%d ", R[i]);
    
    return 0;
}
    
    
