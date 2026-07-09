#include <iostream>
#include <fstream>
using namespace std;
ifstream ka("cmlsc.in");
ofstream ki("cmlsc.out");

const int N_MAX = 1024;

int m, n, A[N_MAX + 1], B[N_MAX + 1], D[N_MAX + 1][N_MAX + 1], raspuns[N_MAX + 1];

void gaseste(int x, int y)
{
    if(x != 0)
    {
        if(D[x - 1][y - 1] == D[x][y] - 1 && A[x] == B[y])
        {
            raspuns[++raspuns[0]] = A[x];
            gaseste(x - 1, y - 1);
        }
        else if(D[x][y - 1] == D[x][y])
            gaseste(x, y - 1);
        else // if D[x - 1][y] == D[x][y]
            gaseste(x - 1, y);
    }

}

int main()
{
    ka >> m >> n;
    for(int i = 1; i <= m; i++)
        ka >> A[i];
    for(int i = 1; i <= n; i++)
        ka >> B[i];
    for(int i = 1; i <= m; i++)
        for(int j = 1; j <= n; j++)
        {
            if(A[i] == B[j])
                D[i][j] = D[i - 1][j - 1] + 1;
            else
                D[i][j] = max(D[i][j - 1], D[i - 1][j]);
        }
    ki << D[m][n] << '\n';
    gaseste(m, n);
    for(int i = D[m][n]; i >= 1; i--)
        ki << raspuns[i] << " ";
}
