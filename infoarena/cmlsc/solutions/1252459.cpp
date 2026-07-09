#include <iostream>
#include <fstream>

using namespace std;
const int Nmax = 1111;

int max(const int x, const int y) { return x > y ? x : y; }

int A[Nmax], B[Nmax];
int d[Nmax][Nmax][2];
int sol[Nmax];

int main()
{
    ifstream f ("cmlsc.in");
    ofstream g ("cmlsc.out");
    
    int M, N;
    f >> M >> N;
    for (int i = 1; i <= M; i++)
        f >> A[i];
    for (int i = 1; i <= N; i++)
        f >> B[i];
    
    for (int i = 1; i <= M; i++)
    for (int j = 1; j <= N; j++)
    {
        int mx = max(d[i-1][j][0], d[i][j-1][0]);
        d[i][j][0] = mx;
        d[i][j][1] = d[i-1][j][0] > d[i][j-1][0] ? 1 : 2;
        if (A[i] == B[j] && d[i-1][j-1][0] + 1 > mx)
        {
            d[i][j][0] = d[i-1][j-1][0] + 1;
            d[i][j][1] = 3;
        }
    }
    
    int answer = sol[0] = d[M][N][0];
    int m = M, n = N;
    while (m && n)
    {
        switch (d[m][n][1])
        {
            case 1: m--; break;
            case 2: n--; break;
            case 3: sol[sol[0]--] = A[m]; m--; n--; break;
            default: cerr << "d[][]:" << m << ' ' << n << " unexpected value" << '\n';
        }
    }
    g << answer << '\n';
    for (int i = 1; i <= answer; i++)
    {
        g << sol[i] << ' ';
    }
    g << '\n';

    return 0;
}














