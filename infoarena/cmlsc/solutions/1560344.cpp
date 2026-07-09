#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 1024;

int A[MAX_N + 1];
int B[MAX_N + 1];

int D[2][MAX_N + 1];
int cut[2][MAX_N + 1];

int solution[MAX_N];
int solutionSize;

void LCS( int stA, int fnA, int stB, int fnB )
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

    for ( int i = stB - 1; i <= fnB; ++i )
    {
        D[0][i] = 0;
        cut[0][i] = cut[1][i] = i;
    }

    int mid = ( stA + fnA ) / 2;
    bool line = 1;

    for ( int i = stA; i <= fnA; ++i )
    {
        D[line][stB - 1] = 0;
        for ( int j = stB; j <= fnB; ++j )
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
    ifstream in("cmlsc.in");
    ofstream out("cmlsc.out");
    in.tie(0);
    ios_base::sync_with_stdio(0);
    int N, M;

    in >> N >> M;

    for ( int i = 1; i <= N; ++i )
        in >> A[i];

    for ( int i = 1; i <= M; ++i )
        in >> B[i];
    in.close();

    LCS( 1, N, 1, M );

    out << solutionSize << '\n';
    for ( int i = 0; i < solutionSize; ++i )
        out << solution[i] << ' ';
    out.close();
    return 0;
}
