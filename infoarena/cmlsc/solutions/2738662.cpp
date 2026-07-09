#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>

using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int** cmlsc(int* a, int* b, const int& n, const int& m)
{
    int** c = new int*[n + 1];
    for (int i = 0; i <= n; ++i)
    {
        c[i] = new int[m+ 1];
    }
    for (int i = 0; i <= n; ++i)
    {
        c[i][0] = 0;
    }
    for (int i = 0; i <= m; ++i)
        c[0][i] = 0;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            if(a[i - 1] == b[j - 1])
                c[i][j] = c[i - 1][j - 1] + 1;
            else
               c[i][j] = max(c[i][j - 1], c[i - 1][j]);
        }
    }
    return c;
}

int backtrack(int** c, int* a, int* b, int x, int y, int* r, int k)
{
    if (x == 0 || y == 0)
        return 0;
    if (a[x - 1] == b[y - 1])
    {
        r[k] = a[x - 1];
        return backtrack(c, a, b, x - 1, y - 1, r, k + 1) + 1;
    }
    if (c[x][y - 1] > c[x - 1][y])
        return backtrack(c, a, b, x, y - 1, r, k);
    return backtrack(c, a, b, x - 1, y, r, k);
}


int main()
{
    int M, N, x;
    fin >> M >> N;
    int* a = new int[N];
    int* b = new int[M];
    int* r = new int[max(N, M)];

    for(int i = 0; i < M; ++i)
    {
        fin >> b[i];
    }
    for(int i = 0; i < N; ++i)
    {
        fin >> a[i];
    }
    int** c = cmlsc(a, b, N, M);

    int K = backtrack(c, a, b, N, M, r, 0);
    fout << K << '\n';
    for (int i = K - 1; i >= 0; --i)
        fout << r[i] << ' ';
    for (int i = 0; i <= N; ++i)
        delete[] c[i];
    return 0;
}
