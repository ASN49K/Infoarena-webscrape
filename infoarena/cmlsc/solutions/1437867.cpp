#include <fstream>

using namespace std;

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

#define N 1030

short v1[N], v2[N], a[N][N], sir[N];
int nr = 0;
int n, m;

inline short maxim(short x, short y)
{
    return (x > y) ? x : y;
}

int main()
{
    in >> n >> m;
    for(int i = 1; i <= n; i++)
        in >> v1[i];
    for(int i = 1; i <= m; i++)
        in >> v2[i];

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            if(v1[i] == v2[j])
                a[i][j] = a[i - 1][j - 1] + 1;
            else
                a[i][j] = maxim(a[i - 1][j], a[i][j - 1]);

    out << a[n][m] << '\n';

    for(int i = n, j = m; i, j; )
        if(v1[i] == v2[j])
            sir[++nr] = v1[i], i--, j--;
        else if(a[i - 1][j] < a[i][j - 1])
            j--;
        else
            i--;

    for(int i = nr; i >= 1; i--)
        out << sir[i] << ' ';
    return 0;
}
