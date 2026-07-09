#include <fstream>
#define InFile  "cmlsc.in"
#define OutFile "cmlsc.out"
#define DIM 1024

using namespace std;

void read ();
void solve ();
void print ();

unsigned short int M, N;
unsigned short int A[DIM], B[DIM];

unsigned short int matrix[DIM][DIM];
unsigned short int C[DIM];
unsigned short int i, j;

unsigned short int MAX;

int main ()
{
    read ();
    solve ();
    print ();
    return 0;
}

void read ()
{
    ifstream fin (InFile);
    fin >> M >> N;
    for (i=1; i<=M; i++)
        fin >> A[i];
    for (j=1; j<=N; j++)
        fin >> B[j];
}

void solve ()
{
    for (i=1; i<=M; i++)
        for (j=1; j<=N; j++)
            if (A[i] == B[j])
                matrix[i][j] = matrix[i-1][j-1] + 1;
            else
                matrix[i][j] = max (matrix[i-1][j], matrix[i][j-1]);
    i = M;
    j = N;
    while (matrix[i][j])
    {
        while (matrix[i][j] == matrix[i-1][j])
            i--;
        while (matrix[i][j] == matrix[i][j-1])
            j--;
        MAX++;
        C[MAX] = A[i];
        i--;
        j--;
    }
}

void print ()
{
    ofstream fout (OutFile);
    fout << MAX << '\n';
    for (i=MAX; i>=1; i--)
        fout << C[i] << ' ';
}
