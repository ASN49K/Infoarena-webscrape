#include <stdio.h>

int M, N, sol[1024], bst;
int A[1024], B[1024], opt[2][1024], tai[2][1024];

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
    int crt = 0, prev = 1;
    
    for (i = l2; i <= r2; ++i)
        opt[prev][i] = opt[crt][i] = 0,
        tai[crt][i] = l2-1;
    for (i = l1; i <= r1; ++i)
    {
        crt ^= 1; prev ^= 1;
        for (j = l2; j <= r2; ++j)
            if (A[i] == B[j])
            {
                if (i == l1 || j == l2)
                    opt[crt][j] = 1, tai[crt][j] = 0;
                else
                    opt[crt][j] = opt[prev][j-1] + 1,                    
                    tai[crt][j] = tai[prev][j-1];
                    
                if (i <= m)
                    tai[crt][j] = j;
            }
            else if (j == l2 || (i > l1 && opt[crt][j-1] < opt[prev][j]))
            {
                opt[crt][j] = opt[prev][j];
                tai[crt][j] = tai[prev][j];
            }
            else
            {
                opt[crt][j] = opt[crt][j-1];                
                tai[crt][j] = tai[crt][j-1];
            }
    }
    
    solve(l1, m, l2, tai[crt][r2]);
    solve(m+1, r1, tai[crt][r2]+1, r2);
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
