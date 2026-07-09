#include <fstream>

#define N 1025

using namespace std;

ifstream fin ("cmlsc.in");
ofstream fout("cmlsc.out");

int v[N], w[N], lcs[N][N], sol[N];

int main()
{
    int m, n;
    fin >> n >> m;
    for(int i = 1; i <= n; ++i) fin >> v[i];
    for(int i = 1; i <= m; ++i) fin >> w[i];
    fin.close();

    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            if(v[i] == w[j]) lcs[i][j] = lcs[i-1][j-1] + 1;
            else lcs[i][j] = max(lcs[i-1][j], lcs[i][j-1]);
    for(int i = n, j = m; i;)
    {
        if(v[i] == w[j])
        {
            sol[++sol[0]] = v[i];
            i--; j--;
        }
        else if(lcs[i-1][j] < lcs[i][j-1]) j--;
        else i--;
    }

    fout << sol[0] << '\n';
    for(int i = sol[0]; i; --i) fout << sol[i] << " ";
    fout.close();
    return 0;
}
