#include <fstream>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

short C[1025][1025];

int main()
{
    short M, N;
    fin >> M >> N;

    short A[1025], B[1025];
    for(short i=1; i<=M; i++)
        fin >> A[i];
    for(short i=1; i<=N; i++)
        fin >> B[i];

    for(short i=0; i<=M; i++)
        C[i][0] = 0;
    for(short j=0; j<=N; j++)
        C[0][j] = 0;

    for(short i=1; i<=M; i++)
        for(short j=1; j<=N; j++)
            if(A[i] == B[j])
                C[i][j] = C[i-1][j-1] + 1;
            else
                if(C[i-1][j] > C[i][j-1])
                    C[i][j] = C[i-1][j];
                else
                    C[i][j] = C[i][j-1];

    /*for(short i=0; i<=M; i++)
    {
        for(short j=0; j<=N; j++)
            fout << C[i][j] << ' ';
        fout << '\n';
    }*/

    short sol[1025];
    short i = M;
    short j = N;
    short len = C[M][N];

    fout << len;

    while(i > 0 && j > 0)
    {
        if(A[i] == B[j])
        {
            sol[len] = A[i];
            len--;
        }
        if(C[i-1][j] > C[i][j-1])
            i--;
        else
            j--;
    }



    for(short i = 1; i<=C[M][N]; i++)
        fout << sol[i] << ' ';
    fout << '\n';

    fin.close();
    fout.close();
    return 0;
}

