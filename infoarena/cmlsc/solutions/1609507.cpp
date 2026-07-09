#include <iostream>
#include <fstream>
using namespace std;

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

const int dmax = 1025;

int a[dmax];
int b[dmax];

int d[dmax][dmax]; // d[i][j] == LUNGIMEA CELUI MAI LUNG SUBSIR COMUN FORMAT CU PRIMELE i DIN a SI PRIMELE j DIN b

int N, M;

void subsir(int i, int j)
{
    if(i == 0 || j == 0) return;

    if(a[i] == b[j])
    {
        subsir(i - 1, j - 1);

        out << a[i] << " ";

        return;
    }

    if(d[i - 1][j] > d[i][j - 1]) subsir(i - 1, j);
    else
        subsir(i, j - 1);
}

int main()
{
    int i, j;

    in >> N >> M;

    for(i = 1; i <= N; i++) in >> a[i];

    for(j = 1; j <= M; j++) in >> b[j];

    for(i = 1; i <= N; i++)
        for(j = 1; j <= M; j++)
        {
            if(a[i] == b[j]) d[i][j] = 1 + d[i - 1][j - 1];
            else
                d[i][j] = max(d[i - 1][j], d[i][j - 1]);
        }

    out << d[N][M] << '\n';

    subsir(N, M);

    return 0;
}
