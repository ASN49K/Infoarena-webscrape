#define MAX_DIM 1024

#include <fstream>
#include <cstring>
#include <algorithm>
#include <string>
using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int n1, n2, sir1[MAX_DIM + 2], sir2[MAX_DIM + 2], a[MAX_DIM + 1][MAX_DIM + 1];
int rasp[MAX_DIM + 2], l;

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
                a[i][j] = a[i - 1][j - 1] + 1;
                if (rasp[i] == '\0')
                {
                    rasp[i] = sir1[i];
                    l = i;
                }
            }
            else
            { a[i][j] = max(a[i - 1][j], a[i][j - 1]); }
        }
    }

    fout << a[n1][n2] << '\n';
    for (int i = 1; i <= l; ++i)
    {
        if (rasp[i])
        {
            fout << rasp[i] << ' ';
        }
    }

    fin.close();
    fout.close();
    return 0;
}
