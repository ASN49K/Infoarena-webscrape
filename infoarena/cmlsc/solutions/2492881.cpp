#include <fstream>

using namespace std;

const int NMAX = 1025;

int M, N;
short A[NMAX], B[NMAX], S[NMAX],
      C[NMAX][NMAX];

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

void citire()
{
    f >> M >> N;
    for(int i = 1; i <= M; i++)
        f >> A[i];
    for(int j = 1; j <= N; j++)
        f >> B[j];
}

void calcul()
{
    for(int i = 1; i <= M; i++)
        for(int j = 1; j <= N; j++)
            if(A[i] == B[j])
                C[i][j] = C[i - 1][j - 1] + 1;
            else
                C[i][j] = max(C[i - 1][j], C[i][j - 1]);
}

void generare()
{
    int i = M, j = N, k = C[M][N];
    while(k > 0)
        if(A[i] == B[j])
        {
            S[k] = A[i];
            i--, j--, k--;
        }
        else
            if(C[i - 1][j] >= C[i][j - 1])
                i--;
            else
                j--;
}

void afisare()
{
    int MAX = C[M][N];
    g << MAX << '\n';
    for(int i = 1; i <= MAX; i++)
        g << S[i] << ' ';
}

int main()
{
    citire();
    calcul();
    generare();
    afisare();
    return 0;
}
