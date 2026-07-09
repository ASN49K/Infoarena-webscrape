#include<fstream>
#define NMAX 256
#define INF 2048
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int sir[NMAX + 1][3];
int mat[NMAX + 1][NMAX + 1];

int init(int a, int b)
{
    for (int i = 1; i <= a; i++)
        for (int j = 1; j <= b; j++)
            mat[i][j] = INF;
}

int caut(int a, int b)
{
    if (mat[a][b] == INF)
    {
        if (sir[a][0] == sir[b][1])
            mat[a][b] = 1 + caut(a - 1, b - 1);
        else
        {
            if (caut (a - 1, b) > caut (a, b - 1))
                mat[a][b] = caut (a - 1, b);
            else
                mat[a][b] = caut (a, b - 1);
        }
    }
    return mat[a][b];
}

void solutie (int a, int b)
{
    int contor = mat[a][b], aux;
    while (contor > 0)
    {
        aux = mat[a][b];
        if (mat[a - 1][b] == aux || mat[a][b - 1] == aux)
        {
            if (mat[a - 1][b] == aux)
                a -= 1;
            else
                b -= 1;
        }
        else
        {
            sir[contor--][2] = sir[a][0];
            a -= 1;
            b -= 1;
        }
    }
}

int main ()
{
    int m, n;
    fin >> m >> n;
    init (m, n);
    for (int i = 1; i <= m; i++)
        fin >> sir[i][0];
    for (int j = 1; j <= n; j++)
        fin >> sir[j][1];
    fout << caut(m, n) << '\n';
    solutie (m, n);
    for (int k = 1; k <= caut(m, n); k++)
        fout << sir[k][2] << ' ';
    fin.close();
    fout.close();
    return 0;
}
