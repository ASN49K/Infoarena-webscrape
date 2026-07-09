#include <cstdio>

#define FIN "cmlsc.in"
#define FOUT "cmlsc.out"
#define MAX_N 1030

int N, M;
int A[MAX_N], B[MAX_N], R[MAX_N];

int D[MAX_N][MAX_N]; 

    inline int MAX (int a, int b)
    {
           return ((a > b) ? a : b);
    }

    void solve ()
    {
         int i, j;
         
         for (i = 1; i <= N; ++i)
             for (j = 1; j <= M; ++j)
                 if (A[i] == B[j]) D[i][j] = D[i - 1][j - 1] + 1;
                              else D[i][j] = MAX (D[i - 1][j], D[i][j - 1]);
                              
         printf ("%d\n", D[N][M]);
         
         int l = N, c = M, k = 0;
         
         while (l && c)
         {
               if (A[l] == B[c]) R[++k] = A[l], --l, --c;
                           else 
                                if (D[l - 1][c] > D[l][c - 1]) --l; else --c;
         }
         
         while (k) printf ("%d ", R[k--]);
    }

    int main ()
    {
        freopen (FIN, "r", stdin);
        freopen (FOUT, "w", stdout);
        
        scanf ("%d %d", &N ,&M);
        int i;
        
        for (i = 1; i <= N; ++i) scanf ("%d", A + i);
        for (i = 1; i <= M; ++i) scanf ("%d", B + i);
        
        solve ();
        
        return 0;
    }
