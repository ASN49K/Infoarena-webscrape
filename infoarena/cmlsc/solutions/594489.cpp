#include <iostream>
#include <fstream>

using namespace std;

short N, M, A[1030], B[1030], CMLSC[1030][1030], S[1030];

void Read ()
{
    ifstream fin ("cmlsc.in");
    short i;
    fin >> N >> M;
    for (i=1; i<=N; ++i)
    {
        fin >> A[i];
    }
    for (i=1; i<=M; ++i)
    {
        fin >> B[i];
    }
    fin.close ();
}

short Max (short a, short b)
{
    if (a>b)
    {
        return a;
    }
    return b;
}

void Type ()
{
    ofstream fout ("cmlsc.out");
    short i;
    fout << CMLSC[N][M] << "\n";
    for (i=1; i<= CMLSC[N][M]; ++i)
    {
        fout << S[i] << " ";
    }
    fout.close ();
}

void BuildCMLSC ()
{
    short i, j;
    for (i=1; i<=N; ++i)
    {
        for (j=1; j<=M; ++j)
        {
            if (A[i]==B[j])
            {
                CMLSC[i][j]=CMLSC[i-1][j-1]+1;
                continue;
            }
            CMLSC[i][j]=Max (CMLSC[i-1][j], CMLSC[i][j-1]);
        }
    }
}

void BuildSolution ()
{
    short i, j, L=0;
    for (i=N, j=M; j>0, j>0; )
    {
        if (A[i]==B[j])
        {
            S[CMLSC[N][M]-L]=A[i];
            L++;
            --i;
            --j;
            continue;
        }
        if (CMLSC[i-1][j]>CMLSC[i][j-1])
        {
            --i;
        }
        else
        {
            --j;
        }
    }
}

int main()
{
    Read ();
    BuildCMLSC ();
    BuildSolution ();
    Type ();
    return 0;
}
