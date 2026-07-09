#include <fstream>
#define OOP 1025

using namespace std;

ifstream fin  ("cmlsc.in");
ofstream fout ("cmlsc.out");

unsigned short int M, N;
unsigned short int A[OOP], B[OOP];

unsigned short int matrix[OOP][OOP];
unsigned short int sol[OOP];
unsigned short int MAX;
unsigned short int i, j;

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
        sol[MAX] = A[i];
        i--;
        j--;
    }
}

void print ()
{
    fout << MAX << "\n";
    for (i=MAX; i>=1; i--)
        fout << sol[i] << " ";
}
