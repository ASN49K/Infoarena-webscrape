/*
#include <fstream>
#define NMax 1024
#define max(a,b) ( (a > b) ? (a) : (b) )
#define FOR( i, A, B ) for( i=A; i<=B; i++ )
int m, n;
int A[NMax], B[NMax], c[NMax][NMax], sir[NMax], lg;

void citire()
{
    int i;
    std::ifstream fin("cmlsc.in");
    fin >> m >> n;
    FOR( i, 1, m ) fin >> A[i];
    FOR( i, 1, n ) fin >> B[i];
    fin.close();
}
int main()
{
      std::ofstream fout("cmlsc.out");
      int i, j;
      citire();

      FOR( i, 1, m )
          FOR( j, 1, m )
               if( A[i]==B[j] )
                   c[i][j] = 1 + c[i-1][j-1];
               else
                   c[i][j] = max( c[i-1][j], c[i][j-1] );

      for( i=m, j=n; i; )
           if( A[i] == B[j] )
               sir[++lg] = A[i], --i, --j ;
           else if( c[i-1][j] < c[i][j-1] )
               --j;
           else
               --i;

      fout << lg << '\n';
      FOR( i, 1, lg )
           fout << sir[i] << ' ';
      fout.close();

      return 0;
}
*/
#include <stdio.h>

#define maxim(a, b) ((a > b) ? a : b)
#define FOR(i, a, b) for (i = a; i <= b; ++i)
#define NMax 1024

int M, N, A[NMax], B[NMax], D[NMax][NMax], sir[NMax], bst;

int main(void)
{
    int i, j;
    
    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);

    scanf("%d %d", &M, &N);
    FOR (i, 1, M)
        scanf("%d", &A[i]);
    FOR (i, 1, N)
        scanf("%d", &B[i]);

    FOR (i, 1, M)
        FOR (j, 1, N)
            if (A[i] == B[j])
                D[i][j] = 1 + D[i-1][j-1];
            else
                D[i][j] = maxim(D[i-1][j], D[i][j-1]);

    for (i = M, j = N; i; )
        if (A[i] == B[j])
            sir[++bst] = A[i], --i, --j;
        else if (D[i-1][j] < D[i][j-1])
            --j;
        else
            --i;

    printf("%d\n", bst);
    for (i = bst; i; --i)
        printf("%d ", sir[i]);

    return 0;
}

