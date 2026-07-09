#include <fstream>
#define DM 1025

using namespace std;

ifstream fin ("cmlsc.in");
ofstream fout ("cmlsc.out");

unsigned int A[DM], B[DM];
unsigned int M, N;

unsigned int JOHN[DM][DM];
unsigned int C[DM];
unsigned int i, j, MAX;

void read ();
void solve ();
void print ();

int main ()
{
    read ();
    solve ();
    print ();
    return 0;
}

void read ()
{
    fin >> M >> N;
    for (i=1; i<=M; i++)
        fin >> A[i];
    for (j=1; j<=N; j++)
        fin >> B[j];
}

void solve ()
{
    MAX = 0;
    for (i=1; i<=M; i++)
        for (j=1; j<=N; j++)
            if (A[i] == B[j])
                JOHN[i][j] = JOHN[i-1][j-1] + 1;
            else
                JOHN[i][j] = max (JOHN[i-1][j], JOHN[i][j-1]);
    i = M;
    j = N;
    while (JOHN[i][j])
    {
        while (JOHN[i][j] == JOHN[i-1][j])
            i--;
        while (JOHN[i][j] == JOHN[i][j-1])
            j--;
        MAX++;
        C[MAX] = A[i];
        i--;
        j--;
    }
}

void print ()
{
    fout << MAX << "\n";
    for (i=MAX; i>=1; i--)
        fout << C[i] << " ";
}
