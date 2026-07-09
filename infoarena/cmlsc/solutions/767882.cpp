#include <fstream>
#include <stack>

using namespace std;

int N, M;
int a[1030], b[1030];
int mat[1030][1030][3];
stack <int> s;

void Citire () {
    ifstream fin ("cmlsc.in");
    fin >> N >> M;
    for (int i = 1; i <= N; i++)
        fin >> a[i];
    for (int j = 1; j <= M; j++)
        fin >> b[j];
    fin.close ();
}

void Business () {
    ofstream fout ("cmlsc.out");
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            if (a[i] == b[j])
            {
                mat[i][j][0] = mat[i - 1][j - 1][0] + 1;
                mat[i][j][1] = i - 1;
                mat[i][j][2] = j - 1;
            }
            else
            {
                if (mat[i][j - 1][0] > mat[i - 1][j][0])
                {
                    mat[i][j][0] = mat[i][j - 1][0];
                    mat[i][j][1] = i;
                    mat[i][j][2] = j - 1;
                }
                else
                {
                    mat[i][j][0] = mat[i - 1][j][0];
                    mat[i][j][1] = i - 1;
                    mat[i][j][2] = j;
                }
            }
        }
    }
    fout << mat[N][M][0] << "\n";
    int i = N, j = M, aux;
    while (i > 0)
    {
        if (a[i] == b[j]) s.push (a[i]);
        aux = mat[i][j][1];
        j = mat[i][j][2];
        i = aux;
    }
    while (!s.empty ())
    {
        fout << s.top () << " ";
        s.pop ();
    }
}

int main () {
    Citire ();
    Business ();
    return 0;
}
