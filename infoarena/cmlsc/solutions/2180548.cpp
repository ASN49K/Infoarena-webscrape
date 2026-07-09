#include <fstream>
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define NMAX 1025
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int n, m, a[NMAX], b[NMAX], c[NMAX][NMAX], st[NMAX], vf;

int main()
{
    fin >> m >> n;
    FOR(i, 1, m)
        fin >> a[i];
    FOR(i, 1, n)
        fin >> b[i];

    FOR(i, 1, m)
        FOR(j, 1, n)
        {
            if(a[i] == b[j])
                c[i][j] = c[i-1][j-1] + 1;
            else
                c[i][j] = max(c[i-1][j], c[i][j-1]);
        }
    for(int i = m, j = n; i; )

        if( a[i] == b[j] )
            st[++vf] = a[i], --i, --j;
        else
            if(c[i-1][j] < c[i][j-1])
                --j;
            else
                --i;
        fout << vf << endl;
        for(int i = vf; i > 0; i--)
            fout << st[i] << " ";

    return 0;
}
