#include<fstream>
#define INF 1024
#define F(i, a, b) for(i = a; i <= b; i++)
#define maxv(a, b) (a > b ? a : b)
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int mat[INF + 1][INF + 1];
int a[INF + 1], b[INF + 1], rez[INF + 1];

int main ()
{
    int m, n, i, j;
    fin >> m >> n;
    //citire ambele siruri
    F(i, 1, m)
    fin >> a[i];
    F(i, 1, n)
    fin >> b[i];
    //calculare mat, unde mat[a][b] repr solutia pentru primele a nr din primul sir si b nr din sirul al doilea
    F(i, 1, m)
    F(j, 1, n)
    if (a[i] == b[j])
        mat[i][j] = mat[i - 1][j - 1] + 1;
    else
        mat[i][j] = maxv(mat[i][j - 1], mat[i - 1][j]);
    fout << mat[m][n] << '\n';
    int aux = mat[m][n];
    mat[0][0] = aux; // copie in plus pentru afisare
    while (aux > 0)
    {
        if (mat[m][n] == mat[m - 1][n] || mat[m][n] == mat[m][n - 1])
        {
            if (mat[m][n] == mat[m - 1][n])
                m -= 1;
            else
                n -= 1;
        }
        else
        {
            rez[aux--] = b[n];
            m -= 1;
            n -= 1;
        }
    }
    F(i, 1, mat[0][0])
    fout << rez[i] << ' ';
    fin.close();
    fout.close();
    return 0;
}
