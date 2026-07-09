#define MAX_DIM 1000

#include <fstream>
#include <cstring>
#include <algorithm>
#include <string>
using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int n1, n2, sir1[MAX_DIM + 2], sir2[MAX_DIM + 2], a[MAX_DIM + 1][MAX_DIM + 1];
string subSiruri[MAX_DIM + 1][MAX_DIM + 1];

int main()
{
    fin >> n1 >> n2;
    for (int i = 1; i <= n1; ++i)
    { fin >> sir1[i]; }
    for (int i = 1; i <= n2; ++i)
    { fin >> sir2[i]; }

    for(int i = 1; i <= n1; ++i)
    {
        for (int j = 1; j <= n2; ++j)
        {
            if (sir1[i] == sir2[j])
            {
                subSiruri[i][j] = subSiruri[i - 1][j - 1];
                a[i][j] = a[i - 1][j - 1] + 1;
                int aux = sir1[i];
                do
                {
                    subSiruri[i][j].push_back((char)('0' + (aux % 10)));
                    aux /= 10;
                } while (aux != 0);
                subSiruri[i][j].push_back(' ');
            }
            else
            {
                if (a[i - 1][j] > a[i][j - 1])
                {
                    a[i][j] = a[i - 1][j];
                    subSiruri[i][j] += subSiruri[i - 1][j];
                }
                else
                {
                    a[i][j] = a[i][j - 1];
                    subSiruri[i][j] += subSiruri[i][j - 1];
                }
            }
        }
    }

    fout << a[n1][n2] << '\n';
    fout << subSiruri[n1][n2];

    fin.close();
    fout.close();
    return 0;
}
