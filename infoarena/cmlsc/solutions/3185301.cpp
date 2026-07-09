#include <fstream>

using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
const int NMAX = 1025;
int M, N, A[NMAX], B[NMAX],
    C[NMAX][NMAX], S[NMAX];

void citire()
{
    int i;
    f >> M >> N;
    for(i = 1; i <= M; i++)
        f >> A[i];
    for(i = 1; i <= N; i++)
        f >> B[i];
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

void afisare()
{
    int MAX = C[M][N];
    g << MAX << '\n';
    for(int i = 1; i <= MAX; i++)
        g << S[i] << ' ';
}

void generare()
{
    int i = M, j = N, k = C[M][N];
    while(i > 0 && j > 0)
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

int main()
{
    citire();
    calcul();
    generare();
    afisare();
    f.close();
    g.close();
    return 0;
}
