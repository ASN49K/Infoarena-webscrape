#include <iostream>
#include <fstream>
using namespace std;
const int NMAX = 1025;

int n, m, nr, A[NMAX], B[NMAX], C[NMAX][NMAX], D[NMAX];

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

void calcul()
{
    int i,j;
    for(i = 1; i <= m; i++)
        for(j = 1; j <= n; j++)
        {
            if(A[i] == B[j])
                C[i][j] = C[i - 1][j - 1] + 1;
            else
                C[i][j] = max(C[i - 1][j], C[i][j - 1]);
        }
    i--;
    j--;
    while(i > 0 && j > 0)
    {
        if(A[i] == B[j])
        {
            D[++nr] = A[i];
            i--;
            j--;
        }
        else
        {
            if(C[i - 1][j] > C[i][j - 1])
                i--;
            else
                j--;
        }
    }
}

int main()
{
    int i, j;
    f >> m >> n;
    for(i = 1; i <= m; i++)
        f >> A[i];
    for(i = 1; i <= n; i++)
        f >> B[i];
    calcul();
    g << nr << '\n';
    for(i = nr; i >= 1; i--)
        g << D[i] << ' ';
    return 0;
}
