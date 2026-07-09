#include <fstream>
#define NMax 1024 + 1

using namespace std;

ofstream fout("cmlsc.out");

short D[NMax][NMax], X[NMax], Y[NMax], n, m;

void Read()
{
    ifstream fin("cmlsc.in");
    fin >> n >> m;
    for ( int i = 1 ; i <= n ; ++i )
        fin >> X[i];
    for ( int i = 1 ; i <= m ; ++i )
        fin >> Y[i];
    fin.close();
}

void Dinamic()
{
    for ( int i = 0 ; i <= n ; ++i )
        D[i][0] = 0;
    for ( int j = 0 ; j <= m ; ++j )
        D[0][j] = 0;

    for ( int i = 1 ; i <= n ; ++i )
        for ( int j = 1 ; j <= m ; ++j )
            if (X[i] == Y[j])
                D[i][j] = D[i - 1][j - 1] + 1;
            else
                D[i][j] = max(D[i - 1][j], D[i][j - 1]);
}

bool Valid(int i, int j)
{
    if (i < 1 || i > n || j < 1 || j > m)
        return false;
    return (D[i][j] != 0);
}

void Back(int i, int j)
{
    if (X[i] == Y[j])
    {
        if (Valid(i - 1, j - 1))
            Back(i - 1, j - 1);
        fout << X[i] << " ";
    }
    else
    {
        if (D[i - 1][j] > D[i][j - 1])
            Back(i - 1, j);
        else
            Back(i, j - 1);
    }
}


int main()
{
    Read();
    Dinamic();
    fout << D[n][m] << '\n';
    Back(n, m);
    return 0;
}
