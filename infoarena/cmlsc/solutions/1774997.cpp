#include <fstream>
using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

const int dim = 1030;

struct T{
    T() : p1{0}, p2{0}, l{0}
    {}

    int p1, p2, l;
} M[dim][dim], N;

int V1[dim], V2[dim], V[dim], cnt;

int main()
{
    int n, m, p1, p2;
    fin >> n >> m;
    p1 = n;
    p2 = m;
    for (int i = 1; i <= n; i++)
        fin >> V1[i];
    for (int i = 1; i <= m; i++)
        fin >> V2[i];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if ( V1[i] == V2[j] )
            {
                M[i][j].p1 = i;
                M[i][j].p2 = j;
                M[i][j].l = M[i - 1][j - 1].l + 1;
            }
            else
                if ( M[i][j - 1].l > M[i - 1][j].l )
                    M[i][j] = M[i][j - 1];
                else
                    M[i][j] = M[i - 1][j];
    fout << M[n][m].l << '\n';
    while ( p1 && p2 )
    {
        N = M[p1][p2];
        V[++cnt] = V1[ N.p1 ];
        p1 = N.p1 - 1;
        p2 = N.p2 - 1;
    }
    while ( cnt )
        fout << V[cnt--] << ' ';

    fin.close();
    fout.close();
    return 0;
}
