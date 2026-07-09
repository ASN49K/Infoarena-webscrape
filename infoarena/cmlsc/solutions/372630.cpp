#include <stdio.h>

int M, N, sol[1024], bst;
int A[1024], B[1024], opt[2][1024], cut[2][1024];

inline int get_opt(int l1, int l2, int l, int c, int idx)
{
    if (l < l1 || c < l2)
        return 0;
    return opt[idx][c];
}

inline int get_cut(int l1, int l2, int l, int c, int idx)
{
    if (l < l1 || c < l2)
        return l2-1;
    return cut[idx][c];
}

void solve(int l1, int r1, int l2, int r2)
{
    if (l1 > r1 || l2 > r2)
        return ;

    int i, j;
    if (l1 == r1 || l2 == r2)
    {
        for (i = l1; i <= r1; ++i)
            for (j = l2; j <= r2; ++j)
                if (A[i] == B[j])
                {
                    sol[i] = 1;
                    ++bst;
                    return ;
                }
        return ;
    }
    
    int m = (l1 + r1) / 2;
    int crt = 1, prev = 0;

    for (i = l1; i <= r1; ++i)
    {
        crt ^= 1; prev ^= 1;
        
        for (j = l2; j <= r2; ++j)
            if (A[i] == B[j])
            {
                opt[crt][j] = get_opt(l1, l2, i-1, j-1, prev) + 1;                    
                cut[crt][j] = get_cut(l1, l2, i-1, j-1, prev);
                if (i <= m)
                    cut[crt][j] = j;
            }
            else
            {
                int i1 = get_opt(l1, l2, i, j-1, crt);
                int i2 = get_opt(l1, l2, i-1, j, prev);
                if (i1 > i2)
                {
                    opt[crt][j] = i1;
                    cut[crt][j] = get_cut(l1, l2, i, j-1, crt);
                }
                else
                {
                    opt[crt][j] = i2;
                    cut[crt][j] = get_cut(l1, l2, i-1, j, prev);                
                }
            }
    }
    
    int x = cut[crt][r2];
    solve(l1, m, l2, x);
    solve(m+1, r1, x+1, r2);
}

int main()
{
    int i, j;
    
    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);
    
    scanf("%d %d", &M, &N);
    for (i = 1; i <= M; ++i)
        scanf("%d", &A[i]);
    for (j = 1; j <= N; ++j)
        scanf("%d", &B[j]);
    
    solve(1, M, 1, N);    
    
    printf("%d\n", bst);
    for (i = 1; i <= M; ++i)
        if (sol[i])
            printf("%d ", A[i]);
    printf("\n");
    
    return 0;
}
