#include <fstream>

#define NM 1025

using namespace std;

ifstream InF ("cmlsc.in");
ofstream OutF ("cmlsc.out");

int a[NM], b[NM];
unsigned m, n;

int aux[NM][NM];
int c[NM];
int i, j, sol;

void scan ();
void solve ();
void print ();

int main ()
{
    scan ();
    solve ();
    print ();
    return 0;
}

void scan ()
{
    int i;
    InF >> m >> n;
    for (i=1; i<=m; i++)
        InF >> a[i];
    for (j=1; j<=n; j++)
        InF >> b[j];
}

void solve ()
{
    sol = 0;
    for (i=1; i<=m; i++)
        for (j=1; j<=n; j++)
            if (a[i] == b[j])
                aux[i][j] = aux[i-1][j-1]+1;
            else
                aux[i][j] = max (aux[i-1][j], aux[i][j-1]);
    i = m;
    j = n;
    while (aux[i][j])
    {
        while (aux[i][j] == aux[i-1][j])
            i--;
        while (aux[i][j] == aux[i][j-1])
            j--;
        sol++;
        c[sol] = a[i];
        i--;
        j--;
    }
}

void print ()
{
    OutF << sol << "\n";
    for (i=sol; i>=1; i--)
        OutF << c[i] << " ";
}
