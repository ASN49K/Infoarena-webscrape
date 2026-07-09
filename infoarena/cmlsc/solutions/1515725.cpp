#include <fstream>
using namespace std;

const int MAXN = 1026;

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

int a[MAXN], b[MAXN];
int m,n;
int d[MAXN][MAXN];

inline int maxl(int a, int b)
{
    return (a > b)?a:b;
}

void citire()
{
    in >> m >> n;
    for (int i = 1;i <= m;++i)
        in >> a[i];
    for (int i = 1;i <= n;++i)
        in >> b[i];
}

void dinamica()
{
    for (int i = 1;i <= m;++i)
        for (int j = 1;j <= n;++j)
            if (a[i] == b[j])
                d[i][j] = d[i - 1][j - 1] + 1;
            else d[i][j] = maxl(d[i - 1][j], d[i][j - 1]);
}

void afisare()
{
    int sir[MAXN];
    int lsir = 0;
    int i = m, j = n;
    while (i != 0)
    {
        if (a[i] == b[j])
        {
            sir[++lsir] = a[i];
            --i;
            --j;
        }
        else if (d[i][j - 1] > d[i - 1][j])
            --j;
        else --i;
   }
   out << lsir << '\n';
   for (int i = lsir;i > 0;--i)
        out << sir[i] << ' ';
   out << '\n';
}

int main()
{
    citire();
    dinamica();
    afisare();
    return 0;
}
