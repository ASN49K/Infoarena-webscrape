#include <bits/stdc++.h>

using namespace std;

const short MAX_N = 1024;

unsigned char A[MAX_N + 1];
unsigned char B[MAX_N + 1];

short D[2][MAX_N + 1];
short cut[2][MAX_N + 1];

unsigned char solution[MAX_N];
short solutionSize;

void LCS( short stA, short fnA, short stB, short fnB )
{
    if ( stA == fnA )
    {
        int i = stB;

        while ( i <= fnB && A[stA] != B[i] )
            ++i;

        if ( i <= fnB )
            solution[solutionSize++] = A[stA];
        return;
    }

    for ( short i = stB - 1; i <= fnB; ++i )
    {
        D[0][i] = 0;
        cut[0][i] = cut[1][i] = i;
    }

    short mid = ( stA + fnA ) / 2;
    bool line = 1;

    for ( short i = stA; i <= fnA; ++i )
    {
        D[line][stB - 1] = 0;
        for ( short j = stB; j <= fnB; ++j )
        {
            if ( A[i] == B[j] )
            {
                D[line][j] = D[line ^ 1][j - 1] + 1;

                if ( i > mid )
                    cut[line][j] = cut[line ^ 1][j - 1];
            }
            else
            {
                if ( D[line][j - 1] >= D[line ^ 1][j] )
                {
                    D[line][j] = D[line][j - 1];

                    if ( i > mid )
                        cut[line][j] = cut[line][j - 1];
                }
                else
                {
                    D[line][j] = D[line ^ 1][j];

                    if ( i > mid )
                        cut[line][j] = cut[line ^ 1][j];
                }
            }
        }
        line ^= 1;
    }

    LCS( stA, mid, stB, cut[line ^ 1][fnB] );
    LCS( mid + 1, fnA, cut[line ^ 1][fnB] + 1, fnB );
}

int main()
{
    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);
    short N, M;

    scanf("%hd%hd", &N, &M);

    for ( short i = 1; i <= N; ++i )
        scanf("%hhd", A + i);

    for ( short i = 1; i <= M; ++i )
        scanf("%hhd", B + i);
    fclose(stdin);

    LCS( 1, N, 1, M );

    printf("%hd\n", solutionSize);
    for ( short i = 0; i < solutionSize; ++i )
        printf("%hhd ", solution[i]);
    fclose(stdout);
    return 0;
}
